  /*
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
//#include <WProgram.h>
#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <ros.h>
#include <custom_msg/MotorConfig.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;
std_msgs::Float32 batteryStatusMotor;
std_msgs::Float32 batteryStatusSystem;
int science = 1;
int host_timeout = 0;
int emergency_kill = 0;
int kill_switch = 2;
int active_state = 0;
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

LiquidCrystal lcd(12, 8, A0, A1, A2, A3); // the lcd

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
  host_timeout = 0;
}
void motors_off(void){
  front_left.write(90);
  front_right.write(90);
  back_left.write(90);
  back_right.write(90);
  front.write(90);
  back.write(90);
  science = 0;
}

void lcdLine1CallBack( const std_msgs::String& msg){
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print(msg.data);
}

void lcdLine2CallBack( const std_msgs::String& msg){
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print(msg.data);
}

ros::Subscriber<custom_msg::MotorConfig> sub("motor_config", &motorConfigCallBack );
ros::Publisher m("batteryStatusMotor", &batteryStatusMotor);
ros::Publisher s("batteryStatusSystem", &batteryStatusSystem);
ros::Subscriber<std_msgs::String> sub1("lcd_line_1", &lcdLine1CallBack );
ros::Subscriber<std_msgs::String> sub2("lcd_line_2", &lcdLine2CallBack );

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
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

  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 2);
  // Print a message to the LCD.

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print("  Project Phoenix   ");
  lcd.setCursor(0, 1);
  lcd.print("   www.uwesub.com   ");
}

void loop()
{
  for (int i = 0; i < 1000; i++)  {
    nh.spinOnce();
    if(active_state==0){
      if(emergency_kill==0){
        host_timeout++;
        delay(1);
        if(host_timeout<=10 & science ==0){
          lcd.setCursor(0, 0); // set the cursor to column 0, line 0
          lcd.print(" !!! STAND BACK !!! ");
          lcd.setCursor(0, 1);
          lcd.print("SCIENCE IS HAPPENING");
          science = 1;
        }
        if(host_timeout>=1000){
          motors_off();
          lcd.setCursor(0, 0); // set the cursor to column 0, line 0
          lcd.print("  Motors disabled   ");
          lcd.setCursor(0, 1);
          lcd.print(" No data from host  ");
        }
        if(digitalRead(kill_switch)==0){
          delay(500);
          emergency_kill = 1;
          lcd.begin(20, 2);
          lcd.setCursor(0, 0); // set the cursor to column 0, line 0
          lcd.print("  Motors disabled   ");
          lcd.setCursor(0, 1);
          lcd.print("  Killed by switch  ");
        }
      }
      else if (emergency_kill=1){
        motors_off();
        if(digitalRead(kill_switch)==1){
          //active_state = 1;
          emergency_kill=0;
        }
      }
    }
    /*
    else if(active_state==1){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn off in 3    ");
      delay(1000);
      if(digitalRead(kill_switch)==1){active_state = 2;}
      if(digitalRead(kill_switch)==0){active_state = 10;}
    }
    else if(active_state==2){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn off in  2   ");
      delay(1000);
      if(digitalRead(kill_switch)==1){active_state = 3;}
      if(digitalRead(kill_switch)==0){active_state = 10;}
    }
    else if(active_state==3){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn off in   1  ");
      delay(2000);
      if(digitalRead(kill_switch)==1){active_state = 4;}
      if(digitalRead(kill_switch)==0){active_state = 10;}
    }
    else if(active_state==4){
      lcd.begin(20, 2);
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn on in 3     ");
      delay(1000);
      if(digitalRead(kill_switch)==0){active_state = 5;}
      if(digitalRead(kill_switch)==1){active_state = 10;}
    }
    else if(active_state==5){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn on in  2    ");
      delay(1000);
      if(digitalRead(kill_switch)==0){active_state = 6;}
      if(digitalRead(kill_switch)==1){active_state = 10;}
    }
    else if(active_state==6){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("arm sequence started");
      lcd.setCursor(0, 1);
      lcd.print("   turn on in   1   ");
      delay(2000);
      if(digitalRead(kill_switch)==0){active_state = 10;}
      if(digitalRead(kill_switch)==1){active_state = 7;}
    }
    else if(active_state==7){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("  arming complete   ");
      lcd.setCursor(0, 1);
      lcd.print("active in 3 secconds");
      delay(3000);
      active_state = 0;
      emergency_kill = 0;
    }
    else if(active_state==10){
      lcd.setCursor(0, 0); // set the cursor to column 0, line 0
      lcd.print("   arming failed    ");
      lcd.setCursor(0, 1);
      lcd.print("     try again      ");
      delay(1000);
      active_state = 0;
      emergency_kill = 1;
    }
    */
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

// lcd callbacks


