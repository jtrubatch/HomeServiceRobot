#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <move_base_msgs/MoveBaseAction.h>

visualization_msgs::Marker marker;
ros::Publisher marker_pub;

void markerStateCallback(const move_base_msgs::MoveBaseActionResult::ConstPtr& msg){	
	if(msg->status.status == 3){
		if(msg->header.seq == 0){
			ROS_INFO("Picking Up");
			// HIDE MARKER
			marker.color.a = 0;
		}
		else if(msg->header.seq == 1){
			ROS_INFO("Dropping Off");
			// MOVE MARKER   
  		marker.pose.position.x = 3.5;
  		marker.pose.position.y = -4; 
  		marker.color.a = 1.0;
		}	 
	}	
	marker_pub.publish(marker);
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  
	marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  uint32_t shape = visualization_msgs::Marker::CUBE;
 
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();
  marker.ns = "add_markers";
  marker.id = 0;
	marker.type = shape;

  marker.action = visualization_msgs::Marker::ADD;

  marker.pose.position.x = 4; // Pick Up position 4, 4
  marker.pose.position.y = 4;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  marker.scale.x = 0.25;
  marker.scale.y = 0.25;
  marker.scale.z = 0.25;

  marker.color.r = 0.0f;
  marker.color.g = 1.0f;
  marker.color.b = 0.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();
	ros::Duration(0.1).sleep(); // Allow time for subscriber
  marker_pub.publish(marker);
  ROS_INFO("Marker Placed");

	ros::Subscriber sub = n.subscribe("/move_base/result", 2, markerStateCallback);
	
	ros::spin();
  
	return 0;
}
