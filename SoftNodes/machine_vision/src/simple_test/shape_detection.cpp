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

#define MAX_DATE 12

void saveImgTimerCallback(const ros::TimerEvent&);
std::string get_date(void);
std::string get_time(void);
void convert_cv_to_ros(void);
void detect_objects(void);
void detect_shape(void);
IplImage* GetThresholdedImage(IplImage*);

CvCapture* capture = 0;
IplImage* frame;
IplImage* frame_org;
IplImage* imgGrayScale;
IplImage* img;
IplImage* imgCanny;

namespace enc = sensor_msgs::image_encodings;

static const char WINDOW[] = "Image window";

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;
  
public:
  ImageConverter()
    : it_(nh_)
  {
    image_pub_ = it_.advertise("out", 1);
    image_sub_ = it_.subscribe("in", 1, &ImageConverter::imageCb, this);

    cv::namedWindow(WINDOW);
  }

  ~ImageConverter()
  {
    cv::destroyWindow(WINDOW);
  }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, enc::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
      cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));

    cv::imshow(WINDOW, cv_ptr->image);
    cv::waitKey(3);
    
    image_pub_.publish(cv_ptr->toImageMsg());
  }
};

int main(int argc, char **argv)
{	
	
	ros::init(argc, argv, "ros_image_capture");


	ros::NodeHandle n;
	
	ImageConverter ic;

	//pubsished messages

	//subscribed messages

	//timers
	//ros::Timer ros::NodeHandle::createTimer(ros::Duration, saveImgTimerCallback, bool oneshot = false); //declare timer	
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


		ImageConverter ic;	//convert cv image to ros image		
		
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

void convert_cv_to_ros(void)
{

}

void detect_objects(void)
{
	frame=cvCloneImage(frame); 
      cvSmooth(frame, frame, CV_GAUSSIAN,3,3); //smooth the original image using Gaussian kernel

      IplImage* imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
      cvCvtColor(frame, imgHSV, CV_BGR2HSV); //Change the color format from BGR to HSV
      IplImage* imgThresh = GetThresholdedImage(imgHSV);
          
      cvSmooth(imgThresh, imgThresh, CV_GAUSSIAN,3,3); //smooth the binary image using Gaussian kernel
            
      cvShowImage("Filtered_image", imgThresh);           
      cvShowImage("Video", frame);
           
      //Clean up used images
      cvReleaseImage(&imgHSV);
      cvReleaseImage(&imgThresh);            
      cvReleaseImage(&frame);	
}

void detect_shape(void)
{

}

IplImage* GetThresholdedImage(IplImage* imgHSV)
{       
       IplImage* imgThresh=cvCreateImage(cvGetSize(imgHSV),IPL_DEPTH_8U, 1);
       cvInRangeS(imgHSV, cvScalar(160,160,60), cvScalar(180,256,256), imgThresh);		//(170,160,60) (180,256,256)
       return imgThresh;
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
