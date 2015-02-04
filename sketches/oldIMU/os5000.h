

#ifdef __cplusplus
  extern "C" {
    //__attribute__((weak)) omit this as used in _write() in Print.cpp
  
    // this function overrides the one of the same name in Print.cpp
    int _write(int file, char *ptr, int len)
    {
        // send chars to zero or more outputs
        for (int i = 0; i < len; i++)  {
          #ifdef PRINTF_SERIAL  // see #define at top of file
            Serial.print(ptr[i]);
          #endif
          #ifdef PRINTF_SERIAL1  // see #define at top of file
            Serial1.print(ptr[i]);
          #endif
        }
        return 0;
    }
  } // end extern "C" section
#endif


char formatline[38] = "$C%fP%fR%fT%fMx%fMy%fMz%fAx%fAy%fAz%f";


class carlOS5000{
  public:
  arvp_msgs::IMU msg;
  
  bool verifyLine( char line [] ); 
  void interpretSerial( char line[] );
  
};

bool carlOS5000::verifyLine( char line[] ){
 if(line[0] != '$'){ return false;}
 
 int len = strlen(line); 
 char checksum; 
 int rv = sscanf(line+ (len-4), "*%hhx", &checksum);
 if(rv != 1){ return false; }
 return true; 
}; 

void carlOS5000::interpretSerial( char line[] ){
  sscanf( line , formatline ,&msg.heading , &msg.pitch, &msg.roll, 
          &msg.temp, &msg.mag[0] , &msg.mag[1] , &msg.mag[2], 
          &msg.accel[0] , &msg.accel[1] , &msg.accel[2] );
};



/*
enum os5000_result {OS5000_OK, OS5000_INVALID_LEN, OS5000_INVALID_START,
     OS5000_NO_CHECKSUM, OS5000_BAD_CHECKSUM, OS5000_UNKNOWN_ERROR};
     
class OS5000 {
public:
  OS5000(ros::NodeHandle *n);
  virtual ~OS5000();
  void handleLine(const char* line, int max, arvp_msgs::IMU* msg);
  static const char* format;
  ros::NodeHandle *nh;
  os5000_result parseLine(const char* line, int max, arvp_msgs::IMU* msg);
  static char calcChecksum(const char *line);
};

const char* OS5000::format = "$C%fP%fR%fT%fMx%fMy%fMz%fAx%fAy%fAz%f";

OS5000::OS5000(ros::NodeHandle *n) {
  Serial1.begin(115200);
  nh = n;
}

OS5000::~OS5000() {
  
}

os5000_result OS5000::parseLine(const char* line, int max, arvp_msgs::IMU* msg) {
  int rv;
  char checksum;
  int len = strnlen(line, max);

  if(!len || len > 100)  // TODO: what is the max valid length?
    return OS5000_INVALID_LEN;
  
  if(line[0] != '$')
    return OS5000_INVALID_START;
  
  rv = sscanf(line+ (len-4), "*%hhx", &checksum);
  if(rv != 1)
    return OS5000_NO_CHECKSUM;
  
  if(calcChecksum(line) != checksum)
    return OS5000_BAD_CHECKSUM;
   
   rv = sscanf(line, format, 
            &msg->heading, &msg->pitch, &msg->roll,
            &msg->temp,
            &msg->mag[0], &msg->mag[1], &msg->mag[2],
            &msg->accel[0], &msg->accel[1], &msg->accel[2]);
   
   if(rv != 10)
     return OS5000_UNKNOWN_ERROR;
     
   msg->header.stamp = nh->now();
   return OS5000_OK;
}

void OS5000::handleLine(const char* line, int max, arvp_msgs::IMU* msg) {
  os5000_result rv = parseLine(line, max, msg);
  
  nh->loginfo(line);
  if(rv != OS5000_OK) {
    switch(rv) {
      case OS5000_INVALID_LEN:
        nh->logerror("Invalid Length");
        break;
      case OS5000_INVALID_START:
        nh->logerror("Invalid start character");
        break;
      case OS5000_NO_CHECKSUM:
        nh->logerror("No checksum");
        break;
      case OS5000_BAD_CHECKSUM:
        nh->logerror("Bad checksum");
        break;
      case OS5000_UNKNOWN_ERROR:
        nh->logerror("Unknown error");
        break;  
    }
  }
}

char OS5000::calcChecksum(const char *line) {
  char cksum = 0;
  for(const char *c=line+1; *c != '*'; *c++)
    cksum ^= *c;
  return cksum;
}
*/
