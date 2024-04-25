#!/usr/bin/env python3
import os
import launch
from launch import LaunchDescription
from launch_ros.actions import Node
import xml.etree.ElementTree as ET

def generate_launch_description():
    package_path = os.path.abspath(__file__).replace("launch/command_groups.launch.py", "")
    config_file_path = f"{package_path}config/drive_config.xml"
    tree = ET.parse(config_file_path)
    root = tree.getroot()

    nodes = []

    for group in root.findall('group'):
        group_name = group.get('name')
        mode = int(group.find('mode').text)
        
        if mode == 2:
            robots = group.find('robots').text.split(',')
            print(f"[INFO]: Configuration:\nRobots: {robots}\nMode: {mode}\n")
            for robot in robots:
                cmd_translator_node = Node(
                    package='minirys_sim',
                    executable='cmd_translator_node.py',
                    namespace=robot,  
                    name='cmd_translator',
                    parameters=[],
                    output='screen'
                )
                odom_translator_node = Node(
                    package='minirys_sim',
                    executable='odom_translator_node.py',
                    namespace=robot,
                    name='odom_translator',
                    parameters=[],
                    output='screen'
                )
                nodes.append(cmd_translator_node)
                nodes.append(odom_translator_node)

        else:
            robots = group.find('robots').text
            sequence = group.find('sequence').text
            loop = int(group.find('loop').text)

            node = Node(
                package='minirys_sim',
                executable='relay_node.py',
                name=group_name,
                parameters=[
                    {'robots': robots},
                    {'mode': mode},
                    {'sequence': sequence},
                    {'loop': loop},
                    {'group_name': group_name},
                ],
                output='screen'
            )
            nodes.append(node)

    return LaunchDescription(nodes)
