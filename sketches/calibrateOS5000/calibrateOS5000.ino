#include <ArduinoHardware.h>


char line[200];


void setup() {
  //start serial comunications between teensy and os5000 
  Serial.begin(9600);
  ///start comunications between teensy and computer 
  Serial1.begin(115200);

}

void loop() {
  //Serial.print("\n -- ");
  if(Serial1.available() and Serial.available() ) {
    Serial1.readBytesUntil('\r\n', line, 200);




    
    Serial.print( line );  
    Serial.print(" \n");
    
  }
    
}
