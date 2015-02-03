#include <ArduinoHardware.h>
#include <ros.h>
#include <arvp_msgs/IMU.h>


//#include <stdio.h>
//#include <stdlib.h>

#include "os5000.h"

char line[200];
arvp_msgs::IMU imu;

ros::NodeHandle nh;
ros::Publisher pub("os5000", &imu);
//OS5000 *sensor;


void setup() {
  
  nh.initNode();
  //sensor = new OS5000(&nh);
  nh.advertise(pub);
  
  //c.msg.heading = 1.0; 

}

void loop() {
  if(Serial1.available()) {
    Serial1.readBytesUntil('\r\n', line, 200);
    //Serial.print( line);
    //sensor -> parseLine(line, 200, &imu);
    carlOS5000 c; 

    if( c.verifyLine(line) == true){
      c.interpretSerial(line);
      imu = c.msg;   
      pub.publish(&imu);

      nh.spinOnce();
    }
    
  }
    
}
