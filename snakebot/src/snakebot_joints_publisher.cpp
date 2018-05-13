
#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  double phase_shift;
  if (n.getParam("phase_shift",phase_shift)){
    ROS_INFO("Got Phase Shift Parameter");
  }
  else{
    ROS_INFO("Failed to get Phase Shift Parameter");
  }
  ros::Publisher joint_1_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_1_position_controller/command", 1000);
  ros::Publisher joint_2_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_2_position_controller/command", 1000);
  ros::Publisher joint_3_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_3_position_controller/command", 1000);
  ros::Publisher joint_4_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_4_position_controller/command", 1000);
  ros::Publisher joint_5_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_5_position_controller/command", 1000);
  ros::Publisher joint_6_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_6_position_controller/command", 1000);
  ros::Publisher joint_7_pub = n.advertise<std_msgs::Float64>("/snakebot/joint_7_position_controller/command", 1000);
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    std_msgs::Float64 msg1,msg2,msg3,msg4,msg5,msg6,msg7;
    msg1.data = sin(count);
    msg2.data = sin(count+1*phase_shift);
    msg3.data = sin(count+2*phase_shift);
    msg4.data = sin(count+3*phase_shift);
    msg5.data = sin(count+4*phase_shift);
    msg6.data = sin(count+5*phase_shift);
    msg7.data = sin(count+6*phase_shift);

    ROS_INFO("Publishing: %d",count);

    joint_1_pub.publish(msg1);
    joint_2_pub.publish(msg2);
    joint_3_pub.publish(msg3);
    joint_4_pub.publish(msg4);
    joint_5_pub.publish(msg5);
    joint_6_pub.publish(msg6);
    joint_7_pub.publish(msg7);
    ros::spinOnce();
    loop_rate.sleep();

    ++count;
  }


  return 0;
}
// %EndTag(FULLTEXT)%
