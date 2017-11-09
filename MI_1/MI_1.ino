#include <PID_v1.h>
#include <Servo.h>

#define PIN_INPUT A1

Servo lsa;
int i;
int RawInput = 0;
double RawV = 0;
double LCD_pos = 0;
double Setpoint, PID_Input, Output;
double Kp = 2, Ki =0.1, Kd =1 ;
PID myPID(&PID_Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
void setup()
{
  Setpoint = 35;
  lsa.attach(12);
  myPID.SetMode(AUTOMATIC);
  Serial.begin(9600);

}

void loop()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  PID_Input = LCD_pos;
  myPID.Compute();
  lsa.write(Output);
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
  Serial.println(Output);
  Serial.println("________________________");
}
