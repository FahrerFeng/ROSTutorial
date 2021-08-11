#include "ros/ros.h"
#include "custom_msg_topic/custom_msg.h"

void student_infoCallback(const custom_msg_topic::custom_msgConstPtr &msg)
{
  ROS_INFO("I heard: [%s %s]", msg->last_name.c_str(), msg->first_name.c_str());
  ROS_INFO("his age is: [%d]; and his score is: [%d]", msg->age, msg->score);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "custom_msg_subscriber");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("student_info", 1000, student_infoCallback);

  ros::spin();
  return 0;
}
