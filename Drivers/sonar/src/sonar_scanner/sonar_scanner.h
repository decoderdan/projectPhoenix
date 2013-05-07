#define THRESHOLD 207

float bins;
float bearing;
int binsArr[90];
int binsArr2[90];
int binsCount;

void pixelPlace( float theta, unsigned int distance, unsigned int depth);
int genRand( int n );
void printascii( void );
void drawScene(unsigned int x, unsigned int y, unsigned int depth);
void initGL(int width, int height);
void bearingCallback(const std_msgs::Float32::ConstPtr& sonarBearing);
void binsCallback(const std_msgs::Float32::ConstPtr& sonarBins);
void binsArrCallback(const std_msgs::Int32MultiArray::ConstPtr& sonarBinsArr);
void binsArrCallback2(const std_msgs::Int32MultiArray::ConstPtr& sonarBinsArr2);
