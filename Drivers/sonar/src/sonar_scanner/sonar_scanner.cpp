#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <iostream>
#include <GL/glfw.h> // Include OpenGL Framework library

#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/ByteMultiArray.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include <custom_msg/SonarData.h>

#include "sonar_scanner.h"

#define WIDTH	600
#define HEIGHT 	600
#define DEPTH	255

#define PI 3.14159265

#define THRESHOLD 207

float bins;
float bearing;
int binsArr[90];
int binsArr2[90];
int binsCount;

float thresholdTmp = 0.0; //12dB Threshold = 0
float contrastTmp = 12.0; //12dB Range = 38.25

int imageArray[HEIGHT][WIDTH];
int imgx = 0, imgy = 0;

void sonarCallback(const custom_msg::SonarData& sonarData);

/************************************************
 * 
 * The maximum length of the sonar reading needs to be at most half
 * the diameter of the displayed circle.
 * 
 * *********************************************/

int main(int argc, char **argv)
{

	ros::init(argc, argv, "sonar_scanner");

	//Seed with the time.
	srand ( (unsigned)time ( NULL ) );

	/* Messages and services */

	ros::NodeHandle scannerN;	

	int i;

	ros::Subscriber newmsgsub = scannerN.subscribe("sonar", 100, sonarCallback);

	ros::Subscriber sub1 = scannerN.subscribe("sonarBearing", 100, bearingCallback);
	ros::Subscriber sub2 = scannerN.subscribe("sonarBins", 100, binsCallback);

	ros::Subscriber sub3 = scannerN.subscribe("sonarBinsArr", 100, binsArrCallback);
	ros::Subscriber sub4 = scannerN.subscribe("sonarBinsArr2", 100, binsArrCallback2);

	// Frame counter and window settings variables
	int frame      = 0, width  = WIDTH, height      = HEIGHT;
	int redBits    = 8, greenBits = 8,   blueBits    = 8;
	int alphaBits  = 8, depthBits = 0,   stencilBits = 0;
 
	// Flag to keep our main loop running
	bool running = true;
 
	// Initialise glfw
	glfwInit();
 
	// Create a window
	if(!glfwOpenWindow(width, height, redBits, greenBits, blueBits, alphaBits, depthBits, stencilBits, GLFW_WINDOW))
	{
		printf("Failed to open window!\n");
		glfwTerminate();
		return 0;
		}
 
	// Call our initGL function to set up our OpenGL options
	initGL(width, height);

/*	while (running == true)
	{

		// Get ros subscriptions
		ros::spinOnce();
		//Do trig to get the xy position of the pixels for the image
		pixelPlace( bearing  / 17.775, (int) bins * 6, genRand(255) );

		// Increase our frame counter
		frame++;
		//Debug
		//printf("Bearing : %f, Distance : %f, X : %d, Y : %d\n",  bearing / 17.775, bins * 6, imgx, imgy);
		
		// Draw the returned xy pixel on the image
		drawScene(imgx, imgy);
 
		// exit if ESC was pressed or window was closed
		running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
	
		//printascii();
		usleep(5000);		
		
	}

*/
		int j = 0;
		i = 0;

		while(1)
		{

			if(i > 360)
				i = 1;

				ros::spinOnce();
				
				for(j = 1; j < binsCount; j++)
				{
					pixelPlace(((float)bearing / 17.775) + 180.0, j*2, binsArr[j]);
				}
				drawScene( (int)imgx, (int)imgy, 150);
				running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
				usleep(1000);
				i++;
		}

	glfwTerminate();		
	return 0;

}
/****************************************************************
 * Do trig to get the xy coordinates of the thing
 * add on half width and half height so it's centred and some things need
 * flipping to make them right 
 * *********************************************************/
void pixelPlace( float theta, unsigned int distance, unsigned int depth )
{

	float x, y;
	if( (theta > 0 && theta < 90) || (theta > 181 && theta < 270) )	{

		theta = 90.0 - theta;
		//printf("< 90\n");
		x = (float)distance * cos( theta *PI/180);
		y = (float)distance * sin( theta *PI/180);
		//printf("%f = %f -- %f\n",theta, x, y);
		imgx = x + ( (float) WIDTH / 2.0) ;
		imgy = (y * -1)+ ( (float) HEIGHT / 2.0);

	}
	else {
		//printf("> 271 && < 360\n");
		y = (float)distance * cos(theta *PI/180);
		x = (float)distance * sin(theta *PI/180);		
		//printf("%f = %f -- %f\n",theta, x, y);
		imgx = x + ((float)WIDTH / 2);
		imgy = (y * -1) + ((float)HEIGHT / 2);
	}

	//imageArray[y][x] = 1;
	//if(depth > THRESHOLD)
	//	imageArray[imgx][imgy] = 255;
	//else
	//	imageArray[imgx][imgy] = 0;

	imageArray[imgx][imgy] = depth;	
}
/****************************************************************
 * print sonar readings in terminal, mega hacks. no longer used
 * ***********************************************************/
void printascii( void )
{

	int i, j;

	for( i = 0; i < HEIGHT; i ++ )
	{
		for( j = 0; j < WIDTH; j++ )
		{
			if(imageArray[i][j] >= 1)
			{
				printf("X ");
				imageArray[i][j] = 0;
			}
			else
				printf("- ");
		}
		printf("\n");
	}
}

int genRand( int n )
{
    
    return rand() % n;
    
}
/***************************************************************
 * set up an image using opengl
 * *************************************************************/
void initGL(int width, int height)
{
	// ----- Window and Projection Settings -----
 
	// Set the window title
	glfwSetWindowTitle("UWESub Sonar");
 
	// Setup our viewport to be the entire size of the window
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
 
	// Change to the projection matrix, reset the matrix and set up orthagonal projection (i.e. 2D)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 0, 1); // Paramters: left, right, bottom, top, near, far
 
	// ----- OpenGL settings -----
 
	glfwSwapInterval(1); 		// Lock to vertical sync of monitor (normally 60Hz, so 60fps)
 
	glEnable(GL_SMOOTH);		// Enable (gouraud) shading
 
	glDisable(GL_DEPTH_TEST); 	// Disable depth testing
 
	glEnable(GL_BLEND);		// Enable blending (used for alpha) and blending function to use
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
	glLineWidth(5.0f);		// Set a 'chunky' line width
 
	glEnable(GL_LINE_SMOOTH);	// Enable anti-aliasing on lines
 
	glPointSize(5.0f);		// Set a 'chunky' point size
 
	glEnable(GL_POINT_SMOOTH);	// Enable anti-aliasing on points
}

void hsv_to_rgb(float h, float s, float v, float &r, float &g, float &b){

    int i = (h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch(i % 6){
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*************************************************************
 * draw x, y position in red on the image
 * ***********************************************************/
void drawScene(unsigned int x, unsigned int y, unsigned int depth)
{

	int i, j;

	// Clear the screen
	//glClear(GL_COLOR_BUFFER_BIT);
 
	// Reset the matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
 
	// ----- Draw stuff! -----
 
	glBegin(GL_POINTS);


	for( i = 0; i < HEIGHT; i ++ )
	{
		for( j = 0; j < WIDTH; j++ )
		{
			if(imageArray[i][j] >= 1)
			{
				float r, g, b;
				//Threshold + mappedvaltocontrast

//ok, eg. we have some vals. 0, 20, 38, and 50.
//treshold = 0dB
//contrast = 12dB
//min_dB = threshold*3.1875 = 0;
//max_dB  = (threshold+contrast)*3.1875 = 38.25
//newval = map(input, min_dB, max_dB, 0.667, 0)

//so 
				float min_dB = thresholdTmp*3.1875; 
				float max_dB = (thresholdTmp + contrastTmp)*3.1875;
				
				//Take bin, and scale it between min and max contrast
				float val_in_dB = map(imageArray[i][j], min_dB, max_dB, 1.0, 0);
				if (val_in_dB < 0) val_in_dB = 0.0;
				if (val_in_dB > 1) val_in_dB = 1.0;
				
				//float dB_to_hue = map(val_in_dB, 0, 255, 0.667, 0.0);
				if (val_in_dB <= 0.16666) { //White zone
					glColor4f(1.0,1.0,1.0-val_in_dB,0.5);
				}
				else if (val_in_dB >= 0.83333) { //Black zone
					glColor4f(1.0-val_in_dB, 0.0, 1.0-val_in_dB,0.5);
				}
				else {
					hsv_to_rgb(val_in_dB,1.0,1.0,r,g,b);
					glColor4f(r,g,b,0.5);
				}				
				
				//glColor3ub(0, imageArray[i][j], imageArray[i][j]);
				//float dB_to_f = map(val_in_dB, min_dB, max_dB, 0.0, 1.0);
				glVertex2f(i, j);
				glVertex2f(0, 0);

				imageArray[i][j] = 0;
			}

		}
	}
	
	//Circles!
	//glColor3f(0.2, 0.3, 0.5);
	//glBegin(GL_POLYGON);
				//Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
				//Note that anything above 24 will have little affect on the circles appearance
				//Play with the numbers till you find the result you are looking for
				//Value 1.5 - Draws Triangle
				//Value 2 - Draws Square
				//Value 3 - Draws Hexagon
				//Value 4 - Draws Octagon
				//Value 5 - Draws Decagon
				//Notice the correlation between the value and the number of sides
				//The number of sides is always twice the value given this range
				//for(double i = 0; i < 2 * PI; i += PI / 1000) //<-- Change this 1000 to # of points
 					//glVertex3f(cos(i) * 30+(WIDTH/2), sin(i) * 30+(HEIGHT/2), 0.0);

	glEnd();
 
	// ----- Stop Drawing Stuff! ------
 
	glfwSwapBuffers(); // Swap the buffers to display the scene (so we don't have to watch it being drawn!)
}

void bearingCallback(const std_msgs::Float32::ConstPtr& sonarBearing){
bearing = sonarBearing->data;
return;
}

void binsCallback(const std_msgs::Float32::ConstPtr& sonarBins){
bins = sonarBins->data;
return;
}

void binsArrCallback(const std_msgs::Int32MultiArray::ConstPtr& sonarBinsArr)
{

int i = 0;
  // print all the remaining numbers
  for(std::vector<int>::const_iterator it = sonarBinsArr->data.begin(); it != sonarBinsArr->data.end(); ++it)
  {
    binsArr[i] = *it;
    if (binsArr[i] == 0) binsArr[i] = 1;
    i++;
  }
  binsCount = i;

return;
}

void binsArrCallback2(const std_msgs::Int32MultiArray::ConstPtr& sonarBinsArr2)
{
int i = 0;
  // print all the remaining numbers
  for(std::vector<int>::const_iterator it = sonarBinsArr2->data.begin(); it != sonarBinsArr2->data.end(); ++it)
  {
    binsArr2[i] = *it;
    i++;
  }

return;
}

void sonarCallback(const custom_msg::SonarData& sonarData) {
	bearing = sonarData.bearing;
	thresholdTmp = sonarData.threshold;
	contrastTmp = sonarData.contrast;
	//Get the bins	
	int i = 0;
  // print all the remaining numbers
  for(std::vector<int>::const_iterator it = sonarData.bins.data.begin(); it != sonarData.bins.data.end(); ++it)
  {
    binsArr[i] = *it;
    if (binsArr[i] == 0) binsArr[i] = 1;
    i++;
  }
  binsCount = i;

}
