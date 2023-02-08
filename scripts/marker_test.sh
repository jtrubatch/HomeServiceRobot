#!/bin/sh

xterm -e " roslaunch my_robot world.launch" &  # Contains rviz launch and config
sleep 6
xterm -e " rosrun add_markers basic_shapes" 



