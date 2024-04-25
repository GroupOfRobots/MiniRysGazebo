#!/usr/bin/env python3
import rclpy
import os
from rclpy.node import Node
from nav_msgs.msg import Odometry

class DataLoggerNode(Node):

    def __init__(self):
        super().__init__('data_logger_node')
        self.subscription = self.create_subscription(
            Odometry,
            '/robot1/odom',
            self.topic_callback,
            10)
        self.subscription

        current_dir = os.path.dirname(os.path.realpath(__file__))
        output_file_path = os.path.join(current_dir, 'output2.txt')
        
        self.file = open(output_file_path, 'a')

    def topic_callback(self, msg):
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation

        linear_velocity = msg.twist.twist.linear
        angular_velocity = msg.twist.twist.angular

        self.get_logger().info(
            f'Position: ({position.x}, {position.y}, {position.z}), '
            f'Orientation: ({orientation.x}, {orientation.y}, {orientation.z}, {orientation.w}), '
            f'Linear Velocity: ({linear_velocity.x}, {linear_velocity.y}, {linear_velocity.z}), '
            f'Angular Velocity: ({angular_velocity.x}, {angular_velocity.y}, {angular_velocity.z})'
        )

        self.file.write(
            f'{position.x}, {position.y}, {position.z}, '
            f'{orientation.x}, {orientation.y}, {orientation.z}, {orientation.w}, '
            f'{linear_velocity.x}, {linear_velocity.y}, {linear_velocity.z}, '
            f'{angular_velocity.x}, {angular_velocity.y}, {angular_velocity.z}\n'
        )
    def __del__(self):
        self.file.close()


def main(args=None):
    rclpy.init(args=args)
    data_logger_node = DataLoggerNode()
    
    try:
        rclpy.spin(data_logger_node)
    except KeyboardInterrupt:
        pass
    finally:
        data_logger_node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()