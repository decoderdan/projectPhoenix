#include <Arduino.h>
 #include <Servo.h>
 #include <LiquidCrystal.h>
 #include <ros.h>
 #include <custom_msg/MotorConfig.h>
 #include <std_msgs/Float32.h>
 #include <std_msgs/String.h>
 #include <std_msgs/Bool.h>

 ros::NodeHandle nh;
 std_msgs::Float32 batteryStatusMotor;
 std_msgs::Float32 batteryStatusSystem;
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

 int emergencyKill = 0;		//kills motors
 int kill_switch = 2;			//emergency switch, 1= turned on,0 = turned off.
 int k_switch = 0;
 int safe = 0;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 100;    // the debounce time; increase if the output flickers



 int mapped_front_left = 90;		//Mapped motors set to off position.
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

 LiquidCrystal lcd(12, 8, A0, A1, A2, A3); // setup for the lcd

void motorConfigCallBack( const custom_msg::MotorConfig& msg) //Function sets up the arduino to accomodate the motor values.
 {
  mapped_front_left = map(int(msg.front_left),-100,100,25,155);		//Sets motor min,max and arduino min,max.
  mapped_front_right = map(int(msg.front_right),-100,100,25,155);
  mapped_back_left = map(int(msg.back_left),-100,100,25,155);
  mapped_back_right = map(int(msg.back_right),-100,100,25,155);
  mapped_front = map(int(msg.front),-100,100,25,155);
  mapped_back = map(int(msg.back),-100,100,25,155);

  front_left.write(mapped_front_left);		//assignes motor values to the corresponding motors.
  front_right.write(mapped_front_right);
  back_left.write(mapped_back_left);
  back_right.write(mapped_back_right);
  front.write(mapped_front);
  back.write(mapped_back);
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
  
 }


void motors_off(void)		//function sets all the motor speeds to 0.
 {
  front_left.write(90);
  front_right.write(90);
  back_left.write(90);
  back_right.write(90);
  front.write(90);
  back.write(90);
 }


void lcdLine1CallBack( const std_msgs::String& msg)	//sets up the first line of the LCD?
 {
  lcd.setCursor(0, 0); 					// set the cursor to column 0, line 0.
  lcd.print(msg.data);
 }

void lcdLine2CallBack( const std_msgs::String& msg)	//sets up the second line of the LCD?
 {
  lcd.setCursor(0, 1);					// set the cursor to column 0, line 1.
  lcd.print(msg.data);
 }

int averageAnalog(int pin)				//function is used for calculating battery voltage.
 {
  int v=0;
  for(int i=0; i<4; i++) v+= analogRead(pin);
  return v/4;
 }


void guiEmergencyCallBack( const std_msgs::Bool& eFlag)
 {
   if (eFlag.data)
     {
       emergencyKill = true;
     }
   if(!eFlag.data)
     {
       emergencyKill = false;
     }
 }
 
 ros::Subscriber<custom_msg::MotorConfig> sub("motor_config", &motorConfigCallBack ); 	//subscribes to the motor config input.
 ros::Publisher m("batteryStatusMotor", &batteryStatusMotor);				//publishes the motor battery status.
 ros::Publisher s("batteryStatusSystem", &batteryStatusSystem);				//publiches the system battery status.
 ros::Subscriber<std_msgs::String> sub1("lcd_line_1", &lcdLine1CallBack );		//subscribes to recieve a string from the host.
 ros::Subscriber<std_msgs::String> sub2("lcd_line_2", &lcdLine2CallBack );
 
// ros::Subscriber<std_msgs::Bool> emergency("emergency", &guiEmergencyCallBack );


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
    
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(m);
  nh.advertise(s);

  front_left.attach(3); 	//attach Front left motor to pin 3
  front_right.attach(5); 	//attach Front right to pin 5
  back_left.attach(6); 		//attach Back left to pin 6
  back_right.attach(9); 	//attach Back right to pin 9
  front.attach(10); 		//attach Front to pin 10
  back.attach(11); 		//attach Back to pin 11
 
 lcd.begin(20, 2);		//set up the LCD's number of columns and rows:
 lcd.setCursor(0, 0); 		// set the cursor to column 0, line 0
 lcd.print("  Project Phoenix   ");
 lcd.setCursor(0, 1);
 lcd.print("   www.uwesub.com   ");
 }


void loop() {
  
  	for (int i = 0; i < 1000; i++)	//used to only send the battery voltages once a second.
	 {  
	  nh.spinOnce();

  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin); 

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // toggle the ledState if the new button state changes
 
        ledState = !ledState;

    }
  }
  
  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;

		if(emergencyKill == true)
			 {
      			    motors_off();
    			    lcd.setCursor(0, 0); 
                            delay(1000);			//sets line and position of the LCD
    		    	    lcd.print("  Emergency Kill  ");
    		      	    lcd.setCursor(0, 1);
                            delay(1000);
    		    	    lcd.print("  Motors Dissabled ");
                            safe = 0;
  			 }
  
                       if(ledState == 0)
                       {
                            motors_off();
			 
                            if(k_switch == 0)
                              {
	 		        lcd.setCursor(0, 0);
                                delay(1000);			//sets line and position of the LCD
			        lcd.print("    Kill Switch    ");
		      	        lcd.setCursor(0, 1);
                                delay(1000);
		    	        lcd.print("  Motors Dissabled ");
                                k_switch = 1;
                                safe = 0;
                              }
			 
                       }


            if(safe == 0)
             {
                  if ((emergencyKill == false)&&(ledState == 1))                       {
                        {
                              lcd.clear();
                              lcd.setCursor(0, 0); 			//sets line and position of the LCD
                              lcd.print("          NO       ");
                              lcd.setCursor(0, 1);
                              lcd.print("         KILL      ");
                              k_switch = 0;
                              safe = 1;
                             
                        }
              }
  }
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



  


