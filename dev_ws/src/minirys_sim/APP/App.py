import os
import sys
import gi
import xml.etree.ElementTree as ET
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk, Gdk, Gio
import inspect
import subprocess
from subprocess import PIPE, run, TimeoutExpired, CalledProcessError
import threading
import time
from PIL import Image
from gi.repository import GdkPixbuf
import re
from datetime import datetime
import xml.dom.minidom
from xml.dom.minidom import parseString
import json

import rclpy
from rclpy.executors import SingleThreadedExecutor
from gazebo_msgs.srv import DeleteEntity,GetModelList

class ProcessClass:
    def __init__(self):
        self.process = None
        self.gazebo_process = None
        self.sim_terminal_title = "SimulatorTerminal"
        self.gazebo_terminal_title = "GazeboTerminal"
        self.drive_terminal_title = "DriveTerminal"
        self.monitor_terminal_title = "MonitorTerminal"
        self.sim_terminal_command = f"gnome-terminal --title='{self.sim_terminal_title}'"
        self.gazebo_terminal_command = f"gnome-terminal --title='{self.gazebo_terminal_title}'"
        self.drive_terminal_command = f"gnome-terminal --title='{self.drive_terminal_title}'"
        self.monitor_terminal_command = f"gnome-terminal --title='{self.monitor_terminal_title}'"

    def is_terminal_open(self, title):
        terminal_list = subprocess.check_output("wmctrl -l", shell=True).decode()
        return title in terminal_list

class RobotOptions:
    def __init__(self):
        self.robot_namespace = "robot"
        self.color_code = "#9370DB"
        self.camera_enabled = True
        self.camera_visibility = False
        self.label_enabled = True
        self.label_x = 0.13
        self.label_y = 0.05
        self.TOF_enabled = False
        self.horizontal_sensor_visibility = True
        self.vertical_sensor_visibility = False
        self.all_sensor_visibility = False
        self.TOF_FOV_angle = 0.08
        self.TOF_range = 5
        self.spawn_x = -2.0
        self.spawn_y = -3.0
        self.spawn_z = 0.0
        self.spawn_roll = 0.0
        self.spawn_pitch = 0.0
        self.spawn_yaw = 1.570796327
        self.chassis_mu1 = 0.0
        self.chassis_mu2 = 0.0
        self.chassis_kp = 10000000.0
        self.chassis_kd = 1.0
        self.wheel_mu1 = 20.0
        self.wheel_mu2 = 20.0
        self.wheel_kp = 10000000.0
        self.wheel_kd = 1.0
        self.wheel_joint_dumping = 100.0
        self.wheel_joint_friction = 1.0
        self.chassis_mx = 0.0
        self.chassis_my = 0.0
        self.chassis_mz = 0.015152
        self.chassis_ixx = 0.002829167
        self.chassis_ixy = 0.0
        self.chassis_ixz = 0.0
        self.chassis_iyy = 0.002829167
        self.chassis_iyz = 0.0
        self.chassis_izz = 0.3625
        self.wheels_ixx = 0.00013418
        self.wheels_ixy = 0.0
        self.wheels_ixz = 0.0
        self.wheels_iyy = 0.00013418
        self.wheels_iyz = 0.0
        self.wheels_izz = 0.00026198
		
def populate_robot_option_name_list():
    options = {
        "robot_namespace": str,
        "color_code": str, 
        "camera_enabled": bool,
        "camera_visibility": bool,
        "label_enabled": bool,
        "label_x": float,
        "label_y": float,
        "TOF_enabled": bool,
        "horizontal_sensor_visibility": bool,
        "vertical_sensor_visibility": bool,
        "all_sensor_visibility": bool,
        "TOF_FOV_angle": float,
        "TOF_range": float,
        "spawn_x": float,
        "spawn_y": float,
        "spawn_z": float,
        "spawn_roll": float,
        "spawn_pitch": float,
        "spawn_yaw": float,
        "chassis_mu1": float,
        "chassis_mu2": float,
        "chassis_kp": float,
        "chassis_kd": float,
        "wheel_mu1": float,
        "wheel_mu2": float,
        "wheel_kp": float,
        "wheel_kd": float,
        "wheel_joint_dumping": float,
        "wheel_joint_friction": float,
        "chassis_mx": float,
        "chassis_my": float,
        "chassis_mz": float,
        "chassis_ixx": float,
        "chassis_ixy": float,
        "chassis_ixz": float,
        "chassis_iyy": float,
        "chassis_iyz": float,
        "chassis_izz": float,
        "wheels_ixx": float,
        "wheels_ixy": float,
        "wheels_ixz": float,
        "wheels_iyy": float,
        "wheels_iyz": float,
        "wheels_izz": float,
    }

    return options


class RobotGroupDriveParameters:
    def __init__(self):
        self.group_name = ""
        self.robots = ""
        self.mode = 0
        self.sequence = ""
        self.loop = 0
    def __str__(self):
        return f"RobotGroupDriveParameters(group={self.group_name}, robots={self.robots}, mode={self.mode}, sequence={self.sequence}, loop={self.loop})"
    __repr__ = __str__
        

class SimulationParameters:
    def __init__(self):
        self.robots_number = 1
        self.number_of_rows = 1
        self.gazebo_world = "empty.world"
        
        self.use_gradient_color = True     
        self.randomize_colors = False     
        self.gradient_starting_color = "#000000"
        self.gradient_color_step = "#020501"
       
        self.x_separation = 0.0
        self.y_separation = 0.0
        self.z_separation = 0.0
        self.x_offset = -2.0
        self.y_offset = -3.0
        self.z_offset = 0.056
        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 1.570796327

        self.camera_enabled = True
        self.camera_visibility = False
        self.TOF_enabled = True
        self.horizontal_sensor_visibility = False
        self.vertical_sensor_visibility = False
        self.all_sensor_visibility = False

        self.camera_enabled = True
        self.camera_visibility = False
        self.TOF_enabled = True
        self.horizontal_sensor_visibility = False 
        self.vertical_sensor_visibility = False
        self.all_sensor_visibility = False

        self.param_to_change = ["wheel_mu1", "wheel_mu2"]
        self.start_from = [1.0, 1.0]
        self.iterate_by = [2.0, 2.0]


def populate_simulation_options_name_list():
    simulation_options_name_list = {
        "robots_number": int,
        "number_of_rows": int,
        "gazebo_world": str,

        "use_gradient_color": bool,
        "randomize_colors": bool,
        "gradient_starting_color": str,
        "gradient_color_step": str,
    
        "x_separation": float,
        "y_separation": float,
        "z_separation": float,
        "x_offset": float,
        "y_offset": float,
        "z_offset": float,
        "roll": float,
        "pitch": float,
        "yaw": float,

        "param_to_change": list,
        "start_from": list,
        "iterate_by": list,

        "camera_enabled": bool,
        "camera_visibility": bool,
        
        "TOF_enabled": bool,
        "horizontal_sensor_visibility": bool, 
        "vertical_sensor_visibility": bool,
        "all_sensor_visibility": bool,
    }

    list_value_types = {
        "param_to_change": str,
        "start_from": float,
        "iterate_by": float,
    }

    return simulation_options_name_list, list_value_types 


class ParamsToChange:
    def __init__(self):
        self.TOF_FOV_angle = False
        self.TOF_range = False
        self.chassis_mu1 = False
        self.chassis_mu2 = False
        self.chassis_kp = False
        self.chassis_kd = False
        self.wheel_mu1 = True
        self.wheel_mu2 = True
        self.wheel_kp = False
        self.wheel_kd = False
        self.wheel_joint_dumping = False
        self.wheel_joint_friction = False
        self.chassis_mx = False
        self.chassis_my = False
        self.chassis_mz = False
        self.chassis_ixx = False
        self.chassis_ixy = False
        self.chassis_ixz = False
        self.chassis_iyy = False
        self.chassis_iyz = False
        self.chassis_izz = False
        self.wheels_ixx = False
        self.wheels_ixy = False
        self.wheels_ixz = False
        self.wheels_iyy = False
        self.wheels_iyz = False
        self.wheels_izz = False


class GroupCreationWindow(Gtk.Window):
    def __init__(self, main_window, group_param, is_form_edit_button):
        
        main_window.update_robots_already_taken_list()

        self.is_form_edit_button = is_form_edit_button        
        Gtk.Window.__init__(self, title="Edit Group" if is_form_edit_button else "Create Group")
        self.set_size_request(300, 200)
        self.main_window = main_window
        self.layout = Gtk.VBox(spacing=10)
        self.add(self.layout)
        self.monitor_clicked_flag = 0

        if group_param:
            current_group_name = group_param.group_name
        else:
            try:
                current_group_name = f"Group{int(str(main_window.robot_group_params_list[len(main_window.robot_group_params_list)-1].group_name).replace('Group', '')) + 1}"
            except:
                current_group_name = "Group1"
                
        self.group_name_entry = Gtk.Entry()
        self.group_name_entry.set_text(current_group_name)
        self.layout.pack_start(self.group_name_entry, False, False, 0)

        self.checkboxes = []
        selected_robots = group_param.robots.split(",") if group_param and group_param.robots else []
        
        for i in range(self.main_window.simulation_options.robots_number):
            robot_name = f"robot{i+1}"
            checkbox = Gtk.CheckButton(label=robot_name)
            if robot_name in selected_robots:
                checkbox.set_active(True)
            if robot_name in self.main_window.robots_already_taken_to_other_group and robot_name not in selected_robots:
                checkbox.set_sensitive(False)
            self.checkboxes.append(checkbox)
            self.layout.pack_start(checkbox, False, False, 0)

        save_button = Gtk.Button(label="Save")
        save_button.connect("clicked", self.on_save_button_clicked)
        self.layout.pack_start(save_button, False, False, 0)

        self.robot_group_params = group_param if group_param else RobotGroupDriveParameters()


    def on_save_button_clicked(self, widget):
        selected_robots = [f"robot{i+1}" for i, checkbox in enumerate(self.checkboxes) if checkbox.get_active()]

        if not selected_robots:
            print("[APP INFO] No robots have been selected...")
            print("[APP INFO] Aborting...")
            self.destroy()
            return

        # If this window was opened by the edit button, update the existing group.
        if self.is_form_edit_button:  # This variable should be set in the __init__ method
            self.robot_group_params.group_name = self.group_name_entry.get_text()
            self.robot_group_params.robots = ",".join(selected_robots)
            print(f"Group Edited: {self.robot_group_params.group_name}")
        else:
            new_group = RobotGroupDriveParameters()
            new_group.robots = ",".join(selected_robots)
            new_group.group_name = self.group_name_entry.get_text()
            self.main_window.robot_group_params_list.append(new_group)
            print(f"New Group Created: {new_group.group_name}")

        self.main_window.update_right_column()
        self.destroy()


class EditParamsToChangeWindow(Gtk.Window):
    def __init__(self, main_window):
        Gtk.Window.__init__(self, title="Edit params to change")
        self.main_window = main_window
        # Set the size of the new window (optional)
        self.set_default_size(300, 660)
        
        self.params_to_change = ParamsToChange()
        self.params_to_change_option_name_list = vars(self.params_to_change)

        self.update_param_to_change_from_sim_params()
        # Create a new vertical box named "main_box"
        main_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        main_box.set_margin_top(10)
        main_box.set_margin_bottom(10)
        main_box.set_margin_start(10)
        main_box.set_margin_end(10)
        
        # Create a new horizontal box named "foot_box"
        foot_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL)
        main_box.pack_end(foot_box, False, True, 0)

        # Center align the button
        foot_box.set_halign(Gtk.Align.CENTER)
        foot_box.set_margin_top(5)
        foot_box.set_margin_bottom(5)
        foot_box.set_margin_start(5)
        foot_box.set_margin_end(5)

        options_widgets = self.create_options_widgets()
        main_box.pack_start(options_widgets, True, True, 0)

        # Create a new ScrolledWindow and add main_box into it
        scrolled_window = Gtk.ScrolledWindow()
        scrolled_window.add(main_box)
        self.add(scrolled_window) 

        # Create a new button and add it to the foot_box
        button = Gtk.Button(label="Submit")
        button.connect("clicked", self.on_button_clicked)
        foot_box.pack_start(button, False, False, 0)
    
    def update_param_to_change_from_sim_params(self):
        if self.main_window.simulation_options.param_to_change is not None:
            for param_name in self.params_to_change_option_name_list.keys():
                if param_name in self.main_window.simulation_options.param_to_change:
                    setattr(self.params_to_change, param_name, True)
                else:
                    setattr(self.params_to_change, param_name, False)
 
    
    def create_options_widgets(self):
        # Create a vertical box to hold all options
        options_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)

        for param_name in self.params_to_change_option_name_list.keys():
            # Create a horizontal box to hold the checkbox and label
            hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL)

            # Create a checkbox and label with the name of the parameter
            checkbox = Gtk.CheckButton(label=param_name)

            # Set the checkbox to the current state of the parameter
            checkbox.set_active(getattr(self.params_to_change, param_name))

            # When the checkbox is toggled, update the corresponding option in params_to_change
            checkbox.connect("toggled", self.update_param_to_change, param_name)
            
            hbox.pack_start(checkbox, False, False, 0)
            options_box.pack_start(hbox, False, False, 0)

        return options_box
    
    def update_param_to_change(self, checkbox, param_name):
        if checkbox.get_active():
            setattr(self.params_to_change, param_name, True)
        else:
            setattr(self.params_to_change, param_name, False)

    def update_sim_param_lists_based_on_params_to_change(self):
        param_to_change_name_list = []
        for param_name in self.params_to_change_option_name_list.keys():
            if getattr(self.params_to_change, param_name):
                param_to_change_name_list.append(param_name)
        return param_to_change_name_list


    def new_start_and_iterate_values(self, param_to_change_name_list):
        old_start_from = self.main_window.simulation_options.start_from
        old_iterate_by = self.main_window.simulation_options.iterate_by
        old_param_to_change = self.main_window.simulation_options.param_to_change

        new_start_from = [None] * len(param_to_change_name_list)
        new_iterate_by = [None] * len(param_to_change_name_list)

        # Check if old_param_to_change, old_start_from, or old_iterate_by is None
        if old_param_to_change is None or old_start_from is None or old_iterate_by is None:
            return new_start_from, new_iterate_by

        for old_name, start, iterate in zip(old_param_to_change, old_start_from, old_iterate_by):
            if old_name in param_to_change_name_list:
                index = param_to_change_name_list.index(old_name)
                new_start_from[index] = start
                new_iterate_by[index] = iterate

        return new_start_from, new_iterate_by

    def on_button_clicked(self, button):
        print("Submit button form EditParamsToChangeWindow was clicked")
        param_to_change_name_list = self.update_sim_param_lists_based_on_params_to_change()
        new_start_from, new_iterate_by = self.new_start_and_iterate_values(param_to_change_name_list)
        self.main_window.simulation_options.start_from = new_start_from
        self.main_window.simulation_options.iterate_by = new_iterate_by
        print(f"new_start_from, new_iterate_by: {new_start_from}, {new_iterate_by}")
        print(f"param_to_change_name_list: {param_to_change_name_list}")
        self.main_window.simulation_options.param_to_change = param_to_change_name_list
        print(f"self.main_window.simulation_options.param_to_change: {self.main_window.simulation_options.param_to_change}")
        self.main_window.update_simulation_params_in_xml(self.main_window.simulation_options)
        self.main_window.update_right_column()
        self.destroy()



class MainWindow(Gtk.ApplicationWindow):
    def __init__(self, app):
        css_provider = Gtk.CssProvider()
        css_provider.load_from_data("""
            .missing-field {
                border-color: red;
            }
        """.encode())

        Gtk.StyleContext.add_provider_for_screen(
            Gdk.Screen.get_default(), 
            css_provider, 
            Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION
        )
        ###############
        ## VARIABLES ##
        ###############
        self.tab1 = "\nSimulation parametes\n"
        self.tab2 = "\nRobot data\n"
        self.tab3 = "\nRobots driver\n"
        self.list_of_tabs = [self.tab1, self.tab2, self.tab3]
        
        self.tab_selected = self.tab1
        self.robot_selected = "Robot -1"
        self.upload_clicked = 0
        self.gazebo_running = 0
        self.robot_group_params_list = []

        self.robots_already_taken_to_other_group = []

        Gtk.Window.__init__(self, title="Mulitiple-robot system simulator", application=app)
        
        # Set the icon of the window
        self.set_icon_from_file("icon.png")

        # Set the size of the window
        self.set_default_size(int(800*1.3), int(600*1.5))
        
        # self.params_to_change_option_list = ParamsToChange()

        self.simulator_process = ProcessClass()
        script_path = os.path.abspath(__file__).replace("APP/App.py", "")
        self.package_path = os.path.dirname(script_path)
        self.initialize_drive_config_from_xml()

        self.world_list = []
        self.load_worlds_from_xml()

        self.simulation_options_name_list, self.list_value_types = populate_simulation_options_name_list() # This function only sets the options dictionary
        self.robot_options_name_list = populate_robot_option_name_list() # This function only sets the options dictionary
        self.simulation_options = self.load_launch_data()

        # Create a Gtk.Grid layout
        self.grid = Gtk.Grid()
        self.add(self.grid)

        # Create a Gtk.Paned to divide the window into two parts
        self.paned = Gtk.Paned(orientation=Gtk.Orientation.HORIZONTAL)
        self.grid.attach(self.paned, 0, 0, 1, 1)
        self.paned.set_hexpand(True)
        self.paned.set_vexpand(True)
        self.paned.set_position(500)

        # Create a Gtk.ScrolledWindow for the left column
        self.left_scrolled_window = Gtk.ScrolledWindow()
        self.left_scrolled_window.set_policy(Gtk.PolicyType.NEVER, Gtk.PolicyType.AUTOMATIC)
        self.paned.pack1(self.left_scrolled_window, resize=True, shrink=True)

        # Create a Gtk.ListBox for the boxes in the left column
        self.left_listbox = Gtk.ListBox()
        self.left_scrolled_window.add(self.left_listbox)     
        self.left_listbox.connect("row-selected", self.on_robot_selected)  # Connect the row-selected signal to a callback function

        # Buttons of the left column
        self.add_button("Upload") # Upload from the file
        self.add_button("Clear")  # Clear configs
        
        # Add left tutorial
        left_tutorial = Gtk.Label(label="\n\nClick \"Upload\" after starting the simulation to populate the list of robots.")
        left_tutorial.set_line_wrap(True)  
        left_tutorial.set_max_width_chars(-1)
        left_tutorial.set_justify(Gtk.Justification.LEFT)

        self.left_listbox.add(left_tutorial)
        self.set_widget_margins(left_tutorial, start=25, end=25)

        
        # Create a Gtk.ScrolledWindow for the right column
        self.right_scrolled_window = Gtk.ScrolledWindow()
        self.right_scrolled_window.set_policy(Gtk.PolicyType.NEVER, Gtk.PolicyType.AUTOMATIC)
        self.paned.pack2(self.right_scrolled_window, resize=True, shrink=True)

        # Add elements to the right column
        self.right_column = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.right_viewport = Gtk.Viewport()
        self.right_viewport.add(self.right_column)
        self.right_scrolled_window.add(self.right_viewport)

        # Add rigth tutorial
        self.add_expandable_item_list(self.list_of_tabs)
        box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        right_tutorial = Gtk.Label(label="\n\nSelect the \"Simulation parameters\" tab from the expandable list above to configure the simulation. \n\nUse \"Run Gazebo\" and \"Run Simulator\" to start the simulation.")
        right_tutorial.set_line_wrap(True)  
        right_tutorial.set_max_width_chars(-1)  
        right_tutorial.set_justify(Gtk.Justification.FILL) 
        self.set_widget_margins(right_tutorial, start=25, end=25)

        box.pack_start(right_tutorial, expand=True, fill=True, padding=0)
        self.right_column.add(box)

        # Add a Gtk.Box for the three buttons
        self.button_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        self.add_buttons_to_box(["Close Gazebo", "Run Gazebo", "Close Simulator", "Run Simulator"])
        self.grid.attach(self.button_box, 0, 1, 1, 1)
        self.button_box.set_halign(Gtk.Align.END)
        
        # Add a Gtk.Label for the text in the second row
        self.text_label = Gtk.Label(label="Simulator v4.4")
        self.grid.attach(self.text_label, 0, 2, 1, 1)
        self.text_label.set_halign(Gtk.Align.START)

        # Set margins 
        self.set_widget_margins(self.left_scrolled_window)
        self.set_widget_margins(self.right_scrolled_window)
        self.set_widget_margins(self.button_box)
        self.set_widget_margins(self.text_label)
        self.set_widget_margins(self.grid, top=5, bottom=5, start=5, end=5)

        # Set the window position on the desired monitor
        set_window_position(self) # TODO: Comment after testing

    def set_widget_margins(self, widget, top=10, bottom=10, start=10, end=10):
        widget.set_margin_top(top)
        widget.set_margin_bottom(bottom)
        widget.set_margin_start(start)
        widget.set_margin_end(end)
        
##############################################################################################################
########################################### CLICK HANDLE #####################################################
##############################################################################################################

    def on_robot_selected(self, listbox, row):
        if row is not None:
            if self.tab_selected == self.tab2: 
                self.robot_selected = row.get_child().get_label()
                self.update_right_column()

    def on_list_item_selected(self, listbox, row):
        if row is not None:
            self.tab_selected = row.get_child().get_text()
            self.update_right_column()

    def on_button_click(self, button):
        actions = {
            "Upload": self.upload_config,
            "Clear": self.clear_config,
            "Close Gazebo": self.close_gazebo,
            "Run Gazebo": self.run_gazebo,
            "Close Simulator": self.close_simulator,
            "Run Simulator": self.run_simulator,
        }

        action = actions.get(button.get_label())
        if action:
            action()
        else:
            print(f"Unhandled button click for: {button.get_label()}")

    # Add new methods for each button action
    def upload_config(self):
        print("Upload button clicked!")
        self.upload_clicked = 1
        path = f"{self.package_path}/APP/robot_colored/image_generator.py"
        # Execute the Python code
        process = subprocess.Popen(["python3", path])
        process.communicate()  # Wait for the subprocess to finish
        # print(self.robot_params_list)
        self.update_left_column()
        self.paned.pack1(self.left_scrolled_window, resize=True, shrink=True)
        # TODO: Implement functionality for uploading config
        
    def clear_config(self):
        print("Clear button clicked!")
        self.upload_clicked = 0
        time.sleep(1)
        if self.gazebo_running ==1:
            for i in range(int(self.simulation_options.robots_number)):
                time.sleep(0.5)
                self.kill_robot(i+1, False, conditional_attempt=True)
                # self.remove_robot_config_file(i+1)
        self.clear_robot_list()

    def close_gazebo(self):
        print("Close Gazebo button clicked!")
        self.gazebo_running = 0
        try:
            # Close the Gazebo terminal window if it's open
            if self.simulator_process.is_terminal_open(self.simulator_process.gazebo_terminal_title):
                close_command = f"wmctrl -c '{self.simulator_process.gazebo_terminal_title}'"
                subprocess.Popen(close_command, shell=True)
                print("Gazebo terminal closed.")
            else:
                print("No running Gazebo terminal found.")
            
            # Kill all Gazebo related processes
            kill_commands = ["killall -9 gazebo", "killall -9 gzserver", "killall -9 gzclient"]
            for cmd in kill_commands:
                subprocess.Popen(cmd, shell=True)
                print(f"Command executed: {cmd}")

        except Exception as e:
            print(f"Error closing Gazebo: {e}")

    def run_gazebo(self):
        print("Run Gazebo button clicked!")
        self.gazebo_running = 1

        command = f"cd; cd dev_ws; source install/setup.bash;ros2 launch gazebo_minirys_sim world.launch.py world_name:={self.simulation_options.gazebo_world}; read"  # Replace with the actual command to run Gazebo
        sim_terminal_command = f"{self.simulator_process.gazebo_terminal_command} -- bash -c '{command}; exec bash'"

        if self.simulator_process.gazebo_process is None or self.simulator_process.gazebo_process.poll() is not None:
            if not self.simulator_process.is_terminal_open(self.simulator_process.gazebo_terminal_title):
                self.simulator_process.gazebo_process = subprocess.Popen(sim_terminal_command, shell=True)
                print("Gazebo process started.")
            else:
                print("Gazebo is already running.")
        else:
            print("Gazebo is already running.")

    def close_simulator(self):
        print("Close Simulator button clicked!")
        self.gazebo_running = 0

        if self.simulator_process.is_terminal_open(self.simulator_process.sim_terminal_title):
            close_command = f"wmctrl -c '{self.simulator_process.sim_terminal_title}'"
            subprocess.Popen(close_command, shell=True)
            print("Simulator terminal closed.")
        else:
            print("No running simulator process found.")

    def run_simulator(self):
        print("Run Simulator button clicked!")
        self.sim_running = 1
        self.update_simulation_params_in_xml(self.simulation_options)
        print(f"run_sim.robots_number: {self.simulation_options.robots_number}")

        command = "cd; cd dev_ws; source install/setup.bash;ros2 launch minirys_sim main.launch.py; read"  
        sim_terminal_command = f"{self.simulator_process.sim_terminal_command} -- bash -c '{command}; exec bash'"

        if self.simulator_process.process is None or self.simulator_process.process.poll() is not None:
            if not self.simulator_process.is_terminal_open(self.simulator_process.sim_terminal_title):
                self.simulator_process.process = subprocess.Popen(sim_terminal_command, shell=True)
                print("Simulator process started.")
            else:
                print("Simulator is already running.")
        else:
            print("Simulator is already running.")

    def on_box_button_click(self, button, robot_index, button_name):
        print(f"robot_index: {robot_index}")

        print(f"[APP INFO] Robot {robot_index}, Button \"{button_name}\" clicked")
        if button_name == "Kill":
            self.kill_robot(robot_index, True, conditional_attempt=True)
            
        if button_name == "Save":
            file_path = f"{self.package_path}/config/robots/robots_archive/"
            print(f"ROBOT INDEX: {robot_index} saved")
            self.create_robot_options_xml(self.robot_params_list[robot_index-1], file_path, robot_index)



##################################################################################################################
################################################ UPDATE APP ######################################################
##################################################################################################################


    def kill_robot(self, robot_index, update_left, conditional_attempt):
        command = ["ros2", "service", "call", "/delete_entity", "gazebo_msgs/srv/DeleteEntity", f'{{name: "robot{robot_index}"}}']
        max_attempts = 5
        attempt = 0  # Current attempt count
        if conditional_attempt == False:
            subprocess.Popen(command)
            self.remove_robot_config_file(robot_index)
            self.kill_zombie_node(robot_index)
            if update_left:
                self.update_left_column()
        else:
            while attempt < max_attempts:
                try:
                    print(f"[APP INFO] Attempting to kill robot{robot_index}, attempt {attempt + 1}")
                    subprocess.Popen(command)
                    time.sleep(0.5)
                    model_check = self.check_if_model_exist(f"robot{robot_index}")
                    if model_check == 0:
                        print(f"[APP INFO] Successfully killed robot{robot_index}")
                        self.remove_robot_config_file(robot_index)
                        self.kill_zombie_node(robot_index)
                        if update_left:
                            self.update_left_column()
                        break
                    elif model_check == 1:
                        print(f"[APP ERROR] Failed to kill robot{robot_index}, retrying...")
                        attempt += 1
                        time.sleep(0.1)
                    else:
                        attempt += 1
                        time.sleep(0.1)
                except subprocess.CalledProcessError as e:
                    print(f"[APP ERROR] Exception while trying to kill robot{robot_index}: {e}")
                    attempt += 1
                    time.sleep(0.1)

        if attempt == max_attempts:
            print(f"[APP ERROR] Could not kill robot{robot_index} after {max_attempts} attempts. Try again or restart the simulation...")

    def check_if_model_exist(self, robot_name):
        output = 0
        command = ["ros2", "service", "call", "/get_model_list", "gazebo_msgs/srv/GetModelList"]
        time.sleep(0.25)
        try:
            result = run(command, stdout=PIPE, stderr=PIPE, check=True, text=True, timeout=6)
            time.sleep(0.1)
            # Check if the robot exists in the output
            if re.search(fr'\b{robot_name}\b', result.stdout):
                output = 1
            else:
                output = 0

            return output
        except CalledProcessError:
            print("[APP WARNING] Failed to get model list")
            return -1
        except TimeoutExpired:
            print("[APP ERROR] Timeout Expired 6. Please try again...")
            return -1

    def remove_robot_config_file(self, robot_index):
        # Delete robot config file
        file_path = f"{self.package_path}/config/robots/robot{robot_index}_config.xml"
        try:
            os.remove(file_path)
        except OSError:
            print("[APP INFO] There is no such config file any more")
        
    def kill_zombie_node(self, robot_index):
        def check_node():
            while True:
                result = subprocess.run(["pgrep", "-f", f"__ns:=/robot{robot_index}"], stdout=subprocess.PIPE)
                if result.stdout:
                    # Node still exists
                    print(f"[APP INFO] Robot{robot_index} node still exists. Retrying...")
                    command = ["pkill", "-f", "-9", f"__ns:=/robot{robot_index}"]
                    subprocess.Popen(command)
                    time.sleep(0.1)
                else:
                    print(f"[APP INFO] Robot{robot_index} zombie node detected. Terminating...")
                    break
        
        # Start the thread to check and kill the zombie node
        thread = threading.Thread(target=check_node)
        thread.start()

    def load_worlds_from_xml(self):
        file_path = f"{self.package_path}/config/world_list.xml"
        tree = ET.parse(file_path)
        root = tree.getroot()
        for value in root.findall('value'):
            self.world_list.append(value.text)
        
            
    def update_right_column(self):    
        for child in self.right_column.get_children()[1:]:
            self.right_column.remove(child)
        if self.tab_selected == self.tab1:
            # Create a new ComboBox with world names
            world_combo = Gtk.ComboBoxText()
            for world in self.world_list:
                world_combo.append_text(world)
            world_combo.set_active(self.world_list.index(self.simulation_options.gazebo_world))
            world_combo.connect("changed", self.on_world_combo_changed)  
            world_label = Gtk.Label(label="Gazebo world:")
            world_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
            world_box.pack_start(world_label, False, False, 0)
            world_box.pack_start(world_combo, True, True, 0)
            self.right_column.pack_start(world_box, False, False, 0)
            
            option_widgets = self.create_option_widgets(self.simulation_options_name_list, self.simulation_options)
            self.right_column.pack_start(option_widgets, False, False, 0)

            button = Gtk.Button(label="Edit parameters to change")
            button.connect("clicked", self.on_edit_button_clicked)
            self.right_column.pack_start(button, False, False, 0)  # Add the button at the top of the right column
            default_values = RobotOptions()
            option_widgets2 = self.create_option_widgets_for_lists(default_values, self.list_value_types, self.simulation_options)
            self.right_column.pack_start(option_widgets2, False, False, 0)
        elif self.tab_selected == self.tab2:
            if self.robot_selected == "Robot -1":
                info_label = Gtk.Label(label="Click the ""Upload"" button on the left, and choose a robot to see its data")
                self.right_column.pack_start(info_label, False, False, 0)
            else:
                robot = self.robot_selected.replace("Robot ", "")
                if (int(robot) < 0 or self.robot_params_list == []) and self.upload_clicked == 0:
                    print(robot)
                    tab_name = self.tab1.replace("\n", "")
                    print(f"[APP INFO] No robot has been detected. Please press \"Upload\" first. If no robot has appeared on the left, you need to create robots by configuring simulation in \"{tab_name}\" tab and starting it with the \"Run Simulator\" button")
                    return
                option_widgets = self.create_option_widgets(self.robot_options_name_list, self.robot_params_list[int(robot)-1])
                self.right_column.pack_start(option_widgets, False, False, 0)
        elif self.tab_selected == self.tab3:
            print("[APP INFO] All configurations will be saved after pressing ""Launch driver""")
            group_param = []

            # First Row
            create_group_button = Gtk.Button(label="Create new group")
            create_group_button.connect("clicked", self.on_create_group_button_clicked, group_param)
            self.right_column.pack_start(create_group_button, False, False, 0)

            # Second Row
            second_row_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL)
            second_row_box.set_homogeneous(True)  # This ensures equal spacing
            launch_robot_driver_button = Gtk.Button(label="Launch driver")
            launch_robot_driver_button.connect("clicked", self.on_launch_robot_driver_button_clicked)
            second_row_box.pack_start(launch_robot_driver_button, True, True, 0)

            close_robot_driver_button = Gtk.Button(label="Close driver")
            close_robot_driver_button.connect("clicked", self.on_close_robot_driver_button_clicked)
            second_row_box.pack_start(close_robot_driver_button, True, True, 0)
            self.right_column.pack_start(second_row_box, False, False, 0)

            # Third Row
            third_row_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL)
            third_row_box.set_homogeneous(True)  # This ensures equal spacing
            open_robots_monitor_button = Gtk.Button(label="Open robots monitor")
            open_robots_monitor_button.connect("clicked", self.on_open_robots_monitor_button_button_clicked)
            third_row_box.pack_start(open_robots_monitor_button, True, True, 0)

            close_robots_monitor_button = Gtk.Button(label="Close robots monitor")
            close_robots_monitor_button.connect("clicked", self.on_close_robots_monitor_button_button_clicked)
            third_row_box.pack_start(close_robots_monitor_button, True, True, 0)
            self.right_column.pack_start(third_row_box, False, False, 0)

            for group_param in self.robot_group_params_list:
                self.add_group_box(group_param)

        else:
            new_label = Gtk.Label(label=f"Nothing to see here. For now at least...")
            self.right_column.pack_start(new_label, False, False, 0)

        self.right_column.show_all()
        self.expander.set_expanded(False) 

    def on_open_robots_monitor_button_button_clicked(self, widget):
        print("[APP INFO] Open robots monitor button clicked!")
        self.write_to_drive_config_xml()
        self.monitor_clicked_flag = 1
        if self.gazebo_running and self.sim_running:
            command = "cd; cd dev_ws; source install/setup.bash;ros2 run minirys_sim monitor_node.py; read"  # Replace with the actual command to run the simulator
            monitor_terminal_command = f"{self.simulator_process.monitor_terminal_command} -- bash -c '{command}; exec bash'"

            if self.simulator_process.process is None or self.simulator_process.process.poll() is not None:
                if not self.simulator_process.is_terminal_open(self.simulator_process.monitor_terminal_title):
                    self.simulator_process.process = subprocess.Popen(monitor_terminal_command, shell=True)
                    print("[APP INFO] MonitorTerminal process started.")
                else:
                    print("[APP INFO] MonitorTerminal is already running.")
            else:
                print("[APP INFO] MonitorTerminal is already running.")
        else:
            print("[APP INFO] You need to start Gazebo and Simulator first...")

    def on_close_robots_monitor_button_button_clicked(self, widget):
        print("Close MonitorTerminal button clicked!")
        self.monitor_clicked_flag = 0
        if self.simulator_process.is_terminal_open(self.simulator_process.monitor_terminal_title):
            close_command = f"wmctrl -c '{self.simulator_process.monitor_terminal_title}'"
            subprocess.Popen(close_command, shell=True)
            print("[APP INFO] MonitorTerminal terminal closed.")
        else:
            print("[APP INFO] No running MonitorTerminal process found.")

    def on_world_combo_changed(self, combo):
        """Callback function to handle changes in the gazebo world dropdown list"""
        self.simulation_options.gazebo_world = combo.get_active_text()
        
    def add_group_box(self, group_param):
        box = Gtk.Frame()
        box.set_label(f"  {group_param.group_name}")
        box.set_size_request(-1, 100)  # Set the constant y size of the boxes

        content_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        box.add(content_box)
        if not group_param.sequence:
            group_param.sequence = ""

        group_options_box = self.create_group_option_widgets(group_param)
        content_box.pack_start(group_options_box, True, True, 0)
        self.right_column.pack_start(box, False, False, 0)
        
        content_box.set_margin_top(10)
        content_box.set_margin_bottom(10)
        content_box.set_margin_start(10)
        content_box.set_margin_end(10)
        box.show_all()


    def on_create_group_button_clicked(self, widget, group_param):
        print("[APP INFO] Create new group button clicked!")
        
        current_group_count = len(self.robot_group_params_list)

        new_group_window = GroupCreationWindow(self, group_param, False)
        new_group_window.show_all()
        self.update_right_column()
        self.view_robot_group_params()

        
    def on_launch_robot_driver_button_clicked(self, widget):
        print("[APP INFO] Launch driver button clicked!")
        self.write_to_drive_config_xml()
        if self.gazebo_running and self.sim_running:
            command = "cd; cd dev_ws; source install/setup.bash;ros2 launch minirys_sim command_groups.launch.py; read"  # Replace with the actual command to run the simulator
            drive_terminal_command = f"{self.simulator_process.drive_terminal_command} -- bash -c '{command}; exec bash'"

            if self.simulator_process.process is None or self.simulator_process.process.poll() is not None:
                if not self.simulator_process.is_terminal_open(self.simulator_process.drive_terminal_title):
                    self.simulator_process.process = subprocess.Popen(drive_terminal_command, shell=True)
                    print("DriveTerminal process started.")
                else:
                    print("DriveTerminal is already running.")
            else:
                print("DriveTerminal is already running.")
        else:
            print("[APP INFO] You need to start Gazebo and Simulator first...")


    def on_close_robot_driver_button_clicked(self, widget):
        print("Close DriveTerminal button clicked!")

        if self.simulator_process.is_terminal_open(self.simulator_process.drive_terminal_title):
            close_command = f"wmctrl -c '{self.simulator_process.drive_terminal_title}'"
            subprocess.Popen(close_command, shell=True)
            print("DriveTerminal terminal closed.")
        else:
            print("No running DriveTerminal process found.")


    def view_robot_group_params(self):
        for param in self.robot_group_params_list:
            print(param.robots)

    def update_robots_already_taken_list(self):
        self.robots_already_taken_to_other_group = []
        for i in range(len(self.robot_group_params_list)):
            robot_entries = self.robot_group_params_list[i].robots.split(",") if self.robot_group_params_list[i].robots else []
            for j in range(len(robot_entries)):
                self.robots_already_taken_to_other_group.append(robot_entries[j])

        print(self.robots_already_taken_to_other_group)
        print("\n")
        for i in range(len(self.robot_group_params_list)):
            print(f"Our robots (list index: {i}): {self.robot_group_params_list[i].robots}")
            print(f"Group Data: {self.robot_group_params_list[i]}\n")

    def create_group_option_widgets(self, group_param):
        options_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        if not hasattr(self, 'entries'):
            self.entries = {}

        # For Robots
        hbox_robots = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        options_box.pack_start(hbox_robots, False, False, 0)
        robots_label = Gtk.Label(label="Robots:")
        hbox_robots.pack_start(robots_label, False, False, 0)
        robots_entry = Gtk.Label(label=getattr(group_param, 'robots'))
        robots_entry.set_margin_top(10)
        robots_entry.set_margin_bottom(10)
        robots_entry.set_margin_start(10)
        robots_entry.set_margin_end(10)
        hbox_robots.pack_start(robots_entry, True, True, 0)
        self.entries['robots'] = robots_entry

        # For Mode
        hbox_mode = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        options_box.pack_start(hbox_mode, False, False, 0)
        mode_label = Gtk.Label(label="Mode:")
        hbox_mode.pack_start(mode_label, False, False, 0)
        mode_entry = Gtk.Entry()
        mode_entry.set_width_chars(1)
        mode_entry.connect("changed", self.on_int_entry_changed, (group_param, 'mode'))
        mode_entry.set_text(str(getattr(group_param, 'mode')))
        hbox_mode.pack_start(mode_entry, False, False, 0)
        self.entries['mode'] = mode_entry
        
        # For Loop
        hbox_loop = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        options_box.pack_start(hbox_loop, False, False, 0)
        loop_label = Gtk.Label(label="Loop:")
        hbox_loop.pack_start(loop_label, False, False, 0)
        loop_entry = Gtk.Entry()
        loop_entry.set_width_chars(3)
        loop_entry.connect("changed", self.on_int_entry_changed, (group_param, 'loop'))
        loop_entry.set_text(str(getattr(group_param, 'loop')))
        hbox_loop.pack_start(loop_entry, False, False, 0)
        self.entries['loop'] = loop_entry
        
        # Step Box (This will contain all steps)
        step_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        options_box.pack_start(step_box, True, True, 0)

        # Clear step_box before populating
        for child in step_box.get_children():
            child.destroy()

        # Load steps from the sequence
        sequence_entries = group_param.sequence.split(",") if group_param.sequence else []
        step_count = 1
        for i in range(0, len(sequence_entries), 3):
            self.add_new_step(None, group_param, step_box, step_count)
            step_count += 1

        
        bottom_buttons_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)

        # Button for adding a step
        add_step_btn = Gtk.Button(label="Add Step")
        add_step_btn.connect("clicked", self.add_new_step, group_param, step_box, 1, True)
        bottom_buttons_box.pack_start(add_step_btn, True, True, 0)
        
        # Button for deleting the group
        delete_group_btn = Gtk.Button(label="Delete Group")
        delete_group_btn.connect("clicked", self.on_delete_group_clicked, group_param)
        bottom_buttons_box.pack_start(delete_group_btn, True, True, 0)

        # Button for renaming the group
        edit_group_btn = Gtk.Button(label="Edit Group")
        edit_group_btn.connect("clicked", self.on_edit_group_clicked, group_param)
        bottom_buttons_box.pack_start(edit_group_btn, True, True, 0)
        
        options_box.pack_start(bottom_buttons_box, True, True, 0)
        
        return options_box
    
    def on_edit_group_clicked(self, button, group_param):
        edit_window = GroupCreationWindow(self, group_param, True)
        edit_window.show_all()

    def on_delete_group_clicked(self, button, group_param):
        # Remove the corresponding group from self.robot_group_params_list
        if group_param in self.robot_group_params_list:
            self.robot_group_params_list.remove(group_param)
        
        # Find and destroy the group box widget
        parent_widget = button.get_parent()  # Options box
        frame = parent_widget.get_parent()   # Frame that wraps the options_box
        if frame:
            frame.destroy()
        self.update_robots_already_taken_list()
        self.update_right_column()
        print("[APP INFO] Group deleted!")

    def add_new_step(self, button, group_param, step_box, current_step, from_button=False):
        step_count = 1
        if from_button:
            sequence_entries = group_param.sequence.split(",") if group_param.sequence else []
            # Increment step_count by the number of existing steps
            step_count = (len(sequence_entries) // 3) + 1
            if group_param.sequence:
                group_param.sequence += ",0,0,0"
            else:
                group_param.sequence = "0,0,0"
        else:
            step_count = current_step

        # Create a horizontal box for each step
        step_hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        step_label = Gtk.Label(label=f"Step {step_count}:")
        step_hbox.pack_start(step_label, False, False, 0)

        # Dropdown for directions
        direction_combobox = Gtk.ComboBoxText()
        directions = [
            "forward",
            "forward and right",
            "right",
            "back and right",
            "back",
            "back and left",
            "left",
            "forward and left"
        ]

        for direction in directions:
            direction_combobox.append_text(direction)

        direction_index = (step_count - 1) * 3 
        speed_index = direction_index + 1
        time_index = direction_index + 2
        sequence_entries = group_param.sequence.split(",") if group_param.sequence else []

        direction_val = sequence_entries[direction_index] if direction_index < len(sequence_entries) else '0'

        try:
            direction_val = int(direction_val)
        except ValueError:
            direction_val = 0

        direction_combobox.set_active(direction_val)

        speed = sequence_entries[speed_index] if speed_index < len(sequence_entries) else '0'
        try:
            speed = int(speed)
        except ValueError:
            speed = 0

        time = sequence_entries[time_index] if time_index < len(sequence_entries) else '0'
        try:
            time = int(time)
        except ValueError:
            time = 0

        speed = sequence_entries[speed_index] if speed_index < len(sequence_entries) else 0
        time = sequence_entries[time_index] if time_index < len(sequence_entries) else 0

        # Setting values and connections for direction combobox
        direction_combobox.connect("changed", self.on_direction_changed, group_param, step_count)
        if direction_val is not None:
            direction_combobox.set_active(int(direction_val))
        step_hbox.pack_start(direction_combobox, False, False, 0)

        speed_label = Gtk.Label(label="Speed:")
        step_hbox.pack_start(speed_label, False, False, 0)

        speed_entry = Gtk.Entry(placeholder_text="Speed")
        speed_entry.set_width_chars(4)
        speed_entry.connect("changed", self.on_speed_time_entry_changed, group_param, 1 + (step_count-1)*3)
        try:
            speed_entry.set_text(str(speed))
        except IndexError:
            speed_entry.set_text("0")
            speed_entry.get_style_context().add_class('missing-field')

        step_hbox.pack_start(speed_entry, False, False, 0)

        duration_label = Gtk.Label(label="Duration:")
        step_hbox.pack_start(duration_label, False, False, 0)

        time_entry = Gtk.Entry(placeholder_text="Time")
        time_entry.set_width_chars(4)
        time_entry.connect("changed", self.on_speed_time_entry_changed, group_param, 2 + (step_count-1)*3)
        try:
            time_entry.set_text(str(time))
        except IndexError:
            time_entry.set_text("0")
            time_entry.get_style_context().add_class('missing-field')
        time_entry.set_margin_end(5)
    
        # Add delete button
        icon = Gio.ThemedIcon(name="window-close-symbolic")
        image = Gtk.Image.new_from_gicon(icon, Gtk.IconSize.BUTTON)
        delete_step_btn = Gtk.Button(image=image)
        delete_step_btn.connect("clicked", self.on_delete_step_clicked, step_hbox, group_param, step_count)
        step_hbox.pack_end(delete_step_btn, False, False, 0)
        
        step_hbox.pack_start(time_entry, False, False, 0)

        step_box.pack_start(step_hbox, False, False, 0)
        step_hbox.show_all()


    def on_delete_step_clicked(self, button, step_hbox, group_param, step_count):
        
        # Remove the step from GUI
        step_hbox.destroy()

        # Update the sequence
        sequence_list = group_param.sequence.split(",") if group_param.sequence else []
        start_index = (step_count - 1) * 3
        end_index = start_index + 3
        del sequence_list[start_index:end_index]
        setattr(group_param, 'sequence', ','.join(sequence_list))

        self.update_right_column()


    def on_direction_changed(self, combobox, group_param, step_count):
        index = combobox.get_active()

        if index is not None:
            print("We are here to change")
            # Update the sequence with the selected direction
            sequence = getattr(group_param, 'sequence', '')
            # Ensure sequence list is large enough to accommodate the new value
            sequence_list = sequence.split(",") if sequence else []
            while len(sequence_list) <= (step_count-1)*3:
                sequence_list.append('')
            sequence_list[(step_count-1)*3] = str(index)
            setattr(group_param, 'sequence', ','.join(sequence_list))


    def on_speed_time_entry_changed(self, entry, group_param, pos):
        value = entry.get_text()

        # Check if value is a float
        try:
            float_value = float(value)
            setattr(group_param, 'sequence', self.update_sequence_value(group_param, pos, value))
            entry.get_style_context().remove_class("missing-field")
        except ValueError:
            print("Invalid float value entered!")
            entry.get_style_context().add_class("missing-field")

    def update_sequence_value(self, group_param, pos, value):
        sequence = getattr(group_param, 'sequence', '')
        sequence_list = sequence.split(",") if sequence else []

        # Ensure sequence list is large enough to accommodate the new value
        while len(sequence_list) <= pos:
            sequence_list.append('')

        sequence_list[pos] = value
        return ','.join(sequence_list)


    def write_to_drive_config_xml(self):
        # Root element
        filepath = f"{self.package_path}/config/drive_config.xml"
        root = ET.Element("drive_config")

        for group_param in self.robot_group_params_list:
            group_elem = ET.SubElement(root, "group", name=group_param.group_name)
            
            robots_elem = ET.SubElement(group_elem, "robots")
            robots_elem.text = group_param.robots if group_param.robots else " "  # Set to space if empty

            mode_elem = ET.SubElement(group_elem, "mode")
            mode_elem.text = str(group_param.mode)

            sequence_elem = ET.SubElement(group_elem, "sequence")
            sequence_elem.text = group_param.sequence if group_param.sequence else " "  # Set to space if empty

            loop_elem = ET.SubElement(group_elem, "loop")
            loop_elem.text = str(group_param.loop)

        tree = ET.ElementTree(root)
        xml_str = ET.tostring(root, encoding='utf-8').decode('utf-8')
        dom = xml.dom.minidom.parseString(xml_str)
        pretty_xml_str = dom.toprettyxml()

        with open(filepath, 'w') as f:
            f.write(pretty_xml_str)


    def initialize_drive_config_from_xml(self):
        file_name = f"{self.package_path}/config/drive_config.xml"
        try:
            tree = ET.parse(file_name)
            root = tree.getroot()

            for group_elem in root.findall("group"):
                param = RobotGroupDriveParameters()
                param.group_name = group_elem.attrib["name"]
                param.robots = group_elem.find("robots").text
                param.mode = int(group_elem.find("mode").text)
                param.sequence = group_elem.find("sequence").text
                param.loop = int(group_elem.find("loop").text)
                
                self.robot_group_params_list.append(param)

        except Exception as e:
            print(f"Error initializing from XML: {e}")


    def on_edit_button_clicked(self, button):
        print("Button was clicked")
        new_window  = EditParamsToChangeWindow(self)
        new_window.show_all()
        
    def update_left_column(self):        
        for child in self.left_listbox.get_children()[2:]:
            self.left_listbox.remove(child)
        self.add_robots()
        self.update_right_column()
        self.left_listbox.show_all()

    def clear_robot_list(self):
        for child in self.left_listbox.get_children()[2:]:
            self.left_listbox.remove(child)
        self.robot_params_list = []
        self.robot_selected = "Robot -1"
        self.update_right_column()
        

####################################################################################################################
################################################## UPDATE XML's ####################################################
####################################################################################################################

    def update_simulation_params_in_xml(self, sim_params):
        xml_file = f"{self.package_path}/config/launch_config.xml"
        print("[APP INFO] Updating simulation parameters in XML file...")

        # Parse the existing XML file
        tree = ET.parse(xml_file)
        root = tree.getroot()

        # Find the 'spawn_parameters' element with mode="row_spawn_parameters"
        for spawn_parameters in root.findall('spawn_parameters'):
            if spawn_parameters.get('mode') == "row_spawn_parameters":
                # For each option, find the corresponding subelement and update its text
                for option_name, _ in self.simulation_options_name_list.items():
                    option_value = getattr(sim_params, option_name)
                    option_element = spawn_parameters.find(option_name)
                    if option_element is not None:
                        option_element.text = str(option_value)

        for list_param in self.list_value_types.keys():
            list_element = root.find(list_param)
            if list_element is not None:
                for value_elem in list_element.findall('value'):
                    list_element.remove(value_elem)
                list_element.tail = "\n    "
                param_values = getattr(sim_params, list_param)
                if param_values is None:
                    param_values = []
                for index, param_value in enumerate(param_values):
                    new_value_elem = ET.SubElement(list_element, 'value')
                    new_value_elem.text = str(param_value)
                    if len(param_values) > index + 1:
                        new_value_elem.tail = "\n        "
                    else:
                        new_value_elem.tail = "\n    "
                print(f"Updated {list_param} values in the XML.")

        # Write the updated XML tree back to the file
        tree.write(xml_file, encoding='utf-8', xml_declaration=True)


    def update_robot_options_in_xml(self, robot_options, xml_path):
        print("[APP INFO] Updating robot options in XML file...")
        # Parse the existing XML file
        tree = ET.parse(xml_path)
        root = tree.getroot()

        # For each option, find the corresponding subelement and update its text
        for option_name, _ in self.robot_options_name_list.items():
            if hasattr(robot_options, option_name):
                option_value = getattr(robot_options, option_name)
                option_element = root.find(option_name)
                if option_element is not None:
                    option_element.text = str(option_value)
            else:
                print(f"[APP INFO] Attribute {option_name} does not exist in robot_options")

        # Write the updated XML tree back to the file
        tree.write(xml_path, encoding='utf-8', xml_declaration=True)


    def create_robot_options_xml(self, robot_options, folder_path, robot_index):
        print("[APP INFO] Creating new XML file with robot options...")
        now = datetime.now()
        formatted = now.strftime('%Y%m%d%H%M%S')
        print(formatted)
        
        xml_path = f"{folder_path}{formatted}_robot{robot_index}.xml"
        # Create the root element
        root = ET.Element("robot_config")

        # For each option in RobotOptions, create a subelement with the option's name and value
        for option_name, _ in self.robot_options_name_list.items():
            option_value = getattr(robot_options, option_name)
            option_element = ET.SubElement(root, option_name)
            option_element.text = str(option_value)
            
        # Create an ElementTree object from the root element
        tree = ET.ElementTree(root)

        # Convert to string
        xml_str = ET.tostring(root, encoding='utf-8').decode('utf-8')

        # Parse string to a DOM object
        dom = xml.dom.minidom.parseString(xml_str)

        # Pretty print to a string
        pretty_xml_str = dom.toprettyxml()

        # Write the ElementTree object to the XML file
        with open(xml_path, 'w') as f:
            f.write(pretty_xml_str)


    def parse_xml_to_options(self, file_path, options_class, options_name_list, option_list_value_types={}):
        tree = ET.parse(file_path)
        root = tree.getroot()

        options = options_class()

        for child in root:
            # Check if this node represents a list (contains <value> elements)
            if child.find('value') is not None:
                if child.tag not in option_list_value_types:
                    raise ValueError(f"Unknown list parameter {child.tag} in XML file.")
                else:
                    list_value_type = option_list_value_types[child.tag]
                    value = [list_value_type(sub_element.text) for sub_element in child.findall('value')]
                    setattr(options, child.tag, value)
            # Check if this node represents a parameter group
            elif len(child) > 0:
                for sub_child in child:
                    if sub_child.tag not in options_name_list:
                        raise ValueError(f"Unknown parameter {sub_child.tag} in XML file.")
                    else:
                        value = self.convert_to_type(sub_child.text, options_name_list[sub_child.tag])
                        setattr(options, sub_child.tag, value)
            # Check if this node represents a parameter
            elif child.tag in options_name_list:
                value = self.convert_to_type(child.text, options_name_list[child.tag])
                setattr(options, child.tag, value)
            else:
                raise ValueError(f"Unknown parameter {child.tag} in XML file.")

        return options

    def convert_to_type(self, value, type):
        if type == bool:
            return value.lower() == 'true'
        elif type == float:
            return float(value)
        elif type == int:
            return int(value)
        elif type == str:
            return str(value)

    
    def atoi(self, text):
        return int(text) if text.isdigit() else text

    def natural_keys(self, text):
        return [self.atoi(c) for c in re.split(r'(\d+)', text)]

    def load_robot_data(self, robot_config_path):
        robot_params_list = []
        file_list = sorted(os.listdir(robot_config_path), key=self.natural_keys)
        if file_list == []:
            print("[APP WARN] No robot config files found.")
            return robot_params_list
        for idx, file in enumerate(file_list):
            if re.match(r"^robot\d+_config.xml$", file):
                print(f"Loading parameters from {file}")
                file_path = os.path.join(robot_config_path, file)
                robot_options = self.parse_xml_to_options(file_path, RobotOptions, self.robot_options_name_list, None)
                robot_params_list.append(robot_options)

        return robot_params_list
    
    def load_launch_data(self):
        file_path = f"{self.package_path}/config/launch_config.xml"
        simulation_options = self.parse_xml_to_options(file_path, SimulationParameters, self.simulation_options_name_list, self.list_value_types)
        return simulation_options
    
##############################################################################################################
################################################## CREATE ####################################################
##############################################################################################################
################################################ LEFT COLUMN #################################################

    def add_robots(self):
        robot_config_path = f"{self.package_path}/config/robots/"
        self.robot_params_list = []
        self.robot_params_list = self.load_robot_data(robot_config_path)
        print("Adding robots to the left column...")
        for i in range(len(self.robot_params_list)):
            robot_index = self.robot_params_list[i].robot_namespace.replace('robot', '')
            box = Gtk.Frame()
            box.set_label(f"  Robot {robot_index}")
            box.set_size_request(-1, 100)  # Set the constant y size of the boxes
            self.add_content_to_boxes(box, i, int(robot_index))
            self.left_listbox.insert(box, -1)


    # Generate content of the robot boxes
    def add_content_to_boxes(self, box, box_index, robot_index):
        content_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        box.add(content_box)

        # Add image to the left
        image_path = f"{self.package_path}/APP/robot_colored/robots/{self.robot_params_list[box_index].color_code}_robot.png"
        desired_width = 110
        desired_height = 110
        pixbuf = GdkPixbuf.Pixbuf.new_from_file_at_scale(image_path, desired_width, desired_height, preserve_aspect_ratio=True)
        image = Gtk.Image.new_from_pixbuf(pixbuf)
        content_box.pack_start(image, False, False, 0)

        text_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)

        # Add text in the center
        name = Gtk.Label(label=f"Robot {robot_index}")
        text_box.pack_start(name, False, True, 0)
        code = Gtk.Label(label=f"Color code: {self.robot_params_list[box_index].color_code}")
        text_box.pack_start(code, False, True, 0)

        if self.simulation_options.param_to_change is not None:
            for i, param in enumerate(self.simulation_options.param_to_change):
                param_to_change_text = Gtk.Label(label=f"{param}: {getattr(self.robot_params_list[box_index], param)}")
                text_box.pack_start(param_to_change_text, False, True, 0)

        content_box.pack_start(text_box, True, True, 0)
        # Add three buttons (one on top of another) on the right
        buttons = ["Kill", "Save"]
        button_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=26)
        for i in range(len(buttons)):
            button = Gtk.Button.new_with_label(f"{buttons[i]}")
            button.set_size_request(-1, 20)
            button.connect("clicked", self.on_box_button_click, robot_index, buttons[i])
            button_box.pack_start(button, False, False, 0)
        content_box.pack_start(button_box, False, False, 0)
        content_box.set_margin_top(5)
        content_box.set_margin_bottom(5)
        content_box.set_margin_start(5)
        content_box.set_margin_end(5)

    # Create buttons on the top of the robot list
    def add_button(self, label):
        button = Gtk.Button.new_with_label(label)
        button.connect("clicked", self.on_button_click)
        self.left_listbox.insert(button, -1)

############################################### RIGHT COLUMN #################################################
    
    def add_expandable_item_list(self, items):
        expander_label = Gtk.Label()
        expander_label.set_markup("\n<span font_weight='bold' font_size='large'>  Simulation configuration</span>\n")
        self.expander = Gtk.Expander()
        self.expander.set_label_widget(expander_label)

        item_list = Gtk.ListBox()
        item_list.connect("row-selected", self.on_list_item_selected)

        for item in items:
            item_list.insert(Gtk.Label(label=item), -1)

        self.expander.add(item_list)
        self.right_column.pack_start(self.expander, False, False, 0)
    
    def create_option_widgets(self, option_types_dictionary, option_values):
        options_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.checkboxes = {}
        self.entries = {}
        for option_name, option_type in option_types_dictionary.items():
            if option_name == "gazebo_world": # This option is in dropdown list on top of right column
                continue
            if option_type == bool:
                checkbutton = Gtk.CheckButton.new_with_label(option_name)
                checkbutton.connect("toggled", self.on_checkbox_toggled, (option_values, option_name))
                checkbutton.set_active(getattr(option_values, option_name))
                options_box.pack_start(checkbutton, False, False, 0)
                self.checkboxes[option_name] = checkbutton
            elif option_type == float:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                float_label = Gtk.Label(label=f"Enter {option_name}:")
                hbox.pack_start(float_label, False, False, 0)

                float_entry = Gtk.Entry()
                float_entry.set_width_chars(11) 
                float_entry.connect("changed", self.on_float_entry_changed, (option_values, option_name))
                float_entry.set_text(str(getattr(option_values, option_name)))
                hbox.pack_start(float_entry, False, False, 0)
                self.entries[option_name] = float_entry
            elif option_type == str:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                string_label = Gtk.Label(label=f"Enter {option_name}:")
                hbox.pack_start(string_label, False, False, 0)

                string_entry = Gtk.Entry()
                string_entry.set_width_chars(11)
                string_entry.connect("changed", self.on_string_entry_changed, (option_values, option_name))
                string_entry.set_text(getattr(option_values, option_name))
                hbox.pack_start(string_entry, False, False, 0)
                self.entries[option_name] = string_entry
            elif option_type == int:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                int_label = Gtk.Label(label=f"Enter {option_name}:")
                hbox.pack_start(int_label, False, False, 0)

                int_entry = Gtk.Entry()
                int_entry.set_width_chars(11)
                int_entry.connect("changed", self.on_int_entry_changed, (option_values, option_name))
                int_entry.set_text(str(getattr(option_values, option_name)))
                hbox.pack_start(int_entry, False, False, 0)
                self.entries[option_name] = int_entry

        return options_box

    def on_checkbox_toggled(self, checkbox, data):
        options_data, option_name = data
        print(f"The {option_name} changed to {options_data}")
        setattr(options_data, option_name, checkbox.get_active())
        
    def on_int_entry_changed(self, entry, data):
        options_data, option_name = data
        try:
            int_value = int(entry.get_text())
            setattr(options_data, option_name, int_value)
            entry.get_style_context().remove_class("missing-field")
        except ValueError:
            print("Invalid integer value entered!")
            entry.get_style_context().add_class("missing-field")

    def on_float_entry_changed(self, entry, data):
        options_data, option_name = data
        try:
            float_value = float(entry.get_text())
            setattr(options_data, option_name, float_value)
            entry.get_style_context().remove_class("missing-field")
        except ValueError:
            print("Invalid float value entered!")
            entry.get_style_context().add_class("missing-field")

    def on_string_entry_changed(self, entry, data):
        options_data, option_name = data
        string_value = entry.get_text()
        setattr(options_data, option_name, string_value)


    def create_option_widgets_for_lists(self, default_values, option_types_dictionary, option_values):
        options_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.list_entries = {}

        # Check if param_to_change is None
        if option_values.param_to_change is None:
            return options_box

        for i, option_name in enumerate(option_values.param_to_change):
            # Get default value from RobotOptions
            default_value = getattr(default_values, option_name, "")
            
            # Update start_from list with the default value
            try:
                option_values.start_from[i] = default_value
            except IndexError:
                option_values.start_from.append(default_value)
            
            hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
            options_box.pack_start(hbox, False, False, 0)

            option_label = Gtk.Label(label=f"{option_name}:")
            hbox.pack_start(option_label, False, False, 0)

            # Create a label
            start_from_label = Gtk.Label(label="start from")
            hbox.pack_start(start_from_label, False, False, 0)

            # Create the start_from entry field
            start_from_entry = Gtk.Entry()
            start_from_entry.set_width_chars(10)
            start_from_entry.connect("changed", self.on_list_float_entry_changed, (option_values, "start_from", i))
            
            try:
                start_from_entry.set_text(str(option_values.start_from[i]))
            except IndexError:
                start_from_entry.set_text("")
                start_from_entry.get_style_context().add_class('missing-field')
            hbox.pack_start(start_from_entry, False, False, 0)
            
            iterate_by_label = Gtk.Label(label="iterate by")
            hbox.pack_start(iterate_by_label, False, False, 0)

            # Create the iterate_by entry field
            iterate_by_entry = Gtk.Entry()
            iterate_by_entry.set_width_chars(10)  
            iterate_by_entry.connect("changed", self.on_list_float_entry_changed, (option_values, "iterate_by", i))
            try:
                iterate_by_entry.set_text(str(option_values.iterate_by[i]))
            except IndexError:
                iterate_by_entry.set_text("")
                iterate_by_entry.get_style_context().add_class('missing-field')
            hbox.pack_start(iterate_by_entry, False, False, 0)

            # Store the entry fields in the self.list_entries dictionary for future reference
            self.list_entries[(option_name, "start_from")] = start_from_entry
            self.list_entries[(option_name, "iterate_by")] = iterate_by_entry

        return options_box

    def on_list_float_entry_changed(self, entry, data):
        options_data, list_name, index = data
        try:
            float_value = float(entry.get_text())
            while len(getattr(options_data, list_name)) <= index:
                getattr(options_data, list_name).append(0)
            getattr(options_data, list_name)[index] = float_value
            # When the entry field is updated, remove the 'missing-field' class
            entry.get_style_context().remove_class('missing-field')
        except ValueError:
            print("Invalid float value entered!")
            entry.get_style_context().add_class("missing-field")

################################################# FOOT ######################################################
            
    # Create butons in the foot of the window
    def add_buttons_to_box(self, button_labels):
        for label in button_labels:
            button = Gtk.Button.new_with_label(label)
            self.button_box.pack_start(button, False, False, 0)
            button.set_size_request(100, 30)  # Set the constant size of the buttons
            button.connect("clicked", self.on_button_click)

def set_window_position(window):
    display = Gdk.Display.get_default()
    monitor_index = 1  # [!] Change this value to control which monitor the window appears on
    
    if monitor_index < display.get_n_monitors():
        monitor = display.get_monitor(monitor_index)
        monitor_geometry = monitor.get_geometry()
        
        x_position = monitor_geometry.x
        y_position = monitor_geometry.y

        window.move(x_position, y_position)
    else:
        print(f"Monitor {monitor_index} not found. Using the default monitor instead.")

def error_handler(error_message):
    print(f"[SIM ERROR]: {error_message}")
    print("[SIM INFO]: Terminating the program...")
    sys.exit(1)

class MyApplication(Gtk.Application):
    def __init__(self):
        Gtk.Application.__init__(self, application_id="com.example.myapp")
        self.connect("activate", self.on_activate)

    def on_activate(self, app):
        win = MainWindow(app)
        win.show_all()

def main():
    app = MyApplication()
    app.run(None)

if __name__ == "__main__":
    main()