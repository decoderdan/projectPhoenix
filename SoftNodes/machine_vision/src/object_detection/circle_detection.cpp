#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv/cvwimage.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv/highgui.h>
#include <cv_bridge/CvBridge.h>

#include <string>
#include <time.h>
#include <ctime>
#include <cv.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <std_msgs/Float32.h>
#include <unistd.h>

#define MAX_DATE 12

void imageCallback(const sensor_msgs::ImageConstPtr&);

IplImage* filter_colour(void);
void detect_circles(IplImage*);
IplImage* GetThresholdedImage(IplImage*);

void circleSizeCallback(const std_msgs::Float32&);

void sendMyImage(image_transport::Publisher);

CvMemStorage* storage;

IplImage* frame = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);
IplImage* frame_org;// = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);;
IplImage* frame_recived = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);
IplImage* frame_sent;
sensor_msgs::CvBridge bridge_;

int process_flag = 1, last_flag =0;
float focal_length = 150;
float actual_radius = 0.1, buoy_dist;
IplImage* cv_input_ = cvCreateImage(cvSize(320,240), IPL_DEPTH_8U, 3);

int main(int argc, char **argv)
{	
	
	ros::init(argc, argv, "circle_dectection");

	ros::NodeHandle n;

	image_transport::ImageTransport it(n);
	
	//pubsished messages	
	image_transport::Publisher pub = it.advertise("circle/image", 1);
	//subscribed messages
	ros::Subscriber sub = n.subscribe("MV_target_circle", 1000, circleSizeCallback);
	image_transport::Subscriber imgsub = it.subscribe("camera/image", 1, imageCallback);
	
	//timers	
//	ros::Timer processImgTimer = n.createTimer(ros::Duration(0.5), processImgTimerCallback);	//create timer to set a flag to start processing
  	

	
	storage = cvCreateMemStorage(0);	//storage for circles
	
  
	cvNamedWindow("Video");     
	cvNamedWindow("HSV_img");
      cvNamedWindow("Filtered_image");
	cvNamedWindow("Edge_detection");
	
	cvMoveWindow("video", 0, 400); 
	cvMoveWindow("HSV_img",320,400);  
      cvMoveWindow("Filtered_image",640,400);
      cvMoveWindow("Edge_detection",980,400);

	//ros::Rate loop_rate(1);  //loop every 1hz

 
	while(ros::ok())
	{
		
     		if ( !cv_input_)
     		{
       		fprintf( stderr, "ERROR: frame is null...\n" );
       		last_flag = process_flag;	//if no images dont run prosessing
      	}

		if(process_flag != last_flag)
		{
		
				last_flag = process_flag;
				IplImage* imgThresh = filter_colour();
				detect_circles(imgThresh);
		
				sendMyImage(pub);
			
				cvReleaseImage(&imgThresh);
		
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

	//cv::WImageBuffer3_b image(frame_sent);
 	//sensor_msgs::ImagePtr sentmsg = sensor_msgs::CvBridge::cvToImgMsg(image.Ipl(), "rgb8");
	//pub.publish(sentmsg);
	//cvReleaseImage(&frame_sent);
}

IplImage* filter_colour(void)
{
	
	frame=cvCloneImage(cv_input_);	 
	
      cvSmooth(frame, frame, CV_GAUSSIAN,3,3); //smooth the original image using Gaussian kernel

      IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
      cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
      IplImage* imgThresh = GetThresholdedImage(imgHSV);
          
      cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,3,3); //smooth the binary image using Gaussian kernel
            
      cvShowImage("Filtered_image", imgThresh);           
      cvShowImage("HSV_img", imgHSV);
           
      //Clean up used images
      cvReleaseImage(&imgHSV);            
      
      return(imgThresh);

}

IplImage* GetThresholdedImage(IplImage* imgHSV)
{       
       IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       IplImage* imgThresh2=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       //cvInRangeS(imgHSV, cvScalar(0, 50, 30), cvScalar(10, 256, 256), imgThresh);		//(170,160,60) (180,256,256)
       //cvInRangeS(imgHSV, cvScalar(170, 50, 30), cvScalar(256, 256, 256), imgThresh2);
       //cvOr(imgThresh,imgThresh2,imgThresh);
       cvInRangeS(imgHSV, cvScalar(5, 20, 20), cvScalar(70, 256, 256), imgThresh);
       cvReleaseImage(&imgThresh2);
       return imgThresh;
} 

void detect_circles(IplImage* imgThresh)
{
	IplImage* canny = cvCreateImage(cvGetSize(imgThresh),IPL_DEPTH_8U,1);
	
	cvCanny(imgThresh, canny, 50, 100, 3);	
	cvShowImage("Edge_detection", canny);           
      
      CvSeq* circles = cvHoughCircles(canny, storage, CV_HOUGH_GRADIENT, 1, 50.0, 100, 25,15,320);  //1, 40.0, 100, 100,0,0);
															  //dp, min dist, high thresh of canny,accumulator(small val more false circles,min rad, max rad)
	
	
	for (int i = 0; i < circles->total; i++)
	{
	     // round the floats to an int
	     float* p = (float*)cvGetSeqElem(circles, i);
	     cv::Point center(cvRound(p[0]), cvRound(p[1]));
	     int radius = cvRound(p[2]);

	     // draw the circle center
	     cvCircle(frame, center, 3, CV_RGB(0,0,255), -1, 8, 0 );

	     // draw the circle outline
	     cvCircle(frame, center, radius+1, CV_RGB(0,255,0), 2, 8, 0 );

	     buoy_dist = actual_radius * focal_length/radius;		//real life radius * focal length / radius in pixels

	     ROS_INFO("x: %d y: %d r: %d buoy distance: %f\n",center.x,center.y, radius, buoy_dist);
	}
		
	//frame_sent = cvCloneImage(frame);
	
	cvShowImage("Video", frame);
	
	cvClearMemStorage(storage);
      cvReleaseImage(&canny);
      cvReleaseImage(&frame);	      	
}


void circleSizeCallback(const std_msgs::Float32& target_circle)
{
	actual_radius = target_circle.data;
}


void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  { 
    cv_input_ = bridge_.imgMsgToCv(msg, "bgr8"); 
    //cv::imshow("recived image", cv_input_->image);      
    
    process_flag = ~process_flag;
  }
  catch (sensor_msgs::CvBridgeException& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}
