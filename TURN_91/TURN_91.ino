#include <PID_v1.h>
#include <Servo.h>

#define PIN_INPUT A1
#define LeftMost1 2  //U0
#define LeftMost2 5  //U3
#define RightMost1 6 //U4
#define RightMost2 9 //U7

Servo lsa;
int left1, left2, right1, right2;
int  LCD_pos;
int sval;
int RawInput = 0;
int count = 0;// countL = 0, countR = 0;
double RawV = 0;
double Kp = 1, Ki = 0, Kd = 0;
double Setpoint, Input, Output;
char condtn;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
//double LCD_pos =  map( LCD_pos, 0, 70, -35, 35);
void setup()
{
  Setpoint = 70;
  lsa.attach(12);
  myPID.SetMode(AUTOMATIC);
  Serial.begin(9600);


}

void trace()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  LCD_pos = ((RawV / 4.5) * 70);
  Input = LCD_pos ;
  myPID.Compute();
  sval = map(Output, 0, 70, 135, 45);
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

void loop()
{
  left1 = digitalRead(LeftMost1);
  right1 = digitalRead(RightMost1);
  left2 = digitalRead(LeftMost2);
  right2 = digitalRead(RightMost2);

  if (left1 == LOW && right2 == LOW)
  {
    trace();
  }


  if (left1 == HIGH && left2 == HIGH && right1 == HIGH && right2 == HIGH)
  {
    //count++;
    //if (count == 1)
    
      lsa.write(30);
      delay(1500);
   //   trace();
    
  }

  if (left1 == HIGH && left2 == HIGH && right1 == HIGH && right2 == LOW)

  {
    lsa.write(35);
    //lsa.write(30);
    delay(500);
    //trace();
  }

  if (left1 == LOW && left2 == HIGH && right1 == HIGH && right2 == HIGH)
  {
    lsa.write(155);
    //lsa.write(150);
    //delay(1500);
    trace();
  }
  /*else
    {
    trace();
    }*/


  Serial.print("central count=");
  Serial.println(count);
  Serial.print("LeftMost=");
  Serial.println(left1);
  Serial.print("RightMost=");
  Serial.println(right1);

}
