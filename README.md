# SnakeBot_ROS
Experimenting with ROS Gazebo and Simulated Snake Robot

<p align="center">
  <img src="https://github.com/OakLake/SnakeBot_ROS/blob/master/GIFs/test_gait.gif">
</p>

---------------------------

## Contents
### src
  - joint state publisher for rviz.
  - joint (#1) controller publisher for gazebo control. (snakebot_joint_1_publisher.cpp).
  
  ```rosrun snakebot snakebot_joint_1_publisher.cpp```
  
### URDF
  - snake urdf with gazebo plugin and transmissions for gazebo control.
### config
  - config.yaml: controller configuration.
### launch
  - display.launch: display urdf in rviz with standard gui joint controls.
  - wave.launch: display urdf in rviz with sine wave control from src/snakebot_jointstate_publisher.cpp.
  - wave_gazebo: launch urdf in gazebo and initialise the necessary controllers.

---------------------------

## Control Joints via rqt_gui
```
roslaunch snakebot wave_gazebo.launch
rosrun rqt_gui rqt_gui
```
Add topic plugin in rqt_gui as seen in following gif, then change the expression to change the joint value, finally check the box on the left to publish.

<p align="center">
  <img src="https://github.com/OakLake/SnakeBot_ROS/blob/master/GIFs/rqt_gui.gif">
</p>


---------------------------

## Resources
- Gazebo ROS control: http://gazebosim.org/tutorials/?tut=ros_control

