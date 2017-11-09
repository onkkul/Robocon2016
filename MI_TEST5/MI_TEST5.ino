#include <PID_v1.h>
#include <Servo.h>

#define PIN_INPUT A1
 

Servo lsa;
int  LCD_pos;
int sval;
int RawInput = 0;
double RawV = 0;
//double LCD_pos = 0;
double Kp =1,Ki =0.1,Kd =0;
double Setpoint, Input, Output;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
//double LCD_pos =  map( LCD_pos, 0, 70, -35, 35);
void setup()
{
  Setpoint = 70;
  lsa.attach(12);
  myPID.SetMode(AUTOMATIC);
  Serial.begin(9600);
  

}

void loop()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  Input = LCD_pos ;
  myPID.Compute();
  sval=map(Output,0,70,115,65);
  lsa.write(sval);
  Serial.print("raw input value is=");
  Serial.println(RawInput);
  Serial.println("...........");
  Serial.print("raw input voltage is=");
  Serial.println(RawV);
  Serial.println("...................");
  Serial.print("LCD position is=");
  Serial.println(LCD_pos);
  Serial.println("........................");
  Serial.print("Servo angle is=");
  Serial.println(sval);
  Serial.println("________________________");
}
