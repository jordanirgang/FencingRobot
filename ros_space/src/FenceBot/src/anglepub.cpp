//#include "ros/ros.h"
//#include <sensor_msg/JointState.h>
//#include <tf/transform_broadcaster.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#define DEGREE M_PI/180

int main(int argc, char ** argv){
    
    ros::init(argc,argv,"joint_controll");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
    tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(30);
    // robot state
    double planar_shift_z = 0, plane_1_x=90*DEGREE, plane_2_x=90*DEGREE, hinc=0.005;
    while(ros::ok()){
    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "axis";
    //update joint_state
    joint_state.header.stamp = ros::Time::now();
    joint_state.name.resize(3);
    joint_state.position.resize(3);
    joint_state.name[0] ="shoulder_z";
    joint_state.position[0] = planar_shift_z;
    joint_state.name[1] ="shoulder_x";
    joint_state.position[1] = plane_1_x;
    joint_state.name[2] ="elbow_x";
    joint_state.position[2] = plane_2_x;

    odom_trans.header.stamp = ros::Time::now();
    joint_pub.publish(joint_state);
    broadcaster.sendTransform(odom_trans);
    loop_rate.sleep();

    }
    return 0;
}