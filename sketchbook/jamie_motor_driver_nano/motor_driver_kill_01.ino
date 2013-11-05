//********************************************************//
//** Name: motor_driver_kill_01				**//
//** Function: shuts off motors if they timeout, the	**//
//** switch is activated of an emergency call is sent.	**//
//********************************************************//

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


 int host_timeout = 0;			//timeout counter
 int emergency_kill = 0;		//kills motors
 int kill_switch = 2;			//emergency switch, 1= turned on,0 = turned off.
 int active_state = 0;			// 0 = on 

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
  host_timeout = 0;
 }


void motors_off(void)		//function sets all the motor speeds to 0.
 {
  front_left.write(90);
  front_right.write(90);
  back_left.write(90);
  back_right.write(90);
  front.write(90);
  back.write(90);
  science = 0;
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

 ros::Subscriber<custom_msg::MotorConfig> sub("motor_config", &motorConfigCallBack ); 	//subscribes to the motor config input.
 ros::Publisher m("batteryStatusMotor", &batteryStatusMotor);				//publishes the motor battery status.
 ros::Publisher s("batteryStatusSystem", &batteryStatusSystem);				//publiches the system battery status.
 ros::Subscriber<std_msgs::String> sub1("lcd_line_1", &lcdLine1CallBack );		//subscribes to recieve a string from the host.
 ros::Subscriber<std_msgs::String> sub2("lcd_line_2", &lcdLine2CallBack );


void setup()		//function allocates the pins of the arduino and sets up the LCD.
 {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
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

void loop ()
 { 
	for (int i = 0; i < 1000; i++)	//used to only send the battery voltages once a second.
	 {  
	  nh.spinOnce();
	
		if(active_state = 0)	//motors are enabled.
		 {

			if(emergency_kill = 1)
			 {
			  motors_off();
			  active_state = 1;			//dissables motors until a command is sent.
				
			  lcd.setCursor(0, 0); 			//sets line and position of the LCD
		    	  lcd.print("   EMERGENCY KILL   ");
		      	  lcd.setCursor(0, 1);
		    	  lcd.print("  Motors Dissabled  ");
			 }

			if (host_timeout >=1000)
			 {
			  motors_off();
			 
			  lcd.setCursor(0, 0); 			//sets line and position of the LCD
		    	  lcd.print("    TIMED OUT   ");
		      	  lcd.setCursor(0, 1);
		    	  lcd.print(" No data from host  ");
			 }

			if(digitalRead(kill_switch)==0)
			 {
			  motors_off();
			  active state = 1;			//dissables motors until a command is sent.
			 
	 		  lcd.setCursor(0, 0); 			//sets line and position of the LCD
			  lcd.print("    Kill Switch   ");
		      	  lcd.setCursor(0, 1);
		    	  lcd.print(" Motors Dissabled  ");
			 }
		 }

		if ((emergency_kill = 0) && (active_state = 1))	//waits for emergency_kill to be reset.
		 {
		  active state = 0;				
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











