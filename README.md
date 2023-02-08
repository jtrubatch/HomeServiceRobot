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

