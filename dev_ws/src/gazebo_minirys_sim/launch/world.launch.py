import launch
import logging
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def gazebo(context):
    world_name = LaunchConfiguration('world_name')

    world_package_name = 'gazebo_minirys_sim'
    world_package_path = get_package_share_directory(world_package_name)

    world_name_evaluated = world_name.perform(context)
    world_path = os.path.join(world_package_path, 'worlds', world_name_evaluated)
    print(f"\n{world_path}\n")

    gazebo_description = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(
                get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')),
                launch_arguments={'world': world_path}.items()
    )

    return [gazebo_description]

def generate_launch_description():
    """
    Creates the simulation world.
    Sets up the Gazebo launch description using the room.world file.
    
    Launch Argument:
        world_name: The name of the world file to be loaded.

    Returns:
        List[IncludeLaunchDescription]: A list containing the Launch Argument and the Gazebo
                                        launch description for the given world.
    """

    launch.logging.get_logger().setLevel(logging.WARNING)
    return LaunchDescription([
        DeclareLaunchArgument(
        'world_name',
        default_value='empty.world',
        description='Name of the world file to load'
        ),
        OpaqueFunction(function=gazebo)
    ])