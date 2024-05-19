# MiniRysGazebo

## Software requirements:
- wmctrl
```
sudo apt install wmctrl
```

## Steps to run the simulator:

Go to the folder of your choosing:

```
cd <path_your_desired_folder>
```
Clone the repository:

```
git clone https://github.com/GroupOfRobots/MiniRysGazebo
```
Navigate to the "minirys_sim" folder:

```
cd MiniRysGazebo/dev_ws/src/minirys_sim/
```
Set scripts as executables:

```
chmod +x scripts/*.py
```
Return to the workspace folder:

```
cd ../..
```
Build the packages:

```
colcon build
```
Source the terminal:

```
source install/setup.bash
```
Go to the "APP" folder:

```
cd src/minirys_sim/APP
```
Run the app:

```
python3 App.py
```

## All the steps combined to copy (starting in the folder of your choosing):

```
git clone https://github.com/GroupOfRobots/MiniRysGazebo
cd MiniRysGazebo/dev_ws/src/minirys_sim/
chmod +x scripts/*.py
cd ../..
colcon build
source install/setup.bash
cd src/minirys_sim/APP
python3 App.py
```

## After installation (from the MiniRysGazebo folder):

```
cd dev_ws
source install/setup.bash
cd src/minirys_sim/APP
python3 App.py
```

## Simulation setup:

In the "Simulation parameters" tab (expandable list), you can set the number of robots for the simulation. Then, proceed to the "Robot driver" tab and set up driver groups:

1. Create a new group.
2. Select robots that should belong to the group.
3. Save the group.

There are three modes of control:
- Mode 0: (other parameters are ignored) Control the group with a teleop_twist_keyboard controller.
- Mode 1: Create a sequence of moves. Specify how many loops of the commands the group should perform using the loop field (-1 for infinite). Then, you can add and delete steps.
- Mode 2: (other parameters are ignored) This mode creates translator nodes for each robot in the group. The robot will listen to the MotorCommand.msg message type published on the /robotX/motor_command (where "X" is the number of the robot) topic and send the AngularPose.msg message type to /robotX/angular_pose topic.

Lastly, click the following buttons:
- "Run Gazebo"
- "Run Simulator"
- "Launch driver"
