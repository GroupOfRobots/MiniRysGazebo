from http.server import executable
from modulefinder import packagePathMap
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package = "minirys_sim_pkg",
            executable = "cmd_pub_test.py",
            name = "steering_miniRys_node"
        )
    ])