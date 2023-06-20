import rclpy
from rclpy.node import Node
import sys
import select
import termios

import os
from pathlib import Path
from launch import LaunchDescription
from launch.launch_service import LaunchService
from launch_ros.actions import Node as LaunchNode
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory


class SpawnEntity(Node):
    def __init__(self):
        super().__init__('spawn_entity')
        self.get_logger().info("Press 'L' key to spawn robot nodes in new namespaces.")
        
                    
        
                            
                    
    def spawn_nodes_in_namespace(self, namespace):
        package_name = 'minirys_sim'
    
        spawn_x = '-1.0'
        spawn_y = '-3.0'
        spawn_z = '0.0'
        spawn_roll = '0.0'
        spawn_pitch = '0.0'
        spawn_yaw = '1.5'

        LaunchDescription([
            IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory(package_name),'launch','rsp.launch.py')]), 
                launch_arguments={'use_sim_time': 'true', 
                                'camera': 'true',
                                'horizontal_sensor_visibility': 'false',
                                'vertical_sensor_visibility': 'false',
                                'all_sensor_visibility': 'false',
                                'none_sensor_visibility': 'true',
                                'TOF_FOV_angle': '0.08',
                                'TOF_range': '5'
                                }.items()

            ),
            LaunchNode(
                package='gazebo_ros', 
                executable='spawn_entity.py',
                arguments=[
                            '-topic', 'robot_description',
                            '-entity', 'rys',
                            '-x', spawn_x,
                            '-y', spawn_y,
                            '-z', spawn_z,
                            '-R', spawn_roll,
                            '-P', spawn_pitch,
                            '-Y', spawn_yaw
                            ],
                output='screen'),
            LaunchNode(
                package='controller_manager',
                executable='spawner.py',
                arguments=["diff_controler"],
                namespace=namespace,
                output='screen',
                parameters=[],
            ),
            LaunchNode(
                package='controller_manager',
                executable='spawner.py',
                arguments=["joint_broadcaster"],
                namespace=namespace,
                output='screen',
                parameters=[],
            )
        ])


def main():
    rclpy.init()
    node = SpawnEntity()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: 
        node.destroy_node() 
        rclpy.shutdown()

if __name__ == '__main__':
    main()