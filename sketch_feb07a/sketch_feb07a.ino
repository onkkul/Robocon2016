#include <Servo.h>

#define PIN_INPUT A1
 
int S1=7;


Servo lsa;
int  LCD_pos;
int i;
int RawInput = 0;
double RawV = 0;
//double LCD_pos = 0;
double Kp =1,Ki =0 ,Kd =0;
double Setpoint, Input, Output;

void setup()
{
  
  lsa.attach(12);
  Serial.begin(9600);
  

}

void loop()
{
 
    LSAFUN();
 
}

void LSAFUN()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  int Pos=map(LCD_pos,0,70,110,70);
  int LSAAngle=(180-Pos);
  if(LSAAngle>0)
  {
   lsa.write(LSAAngle);
  }
  else if(LSAAngle<=0)
  {
    LSAAngle= -(LSAAngle);
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

