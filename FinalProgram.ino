#include <PrintCascade.h>
#include <SerialDebug.h>



#include <PID_v1.h>

#include <QTRSensors.h>

#include <Servo.h>
int data[8] = {2, 3, 4, 5, 6, 7, 8, 9};
Servo servo;
double Setpoint, Input, Output;
double aggKp=4, aggKi=0.2, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;


PID myPID(&Input, &Output, &Setpoint, consKp, consKi, consKd, DIRECT);

int result[8];
void setup() {

if(DEBUG)
{
  SerialDebugger.begin(9600);
  }
SerialDebugger.enable(ERROR);

  Setpoint = 100;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);

  // put your setup code here, to run once:
  servo.attach(18);
  pinMode(data[0], INPUT);
  pinMode(data[1], INPUT);
  pinMode(data[2], INPUT);
  pinMode(data[3], INPUT);
  pinMode(data[4], INPUT);
  pinMode(data[5], INPUT);
  pinMode(data[6], INPUT);
  pinMode(data[7], INPUT);

}

void process()
{
  
  for (int i = 0; i <= 7; i++)
  {
    
  Input = analogRead(data[i]);
    
    unsigned long lastTime = 0;
    double Setpoint;
    double errSum;
    double lastErr;
    double kp = 1;
    double ki = 1;
    double kd = 1;
    /*How long since we last calculated*/
    unsigned long now = millis();


    double timeChange = (double)(now - lastTime);

    /*Compute all the working error variables*/
    double error = Setpoint - Input;
    errSum += (error * timeChange);
    double dErr = (error - lastErr) / timeChange;

    /*Compute PID Output*/
    Output = kp * error + ki * errSum + kd * dErr;
    Output = result[i];
    /* head = output(head, y);*/

    lastErr = error;
    lastTime = now;

  }
}

void logic_turns()
{
  if ((result[1] == LOW && result[2] == LOW && result[3] == LOW && result[4] == LOW && result[5] == LOW && result[6] == LOW) ||
      (result[1] == LOW && result[2] == LOW && result[3] == LOW && result[4] == LOW && result[5] == LOW && result[6] == LOW && result[7] == LOW) ||
      (result[0] == LOW && result[1] == LOW && result[2] == LOW && result[3] == LOW && result[4] == LOW && result[5] == LOW && result[6] == LOW) ||
      (result[0] == LOW && result[1] == LOW && result[2] == LOW && result[3] == LOW && result[4] == LOW && result[5] == LOW && result[6] == LOW && result[7] == LOW))
  {
    servo.write(90);
    delay(20);

  }
  else if ((result[0] == LOW && result[1] == LOW && result[2] == LOW) ||
           (result[0] == LOW && result[1] == LOW && result[2] == LOW && result[3] == LOW) ||
           (result[0] == LOW && result[1] == LOW && result[2] == LOW && result[3] == LOW && result[4] == LOW))
  {
    servo.write(-90);
    delay(20);
  }
  else if ((result[5] == LOW && result[6] == LOW && result[7] == LOW) ||
           (result[4] == LOW && result[5] == LOW && result[6] == LOW && result[7] == LOW) ||
           (result[3] == LOW && result[4] == LOW && result[5] == LOW && result[6] == LOW && result[7] == LOW))
  {
    servo.write(90);
    delay(20);
  }

}

void logic_follow()
{
  if ((result[0] == LOW) || (result[0] == LOW && result[1]))
  {
    servo.write(45);
    delay(20);
  }
  else if ((result[1] == LOW) || (result[2] == LOW && result[1]))
  {
    servo.write(35);
    delay(20);
  }
  else if ((result[2] == LOW) || (result[2] == LOW && result[3]))
  {
    servo.write(25);
    delay(20);
  }
  else if (result[3] == LOW)
  {
    servo.write(15);
    delay(20);
  }

  else if (result[4] == LOW)
  {
    servo.write(-15);
    delay(20);
  }

  else if (result[3] == LOW && result[4] == LOW)
  {
    servo.write(0);
    delay(20);
  }
  if ((result[7] == LOW) || (result[7] == LOW && result[6]))
  {
    servo.write(-45);
    delay(20);
  }
  else if ((result[6] == LOW) || (result[5] == LOW && result[6]))
  {
    servo.write(-35);
    delay(20);
  }
  else if ((result[5] == LOW) || (result[5] == LOW && result[4]))
  {
    servo.write(-25);
    delay(20);
  }

}


void loop() {
  // put your main code here, to run repeatedly:
SerialDebugger.debug(NOTIFICATION,"loop","notifications are enabled");
  if(SerialDebugger.debug(ERROR,"loop","errors are disabled"))
  process();
  logic_turns();
  logic_follow();
}
