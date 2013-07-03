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
#include <cv.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define THRESHOLD 207
#define PI 3.141592654
#define WIDTH 1500
#define HEIGHT 1500
#define DEPTH 255

float bins;
float bearing;
float resolution;

int binsArr[90];
int binsArr2[90];
int binsCount;


float thresholdTmp = 0.0; //12dB Threshold = 0
float contrastTmp = 12.0; //12dB Range = 38.25


int imgx = 0, imgy = 0;
int imageArray[HEIGHT][WIDTH];
int thetaCount = 0;
int heightCount = 0;
int thetaUsed[360];
int heightUsed[750];

void sonarCallback(const custom_msg::SonarData& sonarData);
float map(float x, float in_min, float in_max, float out_min, float out_max);
int pixelPlace( float theta, unsigned int distance, unsigned int depth );
void drawPolar( float theta, unsigned int distance, unsigned int depth );

uint8_t sonarData[360][750];

uint32_t id = 0;
IplImage* sonar_cv_image = NULL;

ros::Publisher laserpub;
ros::Publisher pcpub;


int main(int argc, char **argv) {
	ros::init(argc, argv, "sonar_to_range");
	
	/* Messages and services */
	ros::NodeHandle n;	

  laserpub = n.advertise<sensor_msgs::LaserScan>("scan", 100);
	ros::Subscriber sonarSub = n.subscribe("sonar", 100, sonarCallback);
	//tf::TransformListener tf(ros::Duration(10));
	//costmap_2d::Costmap2DROS costmap("my_costmap", tf);
  cvNamedWindow("window", CV_WINDOW_AUTOSIZE);
  
	ros::spin();

}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sonarCallback(const custom_msg::SonarData& sonarData) {
  bearing = sonarData.bearing / 17.775; 
  resolution = sonarData.resolution;
  thresholdTmp = sonarData.threshold;
  contrastTmp = sonarData.contrast;


  ROS_INFO("sonar callback, %f", bearing);

  //Get the bins  
  int i = 0;
  // print all the remaining numbers
  for(std::vector<int>::const_iterator it = sonarData.bins.data.begin(); it != sonarData.bins.data.end(); ++it)
  {
    binsArr[i] = *it;
    if (binsArr[i] == 0) binsArr[i] = 1;

 //   try {
    
    drawPolar(bearing, (int)(i * resolution), *it);
 //   } catch (exception ex) {
      // some problem here
 //   }

    i++;
  }
  binsCount = i;
}

void drawPolar( float theta, unsigned int distance, unsigned int depth ) {

    static float last_bearing = 0;
    static bool found_start = false;
    static bool found_end = false;

    // wait until found start or end

    if((last_bearing > 300 && theta < 60) || (last_bearing < 60 && theta > 300)) {
      if(! found_start) {
        // found beginning or end
        ROS_INFO("Found start %f", theta);
        found_start = true;
        //Clear the sonar data;
        thetaCount = 0;
        for (int i = 0; i < 360; i++) {
          thetaUsed[i] = false;
          for (int j = 0; j < 750; j++){
            sonarData[i][j] = 0;
          }
        }
      } else {
        found_end = true;
        found_start = false;
      }
    }

    if(found_start) {
      if (!thetaUsed[(int)theta]) ROS_INFO("constructing image, %f", theta);
      // populate polarArr
      sonarData[(int)theta][(int)(distance*10)] = depth;
      if (thetaUsed[(int)theta] == false) thetaCount++;
      thetaUsed[(int)theta] = true;
      if (heightUsed[(int)(distance*10)] == false) heightCount++;
      heightUsed[(int)(distance*10)] = true;
    } 

    if(found_end) {
      ROS_INFO("Found end. Got %i angles", thetaCount);

      found_start = false;
      found_end = false;

      //We now have all the data to construct the image...
      // construct image
      //ROS_INFO("Height: %i", heightCount);
      int imgData[thetaCount][heightCount];
      int imgCounter = 0;
      for (int i = 0; i < 360; i++) {
        if (thetaUsed[i]) {
          int heightCounter = 0;
          //We have data for this angle. Use it in the image
          for (int j = 0; j < heightCount; j++) {
            if (heightUsed[j]) {
              float min_dB = thresholdTmp*3.1875; 
              float max_dB = (thresholdTmp + contrastTmp)*3.1875;            
              //Take bin, and scale it between min and max contrast
              uint8_t val_in_dB = (uint8_t)map(sonarData[i][j], min_dB, max_dB, 255.0, 0.0);
              imgData[imgCounter][heightCounter] = val_in_dB;
              heightCounter++;
            }
          }
          imgCounter++;
        }
      }

      //Now we have the data, attempt to make an image
      // create the image 'canvas'
      sonar_cv_image = cvCreateImage(cvSize(thetaCount,heightCount), IPL_DEPTH_8U, 3);

      for( int y=0; y < sonar_cv_image->height; y++ ) { 
          uchar* ptr = (uchar*) ( sonar_cv_image->imageData + y * sonar_cv_image->widthStep ); 
          for( int x=0; x<sonar_cv_image->width; x++ ) { 
              ptr[3*x] = imgData[x][y];
              ptr[3*x+1] = imgData[x][y];
              ptr[3*x+2] = imgData[x][y]; //Set red to max (BGR format)
          }
      }


  cvNamedWindow("window", CV_WINDOW_AUTOSIZE);
  cvShowImage("window", sonar_cv_image);
  cvWaitKey(0);
  cvReleaseImage(&sonar_cv_image);
  cvDestroyWindow("window");

      //Attempt to localize
      //YES: We localised OR

      //#SOME CODE

      //NO

      found_start = true;

    }  

    // save this bearing as last bearing

    last_bearing = theta;
}

/*
int pixelPlace( float theta, unsigned int distance, unsigned int depth ) {
  float x, y;
  if( (theta > 0 && theta < 90) || (theta > 181 && theta < 270) ) {
    theta = 90.0 - theta;
    x = (float)distance * cos( theta *PI/180);
    y = (float)distance * sin( theta *PI/180);
    imgx = x + ( (float) WIDTH / 2.0) ;
    imgy = (y * -1)+ ( (float) HEIGHT / 2.0);
  } else {
    y = (float)distance * cos(theta *PI/180);
    x = (float)distance * sin(theta *PI/180);   
  }

  imgx = x + ((float)WIDTH / 2);
  imgy = (y * -1) + ((float)HEIGHT / 2);

  imageArray[imgx][imgy] = depth;

  ROS_INFO("MADE IT 1");
  ROS_INFO("height = %d", size.height);
  for( int y=0; y < sonar_cv_image->height; y++ ) { 
      ROS_INFO("MADE IT 2");
      uchar* ptr = (uchar*) ( sonar_cv_image->imageData + y * sonar_cv_image->widthStep ); 
      ROS_INFO("MADE IT 3");
      for( int x=0; x<sonar_cv_image->width; x++ ) { 
          ROS_INFO("X: %i, Y: %i", x, y);
          ptr[3*x+2] = 255; //Set red to max (BGR format)
      }
  }

  cvNamedWindow("window", CV_WINDOW_AUTOSIZE);
  cvShowImage("window", sonar_cv_image);
  cvWaitKey(0);
  cvReleaseImage(&sonar_cv_image);
  cvDestroyWindow("window");
  return 1;

} */