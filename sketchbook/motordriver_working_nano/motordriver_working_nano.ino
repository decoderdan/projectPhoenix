  /*
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
//#include <WProgram.h>
#include <Arduino.h>
#include <Servo.h> 
#include <ros.h>
#include <custom_msg/MotorConfig.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;
std_msgs::Float32 batteryStatusMotor;
std_msgs::Float32 batteryStatusSystem;

int mapped_front_left = 90;
int mapped_front_right = 90;
int mapped_back_left = 90;
int mapped_back_right = 90;
int mapped_front = 90;
int mapped_back = 90;
Servo front_left;
Servo front_right;
Servo back_left;
Servo back_right;
Servo front;
Servo back;


void motorConfigCallBack( const custom_msg::MotorConfig& msg){
  mapped_front_left = map(int(msg.front_left),-100,100,25,155);
  mapped_front_right = map(int(msg.front_right),-100,100,25,155);
  mapped_back_left = map(int(msg.back_left),-100,100,25,155);
  mapped_back_right = map(int(msg.back_right),-100,100,25,155);
  mapped_front = map(int(msg.front),-100,100,25,155);
  mapped_back = map(int(msg.back),-100,100,25,155);
  front_left.write(mapped_front_left);
  front_right.write(mapped_front_right);
  back_left.write(mapped_back_left);
  back_right.write(mapped_back_right);
  front.write(mapped_front);
  back.write(mapped_back);
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

ros::Subscriber<custom_msg::MotorConfig> sub("motor_config", &motorConfigCallBack );
ros::Publisher m("batteryStatusMotor", &batteryStatusMotor);
ros::Publisher s("batteryStatusSystem", &batteryStatusSystem);

void setup()
{
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(m);
  nh.advertise(s);
  front_left.attach(3); //attach it to pin 9
  front_right.attach(5); //attach it to pin 9
  back_left.attach(6); //attach it to pin 9
  back_right.attach(9); //attach it to pin 9
  front.attach(10); //attach it to pin 9
  back.attach(11); //attach it to pin 9
}

void loop()
{
  for (int thisPin = 0; thisPin < 1000; thisPin++)  {
    nh.spinOnce();
    delay(1);      
  }
  float batVoltage = averageAnalog(5);
  batVoltage = (batVoltage/1024)*26;
  batteryStatusMotor.data =  batVoltage;
  m.publish(&batteryStatusMotor);
  float sysVoltage = averageAnalog(6);
  sysVoltage = (sysVoltage/1024)*26;
  batteryStatusSystem.data =  sysVoltage;
  s.publish(&batteryStatusSystem);
}

int averageAnalog(int pin){
  int v=0;
  for(int i=0; i<4; i++) v+= analogRead(pin);
  return v/4;
}
