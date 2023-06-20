#!/usr/bin/env python3
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='minirys_sim',
            executable='robot_menager_node.py',
            name='robot_menager_node',
            output='screen',
        ),
    ])
