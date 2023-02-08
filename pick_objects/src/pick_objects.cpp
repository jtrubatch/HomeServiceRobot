#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


int main(int argc, char** argv){
  // initialize
  ros::init(argc, argv, "pick_objects");
	ros::NodeHandle n;
  MoveBaseClient ac("move_base", true);

  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // Initial Goal / Pick Up
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = 4;
  goal.target_pose.pose.position.y = 4;
  goal.target_pose.pose.orientation.w = 1;

  ROS_INFO("Sending Pick Up");
  ac.sendGoal(goal);

  ac.waitForResult();

  // Status Check
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Robot has arrived at the pickup");
    ros::Duration(5.0).sleep();
    }
  else{
    ROS_INFO("robot has failed to reach the pickup");
    }
	
	
	// Final Goal / Drop Off
	goal.target_pose.header.stamp = ros::Time::now();
	goal.target_pose.pose.position.x = 3.5; // drop off 3.5, -4
	goal.target_pose.pose.position.y = -4;
	goal.target_pose.pose.orientation.w = 1;
	
	ROS_INFO("Sending Drop Off");
	ac.sendGoal(goal);
	
	ac.waitForResult();
	
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Robot has arrived at the drop off");
    }
  else{
    ROS_INFO("Robot has failed to reach the drop off");
    }
  
  return 0;
}
