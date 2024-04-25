import logging
import launch
import time
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, ExecuteProcess
from launch.substitutions import LaunchConfiguration, Command
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def kill_gazebo(context):
    """Kill any running gazebo processes to avoid address conflicts."""
    return [
        ExecuteProcess(
            cmd=["killall", "-9", "gazebo"],
            name="kill_gazebo",
            output="screen"
        )
    ]

def kill_gazebo(context):
    """Kill any running gzserver processes to avoid address conflicts."""
    return [
        ExecuteProcess(
            cmd=["killall", "-9", "gzserver"],
            name="kill_gzserver",
            output="screen"
        )
    ]

def start_gazebo(context):
    world_name = LaunchConfiguration('world_name')
    world_package_name = 'gazebo_minirys_sim'
    world_package_path = get_package_share_directory(world_package_name)

    world_name_converted = world_name.perform(context)
    world_path = os.path.join(world_package_path, 'worlds', world_name_converted)
    print(f"\n{world_path}\n")

    return [
        ExecuteProcess(
            cmd=['gazebo', '--verbose', world_path, '-s', 'libgazebo_ros_factory.so'],
            output='screen'
        )
    ]

def generate_launch_description():
    """
    Creates the simulation world.
    Sets up the Gazebo launch description using the specified world file,
    ensuring that any existing Gazebo processes are terminated first to avoid port conflicts.
    # """
    launch.logging.get_logger().setLevel(logging.WARNING)
    return LaunchDescription([
        DeclareLaunchArgument(
            'world_name',
            default_value='empty.world',
            description='Name of the world file to load'
        ),
        # OpaqueFunction(function=kill_gazebo),
        OpaqueFunction(function=start_gazebo)
    ])