import os
import sys
import gi
import xml.etree.ElementTree as ET
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk, Gdk, Gio
import inspect
import subprocess
import threading
import time
from PIL import Image
from gi.repository import GdkPixbuf
import re
from datetime import datetime
import xml.dom.minidom



##############################################################################################################
############################################### TODO LIST ####################################################
##############################################################################################################
# TODO: Add margins to the window                                                                       [DONE]
# TODO: After click run sim save changes to congig files                                                [DONE]
# TODO: Download sim parameters at the start of the app                                                 [DONE]
# TODO: If upload clicked overwrite all changes in the robot congif files
# TODO: Add functionality to the robots Kill button                                                     [DONE]                                                          
# TODO: Add functionality to the robots Modify button                                                       
# TODO: Add functionality to the robots Save button                                                     [DONE]
# TODO: Delete unnecessary print statements. Add [APP INFO], [APP ERROR] to nessesery ones
# TODO: Potential problem: After killing all robots simulation is terminated by ROS2. Maby make blank 
# process to solve that. Or find alternative approach


# TODO: Robot menager that check after spwoning if everyting spawned correctly 
# and after killing is everyting was killed correctly. Consider as function in the APP 

# TODO: Killing process is not reliable. There is a problem when app kills bot and box with a buttno 
# but in ros and gazebo there is still a robot.                                                         [DONE]

# UPDATE:
# kill button relaiable
# robot menager to double check
# gazebo to different package (collisions)

# you need to somehow manage the lifecycle of robots. Good idea is to add KILLALL button to the app. 
##############################################################################################################
##############################################################################################################

class ProcessClass:
    def __init__(self):
        self.process = None
        self.gazebo_process = None
        self.terminal_title = "SimulatorTerminal"
        self.gazebo_terminal_title = "GazeboTerminal"
        self.terminal_command = f"gnome-terminal --title='{self.terminal_title}'"
        self.gazebo_terminal_command = f"gnome-terminal --title='{self.gazebo_terminal_title}'"

    def is_terminal_open(self, title):
        terminal_list = subprocess.check_output("wmctrl -l", shell=True).decode()
        return title in terminal_list


class AppFlaggs:
    def __init__(self):
        self.is_simulation_running = False
        self.is_gazebo_running = False
        self.is_robot_alive = []
        self.is_robot_modified = []


class RobotOptions:
    def __init__(self):
        self.use_sim_time = True
        self.robot_namespace = "robot"
        self.color_code = "#9370DB"
        self.camera_enabled = True
        self.camera_visibility = True
        self.label_enabled = True
        self.label_x = 0.13
        self.label_y = 0.05
        self.TOF_enabled = True
        self.horizontal_sensor_visibility = False
        self.vertical_sensor_visibility = False
        self.none_sensor_visibility = True
        self.all_sensor_visibility = False
        self.TOF_FOV_angle = 0.08
        self.TOF_range = 5
        self.spawn_x = -2.0
        self.spawn_y = -3.0
        self.spawn_z = 0.0
        self.spawn_roll = 0.0
        self.spawn_pitch = 0.0
        self.spawn_yaw = 1.570796327
        self.chassis_mu1 = 0.1
        self.chassis_mu2 = 0.1
        self.chassis_kp = 0.7
        self.chassis_kd = 0.05
        self.wheel_mu1 = 10
        self.wheel_mu2 = 10
        self.wheel_kp = 0.7
        self.wheel_kd = 0.05
        self.wheel_joint_dumping = 0.1
        self.wheel_joint_friction = 0.1

def populate_robot_option_name_list():
    options = {
        "use_sim_time": bool,
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
        "none_sensor_visibility": bool,
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
        "wheel_joint_friction": float
    }

    return options

class SimulationParameters:
    def __init__(self):
        self.robots_number = 1
        self.number_of_rows = 1
        
        # self.use_default_colors = True
        # self.default_randomize_colors = False
        # self.default_starting_color = 0
        # self.custom_colors = ["#000000"]  # HIDDEN VARIABLE
        # TODO: Maybe instead of list of values better way would be send hash with how much it should change values of next robot or something
        
        self.x_separation = 0.0
        self.y_separation = 0.0
        self.z_separation = 0.0
        self.x_offset = -2.0
        self.y_offset = -3.0
        self.z_offset = 0.0
        self.roll = 0.0
        self.pitch = 0.0
        self.yaw = 1.570796327

def populate_simulation_options_name_list():
    simulation_options_name_list = {
        "robots_number": int,
        "number_of_rows": int,

        # "use_default_colors": bool,
        # "default_randomize_colors": bool,
        # "default_starting_color": int,
        
        "x_separation": float,
        "y_separation": float,
        "z_separation": float,
        "x_offset": float,
        "y_offset": float,
        "z_offset": float,
        "roll": float,
        "pitch": float,
        "yaw": float
    }
    # hidden_simulation_parameters_name_list = {
    #     "custom_colors": list
    # }

    return simulation_options_name_list #, hidden_simulation_parameters_name_list

class MainWindow(Gtk.ApplicationWindow):
    def __init__(self, app):
        ###############
        ## VARIABLES ##
        ###############
        self.tab1 = "\nDefault parameter values\n"
        self.tab2 = "\nUnsupported feature\n"
        self.tab3 = "\nRobot data\n"
        self.list_of_tabs = [self.tab1, self.tab2, self.tab3]
        
        self.tab_selected = self.tab1
        self.robot_selected = "Robot -1"
        self.upload_clicked = 0
        
        Gtk.Window.__init__(self, title="Mulitiple-robot system simulator", application=app)
        
        # Set the icon of the window
        self.set_icon_from_file("icon.png")

        # Set the size of the window
        self.set_default_size(int(800*1.5), int(600*1.5))
        
        self.simulator_process = ProcessClass()
        script_path = os.path.abspath(__file__).replace("APP/App.py", "")
        self.package_path = os.path.dirname(script_path)
        
        self.simulation_options_name_list = populate_simulation_options_name_list() # This function only sets the options dictionary
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
        self.paned.set_position(500)  # Set the initial position of the divider

        
        # Create a Gtk.ScrolledWindow for the left column
        self.left_scrolled_window = Gtk.ScrolledWindow()
        self.left_scrolled_window.set_policy(Gtk.PolicyType.NEVER, Gtk.PolicyType.AUTOMATIC)
        self.paned.pack1(self.left_scrolled_window, resize=True, shrink=True)

        # Create a Gtk.ListBox for the boxes in the left column
        self.left_listbox = Gtk.ListBox()
        self.left_scrolled_window.add(self.left_listbox)
        self.left_listbox.connect("row-selected", self.on_robot_selected)  # Connect the row-selected signal to a callback function

        # Add elements to the left column
        self.add_button("Upload") # Upload from the file
        # self.add_boxes(10)
        self.add_button("Clear")  # Clear configs
        # self.add_robots() 

        # Create a Gtk.ScrolledWindow for the right column
        self.right_scrolled_window = Gtk.ScrolledWindow()
        self.right_scrolled_window.set_policy(Gtk.PolicyType.NEVER, Gtk.PolicyType.AUTOMATIC)
        self.paned.pack2(self.right_scrolled_window, resize=True, shrink=True)

        # Add elements to the right column
        self.right_column = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.right_viewport = Gtk.Viewport()
        self.right_viewport.add(self.right_column)
        self.right_scrolled_window.add(self.right_viewport)

        self.add_expandable_item_list(self.list_of_tabs)

        # Add a Gtk.Box for the three buttons
        self.button_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        self.add_buttons_to_box(["Close Gazebo", "Run Gazebo", "Close Simulator", "Run Simulator"])
        self.grid.attach(self.button_box, 0, 1, 1, 1)
        self.button_box.set_halign(Gtk.Align.END)
        
        # Add a Gtk.Label for the text in the second row
        self.text_label = Gtk.Label(label="Simulator v1.5")
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
            # print(row.get_child().get_label())
            if self.tab_selected == self.tab3: 
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
        self.upload_clicked = 0
        self.clear_robot_list() 
        print("Clear button clicked!")
        # TODO: Implement functionality for clearing config

    def close_gazebo(self):
        print("Close Gazebo button clicked!")
        if self.simulator_process.is_terminal_open(self.simulator_process.gazebo_terminal_title):
            close_command = f"wmctrl -c '{self.simulator_process.gazebo_terminal_title}'"
            subprocess.Popen(close_command, shell=True)
            print("Gazebo terminal closed.")
        else:
            print("No running Gazebo terminal found.")

    def run_gazebo(self):
        print("Run Gazebo button clicked!")
        # world_name = "room.world"
        world_name = "empty.world"
        command = f"cd; cd dev_ws; source install/setup.bash;ros2 launch gazebo_minirys_sim world.launch.py world_name:={world_name}"  # Replace with the actual command to run Gazebo
        terminal_command = f"{self.simulator_process.gazebo_terminal_command} -- bash -c '{command}; exec bash'"

        if self.simulator_process.gazebo_process is None or self.simulator_process.gazebo_process.poll() is not None:
            if not self.simulator_process.is_terminal_open(self.simulator_process.gazebo_terminal_title):
                self.simulator_process.gazebo_process = subprocess.Popen(terminal_command, shell=True)
                print("Gazebo process started.")
            else:
                print("Gazebo is already running.")
        else:
            print("Gazebo is already running.")

    def close_simulator(self):
        print("Close Simulator button clicked!")
        # TODO: Implement functionality for resetting the simulator
        # if self.simulator_process.is_terminal_open(self.simulator_process.terminal_title) and self.simulator_process.process.poll() is None:
        #     self.simulator_process.process.terminate()
        #     self.simulator_process.process.wait()
        #     print("Simulator process terminated.")


        if self.simulator_process.is_terminal_open(self.simulator_process.terminal_title):
            close_command = f"wmctrl -c '{self.simulator_process.terminal_title}'"
            subprocess.Popen(close_command, shell=True)
            print("Simulator terminal closed.")
        else:
            print("No running simulator process found.")


    def run_simulator(self):
        print("Run Simulator button clicked!")
        self.update_simulation_params_in_xml(self.simulation_options)

        command = "cd; cd dev_ws; source install/setup.bash;ros2 launch minirys_sim main.launch.py"  # Replace with the actual command to run the simulator
        terminal_command = f"{self.simulator_process.terminal_command} -- bash -c '{command}; exec bash'"

        if self.simulator_process.process is None or self.simulator_process.process.poll() is not None:
            if not self.simulator_process.is_terminal_open(self.simulator_process.terminal_title):
                self.simulator_process.process = subprocess.Popen(terminal_command, shell=True)
                print("Simulator process started.")
            else:
                print("Simulator is already running.")
        else:
            print("Simulator is already running.")


    def on_box_button_click(self, button, robot_index, button_name):
        print(f"[APP INFO] Robot {robot_index}, Button \"{button_name}\" clicked")
        if button_name == "Kill":
            self.remove_robot_config_file(robot_index)
            self.kill_robot(robot_index, True)
            

        if button_name == "Save":
            file_path = f"{self.package_path}/config/robots/robots_log/"
            self.create_robot_options_xml(self.robot_params_list[robot_index-1], file_path, robot_index)

        if button_name == "Modify":
            file_path = f"{self.package_path}/config/robots/robot{robot_index}_config.xml"
            # self.kill_robot(robot_index, False)
            self.update_robot_options_in_xml(self.robot_params_list[robot_index-1], file_path)

            

##################################################################################################################
################################################ UPDATE APP ######################################################
##################################################################################################################
    
    def kill_robot(self, robot_index, update_left):
        argument = f"name: \"robot{robot_index}\""
        argument_2 = f"{{ {argument} }}"
        command = ["ros2", "service", "call", "/delete_entity", "gazebo_msgs/srv/DeleteEntity", argument_2]
        process = subprocess.Popen(command)

        # Killing zombie nodes
        print(f"[APP INFO] Killing robot{robot_index}")
        self.kill_zombie_node(robot_index)
        
        # Update list of robot
        if update_left:
            self.update_left_column()
    
    def remove_robot_config_file(self, robot_index):
        # Delete robot config file
        file_path = f"{self.package_path}/config/robots/robot{robot_index}_config.xml"
        os.remove(file_path)
        
    def kill_zombie_node(self, robot_index):
        def check_node():
            while True:
                result = subprocess.run(["pgrep", "-f", f"__ns:=/robot{robot_index}"], stdout=subprocess.PIPE)
                if result.stdout:
                    # Node still exists
                    print(f"[APP INFO] Robot{robot_index} node still exists. Retrying...")
                    command = ["pkill", "-f", "-9", f"__ns:=/robot{robot_index}"]
                    subprocess.Popen(command)
                    time.sleep(0.25) # Wait for 0.25 seconds
                else:
                    print(f"[APP INFO] Robot{robot_index} zombie node detected. Terminating...")
                    break
        
        # Start the thread to check and kill the zombie node
        thread = threading.Thread(target=check_node)
        thread.start()

    def update_right_column(self):        
        for child in self.right_column.get_children()[1:]:
            self.right_column.remove(child)
        
        if self.tab_selected == self.tab1:
            option_widgets = self.create_option_widgets(self.simulation_options_name_list, self.simulation_options)
            self.right_column.pack_start(option_widgets, False, False, 0)
        elif self.tab_selected == self.tab2:
            new_label = Gtk.Label(label=f"\n\n\nNothing to see here. For now at least...")
            self.right_column.pack_start(new_label, False, False, 0)
        elif self.tab_selected == self.tab3:
            robot = self.robot_selected.replace("Robot ", "")
            if (int(robot) < 0 or self.robot_params_list == []) and self.upload_clicked == 0:
                print(robot)
                # TODO: remove this variable below in the final program (also change it in the print and check if everthing is correct):
                tab_name = self.tab1.replace("\n", "")
                print(f"[APP INFO] No robot has been detected. Please press \"Uppload\" first. If no robot has appeared on the left, you need to create robots by configuring simulation in \"{tab_name}\" tab and  starting it with the \"Run Simulator\" button")
                return
            option_widgets = self.create_option_widgets(self.robot_options_name_list, self.robot_params_list[int(robot)-1])
            self.right_column.pack_start(option_widgets, False, False, 0)
        else:
            new_label = Gtk.Label(label=f"Nothing to see here. For now at least...")
            self.right_column.pack_start(new_label, False, False, 0)

        self.right_column.show_all()

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
        self.update_right_column()
        self.robot_selected = "Robot 1"

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
        formatted = now.strftime('%Y%m%d%H%M')
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


    def parse_xml_to_options(self, file_path, options_class, options_name_list, element_name):
        tree = ET.parse(file_path)
        root = tree.getroot()

        options = options_class()
        if element_name is not None:
            root = root.find(element_name)

        if root is None:
            error_handler(f"[APP ERROR] Could not find element {element_name} in XML file {file_path}")
            return options
            
        for option_name, option_type in options_name_list.items():
            element = root.find(option_name)
            if element is not None:
                value = element.text
                if option_type == bool:
                    value = value.lower() == 'true'
                elif option_type == float:
                    value = float(value)
                elif option_type == str:
                    value = str(value)
                setattr(options, option_name, value)

        return options
    
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
        simulation_options = self.parse_xml_to_options(file_path, SimulationParameters, self.simulation_options_name_list, "spawn_parameters")
        
        return simulation_options
##############################################################################################################
################################################## CREATE ####################################################
##############################################################################################################
################################################ LEFT COLUMN #################################################

    def add_robots(self):
        robot_config_path = f"{self.package_path}/config/robots/"
        self.robot_params_list = []
        self.robot_params_list = self.load_robot_data(robot_config_path)
        # for robot in self.robot_params_list:
        #     print(robot.robot_namespace)
        print("Adding robots to the left column...")
        for i in range(len(self.robot_params_list)):
            robot_index = self.robot_params_list[i].robot_namespace.replace('robot', '')
            box = Gtk.Frame()
            box.set_label(f"  Robot {robot_index}")
            box.set_size_request(-1, 100)  # Set the constant y size of the boxes
            # print(robot_index)
            self.add_content_to_boxes(box, i, int(robot_index))
            self.left_listbox.insert(box, -1)


    # Generate content of the robot boxes
    def add_content_to_boxes(self, box, box_index, robot_index):
        content_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
        box.add(content_box)

        # Add image to the left
        image_path = f"{self.package_path}/APP/robot_colored/robots/{self.robot_params_list[box_index].color_code}_robot.png"
        # print(image_path)
        desired_width = 110  # Set this to your desired width
        desired_height = 110  # Set this to your desired height
        pixbuf = GdkPixbuf.Pixbuf.new_from_file_at_scale(image_path, desired_width, desired_height, preserve_aspect_ratio=True)
        # pixbuf = GdkPixbuf.Pixbuf.new_from_file(image_path)
        image = Gtk.Image.new_from_pixbuf(pixbuf)
        content_box.pack_start(image, False, False, 0)

        # Add text in the center
        text = Gtk.Label(label=f"Robot {[robot_index]} Content")
        content_box.pack_start(text, True, True, 0)

        # Add three buttons (one on top of another) on the right
        buttons = ["Modify", "Kill", "Save"]
        button_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        for i in range(3):
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
        expander = Gtk.Expander()
        expander.set_label_widget(expander_label)

        item_list = Gtk.ListBox()
        item_list.connect("row-selected", self.on_list_item_selected)

        for item in items:
            item_list.insert(Gtk.Label(label=item), -1)

        expander.add(item_list)
        self.right_column.pack_start(expander, False, False, 0)
    
    def create_option_widgets(self, options, options_struct):
        options_box = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.checkboxes = {}
        self.entries = {}

        for option, option_type in options.items():
            if option_type == bool:
                checkbutton = Gtk.CheckButton.new_with_label(option)
                checkbutton.connect("toggled", self.on_checkbox_toggled, (options_struct, option))
                checkbutton.set_active(getattr(options_struct, option))
                options_box.pack_start(checkbutton, False, False, 0)
                self.checkboxes[option] = checkbutton
            elif option_type == float:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                float_label = Gtk.Label(label=f"Enter {option}:")
                hbox.pack_start(float_label, False, False, 0)

                float_entry = Gtk.Entry()
                float_entry.connect("changed", self.on_float_entry_changed, (options_struct, option))
                float_entry.set_text(str(getattr(options_struct, option)))
                hbox.pack_start(float_entry, False, False, 0)
                self.entries[option] = float_entry
            elif option_type == str:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                string_label = Gtk.Label(label=f"Enter {option}:")
                hbox.pack_start(string_label, False, False, 0)

                string_entry = Gtk.Entry()
                string_entry.connect("changed", self.on_string_entry_changed, (options_struct, option))
                string_entry.set_text(getattr(options_struct, option))
                hbox.pack_start(string_entry, False, False, 0)
                self.entries[option] = string_entry
            elif option_type == int:
                hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=6)
                options_box.pack_start(hbox, False, False, 0)

                int_label = Gtk.Label(label=f"Enter {option}:")
                hbox.pack_start(int_label, False, False, 0)

                int_entry = Gtk.Entry()
                int_entry.connect("changed", self.on_int_entry_changed, (options_struct, option))
                int_entry.set_text(str(getattr(options_struct, option)))
                hbox.pack_start(int_entry, False, False, 0)
                self.entries[option] = int_entry

        return options_box

    def on_checkbox_toggled(self, checkbox, data):
        # print("CHECKED!!!")
        options_data, option = data
        setattr(options_data, option, checkbox.get_active())
        
    def on_int_entry_changed(self, entry, data):
        options_data, option = data
        try:
            int_value = int(entry.get_text())
            setattr(options_data, option, int_value)
        except ValueError:
            print("Invalid integer value entered!") # TODO: Error occurs even if intiger is correct

    def on_float_entry_changed(self, entry, data):
        options_data, option = data
        try:
            float_value = float(entry.get_text())
            setattr(options_data, option, float_value)
        except ValueError:
            print("Invalid float value entered!")

    def on_string_entry_changed(self, entry, data):
        options_data, option = data
        string_value = entry.get_text()
        setattr(options_data, option, string_value)

################################################# FOOT ######################################################
            
    # Create butons in the foot of the window
    def add_buttons_to_box(self, button_labels):
        for label in button_labels:
            button = Gtk.Button.new_with_label(label)
            self.button_box.pack_start(button, False, False, 0)
            button.set_size_request(100, 30)  # Set the constant size of the buttons
            button.connect("clicked", self.on_button_click)

def set_window_position(window):
    screen = Gdk.Screen.get_default()
    monitor = 1  # Change this value to control which monitor the window appears on
    
    if monitor < screen.get_n_monitors():
        monitor_geometry = screen.get_monitor_geometry(monitor)
        x_position = monitor_geometry.x
        y_position = monitor_geometry.y

        window.move(x_position, y_position)
    else:
        print(f"Monitor {monitor} not found. Using the default monitor instead.")

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