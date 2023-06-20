
[TODO]: "description/gazebo_materials/rys.material" file MUST BE copied to:

    /usr/share/gazebo-11/media/materials/scripts/

(It is the path for Gazebo materials)


[In terminal]:        //<--- [TODO!!!] Check if is it correct
-[ARCHIVE (NO NEED TO TYPE IT)]export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:~/dev_ws/src/minirys_sim/description/materials
-[IF NEEDED]chmod +x scripts/*.py
cd ../dev_ws
colcon build --simlink-install
source install/setup.bash
cd src/minirys_sim/APP
python3 App.py

[Libraries]:
    - sudo apt install python3-gi python3-gi-cairo gir1.2-gtk-3.0
    - sudo apt-get install xdotool
    - sudo apt-get install wmctrl
    - pip install pillow


[Debug tips]: 
    - Most of the ROS2 output is suppressed by default. To see specific launch file logs on the terminal you need to comment out the following lines from the launch file of your interest:
    launch.logging.get_logger().setLevel(logging.WARNING)  //[TODO]: TODO in main.launch file
    - Simulation output structure: [Output_type] process_code message
            - [Output_type]: It is used to idnicate the type of the output.
            Values: [SIM INFO] [SIM WARN] [SIM ERROR] (for app it is [APP INFO] [APP WARN] [APP ERROR], and for menager it is [MEN INFO], [MEN WARN] [MEN ERROR])
            - process_code: It is used to idnicate the process ID. 
            Values: 00 - main.launch.py, 01 - robot.launch.py, 02 - world.launch.py, 03 - delete_robot.launch.py(legacy), 04 - delete_robot.py(legacy), 05 - menager.launch.py, 06 - robot_menager_node.py
            EXAMPLE: [SIM ERROR] 00 Terminating launch sequence...


[NOTES]:

 -> there are difference between URDF and SDF. Gazebo using SDF because some of the config are not avilable in URDF format. Gazebo tag is for that. Here is a link:
 http://classic.gazebosim.org/tutorials?tut=ros_urdf&cat=connect_ros

 -> Consider the difficulties of matching the simulated robot to the real one (simulated physics wise)

 -> This will enable us not to start from the beginning and continue to develop the multi-robot system from some point. This will make it easier to implement the system in robotic classes