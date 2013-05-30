#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <custom_msg/IMUData.h>
#include <custom_msg/TargetVector.h>

#define MIN_DISTANCE_FROM_WP 0.15

float yaw_input;

void imuCallBack(const custom_msg::IMUData& data) {
    yaw_input = data.yaw;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "navigator");

    ros::NodeHandle n;
    ros::Subscriber imuSub = n.subscribe("imu", 100, imuCallBack);

    tf::TransformListener listener;

    ros::Rate rate(50.0);

    int cur_wp = 1;

    while (n.ok()){
      ros::spinOnce();

      tf::StampedTransform transform;
      try {
        listener.lookupTransform("/imu", "/square_WP" + cur_wp, ros::Time(0), transform);

        //Got our WP. Figure out the yaw to to wp:
        float angle_diff = atan2(transform.getOrigin().y(), transform.getOrigin().x());
        float dist_diff = sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));

        std::cout << "Angle: " << angle_diff << ", Distance: " << dist_diff << std::endl;

        //See if we are close?
        if (dist_diff <= MIN_DISTANCE_FROM_WP) {
            //We have acheived the way point.
            //Rotate, then move to the next one...
        }
        else {
            //Still on this way point.
            custom_msg::TargetVector tv;
            tv.vector_x = 20; //20% speed
            tv.vector_yaw = angle_diff;
            tv.set_y = false;
            tv.set_z = false;
            tv.set_pitch = false;
            tv.set_roll = false;
            //Don't publish it yet
        }

      }
      catch (tf::TransformException ex) {
        ROS_ERROR("%s",ex.what());
      }

      rate.sleep();
    }
    return 0;
};
