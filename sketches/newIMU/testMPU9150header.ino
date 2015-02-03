#include <Wire.h>
#include "MPU9150.h"
#include <ros.h>
#include <arvp_msgs/IMU.h> //this is the template for the custom IMU message

arvp_msgs::IMU imu; ///here I declare an object imu, which is a continer that ros 
//uses for it's message and also that I can put the data in. 

ros::NodeHandle nh;
ros::Publisher pub("mpu1950", &imu);
///^ this sets up a ros publisher node. I name it mpu1950 for the name of the chip

void setup() {
  setupMPU();

}

void loop() {
  // put your main code here, to run repeatedly:
  //char dataString; 
 //double temp = getDataMPU();
  IMUdata D; 
  getRawDataMPU(D);
  
  ///now I want to put that data into the imu mesg structure
  imu.heading = 1.0;
  imu.pitch = 1.0; 
  imu.roll = 1.0 ; ///these really should have sensor fused data from the compass and the gyros
  ///but that's not trivial. I'll let this be first. 
  imu.mag[0] = D.cmps[0]; 
  imu.mag[1] = D.cmps[1]; 
  imu.mag[2] = D.cmps[2]; 
  imu.accel[0] = D.accl[0];
  imu.accel[1] = D.accl[1];
  imu.accel[2] = D.accl[2];
  imu.temp = D.temp;
  imu.header.stamp = nh.now();
  
  pub.publish(&imu);
  nh.spinOnce();
  //Serial.print( temp );
  //Serial.print( "   "  );
}
