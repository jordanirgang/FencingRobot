#pragma once

#include <memory>
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "sensor_msgs/msg/joint_state.h"

class RobotAngleNode:public rclcpp::Node {
    public:
        explicit RobotAngleNode(char * transformation[]):Node("joint_tf2_broadcaster"){};
    private:
        void make_transforms(char * transformation[]);

};