# HomeServiceRobot
Project to Simulate SLAM and Object Pick Up and Drop Off 

## Overview
Simulation environment set up in [Gazebo](https://gazebosim.org)  

Official ROS Packages Used:  
- [gmapping](http://wiki.ros.org/gmapping) > Mapping and Map Creation
- [amcl](http://wiki.ros.org/amcl) > Localization and Navigation
- [teleop_twist_keyboard](http://wiki.ros.org/teleop_twist_keyboard) > Manual Control
- [Rviz](http://wiki.ros.org/rviz) > Visualization and Navigation Control

ROS Packages Created for Project:
- add_markers > Marker Creation
- pick_objects > Navigation Goal Setting
- my_robot > Differential Drive Robot Model

Included Shell Scripts:
- mapping.sh > Mapping
- amcl_test.sh > Manual Navigation Testing
- goal_test.sh > Navigation Goal Testing
- marker_test.sh > Marker Testing
- home_service.sh > Project Task  

## Package Descriptions
### gmapping  
Gmapping utilizes the state information, position and orientation, of the robot and sensor data, in this case a simulated lidar(hokuyo), to produce an occupancy grid which is rendered as a map. A probabilistic particle filter is used to determine the most likely configuration of the occupied grid cells in the detection area. 

### amcl  
Amcl, adaptive monte carlo localization, determines the robots pose on a known map. Similar to gmapping, it utilizes a probablistic particle filter to calulate the robots pose relative to the map based on sensor and odometry data. While the amcl package is the focus of this project, it is part of a larger collection of packages, the ROS navigation stack. Other packages in this collection are used to generate costmaps and navigation paths. The cost maps assign a value(in this case distance) to each grid cell. This allows the planner to calculate the most effective(shortest) route to a navigation goal. Additionally, the stack includes a package for simple recovery behavior the case the robot becomes stuck. 

### teleop_twist_keyboard
This package provides the ability to manually control a robot. This is accomplished by mapping preset velocity, linear and angular, values to keys and these commands are then published as Twist messages. 

### RViz  
Rviz is a GUI package that allows the visualization of data and limited interaction and control of the environment/robot. 

### add_markers
This package specifies and publishes marker(object) data to be utilized by RViz. In this case, a small cube that is created, hidden, and then made to reappear in a different location.

### pick_objects
This package publishes navigation goal data for the planner to utilize. 

## Notes  
The project examples utilized turtlebot packages. The final project utilizes a custom gazebo world and the robot from the previous projects.  
The turtlebot packages have been excluded. The project file structure and some file names have been altered accordingly.  
- maps and rvizConfig directories have been placed in the my_robot directory 
- The world file homeservice.world has been placed in my_robot/worlds
- Launch files are located in my_robot/launch
- test_slam.sh -> mapping.sh
- test_navigation.sh -> amcl_test.sh
- add_marker.sh -> marker_test.sh
- pick_objects.sh -> goal_test.sh

