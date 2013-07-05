#include <ros/ros.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/TargetVector.h>
#include <custom_msg/PIDValues.h>

#define GRABBING_YAW 0
#define DIVING 1
#define CENTERING 2
#define STOPPING 3
#define TURNING 4
#define VALIDATING 5
#define SURFACING 6
#define FINISHED 7

bool got_yaw = false;
float _current_yaw = 0;
ros::Time start_time;
ros::Publisher pid_config_publisher;

void imuCallBack(const custom_msg::IMUData& data) {
    _current_yaw = data.yaw;
    got_yaw = true;
}

int main(int argc, char** argv){
    float dive_time = 15;
    float to_center_time = 30;
    float stop_time = 5;
    float rotate_time = 10;
    float through_gate_time = 25;
    float TARGET_DEPTH = 1.6;

    int state = GRABBING_YAW;

    if (argc != 7) {
        //Print help
        printf("\nArguments are all floats, and should be passed in this order:\n\nDIVE_TIME\nTO_CENTER_TIME\nSTOP_TIME\nROTATE_TIME\nTHROUGH_GATE_TIME\n\n");
        return 0;
    }
    else if (argc == 7) {
	TARGET_DEPTH = atof(argv[1]);
	dive_time = atof(argv[2]);
	to_center_time = atof(argv[3]);
	stop_time = atof(argv[4]);
	rotate_time = atof(argv[5]);
        through_gate_time = atof(argv[6]);
    }

    ros::init(argc, argv, "dead_reckoning_pilot");
    ros::NodeHandle n;
    ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
    ros::Publisher target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
    pid_config_publisher = n.advertise<custom_msg::PIDValues>("pidGui", 1000);    

    ROS_INFO("Depth:  %f\nDive:    %fs\nForward: %fs\nStop:    %fs\nRotate:  %fs\nForward: %fs", TARGET_DEPTH, dive_time, to_center_time, stop_time, rotate_time, through_gate_time);

    while (ros::ok()) {

	//Set up the custom messages to publish
	custom_msg::TargetVector tv;
	custom_msg::PIDValues curPIDConfig;

	float start_yaw;

	switch (state) {
		case GRABBING_YAW: 	
			if (got_yaw) {
				start_yaw = _current_yaw; //Save current yaw for later
				state = DIVING;

				tv.vector_yaw = start_yaw;
				tv.vector_z = TARGET_DEPTH; //Set depth
				tv.vector_pitch = 0.0;
				tv.set_x = false;
				tv.set_y = false;
				tv.set_z = true;
				tv.set_yaw = true;
				tv.set_pitch = true;
				tv.set_roll = false;

				//Publish out target vector and target yaw.
				target_publisher.publish(tv);

				ROS_INFO("Got Current Yaw Reading (%f). State = DIVING", _current_yaw);
			}
			break;
		case DIVING:
			ROS_INFO("Diving to %fM", TARGET_DEPTH);
			curPIDConfig.yaw_Kp = 2.0;
			curPIDConfig.yaw_Ki = 0.05;
			curPIDConfig.yaw_Kd = 0.1;
			curPIDConfig.pitch_Kp = 2.0;
			curPIDConfig.pitch_Ki = 1.0;
			curPIDConfig.pitch_Kd = 0.0;
			curPIDConfig.depth_Kp = 400.0;
			curPIDConfig.depth_Ki = 1.0;
			curPIDConfig.depth_Kd = 0.0;
			pid_config_publisher.publish(curPIDConfig);

			//Set up a timer
		        start_time = ros::Time::now();
			state = CENTERING;
			break;
		case CENTERING: 
			//Check the timer
			if (ros::Time::now().toSec() >= (start_time.toSec() + dive_time)) {
				ROS_INFO("Driving forward for %f seconds", to_center_time);				

				tv.vector_x = 80; //80% speed
				tv.set_x = true;
				target_publisher.publish(tv);

				start_time = ros::Time::now();
				state = STOPPING;
			}
			break;
		case STOPPING: 
			//Check the timer
			if (ros::Time::now().toSec() >= (start_time.toSec() + to_center_time)) {
				ROS_INFO("Stopping within %f seconds", stop_time);				
				tv.set_x = true;
				tv.vector_x = 0; //0% speed
				target_publisher.publish(tv);

				start_time = ros::Time::now();
				state = TURNING;
			}
			break;
		case TURNING:
			//Check the timer
			if (ros::Time::now().toSec() >= (start_time.toSec() + stop_time)) {
				ROS_INFO("Turning to %f", (start_yaw + 90.0));
				tv.vector_yaw = start_yaw + 90.0;
				tv.set_yaw = true;
				target_publisher.publish(tv);

				start_time = ros::Time::now();
				state = VALIDATING;
			}
			break;
		case VALIDATING:
			//Check the timer
			if (ros::Time::now().toSec() >= (start_time.toSec() + rotate_time)) {
				ROS_INFO("Validating");
				tv.vector_x = 80; //80% speed
				tv.set_x = true;
				target_publisher.publish(tv);

				start_time = ros::Time::now();
				state = SURFACING;
			}
			break; 
		case SURFACING:
			//Check the timer
			if (ros::Time::now().toSec() >= (start_time.toSec() + through_gate_time)) {
				ROS_INFO("Surfacing");
				tv.vector_x = 0; //0% speed
				tv.vector_z = 0.20;
				tv.set_x = true;
				tv.set_z = true;
				target_publisher.publish(tv);
		    		
				state = FINISHED;
			}
			break;
		case FINISHED:
			curPIDConfig.yaw_Kp = 0.0;
			curPIDConfig.yaw_Ki = 0.0;
			curPIDConfig.yaw_Kd = 0.0;
			curPIDConfig.pitch_Kp = 0.0;
			curPIDConfig.pitch_Ki = 0.0;
			curPIDConfig.pitch_Kd = 0.0;
			curPIDConfig.depth_Kp = 0.0;
			curPIDConfig.depth_Ki = 0.0;
			curPIDConfig.depth_Kd = 0.0;
			pid_config_publisher.publish(curPIDConfig);
			ros::spinOnce();
			return 1;
			break;
	}
	ros::spinOnce();
    }

    return 0;
};
