#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from minirys_sim.srv import OdomService, CloseMenager
import math
from gazebo_msgs.srv import GetModelList
import re

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

class OdomServiceNode(Node):
    def __init__(self):
        super().__init__('robot_mentager_node')
        self.OdomService = self.create_service(OdomService, 'get_odom', self.get_odom_callback)
        self.odom_data = {}  # recent odom message
    
        self.CloseMenager = self.create_service(CloseMenager, 'close_menager', self.close_menager_callback)
        self._shutdown_requested = False

        self.client = self.create_client(GetModelList, '/get_model_list')
        self.timer = self.create_timer(10.0, self.get_model_list_callback)
        self.robot_namespaces = []
        self.odom_subscriptions = {}
    
    def close_menager_callback(self, request, response):
        self.get_logger().info('Shutdown requested')
        self._shutdown_requested = True
        response.success = True
        return response

    def get_model_list_callback(self):
        request = GetModelList.Request()
        future = self.client.call_async(request)
        future.add_done_callback(self.update_robot_namespaces_callback)

    def update_robot_namespaces_callback(self, future):
        try:
            response = future.result()
            new_robot_namespaces = [model_name for model_name in response.model_names if re.match('robot\d+', model_name)]

            # Compare new list with old one
            if new_robot_namespaces != self.robot_namespaces:
                # Remove old subscriptions
                for namespace in self.robot_namespaces:
                    if namespace in self.odom_subscriptions:
                        self.destroy_subscription(self.odom_subscriptions[namespace])
                        del self.odom_subscriptions[namespace]

                # Update robot_namespaces and add new subscriptions
                self.robot_namespaces = new_robot_namespaces
                self.get_logger().info(f'[MEN INFO] New namespaces: {new_robot_namespaces}')
                for namespace in self.robot_namespaces:
                    subscription = self.create_subscription(
                        Odometry, 
                        '/{}/odom'.format(namespace), 
                        lambda msg, namespace=namespace: self.odom_callback(msg, namespace), 
                        10 )
                    self.odom_subscriptions[namespace] = subscription
        except Exception as e:
            self.get_logger().error('[MEN ERROR] Error getting model list: %s' % str(e))
    
    def odom_callback(self, msg, namespace):
        self.odom_data[namespace] = msg

    def get_odom_callback(self, request, response):
        namespace = request.robot_namespace
        try:
            if namespace in self.odom_data:
                odom = self.odom_data[namespace]
                response.x = odom.pose.pose.position.x
                response.y = odom.pose.pose.position.y
                response.z = odom.pose.pose.position.z

                quaternion = (
                    odom.pose.pose.orientation.x,
                    odom.pose.pose.orientation.y,
                    odom.pose.pose.orientation.z,
                    odom.pose.pose.orientation.w)
                    
                roll, pitch, yaw = euler_from_quaternion(quaternion[0], quaternion[1], quaternion[2], quaternion[3])
                response.roll = roll
                response.pitch = pitch
                response.yaw = yaw
                response.success = True
            else:
                response.success = False
                self.get_logger().error('[MEN ERROR] Requested namespace does not exist')
        except Exception as e:
            response.success = False
            self.get_logger().error('[MEN ERROR] Error processing request: %s' % str(e))

        return response

def main(args=None):
    rclpy.init(args=args)

    node = OdomServiceNode()
    while rclpy.ok() and not node._shutdown_requested:
        rclpy.spin_once(node)
        
    node.get_logger().info('[MEN INFO] Shutting down')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()