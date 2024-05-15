#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time
import subprocess
from geometry_msgs.msg import Vector3
import signal
import threading


class ProcessClass:
    def __init__(self):
        self.process = None
        self.gazebo_process = None
        self.terminal_title = "Default"
        self.terminal_command = f"gnome-terminal --title='{self.terminal_title}'"

    def is_terminal_open(self, title):
        terminal_list = subprocess.check_output("wmctrl -l", shell=True).decode()
        return title in terminal_list

class RelayNode(Node):

    DIRECTIONS = {
        0: Twist(linear=Vector3(x=1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=0.0)),  # Forward
        1: Twist(linear=Vector3(x=1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=-1.0)),  # Forward & Right
        2: Twist(linear=Vector3(x=0.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=-1.0)),  # Right
        3: Twist(linear=Vector3(x=-1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=-1.0)),  # Back & Right
        4: Twist(linear=Vector3(x=-1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=0.0)),  # Back
        5: Twist(linear=Vector3(x=-1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=1.0)),  # Back & Left
        6: Twist(linear=Vector3(x=0.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=1.0)),  # Left
        7: Twist(linear=Vector3(x=1.0, y=0.0, z=0.0), angular=Vector3(x=0.0, y=0.0, z=1.0))   # Forward & Left
    }

    def __init__(self, robots=None, mode=None, sequence=None, loop=None, group_name=None):
        super().__init__("relay_node")

        signal.signal(signal.SIGINT, self.shutdown_handler)
        self.directions_names = [
            "forward",
            "forward and right",
            "right",
            "back and right",
            "back",
            "back and left",
            "left",
            "forward and left"
        ]
        
        # Declare the parameters
        self.declare_parameter("robots", "")
        self.declare_parameter("mode", 0)
        self.declare_parameter("sequence", "")
        self.declare_parameter("loop", 0)
        self.declare_parameter("group_name", "Default")

        # If parameters are not passed to the constructor, get them
        if robots is None:
            robots_string = self.get_parameter("robots").get_parameter_value().string_value
        if mode is None:
            mode = self.get_parameter("mode").get_parameter_value().integer_value
        if sequence is None:
            sequence = self.get_parameter("sequence").get_parameter_value().string_value
        if loop is None:
            loop = self.get_parameter("loop").get_parameter_value().integer_value
        if group_name is None:
            group_name = self.get_parameter("group_name").get_parameter_value().string_value
    
        self.robots_string = robots_string
        self.robots = self.robots_string.split(',')
        self.mode = mode
        self.sequence = sequence
        self.loop = loop
        self.group_name = group_name
        self.publisher_list = {}

        self.teleop_process = ProcessClass()
        self.teleop_process.terminal_title = self.group_name
        self.teleop_process.terminal_command = f"gnome-terminal --title='{self.teleop_process.terminal_title}'"
        
        if self.mode == 1:
            self.get_logger().info(f"Configuration:\nRobots: {self.robots}\nMode: {self.mode}\nSequence: {self.sequence}\nLoop: {self.loop}\nGroup Name: {self.group_name}\n")
        if self.mode == 0:
            self.get_logger().info(f"Configuration:\nRobots: {self.robots}\nMode: {self.mode}\n")
        
        for robot in self.robots:
            topic_name = f"/{robot}/cmd"
            pub = self.create_publisher(Twist, topic_name, 10)
            self.publisher_list[topic_name] = pub

        if self.mode == 0:
            # Direct Drive mode
            self.create_subscription(Twist, self.group_name, self.relay_callback, 10)
            self.run_teleop_command()
        else:
            # Sequence mode
            self.execute_sequence()
        
    def run_teleop_command(self):
        command = f"cd; cd dev_ws; source install/setup.bash;ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args --remap cmd_vel:={self.group_name}; read" 
        terminal_command = f"{self.teleop_process.terminal_command} -- bash -c '{command}; exec bash'"

        if self.teleop_process.process is None or self.teleop_process.process.poll() is not None:
            if not self.teleop_process.is_terminal_open(self.teleop_process.terminal_title):
                self.teleop_process.process = subprocess.Popen(terminal_command, shell=True)
                print("Teleop process started.")
            else:
                print("Teleop is already running.")
        else:
            print("Teleop is already running.")

    def shutdown_handler(self, sig, frame):
        self.get_logger().info('Caught Ctrl+C, stopping robots...')
        self.send_stop_signal()
        self.destroy_node()
        rclpy.shutdown()

    def send_stop_signal(self):
        stop_msg = Twist()
        for pub in self.publisher_list.values():
            pub.publish(stop_msg)

    def execute_sequence(self):
        try:
            commands = list(map(float, self.sequence.split(',')))
        except ValueError:
            self.get_logger().error("Invalid sequence format. Ensure it's comma-separated numbers.")
            return

        if commands:
            # Run indefinitely if loop == -1
            while self.loop == -1 or self.loop > 0:
                i = 0
                while i < len(commands):
                    direction = int(commands[i])
                    speed = commands[i + 1]
                    duration = commands[i + 2]

                    twist = Twist()
                    twist.linear.x = self.DIRECTIONS[direction].linear.x * speed
                    twist.angular.z = self.DIRECTIONS[direction].angular.z * speed
                    twist.linear.y= 0.0
                    twist.angular.y = 0.0
                    twist.linear.z = 0.0
                    twist.angular.x = 0.0


                    self.publish_twist(twist)
                    print(f"Executing Command: Direction \"{self.directions_names[int(direction)]}\", Speed {speed}")

                    animation_thread = threading.Thread(target=self.animation, args=(duration,))
                    animation_thread.start()
                    animation_thread.join()
                    print(f"\nCompleted \"{self.directions_names[int(direction)]}\" for {duration} seconds\n")

                    # Send a stop message after the action completes
                    self.send_stop_signal()
                    time.sleep(0.2) 
                    
                    i += 3  # Move to the next command

                if self.loop > 0:
                    self.loop -= 1  # Decrement the loop count

            if self.loop == 0:
                self.destroy_node()
        else:
            print("[SIM ERROR] 06 No sequence for mode = 1")

    def send_stop_signal(self):
        stop_msg = Twist()
        self.publish_twist(stop_msg)

    def publish_twist(self, twist):
        for pub in self.publisher_list.values():
            pub.publish(twist)

    def relay_callback(self, msg):
        if self.mode != 0:
            self.get_logger().error("Invalid mode for relay callback.")
            return

        for pub in self.publisher_list.values():
            pub.publish(msg)
    
    def animation(self, duration):
        for k in range(int(duration)):
            x = "|" * (k + 1)
            print(f"{x}\n", end="", flush=True)
            time.sleep(1)

def main(args=None):
    rclpy.init(args=args)

    node = RelayNode()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == "__main__":
    main()
