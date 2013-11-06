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
  // constants won't change. They're used here to 
  // set pin numbers:
  const int buttonPin = 2;    // the number of the pushbutton pin
  const int ledPin = 13;      // the number of the LED pin

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


 LiquidCrystal lcd(12, 8, A0, A1, A2, A3); // setup for the lcd


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
 
void setup()
  {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);

  // set initial LED state
    digitalWrite(ledPin, ledState);
  
    Serial.println("begin");
    
    lcd.begin(20, 2);		//set up the LCD's number of columns and rows:
    lcd.setCursor(0, 0); 		// set the cursor to column 0, line 0
    lcd.print("  Project Phoenix   ");
    lcd.setCursor(0, 1);
    lcd.print("   www.uwesub.com   ");
  }


void loop()
  {
    // read the state of the switch into a local variable:
    int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing:
    
    if (reading != lastButtonState) 
      {
        // reset the debouncing timer
        lastDebounceTime = millis();
      } 
  
    if ((millis() - lastDebounceTime) > debounceDelay) 
       {
        if (reading != buttonState) 
          {
            buttonState = reading; 
            ledState = !ledState;

          }
      }
  
  // set the LED:
    digitalWrite(ledPin, ledState);
  
    if(ledState) 
      {
        Serial.println("HIGH");
      }
    
    else 
      {
        Serial.println("LOW");
      }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
    lastButtonState = reading;

    if(ledState == 0)
      {
        if(k_switch == 0)
          {
	    lcd.setCursor(0, 0);			//sets line and position of the LCD
	    lcd.print("    Kill Switch    ");
	    lcd.setCursor(0, 1);
	    lcd.print("  Motors Dissabled ");
            k_switch = 1;
            safe = 0;
          }
			 
      }


    if(safe == 0)
      {
        if (ledState == 1)
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




  


