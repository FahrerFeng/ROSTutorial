#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv){
		ros::init(argc, argv, "talker");
		//节点句柄
		ros::NodeHandle n;
		//创建publisher, 发布名为chatter的topic, 消息类型为std_msgs::String
		ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
		//设置循环频率
		ros::Rate loop_rate(10);
		int count = 0;
		while(ros::ok()){
			std_msgs::String msg;
			std::stringstream ss;
			ss << "hello world " << count;
			msg.data = ss.str();
			//发布消息
			ROS_INFO("%s", msg.data.c_str());
			chatter_pub.publish(msg);
			//循环等待回调函数
			ros::spinOnce();
			//按照循环频率延时
			loop_rate.sleep();
			++count;
		}
		return 0;
}
