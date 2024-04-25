#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
import math
import time

def quaternion_to_euler(x, y, z, w):
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


class DataLoggerNode(Node):
    def __init__(self):
        super().__init__('data_logger_node')
        self.subscription = self.create_subscription(
            Odometry,
            '/robot1/odom',
            self.topic_callback,
            10)
        self.start_time = None
        self.end_time = None
        self.time_record_flag = False

    def topic_callback(self, msg):
        orientation_q = msg.pose.pose.orientation
        _, pitch, _ = quaternion_to_euler(
            orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w)
        pitch = abs(pitch)
        
        if pitch > 0.34906585 and pitch < 0.54906585 and self.time_record_flag == False:
            self.start_time = time.time()
            print("Start")
            self.time_record_flag = True

        if pitch > 1.22173048 and pitch < 1.42173048 and self.time_record_flag == True:
            print("Stop")
            self.end_time = time.time()
            time_diff = self.end_time - self.start_time
            self.get_logger().info(f'Rising time: {time_diff} seconds')
            self.time_record_flag = False
            

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