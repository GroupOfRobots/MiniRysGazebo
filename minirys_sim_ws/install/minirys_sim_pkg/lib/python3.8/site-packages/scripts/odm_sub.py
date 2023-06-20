#! /usr/bin/env python3

from types import new_class
import rclpy
from rclpy.node import Node
import math
from geometry_msgs.msg import Twist, Point, Quaternion
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64
import sys, select, termios, tty
from minirys_sim_pkg.msg import Orders

M = [float(0),float(0),float(0)]
error_PID1 = float(0)
last_error_PID1_1 = float(0)
last_error_PID1_2 = float(0)
error_PID2 = float(0)
last_error_PID2_1 = float(0)
last_error_PID2_2 = float(0)

new_vel = float(0)
last_vel = float(0)

vel_x = float(0)
vel_y = float(0)
vel = float(0)
angle_vel = float(0)
vel_correction = float(0)

counter = 0
target_angle = float(0)
last_control = float(0)

last_x = float(0)
last_y = float(0)
last_angle = float(0)
last_new_vel = float(0)

actual_x = float(0)
actual_y = float(0)
actual_angle = float(0)
set_vel = float(0)
rotate = float(0)
tilt = float(0)
last_tilt  = float(0)
switch_flag = int(0)

max_vel = float(0)
max_control = float(0)

K1 = float(0)
I1 = float(0)
Td1 = float(0)

K2 = float(0)
I2 = float(0)
Td2 = float(0)

T = float(0)
control_flag = int(0)


def euler_from_quaternion(x, y, z, w):
  t0 = +2.0 * (w * x + y * z)
  t1 = +1.0 - 2.0 * (x * x + y * y)
  roll_x = math.atan2(t0, t1)

  t2 = +2.0 * (w * y - z * x)
  t2 +1.0 if t2 > +1.0 else t2
  t2 -1.0 if t2 < -1.0 else t2
  pitch_y = math.asin(t2)

  t3 = +2.0 * (w * z + x * y)
  t4 = +1.0 - 2.0 * (y * y + z * z)
  yaw_z = math.atan2(t3, t4)

  return roll_x, pitch_y, yaw_z


class Balancing(Node):
    def __init__(self):
      super().__init__("calculate_speed_node")

      self.sub = self.create_subscription(Odometry, "/MiniRysv4_1/odom", self.sub_callback, 10)
      self.subscribe_orders = self.create_subscription(Orders, "Orders_topic", self.orders_callback, 10)
      self.pub = self.create_publisher(Twist, "/MiniRysv4_1/cmd", 10)
      self.move = Twist()
      self.orders = Orders()

    def orders_callback(self, msg):
      global set_vel, rotate, control_flag
      set_vel = msg.move
      rotate = msg.rotate
      control_flag = msg.control_flag
      print("HORIZONTAL MODE")
      print("New_orders: ")
      print("   set_vel:    ", set_vel)
      print("   rotation:   ", rotate)

    def sub_callback(self, msg):
      global error_PID1,last_error_PID1_1,last_error_PID1_2,M,new_vel,counter,target_angle,last_x,actual_x,last_vel,vel_x,vel_y,last_control
      global error_PID2,last_error_PID2_1,last_error_PID2_2,actual_angle,last_angle,vel_correction,angle_vel,actual_y,last_y,vel,set_vel
      global K1,I1,Td1,K2,I2,Td2,T,max_vel,max_control,last_new_vel, set_vel, rotate, tilt, control_flag,last_tilt, switch_flag
      
      # CONTROL_FLAG = 0 => HORIZONTAL MODE
      # CONTROL_FLAG = 1 => VERTICAL MODE
      

      if control_flag == 0:
        
        new_vel = set_vel
        self.move.linear.x = -float(new_vel)
        self.move.angular.z = float(rotate)
        self.pub.publish(self.move)
        return

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

      #set_vel = 0.5
      #rotate = 0.5

      # K1 = 0     #  .65  
      # I1 = 10000000000000000000000     #  .5
      # Td1 = 0     #  .0002
      
      K2 = 0.715     # 0.715 
      I2 = 0.02      # 0.052
      Td2 = 0.00176   # 0.00176

      T = 0.001

      tilt = -set_vel
      if abs(last_tilt - tilt) == 1:
          switch_flag = 1
      elif counter > 70:
        counter = 0
        switch_flag = 0
        
      
      if switch_flag == 1:
        counter = counter + 1
        tilt = -set_vel/4

      # clip_angle = 0.00#3
      # clip_vel = 0.00#6

      # if(-clip_angle < angle_vel < clip_angle):
      #   angle_vel = 0
      # if(-clip_vel < vel < clip_vel):
      #   vel = 0

      if(-1.458 > actual_angle):
        actual_angle = -1.458
      elif(actual_angle > 1.458):
        actual_angle = 1.458
      

      # vel_correction =  vel + angle_vel

      # error_PID1 = set_vel - vel_correction
      # r0_speed = K1*(1 + (T/(2*I1)) + Td1/T)
      # r1_speed = K1*((T/(2*I1)) - 1 - (2*Td1)/T)
      # r2_speed = K1*Td1/T

      # control = last_control + r0_speed * error_PID1 + r1_speed * last_error_PID1_1 + r2_speed * last_error_PID1_2
      
      # if set_vel == 0:      
      #   control = 0

      # max_control = 5
      # if(control > max_control):
      #   control = max_control
      # elif (control < -max_control):
      #   control = -max_control

      error_PID2 = tilt - actual_angle - vel
      r0_angle = K2*(1 + (T/(2*I2)) + Td2/T)
      r1_angle = K2*((T/(2*I2)) - 1 - (2*Td2)/T)      
      r2_angle = K2*Td2/T

      new_vel = last_new_vel + r0_angle * error_PID2 + r1_angle * last_error_PID2_1 + r2_angle * last_error_PID2_2

      max_vel = 7
      if(new_vel > max_vel):
        new_vel = max_vel
      elif (new_vel < -max_vel):
        new_vel = -max_vel

        
      
      # if(-0.03 < actual_angle < 0.03):
      #   new_vel = 0

      print("VERTICAL MODE")
      print("Angles::\n  roll_x: ",M[0],"\n  pich_y: ",actual_angle,"\n  yaw_z: ",M[2],"\n")
      # print("control =", last_control," + ",r0_speed, "*", error_PID1," + ",r1_speed, "*",last_error_PID1_1," + ",r2_speed,"*",last_error_PID1_2)
      #print("control: ",control)
      print("new_vel =", last_vel," + ",r0_angle,"*", error_PID2," + ",r1_angle,"*",last_error_PID2_1," + ",r2_angle,"*",last_error_PID2_2)
      print("new_vel: ", new_vel)
      print("vel_correction: ", vel_correction)
      print("actual_vel: ",vel )
      print("angular_vel: ",angle_vel)
      print("tilt: ",tilt,"last_tilt: ",last_tilt, "switch_flag: ",switch_flag, "counter: ",counter,  "\n")

      last_new_vel = new_vel
      #last_control = control
      last_x = actual_x
      last_y = actual_y
      last_angle = M[1]
      last_vel = vel
      last_error_PID1_2 = last_error_PID1_1
      last_error_PID1_1 = error_PID1
      last_error_PID2_2 = last_error_PID2_1
      last_error_PID2_1 = error_PID2
      self.move.linear.x = float(new_vel)
      self.move.angular.z = float(rotate)
      last_tilt = tilt
      print("error PID1: ",error_PID1)
      print("error PID2: ",error_PID2, "\n")
      
      #print("control: ",control)
      print("set_vel: ",set_vel)
      print("rotate: ",rotate, "\n")
      print("new_vel: ",new_vel,"\n")


      self.pub.publish(self.move)

        # print("Current speed is: " + str(current_speed)+ " [m/s]") #that only prints calculating resoults

        # print(self.get_parameter("wheel_radius").get_parameter_value())  # to je print parametrów najelepiej skomentować pozostałe rzeczy w tej funkcji
        # funkcja "get_parameter(<parameter_name>)" wyciąga "parameter object" jeżeli chcemy jego wartość to musimy użyć "get_parameter_value()" <- to jest metoda klasy
        # samo to daje nam w terminalu "parameter value message type" co jest długie i mało czytelne. TYPE = 3 oznacza tam że to jest double ***




def main():
    rclpy.init()
    
    my_pubsub = Balancing()

    #pose = Pose()
    #pose.x = odom.pose.pose.position.x
    #pose.y = odom.pose.pose.position.y
    #pose.theta = tf.transformations.euler_from_quaternion([odom.pose.pose.orientation.x,odom.pose.pose.orientation.y,odom.pose.pose.orientation.z,odom.pose.pose.orientation.w])[2]
    print("Process has started...")
    
    try:
        rclpy.spin(my_pubsub)
    except KeyboardInterrupt:
        my_pubsub.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()