#include <PID_v1.h>

#define PinIn A0
#define ENA 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENB 7
#define jpulse 0

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
double Kp = 2, Ki = 5, Kd = 1;
double RawInput, RawV = 0;
int lval, rval, LCD_pos;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PinIn);
  Setpoint = 2.25;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void trace()
{
  RawInput = analogRead(PinIn);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  delay(50);
  Input = LCD_pos ;
  myPID.Compute();
  Serial.print("raw input value is=");
  Serial.println(RawInput);
  Serial.print("raw input voltage is=");
  Serial.println(RawV);
  Serial.print("LCD position is=");
  Serial.println(LCD_pos);
  Serial.print("right rpm is=");
  Serial.println(rval);
  Serial.print("left rpm is=");
  Serial.println(rval);
}

void loop()
{
  trace();
  if (Output<35)
  {
    rval = map(Output, 0, 35, 55, 255);
    analogWrite(ENA, rval);
    lval=255-rval;
    analogWrite(ENB, lval);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
  }
  if (Output>35)
  {
    lval = map(Output, 35, 70, 55, 255);
    analogWrite(ENB, lval);
    rval=255-lval;
    analogWrite(ENA, rval);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
  }
  if (Output==35 && digitalRead(jpulse)==0)
  {
     analogWrite(ENB, 255);
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
  }
   if (Output==35 && digitalRead(jpulse)!=0)
  {
     analogWrite(ENB, 255);
    analogWrite(ENA, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, HIGH);
  }
}


