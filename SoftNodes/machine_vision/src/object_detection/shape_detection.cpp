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
void detect_objects(void);
void detect_shape(void);
IplImage* GetThresholdedImage(IplImage*);

CvCapture* capture = 0;
IplImage* frame;
IplImage* frame_org;
IplImage* imgThresh;
IplImage* imgGrayScale;
IplImage* img;
IplImage* imgCanny;
IplImage* shape_img;


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
	
	cvNamedWindow("Video");     
      cvNamedWindow("Filtered_image");
	

	//ros::Rate loop_rate(1);  //loop every 1hz

 
	while(ros::ok())
	{
		
		frame = cvQueryFrame( capture );
		frame_org = frame;
		img = frame;
		
     		if ( !frame ) 
     		{
       		fprintf( stderr, "ERROR: frame is null...\n" );
       		getchar();
       		break;
      	}

	
		
		detect_objects();
		
		
		detect_shape();
 		
 		
     		// Do not release the frame!
     	      //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
      	//remove higher bits using AND operator
      	if ( (cvWaitKey(30) & 255) == 27 ) break;	//wait for 30millisec. also if esc is pressed exit
    
 		
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

	 cvSaveImage(filename_chr, frame_org);
}


void detect_objects(void)
{
	frame=cvCloneImage(frame); 
      cvSmooth(frame, frame, CV_GAUSSIAN,7,7); //smooth the original image using Gaussian kernel 3,3

      IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
      cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
      imgThresh = GetThresholdedImage(imgHSV);
          
      cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,7,7); //smooth the binary image using Gaussian kernel 3,3
            
      shape_img = imgThresh;      
      cvShowImage("Filtered_image", imgThresh);           
      cvShowImage("Video", frame);
           
      //Clean up used images
      //cvReleaseImage(&imgHSV);
      //cvReleaseImage(&imgThresh);            
      //cvReleaseImage(&frame);	
}

IplImage* GetThresholdedImage(IplImage* imgHSV)
{       
       IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       cvInRangeS(imgHSV, cvScalar(0,120,0), cvScalar(6,256,256), imgThresh);		//(170,160,60) (180,256,256)
       return imgThresh;
} 

void detect_shape(void)
{	

	IplImage* gray = imgThresh;
	IplImage* img = frame_org;

(cvGetSize(gray), IPL_DEPTH_8U, 1);
CvMemStorage* storage = cvCreateMemStorage(0);


IplImage* canny = cvCreateImage(cvGetSize(gray),IPL_DEPTH_8U,1);
IplImage* rgbcanny = cvCreateImage(cvGetSize(gray),IPL_DEPTH_8U,3);
cvCanny(gray, canny, 50, 100, 3);

CvSeq* circles = cvHoughCircles(canny, storage, CV_HOUGH_GRADIENT, 1, 50.0, 100, 20,0,200);  //1, 40.0, 100, 100,0,0);
															  //dp, min dist, high thresh of canny,accumulator(small val more false circles,min rad, max rad)
														
cvCvtColor(canny, rgbcanny, CV_GRAY2BGR);

for (int i = 0; i < circles->total; i++)
{
     // round the floats to an int
     float* p = (float*)cvGetSeqElem(circles, i);
     cv::Point center(cvRound(p[0]), cvRound(p[1]));
     int radius = cvRound(p[2]);

     // draw the circle center
     cvCircle(img, center, 3, CV_RGB(0,255,0), -1, 8, 0 );

     // draw the circle outline
     cvCircle(img, center, radius+1, CV_RGB(0,255,0), 2, 8, 0 );

     ROS_INFO("x: %d y: %d r: %d\n",center.x,center.y, radius);
}


cvNamedWindow("circles", 1);
cvNamedWindow("Image", 1);
cvShowImage("circles", rgbcanny);
cvShowImage("Image", img);



       
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
