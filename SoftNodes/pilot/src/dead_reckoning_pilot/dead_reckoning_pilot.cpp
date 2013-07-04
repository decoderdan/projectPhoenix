#include <ros/ros.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/PIDValues.h>

bool got_yaw = false;
float _current_yaw = 0;
ros::Time start_time;

void imuCallBack(const custom_msg::IMUData& data) {
    _current_yaw = data.yaw;
    got_yaw = true;
    //ROS_INFO("Got Yaw");
}

int main(int argc, char** argv){
    float dive_time = 15;
    float to_center_time = 30;
    float stop_time = 5;
    float rotate_time = 10;
    float through_gate_time = 25;

    ROS_INFO("%i, %s", argc, argv[1]);
    if (argc != 6) {
        //Print help
        printf("\nArguments are all floats, and should be passed in this order:\n\nDIVE_TIME\nTO_CENTER_TIME\nSTOP_TIME\nROTATE_TIME\nTHROUGH_GATE_TIME\n\n");
        return 0;
    }
    else if (argc == 6) {
	dive_time = atof(argv[1]);
	to_center_time = atof(argv[2]);
	stop_time = atof(argv[3]);
	rotate_time = atof(argv[4]);
        through_gate_time = atof(argv[5]);
    }

    ros::init(argc, argv, "dead_reckoning_pilot");
    ros::NodeHandle n;
    ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
    ros::Publisher target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
    ros::Publisher pid_pub = n.advertise<custom_msg::PIDValues>("pidGui", 1000);

    ROS_INFO("Dive:    %fs\nForward: %fs\nStop:    %fs\nRotate:  %fs\nForward: %fs", dive_time, to_center_time, stop_time, rotate_time, through_gate_time);

    //Wait for yaw
    while (ros::ok() && (!got_yaw)) ros::spinOnce();

    //--------------------------------------------------------------
    ROS_INFO("Read Yaw (%f), Holding and Diving...", _current_yaw);

    custom_msg::PIDValues pid; 
    custom_msg::TargetVector tv;
    float start_yaw = _current_yaw; //Save current yaw for later

    pid.yaw_Kp = 2.0;
    pid.yaw_Ki = 0.05;
    pid.yaw_Kd = 0.1;
    pid.pitch_Kp = 2.0;
    pid.pitch_Ki = 1.0;
    pid.pitch_Kd = 0.0;
    pid.depth_Kp = 400.0;
    pid.depth_Ki = 1.0;
    pid.depth_Kd = 0.0;

    tv.vector_yaw = start_yaw;
    tv.vector_z = 1.6; //Set depth 0.6M
    tv.set_x = false;
    tv.set_y = false;
    tv.set_z = true;
    tv.set_yaw = true;
    tv.set_pitch = false;
    tv.set_roll = false;

    target_publisher.publish(tv);
//    pid_pub.publish(pid);

    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + dive_time)) {ros::spinOnce();}

    //--------------------------------------------------------------
    ROS_INFO("Moving to center...");
    // send a forward 80% command
    tv.vector_x = 80; //80% speed
    tv.set_x = true;
    tv.set_y = false;
    tv.set_z = false;
    tv.set_yaw = true;
    tv.set_pitch = false;
    tv.set_roll = false;
    target_publisher.publish(tv);
    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + to_center_time)) {ros::spinOnce();}

    //--------------------------------------------------------------
    ROS_INFO("Stopping...");
    // send a stop command
    tv.set_x = true;
    tv.set_y = false;
    tv.set_z = false;
    tv.set_yaw = true;
    tv.set_pitch = false;
    tv.set_roll = false;
    tv.vector_x = 0; //0% speed
    target_publisher.publish(tv);

    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + stop_time)) {ros::spinOnce();}

    //--------------------------------------------------------------
    ROS_INFO("Rotating 90 degrees to Yaw: %f...", (start_yaw + 90));
    tv.vector_yaw = start_yaw + 90.0;
    tv.set_x = false;
    tv.set_y = false;
    tv.set_z = false;
    tv.set_yaw = true;
    tv.set_pitch = false;
    tv.set_roll = false;
    target_publisher.publish(tv);

    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + rotate_time)) {ros::spinOnce();}

    //--------------------------------------------------------------
    ROS_INFO("Moving forward...");
    tv.vector_x = 80; //80% speed
    tv.set_x = true;
    tv.set_y = false;
    tv.set_z = false;
    tv.set_yaw = true;
    tv.set_pitch = false;
    tv.set_roll = false;
    target_publisher.publish(tv);

    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + through_gate_time)) {ros::spinOnce();}

    //--------------------------------------------------------------
    ROS_INFO("Stopping & Resurfacing");
   // send a stop command
    tv.vector_x = 0; //0% speed
    tv.vector_z = 0.10;
    tv.set_x = true;
    tv.set_y = false;
    tv.set_z = true;
    tv.set_yaw = false;
    tv.set_pitch = false;
    tv.set_roll = false;

    target_publisher.publish(tv);

    start_time = ros::Time::now();
    while(ros::Time::now().toSec() < (start_time.toSec() + 1)) {ros::spinOnce();}

    pid.yaw_Kp = 0.0;
    pid.yaw_Ki = 0.0;
    pid.yaw_Kd = 0.0;
    pid.pitch_Kp = 0.0;
    pid.pitch_Ki = 0.0;
    pid.pitch_Kd = 0.0;
    pid.depth_Kp = 0.0;
    pid.depth_Ki = 0.0;
    pid.depth_Kd = 0.0;
 //   pid_pub.publish(pid);

    return 0;
};
