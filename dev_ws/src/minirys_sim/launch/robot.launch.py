#!/usr/bin/env python3

import os
from ament_index_python.packages import get_package_share_directory,get_package_prefix
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch_ros.actions import Node
from launch import LaunchDescription
from launch_ros.descriptions import ParameterValue
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def hex_to_rgba(hex_string):
    hex_string = hex_string.lstrip('#')
    if len(hex_string) != 6:
        raise ValueError("[SIM ERROR] 01 Input hexadecimal is not in correct format")
    r, g, b = (int(hex_string[i:i+2], 16) for i in (0, 2, 4))
    a = 1.0
    return str(r/255), str(g/255), str(b/255), str(a)


def launch_setup(context):
    """
    This function sets up a robot simulation environment by processing the robot URDF file
    with specified configurations. It creates and configures a robot_state_publisher node
    to publish the robot's state.

    This function performs the following steps:
    1. Defines a set of LaunchConfigurations, each corresponding to a specific parameter for the robot.
    2. Builds a list of strings with xacro and parameters to configure the robot model.
    3. Creates a `robot_state_publisher` node with the robot description and the `use_sim_time` parameter.
    4. Extracts the robot namespace string and robot name from the provided `robot_namespace` LaunchConfiguration.
    5. Creates a `spawn_entity` node with arguments for the robot namespace, entity name, and spawn position and orientation.

    Args:
        context (OpaqueFunction): The context object for the OpaqueFunction, used to pass information
                                  and launch configurations between different parts of the launch system.

    Returns:
        list: A list containing the robot_state_publisher and spawn_entity nodes required for the launch process.
    """
    
    ############################################################
    ######################## PARAMETERS ########################
    ############################################################
    # Basic
    use_sim_time = True # NOT "True"
    robot_namespace = LaunchConfiguration('robot_namespace')
    color_code = LaunchConfiguration('color_code')
    label_enabled = LaunchConfiguration('label_enabled')
    label_x = LaunchConfiguration('label_x')
    label_y = LaunchConfiguration('label_y')

    # Sensors
    camera_enabled = LaunchConfiguration('camera_enabled')
    camera_visibility = LaunchConfiguration('camera_visibility')
    horizontal_sensor_visibility = LaunchConfiguration('horizontal_sensor_visibility')
    vertical_sensor_visibility = LaunchConfiguration('vertical_sensor_visibility')
    all_sensor_visibility = LaunchConfiguration('all_sensor_visibility')
    TOF_FOV_angle = LaunchConfiguration('TOF_FOV_angle')
    TOF_range = LaunchConfiguration('TOF_range')
    TOF_enabled = LaunchConfiguration('TOF_enabled')
    
    # Phisics
    chassis_mu1 = LaunchConfiguration('chassis_mu1')
    chassis_mu2 = LaunchConfiguration('chassis_mu2')
    chassis_kp = LaunchConfiguration('chassis_kp')
    chassis_kd = LaunchConfiguration('chassis_kd')
    wheel_mu1 = LaunchConfiguration('wheel_mu1')
    wheel_mu2 = LaunchConfiguration('wheel_mu2')
    wheel_kp = LaunchConfiguration('wheel_kp')
    wheel_kd = LaunchConfiguration('wheel_kd')
    wheel_joint_dumping = LaunchConfiguration('wheel_joint_dumping')
    wheel_joint_friction = LaunchConfiguration('wheel_joint_friction')

    chassis_mx = LaunchConfiguration('chassis_mx')
    chassis_my = LaunchConfiguration('chassis_my')
    chassis_mz = LaunchConfiguration('chassis_mz')

    chassis_ixx = LaunchConfiguration('chassis_ixx')
    chassis_ixy = LaunchConfiguration('chassis_ixy')
    chassis_ixz = LaunchConfiguration('chassis_ixz')
    chassis_iyy = LaunchConfiguration('chassis_iyy')
    chassis_iyz = LaunchConfiguration('chassis_iyz')
    chassis_izz = LaunchConfiguration('chassis_izz')
    
    wheels_ixx = LaunchConfiguration('wheels_ixx')
    wheels_ixy = LaunchConfiguration('wheels_ixy')
    wheels_ixz = LaunchConfiguration('wheels_ixz')
    wheels_iyy = LaunchConfiguration('wheels_iyy')
    wheels_iyz = LaunchConfiguration('wheels_iyz')
    wheels_izz = LaunchConfiguration('wheels_izz')

        
    # Spawn parameters
    spawn_x = LaunchConfiguration('spawn_x')
    spawn_y = LaunchConfiguration('spawn_y')
    spawn_z = LaunchConfiguration('spawn_z')
    spawn_roll = LaunchConfiguration('spawn_roll')
    spawn_pitch = LaunchConfiguration('spawn_pitch')
    spawn_yaw = LaunchConfiguration('spawn_yaw')
    
    # Process the URDF file
    pkg_path = os.path.join(get_package_share_directory('minirys_sim'))
    xacro_file = os.path.join(pkg_path,'description','robot.urdf.xacro')
    workspace_path = get_package_prefix('minirys_sim').replace('install/minirys_sim', '')
    package_path = os.path.join(workspace_path, 'src', 'minirys_sim')

    ## Just to check if the parameters are being passed correctly
    # print(chassis_mx.perform(context)) 
    # print(chassis_my.perform(context))
    # print(f"set to {chassis_mz.perform(context)}")

    color_code_R, color_code_G, color_code_B, color_code_A = hex_to_rgba(color_code.perform(context))
    print(f"R:{color_code_R}, G:{color_code_G}, B:{color_code_B}, A:{color_code_A},")
    # Using Command substitution to set xacro file arguments
    robot_description_config = Command(['xacro ', xacro_file, 
                                        ' package_path:=', package_path,
                                        ' robot_namespace:=', robot_namespace,
                                        ' color_code:=', color_code,
                                        ' color_code_R:=', color_code_R,
                                        ' color_code_G:=', color_code_G,
                                        ' color_code_B:=', color_code_B,
                                        ' color_code_A:=', color_code_A,
                                        ' label_enabled:=', label_enabled,
                                        ' label_x:=', label_x,
                                        ' label_y:=', label_y,

                                        ' camera_enabled:=', camera_enabled,
                                        ' camera_visibility:=', camera_visibility,
                                        ' horizontal_sensor_visibility:=', horizontal_sensor_visibility,
                                        ' vertical_sensor_visibility:=', vertical_sensor_visibility,
                                        ' all_sensor_visibility:=', all_sensor_visibility,
                                        
                                        ' TOF_FOV_angle:=', TOF_FOV_angle,
                                        ' TOF_range:=', TOF_range,
                                        ' TOF_enabled:=', TOF_enabled,
                                        
                                        ' chassis_mu1:=', chassis_mu1,
                                        ' chassis_mu2:=', chassis_mu2,
                                        ' chassis_kp:=', chassis_kp, 
                                        ' chassis_kd:=', chassis_kd, 
                                        ' wheel_mu1:=', wheel_mu1, 
                                        ' wheel_mu2:=', wheel_mu2, 
                                        ' wheel_kp:=', wheel_kp, 
                                        ' wheel_kd:=', wheel_kd, 
                                        ' wheel_joint_dumping:=', wheel_joint_dumping,
                                        ' wheel_joint_friction:=', wheel_joint_friction,

                                        ' chassis_mx:=', chassis_mx,
                                        ' chassis_my:=', chassis_my,
                                        ' chassis_mz:=', chassis_mz,

                                        ' chassis_ixx:=', chassis_ixx,
                                        ' chassis_ixy:=', chassis_ixy,
                                        ' chassis_ixz:=', chassis_ixz,
                                        ' chassis_iyy:=', chassis_iyy,
                                        ' chassis_iyz:=', chassis_iyz,
                                        ' chassis_izz:=', chassis_izz,
                                        ' wheels_ixx:=', wheels_ixx,
                                        ' wheels_ixy:=', wheels_ixy,
                                        ' wheels_ixz:=', wheels_ixz,
                                        ' wheels_iyy:=', wheels_iyy,
                                        ' wheels_iyz:=', wheels_iyz,
                                        ' wheels_izz:=', wheels_izz,
                                        ]),
    

    # Creating the robot_state_publisher node
    params = {'robot_description': ParameterValue(robot_description_config, value_type=str), 'use_sim_time': use_sim_time}
    robot_state_publisher_node = Node(
        namespace=robot_namespace,
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[params]
    )

    # Accessing the robot namespace string from robot_namespace LaunchConfiguration
    robot_namespace_string = "/" + robot_namespace.perform(context) + "/robot_description"
    robot_name = robot_namespace.perform(context)
    
    # Creating the spawn_entity node
    spawn_entity = Node(
                        package='gazebo_ros', 
                        executable='spawn_entity.py',
                        namespace=robot_namespace,
                        arguments=[
                                    '-topic', robot_namespace_string,
                                    '-entity', robot_name,
                                    '-x', spawn_x,
                                    '-y', spawn_y,
                                    '-z', spawn_z,
                                    '-R', spawn_roll,
                                    '-P', spawn_pitch,
                                    '-Y', spawn_yaw
                                    ],
                        output='screen'
                        )

    return [ 
        robot_state_publisher_node,
        spawn_entity
    ]


def generate_launch_description():
    """
    Generates a launch description for the robot simulation, including all necessary launch arguments and nodes.

    This function defines a set of DeclareLaunchArgument instances, each corresponding to a specific parameter
    for the robot simulation. It also includes the launch_setup function as an OpaqueFunction action, which
    sets up the robot simulation launch process.

    Returns:
        launch.LaunchDescription: A launch description object containing all launch arguments and the launch_setup function.
    """
    
    return LaunchDescription([
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Using sim time if true"),

        DeclareLaunchArgument(
            "robot_namespace",
            default_value="robot",
            description="Defining namespace for spawned robot"),
        
        DeclareLaunchArgument(
            "color_code",
            default_value="#9370DB",
            description="Color code name of the spawned robot (in HEX)"),

        DeclareLaunchArgument(
            "color_code_R",
            default_value="0.9",
            description="Red value of the color code"),
        
        DeclareLaunchArgument(
            "color_code_G",
            default_value="0.1",
            description="Green value of the color code"),
        
        DeclareLaunchArgument(
            "color_code_B",
            default_value="0.1",
            description="Blue value of the color code"),

        DeclareLaunchArgument(
            "color_code_A",
            default_value="1.0",
            description="Alpha value of the color code"),
        
        DeclareLaunchArgument(
            "label_enabled",
            default_value="true",
            description="Adds a label to the spawned robot if true. If false, no label will be added"),

        DeclareLaunchArgument(
            "label_x",
            default_value="0.13",
            description="X size of the label"),
        
        DeclareLaunchArgument(
            "label_y",
            default_value="0.05",
            description="Y size of the label"),

        DeclareLaunchArgument(
            "camera_enabled",
            default_value="true",
            description="Adds the camera if true. If false, the camera model and the associated nodes will be disabled for spawned robot"),
        
        DeclareLaunchArgument(
            "camera_visibility",
            default_value="false",
            description="Enables visuals of the camera"),

        DeclareLaunchArgument(
            "TOF_enabled",
            default_value="true",
            description="Adds TOF sensors if true. If false, the nodes for the TOF sensor will be disabled for spawned robot"),
        
        DeclareLaunchArgument(
            "horizontal_sensor_visibility",
            default_value="false",
            description="Enables visuals of the TOF sensor ranges that are used for the horizontal position"),
        
        DeclareLaunchArgument(
            "vertical_sensor_visibility",
            default_value="false",
            description="Enables visuals of the TOF sensor ranges that are used for the vertical position"),
        
        DeclareLaunchArgument(
            "all_sensor_visibility",
            default_value="false",
            description="Enables visuals of all of the TOF sensor ranges"),
        
        DeclareLaunchArgument(
            "TOF_FOV_angle",
            default_value="0.08",
            description="Sets a field of view angle of the TOF sensors"),
        
        DeclareLaunchArgument(
            "TOF_range",
            default_value="5",
            description="Sets a ranges of the TOF sensors"),
        
        DeclareLaunchArgument(
            "spawn_x",
            default_value="-2.0",
            description="Sets the x position of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "spawn_y",
            default_value="-3.0",
            description="Sets the y position of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "spawn_z",
            default_value="0.0",
            description="Sets the z position of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "spawn_roll",
            default_value="0.0",
            description="Sets the roll of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "spawn_pitch",
            default_value="0.0",
            description="Sets the pitch of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "spawn_yaw",
            default_value="1.570796327",
            description="Sets the yaw of the robot to be spawned"),
        
        DeclareLaunchArgument(
            "chassis_mu1",
            default_value="0.1",
            description="Sets friction coefficient along the first friction direction for the chassis"),
        
        DeclareLaunchArgument(
            "chassis_mu2",
            default_value="0.1",
            description="Sets friction coefficient along the second friction direction for the chassis"),
        
        DeclareLaunchArgument(
            "chassis_kp",
            default_value="1000.0",
            description="Sets the stiffness coefficient for the chassis, which is used to simulate the elastic behavior in a collision"),
        
        DeclareLaunchArgument(
            "chassis_kd",
            default_value="0.05",
            description="Sets the damping coefficient for the chassis, which is used to simulate the energy dissipation in a collision"),
        
        DeclareLaunchArgument(
            "wheel_mu1",
            default_value="10",
            description="Sets friction coefficient along the first friction direction for the wheels"),
        
        DeclareLaunchArgument(
            "wheel_mu2",
            default_value="10",
            description="Sets friction coefficient along the second friction direction for the wheels"),
        
        DeclareLaunchArgument(
            "wheel_kp",
            default_value="1000",
            description="Sets the stiffness coefficient for the wheels, which is used to simulate the elastic behavior in a collision"),
        
        DeclareLaunchArgument(
            "wheel_kd",
            default_value="0.05",
            description="Sets the damping coefficient for the wheels, which is used to simulate the energy dissipation in a collision"),
        
        DeclareLaunchArgument(
            "wheel_joint_dumping",
            default_value="0.1",
            description="Sets the damping coefficient for the wheel joints, which is used to simulate the energy dissipation in it"),
        
        DeclareLaunchArgument(
            "wheel_joint_friction",
            default_value="0.1",
            description="Sets friction coefficient for the wheel joints"),

        DeclareLaunchArgument(
            "chassis_mx",
            default_value="0.000001",
            description="x coordinate of the center of mass"),

        DeclareLaunchArgument(
            "chassis_my",
            default_value="0.000109",
            description="y coordinate of the center of mass"),

        DeclareLaunchArgument(
            "chassis_mz",
            default_value="0.011152",
            description="y coordinate of the center of mass"),

        DeclareLaunchArgument(
            "chassis_ixx",
            default_value = "1",
            description = "chassis inertia - ixx"),
            
        DeclareLaunchArgument(
            "chassis_ixy",
            default_value = "1",
            description = "chassis inertia - ixy"),
            
        DeclareLaunchArgument(
            "chassis_ixz",
            default_value = "1",
            description = "chassis inertia - ixz"),
            
        DeclareLaunchArgument(
            "chassis_iyy",
            default_value = "1",
            description = "chassis inertia - iyy"),
            
        DeclareLaunchArgument(
            "chassis_iyz",
            default_value = "1",
            description = "chassis inertia - iyz"),
            
        DeclareLaunchArgument(
            "chassis_izz",
            default_value = "1",
            description = "chassis inertia - izz"),
            
        DeclareLaunchArgument(
            "wheels_ixx",
            default_value = "1",
            description = "wheels inertia - ixx",),
            
        DeclareLaunchArgument(
            "wheels_ixy",
            default_value = "1",
            description = "wheels inertia - ixy",),
            
        DeclareLaunchArgument(
            "wheels_ixz",
            default_value = "1",
            description = "wheels inertia - ixz",),
            
        DeclareLaunchArgument(
            "wheels_iyy",
            default_value = "1",
            description = "wheels inertia - iyy",),
            
        DeclareLaunchArgument(
            "wheels_iyz",
            default_value = "1",
            description = "wheels inertia - iyz",),
            
        DeclareLaunchArgument(
            "wheels_izz",
            default_value = "1",
            description = "wheels inertia - izz",),

        OpaqueFunction(function=launch_setup)
    ])
