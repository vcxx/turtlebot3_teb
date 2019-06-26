#include <ros/ros.h>
#include <iostream>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <move_base_msgs/MoveBaseActionResult.h>


using namespace std;

ros::Publisher goal_pub_;
ros::Subscriber result_sub_;

void rosParameters(ros::NodeHandle n_private);
void double_loop(void);
void two_points(void);

move_base_msgs::MoveBaseActionGoal GOAL_;
uint8_t STATUS_;
int PLACE_ = 0;
int MODE_ = 1;

void rosParameters(ros::NodeHandle n_private)
{
  n_private.param<int>("mode", MODE_, 1);
}

void Goal_Callback(const move_base_msgs::MoveBaseActionResult& result)
{ 
  STATUS_ = result.status.status ;
  std::cout << "Goal status : " << STATUS_ << '\n';

  if(STATUS_ == 3)
  {
    PLACE_ += 1;
    std::cout << "Goal PLACE_ : " << PLACE_ << '\n';

    switch (MODE_)
    {
    case 1:
      double_loop();
      break;    
    case 2:
      two_points();
      break;                   
    default:
      break;
    }

  }
}

void double_loop(void)
{
    switch (PLACE_)
    {
    case 1:
      std::cout << "Heading to PLACE_1: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = 0.95;
      GOAL_.goal.target_pose.pose.position.y = 0.38;
      GOAL_.goal.target_pose.pose.orientation.z = 0;   
      GOAL_.goal.target_pose.pose.orientation.w = 1;   
      goal_pub_.publish(GOAL_); 
      break;

    case 2:
      std::cout << "Heading to PLACE_2: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = 4;
      GOAL_.goal.target_pose.pose.position.y = 4;
      GOAL_.goal.target_pose.pose.orientation.z = 0;   
      GOAL_.goal.target_pose.pose.orientation.w = 1;   
      goal_pub_.publish(GOAL_);     
      break;    

    case 3:
      std::cout << "Heading to PLACE_3: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = 6.6;
      GOAL_.goal.target_pose.pose.position.y = 3.3;
      GOAL_.goal.target_pose.pose.orientation.z = -0.7;   
      GOAL_.goal.target_pose.pose.orientation.w = 0.7;   
      goal_pub_.publish(GOAL_); 
      break;

    case 4:
      std::cout << "Heading to PLACE_4: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = 0.95;
      GOAL_.goal.target_pose.pose.position.y = 0.38;
      GOAL_.goal.target_pose.pose.orientation.z = 1;   
      GOAL_.goal.target_pose.pose.orientation.w = 0;   
      goal_pub_.publish(GOAL_);     
      break; 

    case 5:
      std::cout << "Heading to PLACE_5: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = -4.3;
      GOAL_.goal.target_pose.pose.position.y = 1.6;
      GOAL_.goal.target_pose.pose.orientation.z = 0.7;   
      GOAL_.goal.target_pose.pose.orientation.w = 0.7;   
      goal_pub_.publish(GOAL_); 
      break;

    case 6:
      PLACE_ = 0;
      std::cout << "Heading to PLACE_6: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = -1;
      GOAL_.goal.target_pose.pose.position.y = 3.5;
      GOAL_.goal.target_pose.pose.orientation.z = -0.7;   
      GOAL_.goal.target_pose.pose.orientation.w = 0.7;    
      goal_pub_.publish(GOAL_);     
      break;    
               
    default:
      break;
    }
}

void two_points(void)
{
    switch (PLACE_)
    {
    case 1:
      std::cout << "Heading to PLACE_1: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = 4.0;
      GOAL_.goal.target_pose.pose.position.y = 4.0;
      GOAL_.goal.target_pose.pose.orientation.z = 0.0;   
      GOAL_.goal.target_pose.pose.orientation.w = 1.0;   
      goal_pub_.publish(GOAL_); 
      break;

    case 2:
      PLACE_ = 0;
      std::cout << "Heading to PLACE_2: " << '\n';
      GOAL_.header.frame_id = "map";
      GOAL_.header.stamp = ros::Time::now();
      GOAL_.goal.target_pose.header.frame_id = "map";
      GOAL_.goal.target_pose.header.stamp = ros::Time::now();

      GOAL_.goal.target_pose.pose.position.x = -3.0;
      GOAL_.goal.target_pose.pose.position.y = 1.0;
      GOAL_.goal.target_pose.pose.orientation.z = 1.0;   
      GOAL_.goal.target_pose.pose.orientation.w = 0.0;    
      goal_pub_.publish(GOAL_);     
      break;    
               
    default:
      break;
    }
}


int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle nh;
	ros::NodeHandle nh_private("~");
  rosParameters(nh_private);

  goal_pub_   = nh.advertise<move_base_msgs::MoveBaseActionGoal>("/move_base/goal", 1);
  result_sub_ = nh.subscribe("/move_base/result", 1, Goal_Callback);

  ros::spin();

  return 0;
}

