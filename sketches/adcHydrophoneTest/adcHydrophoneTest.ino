//This is to test the ads7800 with teensy
const int rcPin = 16;
const int csPin = 15; 
const int busyPin = 14;

int digitalData[12];  

void setup() {
  //start serial comunications between due and computer 
  Serial.begin(9600);

  pinMode(rcPin, OUTPUT );
  digitalWrite( rcPin , HIGH);  
  digitalWrite( csPin , LOW); 
}




void loop() {
  ///start a conversion by pulsing rcPin low : 
  digitalWrite( rcPin , LOW); 
  delayMicroseconds(1); 
  digitalWrite( rcPin , HIGH); 


  ///now wait for busyPin to go high, that will tell you that the conversion is done
  delayMicroseconds(100); 
  if( true ){
    ///now we should be able to read the data on the 12 digital output channels
    for( int a=0; a<12; a++){
      pinMode( a , INPUT);
      digitalData[a] = digitalRead( a );
      Serial.print( digitalData[a] );
    }
   
  }
  
  delay(1000);
  Serial.print( " one cycle \n" );
}
