#include <ArduinoHardware.h>
#include <ros.h>
#include <arvp_msgs/IMU.h>


//#include <stdio.h>
//#include <stdlib.h>


char line[200];
ros::NodeHandle nh;

arvp_msgs::IMU imu;
ros::Publisher pub("os5000", &imu);
#include "os5000.h"

//OS5000 *sensor;


void setup() {
  
  nh.initNode();
  nh.advertise(pub);
  Serial.begin(9600);
  Serial1.begin(115200);

}

void loop() {
  //Serial.print("\n -- ");
  if(Serial1.available()) {
    Serial1.readBytesUntil('\r\n', line, 200);
    //Serial.print( line);
    //Serial.print("\n - ");
    //sensor -> parseLine(line, 200, &imu);
    carlOS5000 c; 

    if( c.verifyLine(line) == true){
      c.interpretSerial(line);
      c.msg.header.stamp = nh.now();

      imu = c.msg; 
    
      Serial.print( imu.temp );  
      Serial.print(" \n");
      ///ok so imu object seems to be full...?
      
      pub.publish( &imu );

      nh.spinOnce();
      delay(100);
    }
    
  }
    
}
