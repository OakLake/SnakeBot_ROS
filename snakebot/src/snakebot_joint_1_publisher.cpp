
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher joint_1_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_1_position_controller/command", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    std_msgs::Float64 msg;
    msg.data = 0.4;

    ROS_INFO("%f", msg.data);

    joint_1_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();

    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%
