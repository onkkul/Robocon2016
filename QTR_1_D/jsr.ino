#define DEBUG true

void setup(){
  if (DEBUG){
    //SerialDebugger.begin(2,9600); //can select uart
    SerialDebugger.begin(9600); //if this line is commented out, the binary sketch size will decrease by 332 bytes
  }
  SerialDebugger.enable(NOTIFICATION);
  //SerialDebugger.enable(ERROR);//uncomment if you want to debug ERRORs
}

void loop(){
  SerialDebugger.debug(NOTIFICATION,"loop","notifications are enabled");
  if (SerialDebugger.debug(ERROR,"loop","errors are disabled")){
    //do actions that might be required when debugging errors
    //(re)setting variables
    //additional SerialDebugger.debug() calls
  }
  delay(1000);
}
