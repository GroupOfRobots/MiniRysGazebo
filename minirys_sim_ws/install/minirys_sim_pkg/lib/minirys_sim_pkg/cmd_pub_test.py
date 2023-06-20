#! /usr/bin/env python3


from email.policy import default
import rclpy
from rclpy.node import Node

import os
from geometry_msgs.msg import Twist, Point
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64
import sys, select, termios, tty
from minirys_sim_pkg.msg import Orders



class CmdPublisher(Node):
    def __init__(self):
        super().__init__("steering_miniRys_node")

        self.publish_orders = self.create_publisher(Orders, "Orders_topic", 10)
        self.timer = self.create_timer(0.0008, self.publish_odom)
        self.orders = Orders()

    def subscriber_callback(self): 
        print("callback")
        print(Odometry.pose.twist.velocity.x)

    def publish_odom(self):

        sys.stdout.flush()
        tty.setraw(sys.stdin.fileno())

        command = sys.stdin.read(1)

        if command == 'w':
            self.orders.move = float(-0.5)
            self.publish_orders.publish(self.orders)
            return
        elif command == 's':
            self.orders.move = float(0.5)
            self.publish_orders.publish(self.orders)              
            return
        elif command == 'a':
            self.orders.rotate = float(-0.5)
            self.publish_orders.publish(self.orders)                
            return
        elif command == 'd':
            self.orders.rotate = float(0.5)
            self.publish_orders.publish(self.orders)               
            return
        elif command == '1':
            self.orders.control_flag = 0
            self.publish_orders.publish(self.orders)               
            return
        elif command == '2':
            self.orders.control_flag = 1
            self.publish_orders.publish(self.orders)               
            return
        self.orders.move = float(0)
        self.orders.rotate = float(0)
        self.publish_orders.publish(self.orders) 



def main():
    rclpy.init()
    
    my_pub = CmdPublisher()
    print("Publisher is running ( PID:", os.getpid(),")...")
    print("Use 'WSAD' too steer the robot")

    try:
        rclpy.spin(my_pub)
        sys.stdout.flush()
    except KeyboardInterrupt:
        my_pub.destroy_node()
        rclpy.shutdown()



if __name__ == '__main__':
    main()