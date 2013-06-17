#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <iostream>

#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/ByteMultiArray.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <custom_msg/SonarData.h>
#include "sensor_msgs/LaserScan.h"
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
//#include <costmap_2d/costmap_2d_ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>

void sonarCallback(const custom_msg::SonarData& sonarData);

/************************************************
 * 
 * The maximum length of the sonar reading needs to be at most half
 * the diameter of the displayed circle.
 * 
 * *********************************************/
uint32_t id = 0;
ros::Publisher laserpub;
ros::Publisher pcpub;

int main(int argc, char **argv)
{

	ros::init(argc, argv, "sonar_to_range");
	
	/* Messages and services */
	ros::NodeHandle n;	

  	laserpub = n.advertise<sensor_msgs::LaserScan>("scan", 100);
	pcpub = n.advertise<pcl::PointCloud<pcl::PointXYZ> > ("cloud", 100);
	ros::Subscriber sonarSub = n.subscribe("sonar", 100, sonarCallback);
	//tf::TransformListener tf(ros::Duration(10));
	//costmap_2d::Costmap2DROS costmap("my_costmap", tf);

	ros::spin();

}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sonarCallback(const custom_msg::SonarData& sonarData) {
	/* Create a transform broadcaster */
  	static tf::TransformBroadcaster br;
  
  	/* Transformation declarations */
  	tf::Transform sonar_tr;
  	tf::Transform sonarHead_tr;

  	/* process sonar data */
	ROS_INFO("Spitting");
	float bearing = -(sonarData.bearing/6399.0*2.0*M_PI)+M_PI * (180.0/M_PI);
  	float min_dB = sonarData.threshold*3.1875; 
	float max_dB = (sonarData.threshold + sonarData.contrast)*3.1875;

  	/* Set the sonar pose */
  	sonar_tr.setOrigin( tf::Vector3(0, 0, -1) );
  	sonar_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0,0) );
	/* Set the sonar head pose */
  	sonarHead_tr.setOrigin( tf::Vector3(0, 0, 0) );
  	sonarHead_tr.setRotation( tf::createQuaternionFromRPY(0.0,0.0,bearing) ); 

	
	br.sendTransform(tf::StampedTransform(sonarHead_tr, ros::Time::now(), "/base_laser", "/base_laser_head"));
			
  sensor_msgs::LaserScanPtr output(new sensor_msgs::LaserScan());

	output->header.stamp = ros::Time::now();
	output->header.seq = id++;
  output->header.frame_id = "/base_laser"; //associated with sonar
  output->angle_min = bearing-0.0523598776;//-1.04719755; //-60 degrees
  output->angle_max = bearing+0.0523598776;//1.04719755; //+60 degrees
  output->angle_increment = 0.0523598776;//0.0872664626; //5 Degrees
  output->time_increment = 0.0; //tbc
  output->scan_time = 0.01; //tbc
  output->range_min = sonarData.min_distance; //1cm
  output->range_max = sonarData.max_distance; //3m

	uint32_t ranges_size = std::ceil((output->angle_max - output->angle_min) / output->angle_increment);
    output->ranges.assign(ranges_size, output->range_max + 1.0);
	//float32[] ranges;

	//Get the bins	
	int i=0;
	output->ranges[0] = 100;
	output->ranges[2] = 100;
  pcl::PointCloud<pcl::PointXYZ> cloud;
    // Fill in the cloud data
  cloud.header.frame_id = "/base_laser_head"; //associated with sonar
  cloud.width    = (sonarData.bins.data.end()-sonarData.bins.data.begin());
  cloud.height   = 1;
  cloud.is_dense = false;
  cloud.points.resize (cloud.width * cloud.height);

  for(std::vector<int>::const_iterator it = sonarData.bins.data.begin(); it != sonarData.bins.data.end(); ++it)
  {
  	//Take bin, and scale it between min and max contrast
		float val_in_dB = map(*it, min_dB, max_dB, 1.0, 0);
		if (val_in_dB < 0) val_in_dB = 0.0;
		if (val_in_dB > 1) val_in_dB = 1.0;
		
		if ((val_in_dB < 0.2) && ((i * sonarData.resolution) > 1.0)) { //Threshold
			//std::cout << "Matched : " << (i * sonarData.resolution) << " Resolution: " << sonarData.resolution << std::endl;
			output->ranges[1] = (i * sonarData.resolution);//i * sonarData.resolution;
			output->header.seq = id++;
			laserpub.publish(output);
		
		}
		cloud.points[i].x = i * sonarData.resolution;
    		cloud.points[i].y = 0;
    		cloud.points[i].z = (map(*it, 0, 255, 0, 2))-3;
    i++;


  pcpub.publish (cloud);
  }
  
}
