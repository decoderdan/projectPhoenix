#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/TargetVector.h>
#include <sstream>

#define MIN_DISTANCE_FROM_WP 0.15
#define MIN_ANGLE 5.0

float yaw_input;

void imuCallBack(const custom_msg::IMUData& data) {
    yaw_input = data.yaw;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "navigator");

    ros::NodeHandle n;
    ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);
		ros::Publisher target_publisher = n.advertise<custom_msg::TargetVector>("vector", 1000);
	
    tf::TransformListener listener;

    ros::Rate rate(50.0);

    int cur_wp = 1;

    while (n.ok()){
      ros::spinOnce();

      tf::StampedTransform transform;
      try {
      	std::ostringstream oss;
				oss << "/wp" << cur_wp;
        listener.lookupTransform("/imu", oss.str(), ros::Time(0), transform);

        //Got our WP. Figure out the yaw to to wp:
        float angle_diff = atan2(transform.getOrigin().y(), transform.getOrigin().x()) * (180/M_PI);
        float dist_diff = sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));

        std::cout << "Cur Yaw: " << yaw_input << " Target Yaw: " << angle_diff << ", Distance: " << dist_diff << std::endl;

        custom_msg::TargetVector tv;
        tv.set_y = false;
				tv.set_z = false;
        tv.set_pitch = false;
        tv.set_roll = false;

				//See if we are close?
				if (dist_diff <= MIN_DISTANCE_FROM_WP) {
					ROS_INFO("Moving to next waypoint");
					
					//We have acheived the way point.
					tv.vector_x = 0;
				
					//Increase the wp counter
					cur_wp++;
				}
				else {
					if ((angle_diff < MIN_ANGLE) && (angle_diff > (-MIN_ANGLE))) {
						//Still on this way point.
						tv.vector_x = 20; //20% speed
						ROS_INFO("Bearing within tolerance. Moving forward.");
					}
					else {
						tv.vector_x = 0; //0% speed
						ROS_INFO("Stopping to adjust bearing.");
					}
					
					tv.vector_yaw = yaw_input + angle_diff;
				}

			//Publish
			target_publisher.publish(tv);

      }
      catch (tf::TransformException ex) {
        ROS_ERROR("%s",ex.what());
      }

      rate.sleep();
    }
    return 0;
};
