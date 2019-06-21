#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Bool.h>

// #include <vector>

ros::Publisher odom_path_pub_;
ros::Subscriber odom_sub_,reset_sub_;
void odom_Cb(const nav_msgs::Odometry& data);
void reset_Cb(const std_msgs::Bool& data);

nav_msgs::Path path;
geometry_msgs::PoseStamped pose;

void odom_Cb(const nav_msgs::Odometry& data)
{
    path.header = data.header;
    pose.header = data.header;
    pose.pose = data.pose.pose;
    path.poses.push_back(pose);
    odom_path_pub_.publish(path);
}

void reset_Cb(const std_msgs::Bool& data)
{
    path.poses.clear();
}

int main(int argc, char** argv){
  ros::init(argc, argv, "show_odom_path");
  ros::NodeHandle nh;
  ros::NodeHandle nh_private("~");

  odom_path_pub_   = nh.advertise<nav_msgs::Path>("odom_path", 6);
  odom_sub_ = nh.subscribe("odom", 2, odom_Cb);
  reset_sub_ = nh.subscribe("reset_odom_path", 2, reset_Cb);

  ros::spin();

  return 0;
}