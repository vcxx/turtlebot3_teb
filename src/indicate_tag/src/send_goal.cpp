#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Point.h>
#include <move_base_msgs/MoveBaseGoal.h>


using namespace std;

ros::Subscriber path_sub_;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal GOAL_;


void Path_Callback(const geometry_msgs::Point& goal)
{
  std::cout << "path callback : " << goal.x << '\n';
  std::cout << "path callback : " << goal.y << '\n';


 
  //we'll send a goal to the robot to move 
  GOAL_.target_pose.header.frame_id = "base_link";
  GOAL_.target_pose.header.stamp = ros::Time::now();
 
  GOAL_.target_pose.pose.position.x = goal.x;
  GOAL_.target_pose.pose.position.y = goal.y;
  GOAL_.target_pose.pose.orientation.w = 1.0;

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  ROS_INFO("Sending goal");
  ac.sendGoal(GOAL_);
 
  ac.waitForResult();
 
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Yeah!! the base moved ");
  else
    ROS_INFO("The base failed to move for some reason");



}

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle nh;
	ros::NodeHandle nh_private("~");


 	path_sub_ = nh.subscribe("new_following_path", 10, Path_Callback);

  ros::spin();

  return 0;
}

