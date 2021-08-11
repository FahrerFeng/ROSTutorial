#include "ros/ros.h"
#include "custom_msg_topic/custom_msg.h"
#include <sstream>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "custom_msg_publisher");
  ros::NodeHandle nh;
  ros::Publisher custom_msg_pub = nh.advertise<custom_msg_topic::custom_msg>("student_info", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    custom_msg_topic::custom_msg msg;
    //std::stringstream ss;
    //ss<<"Zhang San";
    //ss>>msg.last_name; //将字符串流中以空格隔开的第一个子字符串Zhang插入到msg.last_name中
    //ss>>msg.first_name; //将字符串流中以空格隔开的第二个子字符串San插入到msg.first_name中
    msg.last_name = "Zhang";
    msg.first_name = "San";
    msg.age = 18;
    msg.score = 650;

    custom_msg_pub.publish(msg);
    loop_rate.sleep();
  }
  return 0;
}

