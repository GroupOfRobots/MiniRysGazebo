#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import math
import re
import os
from functools import partial
from datetime import datetime
from rosidl_runtime_py.convert import message_to_yaml

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

class OdomPrinterNode(Node):
    def __init__(self):
        super().__init__("robots_monitor_node")
        self.subscriber_list = {}
        self.discover_robots()

        current_dir = os.path.dirname(os.path.realpath(__file__))
        saved_data_dir = os.path.join(current_dir, 'saved_data')
        os.makedirs(saved_data_dir, exist_ok=True)

        num_robots = len(self.subscriber_list)
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        filename = f'{num_robots}_robots_test_{timestamp}.txt'
        self.file_path = os.path.join(saved_data_dir, filename)
        self.file = open(self.file_path, 'a')
        self.get_logger().info(f'Logging data to {self.file_path}')

        self.falling_start_time = {}
        self.falling_end_time = {}
        self.is_falling = {} 


    def discover_robots(self):
        topics_info = self.get_topic_names_and_types()
        robot_odom_topics = [topic for topic, types in topics_info if '/odom' in topic and 'nav_msgs/msg/Odometry' in types]

        for topic in robot_odom_topics:
            robot_id_match = re.search(r"/robot(\d+)/odom", topic)
            if robot_id_match:
                robot_id = robot_id_match.group(1)
                if robot_id not in self.subscriber_list:
                    callback_with_topic = partial(self.odom_callback, topic_name=topic)
                    sub = self.create_subscription(Odometry, topic, callback_with_topic, 10)
                    self.subscriber_list[robot_id] = sub
                    self.get_logger().info(f"Discovered robot: {robot_id}")

    def odom_callback(self, msg, topic_name):
        robot_id = self.get_robot_id_from_topic_name(topic_name)
        position_x = msg.pose.pose.position.x
        velocity_x = msg.twist.twist.linear.x
        angular_velocity_z = msg.twist.twist.angular.z

        orientation_q = msg.pose.pose.orientation
        roll_x, pitch_y, yaw_z = euler_from_quaternion(orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w)
        tilt_y = pitch_y 
        current_time = self.get_clock().now().nanoseconds

        # Falling time monitor
        if tilt_y > 0.349 and tilt_y < 0.549 and not self.is_falling.get(robot_id, False):
            self.falling_start_time[robot_id] = self.get_clock().now()
            self.is_falling[robot_id] = True

        if tilt_y > 1.221 and tilt_y < 1.422 and self.is_falling.get(robot_id, False):
            self.falling_end_time[robot_id] = self.get_clock().now()
            self.is_falling[robot_id] = False
            falling_duration = self.falling_end_time[robot_id] - self.falling_start_time[robot_id]
            self.get_logger().info(f"Robot{robot_id} falling on the face time: {falling_duration.nanoseconds / 1e9} seconds")
        
        if tilt_y < -0.349 and tilt_y > -0.549 and not self.is_falling.get(robot_id, False):
            self.falling_start_time[robot_id] = self.get_clock().now()
            self.is_falling[robot_id] = True

        if tilt_y < -1.221 and tilt_y > -1.422 and self.is_falling.get(robot_id, False):
            self.falling_end_time[robot_id] = self.get_clock().now()
            self.is_falling[robot_id] = False
            falling_duration = self.falling_end_time[robot_id] - self.falling_start_time[robot_id]
            self.get_logger().info(f"Robot{robot_id} falling on the back time: {falling_duration.nanoseconds / 1e9} seconds")    

        self.file.write(f"Robot{robot_id}: Position X: {position_x}, Velocity X: {velocity_x}, Angular Velocity Z: {angular_velocity_z}, Tilt Y: {tilt_y}, Time: {current_time}\n")

    def get_robot_id_from_topic_name(self, topic_name):
        robot_id_match = re.search(r"/robot(\d+)/odom", topic_name)
        if robot_id_match:
            return robot_id_match.group(1)
        return None
    
    def __del__(self):
        if self.file:
            self.file.close()

def main(args=None):
    rclpy.init(args=args)
    node = OdomPrinterNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
