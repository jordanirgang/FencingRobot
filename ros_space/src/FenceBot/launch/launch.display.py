import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    use_sim_time = LaunchConfiguration('use_sim_time', default='false')
    pkg_name = 'FenceBot'
    urdf_file_name = 'urdf/model.urdf'

    urdf = os.path.join(
        get_package_share_directory(pkg_name),
        urdf_file_name)
    
    rviz_file = os.path.join(
        get_package_share_directory(pkg_name),
        "rviz/config_file.rviz")
    
    with open(urdf, 'r') as infp:
        robot_desc = infp.read()
    
    params = {'robot_description': robot_desc}
    
    rviz= Node(
        package="rviz2",
        executable='rviz2',
        name='rviz2',
        parameters=[rviz_file])

    robot_state_pub = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        parameters=[params] 
       )

    robot_joint_pub = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher",
        name="joint_state_publisher",
        parameters=[params]
    )

    robot_joint_pub_gui = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
        name="joint_state_publisher_gui",
        parameters=[params]
    )

    angle_publisher = Node(
        package="FenceBot",
        executable="anglepub",
        name="anglepub"
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'),
            rviz,
            robot_state_pub,
            robot_joint_pub,
            robot_joint_pub_gui
            #angle_publisher
    ])