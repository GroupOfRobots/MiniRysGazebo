#!/usr/bin/env python3
import os
import time

import launch
import logging

from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
from PIL import ImageEnhance

from dataclasses import dataclass
from typing import List
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, OpaqueFunction, SetEnvironmentVariable, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, EnvironmentVariable
import xml.etree.ElementTree as ET


##############################################################################################################
############################################### TODO LIST ####################################################
##############################################################################################################

# TODO: add support of physics parameters                                                                   [DONE]
# TODO: merge rsp.launch.py with launch_sim.launch.py                                                       [DONE]
# TODO: add DeclareLaunchArgument's to newly created launch file                                            [DONE]
# TODO: add documentation (in the code)                                                                     [DONE]
# TODO: make a library of colors for robots                                                                 [TO VERIFICATION]
# TODO: make a relative path to custom Gazebo material path!!! Start with simple colour change              [DONE]
# TODO: add label_enabled argument to launch file                                                           [DONE]
# TODO: change all colors Rys/... and rys/... to the same and make them use path relative to the package    [DONE]                         
# TODO: add texture to label                                                                                [DONE]
# TODO: add unique texture to each robot                                                                    [DONE]
# TODO: make a texture prettier                                                                             [DONE]
# TODO: read color list from color_list.txt                                                                 [DONE]
# TODO: change generate_texture paths to relative to the package                                            [DONE]
# TODO: make colors nice again!!!
# TODO: there is todo in generate_label_texture                                                             [DONE]
# TODO: add enable camera visualization argument to launch file                                             [DONE]
# TODO: support for multipe parameters written in the texture
# TODO: create node that publishes key robot parameters
# TODO: create simulation config file that will be more readable
# TODO: file containing all information that is needed to recreate simulation!!!
# TODO: simple robot movement controler
# TODO: correct models phisics (make movies)
# TODO: consider to do it automatically (get real robot data as it falls down or pushes box with known mass)
# TODO: add support for multiple worlds. 
# TODO: there is todo in generate_robot_data function
# TODO: change all paths to those relative to the package                                                   [DONE]
# TODO: consider to place some of the function in separate files

# TODO: Delete unnecessary print statements. Add [SIM INFO], [SIM WARN], [SIM ERROR] to nessesery ones

# TODO: Coustom colors!!!

# TODO: Output supression as an option (some config file or something)

##############################################################################################################
##############################################################################################################


@dataclass
class RobotParameters:
    use_sim_time: str = 'true'
    robot_namespace: str = 'robot'
    color_code: str = '#9370DB'
    color_code_R: str = '1.0'
    color_code_G: str = '1.0'
    color_code_B: str = '1.0'
    color_code_A: str = '1.0'
    camera_enabled: str = 'true'
    camera_visibility: str = 'false'
    label_enabled: str = 'false'
    label_x: str = '0.13'
    label_y: str = '0.05'
    TOF_enabled: str = 'true'
    horizontal_sensor_visibility: str = 'false'
    vertical_sensor_visibility: str = 'false'
    none_sensor_visibility: str = 'true'
    all_sensor_visibility: str = 'false'
    TOF_FOV_angle: str = '0.08'
    TOF_range: str = '5'
    spawn_x: str = '-2.0'
    spawn_y: str = '-3.0'
    spawn_z: str = '0.0'
    spawn_roll: str = '0.0'
    spawn_pitch: str = '0.0'
    spawn_yaw: str = '1.570796327'
    chassis_mu1: str = '0.1'
    chassis_mu2: str = '0.1'
    chassis_kp: str = '0.7'
    chassis_kd: str = '0.05'
    wheel_mu1: str = '10'
    wheel_mu2: str = '10'
    wheel_kp: str = '0.7'
    wheel_kd: str = '0.05'
    wheel_joint_dumping: str = '0.1'
    wheel_joint_friction: str = '0.1'


@dataclass
class SpawnParameters:
    robots_number: int = 1
    number_of_rows: int = 1

    use_default_colors: bool = True
    # default_randomize_colors: bool = False
    # default_starting_color: int = 0
    # custom_colors: list = ["#000000"]

    x_separation: float = 0.0
    y_separation: float = 0.0
    z_separation: float = 0.0
    x_offset: float = -2.0
    y_offset: float = -3.0
    z_offset: float = 0.0
    roll: float = 0.0
    pitch: float = 0.0
    yaw: float = 1.570796327


def generate_label_texture(package_path, robot_params_list, parameters_to_display, values_of_parameters):
    # Important variables
    pixel_size = 0.00025
    offset_from_corners = 38
    color = '#FFF'
    large_font_size = 56
    small_font_size = 28

    # Load the fonts
    font_large = ImageFont.truetype(font=f'{package_path}/description/materials/scripts/textures/font.ttf', size=large_font_size)
    font_small = ImageFont.truetype(font=f'{package_path}/description/materials/scripts/textures/font.ttf', size=small_font_size)
    

    for idx, robot_params in enumerate(robot_params_list):
        # Create the text lines
        robot_number = robot_params.robot_namespace.replace('robot', '')
        nicer_robot_name = f"Robot {robot_number}"
        text_lines = [(f"{nicer_robot_name}", font_large)]
        for param, value in zip(parameters_to_display, values_of_parameters[idx]):
            if param == 'color_code':
                text_lines.append((f"color_code: {robot_params_list[idx].color_code}", font_small))
            else:
                text_lines.append((f"{param}: {value}", font_small))

        # Calculate the size of the box
        tmp_img = Image.new('RGB', (1, 1))
        line_sizes = [ImageDraw.Draw(tmp_img).textsize(text, font=font) for text, font in text_lines]
        box_width = max(width for width, _ in line_sizes) + offset_from_corners*2
        box_height = sum(height for _, height in line_sizes) + offset_from_corners*2
        charsize = (box_width, box_height)

        # Update the robot parameters
        robot_params.label_x = str(box_width * pixel_size)
        robot_params.label_y = str(box_height * pixel_size)

        # Create the image
        bg_img = Image.new('RGB', charsize, color)
        mask_img = Image.new('L', bg_img.size, 0)
        draw = ImageDraw.Draw(mask_img)
        total_height = offset_from_corners - 9

        for line, font in text_lines:
            text_width, text_height = draw.textsize(line, font=font)
            draw.text(((charsize[0]-text_width)//2, total_height), line, font=font, fill='white')
            total_height += text_height
        bg_img.putalpha(mask_img)

        # Save the image
        texture_name = f"{robot_params.robot_namespace}.png"
        bg_img.save(f'{package_path}/description/materials/scripts/textures/' + texture_name)

        # Update the textures.material file
        with open(f"{package_path}/description/materials/scripts/textures.material", 'r') as file:
            lines = file.readlines()

        line_to_find = f"                texture textures/{texture_name}\n"

        if line_to_find not in lines:
            print(f"Creating {robot_params.robot_namespace} texture description")
            with open(f"{package_path}/description/materials/scripts/textures.material", 'a') as file:
                file.write("\n")
                file.write(f"material rys/{robot_params.robot_namespace}\n")
                file.write("{\n")
                file.write("    technique\n")
                file.write("    {\n")
                file.write("        pass\n")
                file.write("        {\n")
                file.write("            scene_blend alpha_blend\n")
                file.write("            depth_write off\n")
                file.write("            lighting off\n")
                file.write("            texture_unit\n")
                file.write("            {\n")
                file.write(f"                texture textures/{texture_name}\n")
                file.write("            }\n")
                file.write("        }\n")
                file.write("    }\n")
                file.write("}\n")


def generate_robot_data(package_path, spawn_position_params: SpawnParameters, param_to_change, iterate_by, start_from):
    """
    Generates a list of robot parameters based on the provided spawn parameters.

    Args:
        spawn_position_params (SpawnParameters): The spawn position parameters for the robots.
        param_to_change (List[str]): A list of parameter names to set for each robot.
        iterate_by (List[float]): A list of values for each parameter from param_to_change list that should be added to the subsequent robots that will be spawned.
        start_from (List[float]): A list of starting values for each parameter in the `param_to_change` to which iterate_by will be added. (the first values for each parameter in the param_to_change list)

    Returns:
        List[RobotParameters]: A list of robot parameters based on the provided configuration.
    """
    # VARIABLES
    # Initialize the list of robot parameters
    robot_params_list = []
    # Initialize the list of values to display in the label
    values_to_display = []

    # Check if the number of robots is bigger than zero. If not, return an empty list (error case)
    if spawn_position_params.robots_number <= 0:
        print(f"[SIM ERROR] 00 No robot to be spawned. spawn_position_params.robots_number = {spawn_position_params.robots_number}. To spawn a robot, this value must be an integer bigger than zero")
        return [], []
    
    # Upload the color names from the color_list.txt file
    color_name_list, color_code_R_list, color_code_G_list, color_code_B_list, color_code_A_list = read_color_names_from_file(f"{package_path}/config/color_list.txt")
    if len(color_name_list) == 0 or len(color_code_R_list) == 0 or len(color_code_G_list) == 0 or len(color_code_B_list) == 0 or len(color_code_A_list) == 0:
        print("[SIM ERROR] 00 No colors found in the color list.")
        return [], []

    row = 0 # row number, used to calculate the y position of the robot
    column = 0 # column number, used to calculate the x position of the robot
    
    # Check if the number of rows is bigger than the number of robots. If so, set the number of rows to 1
    if spawn_position_params.number_of_rows > spawn_position_params.robots_number:
        robots_per_row = spawn_position_params.robots_number
        print(f"[SIM WARN] 00 The number of rows is bigger than the number of robots. The number of rows will be set to 1")
    else:
        robots_per_row = spawn_position_params.robots_number / spawn_position_params.number_of_rows # calculate the number of robots per row

    # Iterate over the number of robots and generate the parameters for each robot
    for i in range(spawn_position_params.robots_number):
        if i % robots_per_row == 0: # if i is a multiple of robots_per_row, increment the row number and reset the column number
            row += 1    # increment the row number
            column = 0  # reset the column number
        # Generate the parameters for the robot
        robot_params = RobotParameters(
                robot_namespace = f"robot{i + 1}",
                color_code= f"{color_name_list[i % len(color_name_list)]}",
                color_code_R= f"{color_code_R_list[i % len(color_code_R_list)]}",
                color_code_G= f"{color_code_G_list[i % len(color_code_G_list)]}",
                color_code_B= f"{color_code_B_list[i % len(color_code_B_list)]}",
                color_code_A= f"{color_code_A_list[i % len(color_code_A_list)]}",
                spawn_x = f"{spawn_position_params.x_offset + column * spawn_position_params.x_separation}",
                spawn_y = f"{spawn_position_params.y_offset - row + i * spawn_position_params.y_separation}",
                spawn_z = f"{spawn_position_params.z_offset + i * spawn_position_params.z_separation}",
                spawn_roll = f"{spawn_position_params.roll}",
                spawn_pitch = f"{spawn_position_params.pitch}",
                spawn_yaw = f"{spawn_position_params.yaw}",
        )
        # print(f"[SIM INFO] 00 For robot{i+1} color was set to: {color_names[i]}.") # TODO: Delete this line after testing

        # for each robot generate the parameters that should be changed
        new_value_list = []
        if param_to_change and iterate_by and start_from: # if the lists are not empty
            if len(param_to_change) == len(iterate_by) == len(start_from): # if the lists have the same number of elements. Which is required
                for j in range(len(param_to_change)): # iterate over the list of parameters to change
                    try: # try to set the attribute
                        getattr(robot_params, param_to_change[j])
                        new_value = start_from[j] + i * iterate_by[j]
                        new_value_list.append(new_value)
                        setattr(robot_params, param_to_change[j], f"{new_value}")
                        # print(f"[SIM INFO] 00 For robot{i+1} attribute {param_to_change[j]} is set to {new_value}.") # TODO: Uncomment this line after testing
                    except AttributeError: # if the attribute doesn't exist in the RobotParameters class (error case)
                        print(f"[SIM ERROR] 00 Attribute {param_to_change[j]} not found in RobotParameters class.")
                        return [], []
                    except TypeError: # if the attribute is not a float (error case)
                        print(f"[SIM ERROR] 00 Incorrect data type for {param_to_change[j]}.")
                        return [], []
            else:   # if the lists doesn't have the same number of elements (error case)
                print("[SIM ERROR] 00 The lists doesn't contain the same number of parameters.")
                return [], []
        else:  # if one of the lists is empty (error case)
            print("[SIM INFO] 00 There are no parameters to change or one of the lists is empty.")
            return [], []
        column += 1
        values_to_display.append(new_value_list)
        robot_params_list.append(robot_params)
    
    return robot_params_list, values_to_display


def spawn(context, package_path, robot_params: RobotParameters):
    """
    Spawns a robot in the simulation using the provided robot parameters.

    This function sets up the robot launch description using the given
    robot parameters.

    Args:
        context (OpaqueFunction): The context object for the OpaqueFunction, used to pass information
                                  and launch configurations between different parts of the launch system.
        robot_params (RobotParameters): A dataclass object containing the robot's configuration parameters.

    Returns:
        IncludeLaunchDescription: The launch description for spawning the robot with the given parameters.
    """
        
    package_name = 'minirys_sim'
    package_path = get_package_share_directory(package_name)
    
    spawn_another = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(package_path, 'launch', 'robot.launch.py')),
        launch_arguments={
            'use_sim_time': robot_params.use_sim_time,
            'robot_namespace': robot_params.robot_namespace,
            'color_code': robot_params.color_code,
            'color_code_R': robot_params.color_code_R,
            'color_code_G': robot_params.color_code_G,
            'color_code_B': robot_params.color_code_B,
            'color_code_A': robot_params.color_code_A,
            'camera_enabled': robot_params.camera_enabled,
            'camera_visibility': robot_params.camera_visibility,
            'label_enabled': robot_params.label_enabled,
            'label_x': robot_params.label_x,
            'label_y': robot_params.label_y,
            'TOF_enabled':robot_params.TOF_enabled,
            'horizontal_sensor_visibility':robot_params.horizontal_sensor_visibility,
            'vertical_sensor_visibility':robot_params.vertical_sensor_visibility,
            'all_sensor_visibility':robot_params.all_sensor_visibility,
            'none_sensor_visibility':robot_params.none_sensor_visibility,
            'TOF_FOV_angle':robot_params.TOF_FOV_angle,
            'TOF_range':robot_params.TOF_range,
            'spawn_x': robot_params.spawn_x,
            'spawn_y': robot_params.spawn_y, 
            'spawn_z': robot_params.spawn_z, 
            'spawn_roll': robot_params.spawn_roll, 
            'spawn_pitch': robot_params.spawn_pitch, 
            'spawn_yaw': robot_params.spawn_yaw,
            'chassis_mu1': robot_params.chassis_mu1,
            'chassis_mu2': robot_params.chassis_mu2,
            'chassis_kp': robot_params.chassis_kp,
            'chassis_kd': robot_params.chassis_kd,
            'wheel_mu1': robot_params.wheel_mu1,
            'wheel_mu2': robot_params.wheel_mu2,
            'wheel_kp': robot_params.wheel_kp,
            'wheel_kd': robot_params.wheel_kd,
            'wheel_joint_dumping': robot_params.wheel_joint_dumping,
            'wheel_joint_friction': robot_params.wheel_joint_friction
        }.items()
    )

    return [spawn_another]


def launch_gazebo_world(context, world_name: str):
     
    package_name = 'minirys_sim'
    package_path = get_package_share_directory(package_name)
    
    launch_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(package_path, 'launch', 'world.launch.py')),
        launch_arguments={
            'world_name': world_name
        }.items()
    )

    return [launch_gazebo] 



def populate_spawn_params(package_path, mode):
    spawn_position_params = SpawnParameters()
    tree = ET.parse(f"{package_path}/config/launch_config.xml")
    root = tree.getroot()

    # Find the spawn_parameters element with the specified mode attribute
    spawn_params_elem = root.find(f"spawn_parameters[@mode='{mode}']")

    spawn_position_params.robots_number = int(spawn_params_elem.find("robots_number").text)
    spawn_position_params.number_of_rows = int(spawn_params_elem.find("number_of_rows").text)
    spawn_position_params.x_separation = float(spawn_params_elem.find("x_separation").text)
    spawn_position_params.y_separation = float(spawn_params_elem.find("y_separation").text)
    spawn_position_params.z_separation = float(spawn_params_elem.find("z_separation").text)
    spawn_position_params.roll = float(spawn_params_elem.find("roll").text)
    spawn_position_params.pitch = float(spawn_params_elem.find("pitch").text)
    spawn_position_params.yaw = float(spawn_params_elem.find("yaw").text)

    param_to_change = [elem.text for elem in root.find("param_to_change").findall("value")]
    start_from = [float(elem.text) for elem in root.find("start_from").findall("value")]
    iterate_by = [float(elem.text) for elem in root.find("iterate_by").findall("value")]

    print(f"param_to_change: {param_to_change}")
    print(f"start_from: {start_from}")
    print(f"iterate_by: {iterate_by}")
    print(f"spawn_position_params: {spawn_position_params}")
    
    return param_to_change, start_from, iterate_by, spawn_position_params


def save_configs_to_xml(package_path: str, robot_params_list: List[RobotParameters]):
    for robot_params in robot_params_list:
        root = ET.Element("robot_config")

        for param_name, param_value in robot_params.__dict__.items():
            param_elem = ET.SubElement(root, param_name)
            param_elem.text = str(param_value)

        # Save the XML to a file with the specified name format
        file_path = f"{package_path}/config/robots/{robot_params.robot_namespace}_config.xml"
        
        # Use pretty_xml to format the XML content
        formatted_xml = format_xml(root)
        
        with open(file_path, "w", encoding="utf-8") as f:
            f.write('<?xml version="1.0" encoding="utf-8"?>\n')
            f.write(formatted_xml)


def format_xml(element, level = 0):
    indent = '    ' * level
    result = [indent + '<' + element.tag]
    
    # Add attributes, if any
    for name, value in sorted(element.attrib.items()):
        result.append(f' {name}="{value}"')
    
    # Add text content, if any
    if element.text:
        content = element.text.strip()
        if content:
            result.append('>' + content)
    else:
        result.append('>\n')

    # Add children elements, if any
    for child in element:
        result.append(format_xml(child, level + 1))

    # Add closing tag
    result.append('</' + element.tag + '>\n')

    return ''.join(result)

def remove_files_from_folder(folder_path):
    # Check if the folder exists before trying to remove files
    if os.path.isdir(folder_path):
        # List all files in the folder
        files = os.listdir(folder_path)

        # Iterate through the files and remove them
        for file in files:
            file_path = os.path.join(folder_path, file)

            # Check if it's a file (not a directory)
            if os.path.isfile(file_path):
                os.remove(file_path)
                # print(f'File {file_path} has been removed successfully.')
            else:
                print(f'{file_path} is not a file.')

    else:
        print(f'Folder {folder_path} not found.')

def read_color_names_from_file(file_path):
    color_name_list = []
    color_code_R = []
    color_code_G = []
    color_code_B = []
    color_code_A = []  # always 1.0

    with open(file_path, 'r') as file:
        in_color_list = False
        for line in file:
            # print(line)
            line = line.strip()
            if not in_color_list:
                if line == '<color_list>':
                    in_color_list = True
            else:
                if line == '</color_list>':
                    break
                color_parts = line.split('\t')
                if len(color_parts) == 2:
                    color_name_list.append(color_parts[0])
                    rgb_values = color_parts[1].strip("()").split(',')
                    color_code_R.append(int(rgb_values[0]))
                    color_code_G.append(int(rgb_values[1]))
                    color_code_B.append(int(rgb_values[2]))
                    color_code_A.append(1.0)
    # print("Color names:", color_name_list)
    # print("Color codes:", color_code_R, color_code_G, color_code_B, color_code_A)
    return color_name_list, color_code_R, color_code_G, color_code_B, color_code_A



def generate_launch_description():
    """
    Generates a launch description for spawning robots in the simulation.

    This function sets up the spawn parameters for the robots, generates
    the robot parameters based on the specified configuration, and spawns
    the robots in the simulation using the generated parameters.

    Returns:
        LaunchDescription: A launch description containing the actions for
                           creating the simulation world and spawning the 
                           defined robots.
    """
    script_path = os.path.abspath(__file__)
    package_path = os.path.dirname(script_path).replace("/install/minirys_sim/share/minirys_sim/launch", "/src/minirys_sim")
    # print("Package path:", package_path)

    ########################################################################
    ########################## SWARM SETUP #################################
    ########################################################################
    spawn_position_params = SpawnParameters()
    mode = "row_spawn_parameters"
    param_to_change, start_from, iterate_by, spawn_position_params = populate_spawn_params(package_path, mode)
    print(spawn_position_params.robots_number)

    # Position offset (or the position of the first robot) -- calculated for convenience
    # Depend on the number of robots and the number of rows distribute them in a grid from the center

    spawn_position_params.x_offset = -spawn_position_params.x_separation * (spawn_position_params.robots_number/spawn_position_params.number_of_rows - 1.0) / 2.0
    spawn_position_params.y_offset = (-spawn_position_params.y_separation * (spawn_position_params.number_of_rows - 1.0) / 2.0)
    spawn_position_params.z_offset = 0.0

    robot_params_list, values_to_display = generate_robot_data(package_path, spawn_position_params, param_to_change, iterate_by, start_from)
    if not robot_params_list: # Check if the list is empty (error case)
        print("[SIM ERROR] 00 Terminating launch sequence...")
        return LaunchDescription([])
    

    reload_xmls = True                                              # TODO: Set as Launch Argument
    if reload_xmls:
            remove_files_from_folder(f"{package_path}/config/robots")
    # Save the robot parameters to XML files
    save_configs_to_xml(package_path, robot_params_list)

    # Add the color code to the list of parameters to display and values to display
    param_to_display = ['color_code']
    for i in range (len(param_to_change)):
        param_to_display.append(param_to_change[i])
    for i in range (len(values_to_display)):    
        values_to_display[i].insert(0, 0)
    print(f"Param_to_display: {param_to_display}")
    print(f"Values_to_display: {values_to_display}")
    param_to_change = param_to_display

    
    generate_label_texture(package_path, robot_params_list, param_to_change, values_to_display)
    

    
    ########################################################################

    spawn_actions = []
    # print(robot_params_list)
    for i in range(len(robot_params_list)):
        # print(robot_params_list[i].color_code)
        spawn_actions.append(
            OpaqueFunction(
                function=spawn,
                kwargs={
                    'package_path': package_path,
                    'robot_params': robot_params_list[i]
                },
            )
        )


    launch.logging.get_logger().setLevel(logging.WARNING)

    return LaunchDescription([
        SetEnvironmentVariable("RCUTILS_LOGGING_SEVERITY_THRESHOLD", "30"),
        # OpaqueFunction(function=launch_gazebo_world, args=("empty.world",)),
    ] + spawn_actions)


