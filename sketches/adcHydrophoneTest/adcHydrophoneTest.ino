

//This is to test the ads7800 with teensy
const int rcPin = 16;
const int csPin = 15; 
const int busyPin = 14;

int digitalData[12];  
  ///set up conversion array 
int conversionArray[12] = { 0 , 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 }; //4096};


void setup() {
  //start serial comunications between teensy and computer 
  Serial.begin(9600);


  //seting up pins 
  pinMode(rcPin, OUTPUT );
  pinMode(csPin, OUTPUT );
  pinMode(busyPin, INPUT );
  for( int a=0; a<12; a++){
    pinMode( a , INPUT);
  }
  
  //seting up initial conditions
  digitalWrite( rcPin , HIGH);  
  digitalWrite( csPin , LOW); 
}




void loop() {
  ///start a conversion by pulsing rcPin low : 
  digitalWrite( rcPin , LOW); 
  //delayMicroseconds(1); 
  //^ not sure if this is nessisary. probably not, but doesn't hurt if you've got the time
  digitalWrite( rcPin , HIGH); 


  ///now wait for busyPin to go high, that will tell you that the conversion is done
  while( busyPin == LOW){
    //do nothing, you're waiting here 
  }
  
  if( busyPin == HIGH ){
    ///now we should be able to read the data on the 12 digital output channels
    for( int a=0; a<12; a++){
      //get the data 
      digitalData[a] = digitalRead( a );
      
      ///print for diagnostic purposes 
      Serial.print( digitalData[a] );
    }
   
  }
  ///now put the data into an integer
  int analogueInteger = 0; 
  for( int a=0; a<12; a++){
    analogueInteger += digitalData[a]*conversionArray[a]; 
  }
  ///test that in serial
  Serial.print( "   " ); 
  Serial.print( analogueInteger ); 
  Serial.print( "   " ); 
  
  delay(1000);
  Serial.print( " one cycle \n" );
}
