#!/usr/bin/env python3
import os
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from rclpy.serialization import serialize_message
from rosidl_runtime_py.utilities import get_message
from rosidl_runtime_py.convert import message_to_yaml
from datetime import datetime
# from minirys_msgs.msg import AngularPose # need to source the workspace for it to work

class DataLoggerNode(Node):
    def __init__(self):
        super().__init__('data_logger_node')
        self.subscription = self.create_subscription(
            Odometry, # TO CHANGE (example: AngularPose)
            '/robot1/odom', # TO CHANGE (example: /internal/angular_pose)
            self.topic_callback,
            10)
        self.subscription

        current_dir = os.path.dirname(os.path.realpath(__file__))

        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')

        filename = f'Robot1_af.txt' # [!!!] TO CHANGE (example: f'Test41_{timestamp}.txt')

        output_file_path = os.path.join(current_dir, filename)
        
        self.file = open(output_file_path, 'a')
        self.get_logger().info(f'Logging data to {output_file_path}')


    def topic_callback(self, msg):
        # if self.count > 5:
        msg_yaml = message_to_yaml(msg)
        self.get_logger().info(f'Receiving data: \n{msg_yaml}')
        self.file.write(msg_yaml + '\n')
        #     self.count = 0
        # else:
        #     self.count += 1 
        

    def __del__(self):
        if self.file:
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
