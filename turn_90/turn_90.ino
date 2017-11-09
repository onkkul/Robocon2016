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
//int left1, left2, right1, right2;
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
  sval = map(Output, 0, 70, 65 , 115);              // INTERCHANGED 65 AND 115
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
  /*left1 = digitalRead(LeftMost1);
    right1 = digitalRead(RightMost1);
    left2 = digitalRead(LeftMost2);
    right2 = digitalRead(RightMost2);
  */



  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    trace();
  }


  if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 1))
  {
    trace();
  }

  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    //count++;
    //if (count == 1)
    //{
    lsa.write(30);
    delay(1500);
    trace();
    //}
  }


  //       move right
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    lsa.write(115);
    Serial.println("##CORNER## turnig ##right## by ##90##");
    trace();
  }

  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    lsa.write(115);
    Serial.println("##CORNER## turnig ##right## by ##90##");
    trace();
  }




  // move left
  else if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(65);
    Serial.println("##CORNER## turnig ##left## by ##90##");
    trace();
  }

  else if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(65);
    Serial.println("##CORNER## turnig ##left## by ##90##");
    trace();
  }






  /*if (left1 == HIGH && left2 == HIGH && right1 == LOW && right2 == LOW)

    {
     lsa.write(30);
     lsa.write(30); delay(1500);
     trace();
    }

    if (left1 == LOW && left2 == LOW && right1 == HIGH && right2 == HIGH)
    {
     lsa.write(150);
     delay(1500);
     trace();
    }
    else
    {
     trace();
    }
  */














  Serial.print("left count=");
  //  Serial.println(countL);
  Serial.print("central count=");
  Serial.println(count);
  Serial.print("right count=");
  //  Serial.println(countR);
  Serial.print("LeftMost=");
  //Serial.println(left1);
  //Serial.print("RightMost=");
  //Serial.println(right1);

}
