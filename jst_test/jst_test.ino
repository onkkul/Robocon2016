#include <PID_v1.h>
#include <Servo.h>

#define PIN_INPUT A1
#define U0 2
#define U1 3
#define U2 4
#define U3 5
#define U4 6
#define U5 7
#define U6 8
#define U7 9

Servo lsa;
int  LCD_pos;
int sval;
int RawInput;
int count = 0;
int turn = 0;
double RawV = 0;
double Kp = 0.8, Ki = 0, Kd = 0;
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


void setup()
{
  Setpoint = 70;
  lsa.attach(12);
  myPID.SetMode(AUTOMATIC);
  Serial.begin(115200);

}

void trace()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  Input = LCD_pos ;
  myPID.Compute();
  sval = map(Output, 0, 70, 110, 70);//ITS 65 n not 55
  lsa.write(sval);
  Serial.print("raw input value is=");
  Serial.println(RawInput);
  Serial.print("raw input voltage is=");
  Serial.println(RawV);
  Serial.print("LCD position is=");
  Serial.println(LCD_pos);
  Serial.print("Servo angle is=");
  Serial.println(sval);
}

void loop ()
{
  trace();
  
}

