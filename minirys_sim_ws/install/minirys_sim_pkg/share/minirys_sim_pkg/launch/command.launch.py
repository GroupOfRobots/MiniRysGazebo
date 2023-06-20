from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = "minirys_sim_pkg",
            executable = "odm_sub.py",
            name = "calculate_speed_node"
        )
    ])