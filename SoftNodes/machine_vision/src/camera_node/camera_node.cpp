#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv/cvwimage.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv/highgui.h>
#include <cv_bridge/CvBridge.h>

#include <std_msgs/Float32.h>

void processImgTimerCallback(const ros::TimerEvent&);

void circleSizeCallback(const std_msgs::Float32&);

void sendMyImage(image_transport::Publisher);

CvCapture* capture = 0;
IplImage* frame = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);;

int process_flag = 1, last_flag =0;

int main(int argc, char **argv)
{	
	
	ros::init(argc, argv, "camera_node");


	ros::NodeHandle n;

	//pubsished messages

	//subscribed messages
	//ros::Subscriber sub = n.subscribe("MV_target_circle", 1000, circleSizeCallback);
	//timers	
	ros::Timer processImgTimer = n.createTimer(ros::Duration(0.5), processImgTimerCallback);	//create timer to set a flag to start processing
	
	//publish ros images
	
		
	image_transport::ImageTransport it(n);
  	image_transport::Publisher pub = it.advertise("camera/image", 1);
	
	capture = cvCaptureFromCAM(-1);
		if ( !capture ) 
		{
	      	fprintf( stderr, "ERROR: capture is NULL \n" );
	      	getchar();
	      	return -1;
	   	}
	  
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
	

	//ros::Rate loop_rate(1);  //loop every 1hz

 
	while(ros::ok())
	{
		frame = cvQueryFrame( capture );
     		if ( !frame ) 
     		{
       		fprintf( stderr, "ERROR: frame is null...\n" );
       		getchar();
       		break;
      	}

		if(process_flag != last_flag)
		{
			last_flag = process_flag;
		
			sendMyImage(pub);
		}	
 		
 		
     		// Do not release the frame!
     	      //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
      	//remove higher bits using AND operator
      	if ( (cvWaitKey(30) & 255) == 27 ) break;	//wait for 30millisec. also if esc is pressed exit
    
 		

		  
		ros::spinOnce();				//check for subscribed messages
		//loop_rate.sleep();
	}

return 0;
}

void sendMyImage(image_transport::Publisher pub)
{	
	ROS_INFO("point 1");
	
	IplImage* frame_ros = cvCloneImage(frame); 
	cv::WImageBuffer3_b image(frame_ros);
 	sensor_msgs::ImagePtr msg = sensor_msgs::CvBridge::cvToImgMsg(image.Ipl(), "bgr8");
	pub.publish(msg);
	ROS_INFO("point 2");
}

void processImgTimerCallback(const ros::TimerEvent&)
{
	process_flag = ~process_flag;
}

