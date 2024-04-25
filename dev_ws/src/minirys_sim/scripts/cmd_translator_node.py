#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from geometry_msgs.msg import Twist
from minirys_msgs.msg import MotorCommand

class CmdTranslatorNode(Node):
    def __init__(self):
        super().__init__('cmd_translator')
        self.subscriber = self.create_subscription(
            MotorCommand,
            'motor_command',
            self.motor_command_callback,
            10
        )
        self.publisher = self.create_publisher(Twist, 'cmd', 10)

    def motor_command_callback(self, msg):
        twist = Twist()
        twist.linear.x = (msg.speed_l + msg.speed_r) / 2
        twist.angular.z = (msg.speed_r - msg.speed_l) / 2
        if msg.enable:
            self.publisher.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = CmdTranslatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
