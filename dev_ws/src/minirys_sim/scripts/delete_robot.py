#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from gazebo_msgs.srv import DeleteModel
from gazebo_msgs.srv import GetModelList
import sys


class DeleteModelClient(Node):
    def __init__(self):
        super().__init__('delete_model_client')
        self.delete_client = self.create_client(DeleteModel, "/gazebo/delete_model")
        self.list_client = self.create_client(GetModelList, "/get_model_list")

        if not self.wait_for_services():
            self.get_logger().warn('[SIM ERROR] 04 Required services not available. Is Gazebo running?')
            rclpy.shutdown()
            sys.exit(1)

    def wait_for_services(self):
        timeout = 2  # seconds
        for _ in range(timeout):
            if self.delete_client.wait_for_service(timeout_sec=1.0) and self.list_client.wait_for_service(timeout_sec=1.0):
                return True
        return False

    def send_request(self, model_name):
        # First check if the model exists
        list_req = GetModelList.Request()
        future = self.list_client.call_async(list_req)
        rclpy.spin_until_future_complete(self, future)  # Wait for response
        response = future.result()
        
        if model_name in response.model_names:
            self.get_logger().info(f"[SIM INFO] 04 Model '{model_name}' exists, proceeding with deletion...")
            
            # Send deletion request
            del_req = DeleteModel.Request()
            del_req.model_name = model_name
            future = self.delete_client.call_async(del_req)
            rclpy.spin_until_future_complete(self, future)  # Wait for response
            del_response = future.result()

            if del_response.success:
                self.get_logger().info(f"[SIM INFO] 04 Model '{model_name}' successfully deleted.")
                # Check if the model still exists
                future = self.list_client.call_async(list_req)
                rclpy.spin_until_future_complete(self, future)  # Wait for response
                response = future.result()

                if model_name not in response.model_names:
                    self.get_logger().info(f"[SIM INFO] 04 Model '{model_name}' is confirmed to be deleted.")
                else:
                    self.get_logger().warn(f"[SIM ERROR] 04 Model '{model_name}' still exists in the list, deletion failed.")
            else:
                self.get_logger().warn(f"[SIM ERROR] 04 Failed to delete model '{model_name}'. Server response: {del_response.status_message}")
        else:
            self.get_logger().warn(f"[SIM ERROR] 04 Model '{model_name}' does not exist, cannot proceed with deletion.")

def main(args=None):
    rclpy.init(args=args)

    if len(sys.argv) < 2:
        print('[SIM INFO] 04 Pass a model name as an argument to delete it.')
        rclpy.shutdown()
        return

    model_name = sys.argv[1]
    delete_model_client = DeleteModelClient(model_name)
    delete_model_client.send_request(model_name)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
