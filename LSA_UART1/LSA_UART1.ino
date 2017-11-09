#include <Servo.h>

#define PIN_INPUT A1
#define AllHigh 8

Servo lsa;

int Turn;
int RawInput = 0;
int  LCD_pos;
double RawV = 0;
//double Kp = 1, Ki = 0 , Kd = 0;
//double Setpoint, Input, Output;

void setup()
{
  pinMode(8, INPUT);
  lsa.attach(12);
  Serial.begin(9600);

}

void LSAFUN()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  int Pos = map(LCD_pos, 0, 70, 110, 70);
  int LSAAngle = (180 - Pos);
  if (LSAAngle > 0)
  {
    lsa.write(LSAAngle);
  }
  else if (LSAAngle <= 0)
  {
    LSAAngle = -(LSAAngle);
    lsa.write(LSAAngle);
  }
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
  Serial.println(LSAAngle);
  Serial.println("________________________");
}

void loop()
{
  if (AllHigh == LOW)
  {
    LSAFUN();
  }

  else
  {
    lsa.write(90);
    Serial.println("ON 'T' turning by 90");
    delay(250);
  }
}



