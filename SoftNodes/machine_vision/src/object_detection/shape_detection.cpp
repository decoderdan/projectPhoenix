#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <time.h>
#include <ctime>
#include <cv.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <iostream>
#include <stdio.h>

using namespace cv;

#define MAX_DATE 12

void saveImgTimerCallback(const ros::TimerEvent&);
std::string get_date(void);
std::string get_time(void);
void colour_filter(void);
void detect_shape(void);
void GetThresholdedImage(IplImage*);
void create_images();
void release_images(void);

CvCapture* capture = 0;
IplImage* frame;
IplImage* frame_org;
IplImage* imgHSV;
IplImage* imgThresh;
IplImage* canny;
IplImage* rgbcanny;

using namespace cv;


int main(int argc, char **argv)
{	
	
	ros::init(argc, argv, "ros_image_capture");


	ros::NodeHandle n;

	//pubsished messages

	//subscribed messages

	//timers

	ros::Timer saveImgTimer = n.createTimer(ros::Duration(5), saveImgTimerCallback);	//create timer for saving images every 5sec (300s = 5m)
	
	
	capture = cvCaptureFromCAM(1);
		if ( !capture ) 
		{
	      	fprintf( stderr, "ERROR: capture is NULL \n" );
	      	getchar();
	      	return -1;
	   	}
	  
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);
	
	cvNamedWindow("Image", 1); //the unchanged image
	cvNamedWindow("HSV_img",1);     //HSV image
      cvNamedWindow("Filtered_image",1); //image after colour filter
      cvNamedWindow("circles",1);	//canny edge detection
	
	
	cvMoveWindow("Image", 0, 400); 
	cvMoveWindow("HSV_img",320,400);  
      cvMoveWindow("Filtered_image",640,400);
      cvMoveWindow("circles",980,400);
	
	
	//ros::Rate loop_rate(1);  //loop every 1hz

 
	while(ros::ok())
	{

		ROS_INFO("point 1");
		
		/* create the images*/
		create_images();		

		ROS_INFO("point 2");
		frame = cvQueryFrame( capture );				

		ROS_INFO("point 3");
		
     		if ( !frame ) 
     		{
       		fprintf( stderr, "ERROR: frame is null...\n" );
       		getchar();
       		break;
      	}


		
		frame_org = frame;
		
		colour_filter();

		
		//detect_shape();


 		// show images
 		cvShowImage("Image", frame_org);
 		cvShowImage("HSV_img", imgHSV);
 		cvShowImage("Filtered_image", imgThresh);           
      	cvShowImage("circles", rgbcanny);
		
		ROS_INFO("point 4");
      	release_images();
		ROS_INFO("point 5");
	
     		// Do not release the frame!
     	      //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
      	//remove higher bits using AND operator
      	if ( (cvWaitKey(100) & 255) == 27 ) break;	//wait for 30millisec. also if esc is pressed exit
    		
		ros::spinOnce();				//check for subscribed messages
		//loop_rate.sleep();
	}

return 0;
}

void saveImgTimerCallback(const ros::TimerEvent&)
{
	 struct passwd *pw = getpwuid(getuid());
	 const char *homedir = pw->pw_dir;
	 
	 std::string filename_str;
	 
	 filename_str.append(homedir);
	 
	 filename_str.append("/projectPheonix/camera/saved_images/");
	 
	 filename_str.append(get_date());
	 
	 filename_str.append(get_time());
	 
	 filename_str.append(".jpeg");
	 
	 const char * filename_chr = filename_str.c_str();
	 
	 ROS_INFO("saved an image called %s", filename_chr);

	 //cvSaveImage(filename_chr, frame_org);
}


void colour_filter(void)
{
      cvSmooth(frame, frame, CV_GAUSSIAN,7,7); //smooth the original image using Gaussian kernel 3,3

      cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
      GetThresholdedImage(imgHSV);
          
      cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,7,7); //smooth the binary image using Gaussian kernel 3,3
}

void GetThresholdedImage(IplImage* imgHSV)
{       
       cvInRangeS(imgHSV, cvScalar(0,60,100), cvScalar(10,256,256), imgThresh);		//(170,160,60) (180,256,256)
} 

void detect_shape(void)
{	
	CvMemStorage* storage = cvCreateMemStorage(0);


	canny = cvCreateImage(cvGetSize(imgThresh),IPL_DEPTH_8U,1);
	rgbcanny = cvCreateImage(cvGetSize(imgThresh),IPL_DEPTH_8U,3);
	cvCanny(imgThresh, canny, 50, 100, 3);

	CvSeq* circles = cvHoughCircles(canny, storage, CV_HOUGH_GRADIENT, 1, 50.0, 100, 35,5,320);  //1, 40.0, 100, 100,0,0);
															  //dp, min dist, high thresh of canny,accumulator(small val more false circles,min rad, max rad)
														
	cvCvtColor(canny, rgbcanny, CV_GRAY2BGR);

	for (int i = 0; i < circles->total; i++)
	{
	     // round the floats to an int
	     float* p = (float*)cvGetSeqElem(circles, i);
	     cv::Point center(cvRound(p[0]), cvRound(p[1]));
	     int radius = cvRound(p[2]);

	     // draw the circle center
	     cvCircle(frame_org, center, 3, CV_RGB(0,0,255), -1, 8, 0 );

	     // draw the circle outline
	     cvCircle(frame_org, center, radius+1, CV_RGB(0,255,0), 2, 8, 0 );

	     ROS_INFO("x: %d y: %d r: %d\n",center.x,center.y, radius);
	}

       
}



std::string get_time(void)
{
   time_t now;
   char the_date[MAX_DATE];

   the_date[0] = '\0';

   now = time(NULL);

   if (now != -1)
   {
      strftime(the_date, MAX_DATE, "%H_%M_%S", gmtime(&now));
   }

   return std::string(the_date);
}

std::string get_date(void)
{
   time_t now;
   char the_date[MAX_DATE];

   the_date[0] = '\0';

   now = time(NULL);

   if (now != -1)
   {
      strftime(the_date, MAX_DATE, "%d_%m_%y_", gmtime(&now));
   }

   return std::string(the_date);
}

void create_images()
{
	//frame = cvCreateImage(cvSize(320, 240),IPL_DEPTH_8U, 3);
	frame_org = cvCreateImage(cvSize(320, 240),IPL_DEPTH_8U, 3);
	imgHSV = cvCreateImage(cvSize(320, 240),IPL_DEPTH_8U, 3);
	imgThresh = cvCreateImage(cvSize(320, 240),IPL_DEPTH_8U, 1);
	canny = cvCreateImage(cvSize(320, 240),IPL_DEPTH_8U, 1);
	rgbcanny = cvCreateImage(cvGetSize(frame_org),IPL_DEPTH_8U, 3);
}
void release_images()
{
	cvReleaseImage(&frame);
	cvReleaseImage(&frame_org);
	cvReleaseImage(&imgHSV);
	cvReleaseImage(&imgThresh);
	cvReleaseImage(&canny);
	cvReleaseImage(&rgbcanny);
}
