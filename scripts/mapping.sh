#!/bin/sh

xterm -e " roslaunch my_robot world.launch" &  # Contains rviz launch and config
sleep 5
xterm -e " roslaunch my_robot gmapping.launch" &
sleep 5
xterm -e " roslaunch my_robot teleop.launch" 


