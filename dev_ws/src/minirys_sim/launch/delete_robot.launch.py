#!/usr/bin/env python3
import launch
import logging
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable, OpaqueFunction
from launch.substitutions import LaunchConfiguration

def launch_setup(context):
    robot_name = LaunchConfiguration('robot_name')
    print(f"[SIM INFO] 03 From {robot_name.perform(context)}: AAAAAAaaaaaAAAaaaa...")
    kill = Node(
            package='minirys_sim',
            executable='delete_robot.py',
            arguments=[LaunchConfiguration('robot_name')],
            name='delete_robot_node',
            namespace=robot_name
        )
    return [ 
        kill
    ]

def generate_launch_description():
    launch.logging.get_logger().setLevel(logging.WARNING)
   
    return LaunchDescription([
        DeclareLaunchArgument(
            'robot_name',
            default_value='robot3',  # Default robot name
            description='Name of the robot to delete'),
        OpaqueFunction(function=launch_setup)
    ])
