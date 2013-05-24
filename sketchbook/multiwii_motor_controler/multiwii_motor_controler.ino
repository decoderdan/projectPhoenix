#include <Servo.h> 

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

Servo front_right_servo, back_right_servo,back_left_servo,front_left_servo;

void setup() {
  front_right_servo.attach(5);
  back_right_servo.attach(6);
  back_left_servo.attach(9);
  front_left_servo.attach(10);
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
  
  // print the string when a newline arrives:
  if (stringComplete) {
    int atPos = inputString.indexOf('@');
    int starPos = inputString.indexOf('*');
    if ((atPos != -1) && (starPos != -1) && (atPos < starPos)) {
      //possible message
      //Extract message and checksum
      String msg = inputString.substring(atPos+1, starPos);
      String cs = inputString.substring(starPos+1,starPos+3);
      cs += " ";
      //convert them to char arrays
      char checksum[3];
      char message[50];
      cs.toCharArray(checksum, 3);
      msg.toCharArray(message, 50);
      
      //Test checksums
      int testCs = getChecksum(message);      
      int number = (int)strtol(checksum, NULL, 16);
      
      if (number == testCs) {
        msg = msg + " ";
        msg.replace(',', ' ');
        msg.toCharArray(message, 50);
        char * pEnd;
        //Match. Extract values
        int front = (int)strtol(message, &pEnd, 10);
        int back = (int)strtol(pEnd, &pEnd, 10);
        int front_right = (int)strtol(pEnd, &pEnd, 10);
        int back_right = (int)strtol(pEnd, &pEnd, 10);
        int front_left = (int)strtol(pEnd, &pEnd, 10);
        int back_left = (int)strtol(pEnd, NULL, 10);
        
        front_right_servo.write(map(front_right, -100, 100, 0, 180));
        back_right_servo.write(map(back_right, -100, 100, 0, 180));
        back_left_servo.write(map(back_left, -100, 100, 0, 180));
        front_left_servo.write(map(front_left, -100, 100, 0, 180));
        
        //Serial.print("Front: ");
        //Serial.println(front);
        //Serial.print("Back: ");
        //Serial.println(back);
        //Serial.print("Front Right: ");
        //Serial.println(front_right);
        //Serial.print("Back Right: ");
        //Serial.println(back_right);
        //Serial.print("Front Left: ");
        //Serial.println(front_left);
        //Serial.print("Back Left: ");
        //Serial.println(back_left);
      }
    }
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

int getChecksum(char *s) {
  int c = 0;
  while(*s) c ^= *s++;
  return c;
}

