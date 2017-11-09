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
  Setpoint = 70                                                    ;
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
  sval = map(Output, 0, 70, 115, 65);//ITS 65 n not 55
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

void loop()
{
  Serial.print("U0=");
  Serial.println(digitalRead(U0));
  Serial.print("U1=");
  Serial.println(digitalRead(U1));
  Serial.print("U2=");
  Serial.println(digitalRead(U2));
  Serial.print("U3=");
  Serial.println(digitalRead(U3));
  Serial.print("U4=");
  Serial.println(digitalRead(U4));
  Serial.print("U5=");
  Serial.println(digitalRead(U5));
  Serial.print("U6=");
  Serial.println(digitalRead(U6));
  Serial.print("U7=");
  Serial.println(digitalRead(U7));
  Serial.println("______________________");



  // ALL HIGH
  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    //if (turn >= 1)       //change it
    //{

      //lsa.write(170);
      //Serial.println("##CORNER## turnig ##RIGHT## by ##30##");
      //delay(500);
      //trace();
    //}
    count++;
   // delay(20);
   // trace();
  }




  //ALL LOW
  if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    if (count >= 1)
    {
      lsa.write(50);
      Serial.println("detected ##T##");
      delay(500);
      trace();
      
    }
    else
    {
      lsa.write(83);
      Serial.println("moving 4ward");
      trace();
    }
  }




  // move left
  else if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && ((digitalRead(U3) == 1) || (digitalRead(U4) == 1)) && ((digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0)))
  {
    lsa.write(50);
    Serial.println("##CORNER## turnig ##LEFT## by ##30##");
    //trace();
  }




  //       move right
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && ((digitalRead(U3) == 1) || (digitalRead(U4) == 1)) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    lsa.write(130);
    Serial.println("##CORNER## turnig ##RIGHT## by ##30##");
    //delay(500);    //remove it
    //trace();
  }

  else if ((digitalRead(U0) == 0) || (digitalRead(U7) == 0))
  {
    trace();
  }


  else
  {
    trace();
  }
  Serial.print("central count=");
  Serial.println(count);



}
