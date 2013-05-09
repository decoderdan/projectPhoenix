String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int led = 13;
boolean ledon = false;

void setup() {
  pinMode(led, OUTPUT);    
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  digitalWrite(led, LOW);
}

void loop() {
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
        ledon = !ledon;
        if (ledon) {
            digitalWrite(led, HIGH);
        }
        else {
          digitalWrite(led, LOW);
        }
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

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
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
}

int getChecksum(char *s) {
  int c = 0;
  while(*s) c ^= *s++;
  return c;
}


