#include <string>
#include <math.h> 
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>


int main(int argc, char** argv){
    ros::init(argc,argv,"snakebot_jointstate_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states",1);
    ros::Rate loop_rate(30);


    // robot state
    double joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, joint_7;
    
    // message declarations
    sensor_msgs::JointState joint_state;

    double i = 0;


    while(ros::ok()){

    while(1){

    joint_1 = cos(i);
    joint_2 = cos(i);
    joint_3 = cos(i);
    joint_4 = cos(i); 
    joint_5 = cos(i); 
    joint_6 = cos(i); 
    joint_7 = cos(i); 
      // update joint_state
      joint_state.header.stamp = ros::Time::now();
      joint_state.name.resize(7);
      joint_state.position.resize(7);
      joint_state.name[0] ="joint_1";
      joint_state.position[0] = joint_1;
      joint_state.name[1] ="joint_2";
      joint_state.position[1] = joint_2;
      joint_state.name[2] ="joint_3";
      joint_state.position[2] = joint_3;
      joint_state.name[3] ="joint_4";
      joint_state.position[3] = joint_4;
      joint_state.name[4] ="joint_5";
      joint_state.position[4] = joint_5;
      joint_state.name[5] ="joint_6";
      joint_state.position[5] = joint_6;
      joint_state.name[6] ="joint_7";
      joint_state.position[6] = joint_7;
      
      // publish joint_state
      joint_pub.publish(joint_state);
      
      

      // This will adjust as needed per iteration
      
      ros::Duration(0.2).sleep();
      i += 0.1;
    }
    loop_rate.sleep();

      
      
     
      
      
    }

return 0;
}
