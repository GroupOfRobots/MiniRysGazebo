#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from std_msgs.msg import Header
from minirys_msgs.msg import AngularPose
import math

def euler_from_quaternion(x, y, z, w):
    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)

    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)

    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z

class OdomTranslatorNode(Node):
    def __init__(self):
        super().__init__('odom_translator')
        self.subscription = self.create_subscription(
            Odometry,
            'robot1/odom',
            self.odom_callback,
            10
        )
        self.publisher = self.create_publisher(AngularPose, 'robot1/internal/angular_pose', 10)

    def odom_callback(self, msg):
        angular_pose = AngularPose()
        angular_pose.header = msg.header
        
        orientation_q = msg.pose.pose.orientation
        _, pitch_y, _ = euler_from_quaternion(
            orientation_q.x,
            orientation_q.y,
            orientation_q.z,
            orientation_q.w
        )
        tilt_z = pitch_y
        angular_pose.angular_position = tilt_z  # yaw in radians
        angular_pose.angular_velocity = msg.twist.twist.angular.z  # angular velocity in radians per second
        
        self.publisher.publish(angular_pose)

def main(args=None):
    rclpy.init(args=args)
    node = OdomTranslatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
