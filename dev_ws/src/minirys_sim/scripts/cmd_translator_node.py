#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool
from std_msgs.msg import Header
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from minirys_msgs.msg import MotorCommand, AngularPose
import math
import os

def euler_from_quaternion(x, y, z, w):
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)

    t2 = +2.0 * (w * y - z * x)
    pitch_y = math.asin(max(-1.0, min(1.0, t2)))

    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z

class CmdTranslatorNode(Node):
    def __init__(self):
        super().__init__('cmd_translator')

        self.angular_pose_sub = self.create_subscription(
            AngularPose,
            'internal/angular_pose',
            self.angular_pose_callback,
            10
        )
        self.subscriber = self.create_subscription(
            MotorCommand,
            'internal/motor_command',
            self.motor_command_callback,
            10
        )
        self.subscriber_odom = self.create_subscription(
            Odometry,
            'odom',
            self.balancing,
            10
        )
        self.publisher = self.create_publisher(Twist, 'cmd', 10)
        self.subscriber_cmd = self.create_subscription(
            Twist,
            'cmd_vel',
            self.cmd_callback,
            10
        )
        self.publisher_cmd_vel = self.create_publisher(Twist, 'cmd', 10)
        self.balance_sub = self.create_subscription(
            Bool,
            'balance_mode',
            self.balance_callback,
            10
        )

        self.balancing_enabled = False
        self.critical_speed_limit_flag = int(0)
        self.switch_flag = int(0)
        self.counter = int(0)

        self.current_tilt = float(0.0)
        self.last_x = float(0.0)
        self.last_y = float(0.0)
        self.last_angle = float(0.0)
        self.last_vel = float(0.0)
        self.last_new_vel = float(0.0)
        self.last_error_PID2_1 = float(0.0)
        self.last_error_PID2_2 = float(0.0)
        self.last_tilt = float(0.0)
        self.set_vel = float(0.0)
        self.last_rotate = float(0.0)

        self.K2 = float(0.0)
        self.I2 = float(0.0)
        self.Td2 = float(0.0)

        self.desired_set_vel = float(0.0)
        self.ramp_rate = float(0.015)
        self.new_set_vel = float(0.0)


    def angular_pose_callback(self, msg):
        self.current_tilt = msg.angular_position
          
    def balance_callback(self, msg):
        self.balancing_enabled = msg.data
        if self.balancing_enabled:
            self.update_pid_values()  # Update PID values from file
            self.get_logger().info("Balancing mode activated")
        else:
            self.get_logger().info("Balancing mode deactivated")
            twist = Twist()
            twist.linear.x = 0.0
            twist.angular.z = 0.0
            self.publisher_cmd_vel.publish(twist)

    def update_pid_values(self):
        script_dir = os.path.abspath(__file__).replace("install/minirys_sim/lib/minirys_sim/cmd_translator_node.py", "src/minirys_sim/scripts")
        pid_file = os.path.join(script_dir, 'PID.txt')
        try:
            with open(pid_file, 'r') as file:
                lines = file.readlines()
                self.K2 = float(lines[0].strip())
                self.I2 = float(lines[1].strip())
                self.Td2 = float(lines[2].strip())
                self.get_logger().info(f"Updated PID values: K2={self.K2}, I2={self.I2}, Td2={self.Td2}")
        except Exception as e:
            self.get_logger().error(f"Failed to read PID values from file: {str(e)}")


    def motor_command_callback(self, msg):
        if not self.balancing_enabled:
            twist = Twist()
            twist.linear.x = -(msg.speed_l - msg.speed_r) / 2
            twist.angular.z = (msg.speed_r + msg.speed_l) / 2
            self.publisher.publish(twist)

    def cmd_callback(self, msg):
        self.new_set_vel = -msg.linear.y
        self.last_rotate = msg.angular.z
        if not self.balancing_enabled:
            twist = Twist()
            twist.linear.x = float(-msg.linear.y)
            twist.angular.z = float(msg.angular.z)
            self.publisher_cmd_vel.publish(twist)


    def balancing(self, msg):
        # Balancing mode calculations
        if self.balancing_enabled and self.K2 != 0 and self.I2 != 0 and self.Td2 != 0:
            if abs(self.set_vel - self.new_set_vel) > self.ramp_rate:
                self.get_logger().info(f"{self.set_vel}")
                if self.set_vel < self.new_set_vel:
                    self.set_vel += self.ramp_rate
                if self.set_vel > self.new_set_vel:
                    self.set_vel -= self.ramp_rate    
            else:
                self.set_vel = self.new_set_vel
            
            
            # Constants for PID 
            K2 = self.K2
            I2 = self.I2
            Td2 = self.Td2
            

            T = 0.001

            pose_msg = msg.pose.pose.position.x
            vel = msg.twist.twist.linear.x
            angle_vel = msg.twist.twist.angular.z
            actual_x = msg.pose.pose.position.x
            actual_y = msg.pose.pose.position.y
            x_quat = msg.pose.pose.orientation.x
            y_quat = msg.pose.pose.orientation.y
            z_quat = msg.pose.pose.orientation.z
            w_quat = msg.pose.pose.orientation.w 
            M = euler_from_quaternion(x_quat, y_quat, z_quat, w_quat)
            actual_angle = M[1]

            critical_max_vel = 30
            if vel > critical_max_vel or angle_vel > critical_max_vel or vel < -critical_max_vel or angle_vel < -critical_max_vel:
                twist.linear.x = float(0.0)
                twist.angular.z = float(0.0)
                self.publisher_cmd_vel.publish(twist)
                self.critical_speed_limit_flag = 1
                return
            else:
                self.critical_speed_limit_flag = 0

            tilt = self.set_vel


            # PID error calculation
            error_PID2 = tilt - actual_angle - vel
            r0_angle = K2*(1 + (T/(2*I2)) + Td2/T)
            r1_angle = K2*((T/(2*I2)) - 1 - (2*Td2)/T)      
            r2_angle = K2*Td2/T

            new_vel = self.last_new_vel + r0_angle * error_PID2 + r1_angle * self.last_error_PID2_1 + r2_angle * self.last_error_PID2_2
            
            # Velocity clamping
            max_vel = 10
            new_vel = max(-max_vel, min(max_vel, new_vel))

            self.last_new_vel = new_vel
            self.last_x = actual_x
            self.last_y = actual_y
            self.last_angle = M[1]
            self.last_vel = vel
            self.last_error_PID2_2 = self.last_error_PID2_1
            self.last_error_PID2_1 = error_PID2
            self.last_tilt = tilt

            twist = Twist()
            twist.linear.x = -float(new_vel)
            twist.angular.z = float(self.last_rotate)

            # print("Balancing active: New velocity set to", new_vel)
            self.publisher_cmd_vel.publish(twist)

        
        

def main(args=None):
    rclpy.init(args=args)
    node = CmdTranslatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
