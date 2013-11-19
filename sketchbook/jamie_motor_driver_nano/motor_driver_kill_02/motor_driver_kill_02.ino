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
 
 const int buttonPin = 2;   // the number of the pushbutton pin
 const int ledPin = 13;     // the number of the LED pin

 int emergencyKill = 0;		//kills motors
 int kill_switch = 2;		//emergency switch, 1= turned on,0 = turned off.
 int k_switch = 0;			//used to prevent the LCD from being spammed when the kill switch is active.
 int safe = 0;				//used to prevent the LCD from being spammed when the system is fine.

 int ledState = 2;           // the current state of the kill switch
 int buttonState;            // the current reading from the input pin
 int lastButtonState = 0;    // the previous reading from the kill switch

 long lastDebounceTime = 0;  // the last time the output pin was toggled
 long debounceDelay = 100;   // the debounce time; increase if the output flickers



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

 LiquidCrystal lcd(12, 8, A0, A1, A2, A3); // setup for the lcd pins on the arduino

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
  for(int i=0; i<4; i++) v+= analogRead(pin); //read from analog pin.
  return v/4;
 }


/*void guiEmergencyCallBack( const std_msgs::Bool& eFlag) //function checks for a change of the emergency kill flag.
 {
   if (eFlag.data) //if flag is set to 1
     {
       emergencyKill = true; //emergency kill triggered.
     }
   if(!eFlag.data) //if flag is set to 0
     {
       emergencyKill = false; //emergeny kill not triggered.
     }
 }
 */
 ros::Publisher m("batteryStatusMotor", &batteryStatusMotor);				//publishes the motor battery status.
 ros::Publisher s("batteryStatusSystem", &batteryStatusSystem);				//publiches the system battery status.
 
 ros::Subscriber<custom_msg::MotorConfig> sub("motor_config", &motorConfigCallBack ); 	//subscribes to the motor config input.
 
 ros::Subscriber<std_msgs::String> sub1("lcd_line_1", &lcdLine1CallBack );		//subscribes to recieve a string for the LCD.
 ros::Subscriber<std_msgs::String> sub2("lcd_line_2", &lcdLine2CallBack );
 
 //ros::Subscriber<std_msgs::Bool> emergency("emergency", &guiEmergencyCallBack );//subscribes to recieve a boolian value for the emergency kill.


void setup() 
 {
   pinMode(buttonPin, INPUT);
   pinMode(ledPin, OUTPUT);

   digitalWrite(ledPin, ledState);  // set initial LED state
    
   nh.initNode(); //initialises the node handle
  
   nh.subscribe(sub); //sets the node handles for the subscribers
   nh.subscribe(sub1);
   nh.subscribe(sub2);
  // nh.subscribe(emergency);
  
   nh.advertise(m);  //sets the node handles for the publishers.
   nh.advertise(s);
  

   front_left.attach(3); 	//attaches the motors to there corresponding pins
   front_right.attach(5); 	
   back_left.attach(6); 	
   back_right.attach(9); 	
   front.attach(10); 		
   back.attach(11); 		
  
   lcd.begin(20, 2);		//set up the LCD's number of columns and rows:
   lcd.setCursor(0, 0); 		// set the cursor to column 0, line 0
   lcd.print("  Project Phoenix   ");
   lcd.setCursor(0, 1);
   lcd.print("   www.uwesub.com   ");
 }


void loop() 
 { 
   for (int i = 0; i < 1000; i++)	//used to only send the battery voltages once a second.
    {  
      nh.spinOnce();

      int reading = digitalRead(buttonPin);   // read the state of the switch into a local variable:
  
      if (reading != lastButtonState)  // If the switch changed, due to noise or pressing:
       {
         lastDebounceTime = millis();  // reset the debouncing timer
       } 
  
      if ((millis() - lastDebounceTime) > debounceDelay) 
       {
         if (reading != buttonState)  // if the button state has changed: 
          {
            buttonState = reading;
            ledState = !ledState;  // toggle the ledState if the new button state changes
          }
       }
  
      digitalWrite(ledPin, ledState);
      lastButtonState = reading;  //reading from switch is saved for comparrison.

	  if(emergencyKill == true) //if the emergency kill command has been called.
	   {
         while (1) //just used to test to see if the emergency kill is working.
		  {
		    ledState =~ ledState; //flicker the LED
		    delay (1000);
		  }
     /*  motors_off();
    	 lcd.setCursor(0, 0); 
         delay(1000);			//sets line and position of the LCD
    	 lcd.print("  Emergency Kill  ");
    	 lcd.setCursor(0, 1);
         delay(1000);
    	 lcd.print("  Motors Dissabled ");
         safe = 0;*/
  	   }
  
      if(ledState == 0) //is the kill switch has been activated
       {
         motors_off(); //turn off motors
	
         if(k_switch == 0)
          {
	        lcd.setCursor(0, 0);  //sets line and position of the LCD
		    lcd.print("    Kill Switch    "); //print message
		    lcd.setCursor(0, 1);
            lcd.print("  Motors Dissabled ");
            k_switch = 1; //prevents this message from being sent again until the switch has been deactivated.
            safe = 0; //reset so the "no kill" message can be displayed.
          }
			 
       }


      if(safe == 0) //has the kill switch been activated during this program?
       {
         if ((emergencyKill == false)&&(ledState == 1)) //if none of the kill switches/commands are active.                      
          {
            lcd.setCursor(0, 0); 			//sets line and position of the LCD
            lcd.print("          NO       "); //display message
            lcd.setCursor(0, 1);
            lcd.print("         KILL      ");
            k_switch = 0; //reset k_switch
            safe = 1;	  //prevent this message from being displayed again until the switch has become active.
          }
       }
    }

   float batVoltage = averageAnalog(5);   //reads motor battery value from pin 5
   batVoltage = (batVoltage/1024)*26;     //converts that value into a voltage
   batteryStatusMotor.data =  batVoltage; //saves that value to the publisher variable.
   m.publish(&batteryStatusMotor);        //publishes motor battery voltage

   float sysVoltage = averageAnalog(6);    //reads system battery value from pin 6
   sysVoltage = (sysVoltage/1024)*26;      //converts value to a voltage
   batteryStatusSystem.data =  sysVoltage; //saves that to the publisher variable.
   s.publish(&batteryStatusSystem);        //publishes the system battery voltage.
 }

