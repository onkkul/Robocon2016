#include<Servo.h>
Servo lsa;
int U0 = 2;
int U1 = 3;
int U2 = 4;
int U3 = 5;
int U4 = 6;
int U5 = 7;
int U6 = 8;
int U7 = 9;
int left = 10;


void setup()
{
  lsa.attach(13);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(U0));
  Serial.println("....................");
  Serial.println(digitalRead(U1));
  Serial.println("....................");
  Serial.println(digitalRead(U2));
  Serial.println("....................");
  Serial.println(digitalRead(U3));
  Serial.println("....................");
  Serial.println(digitalRead(U4));
  Serial.println("....................");
  Serial.println(digitalRead(U5));
  Serial.println("....................");
  Serial.println(digitalRead(U6));
  Serial.println("....................");
  Serial.println(digitalRead(U7));
  Serial.println("______________________");

  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(0);
    Serial.println("on U0, turning ##LEFT## by ##90##");
  }

  else if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {               
    lsa.write(30);                                                                                   //(digitalRead(U0)==0)&&(digitalRead(U1)==0)&&(digitalRead(U2) == 0)&&(digitalRead(U3) == 0)&&(digitalRead(U4) == 0)&&(digitalRead(U5) == 0)&&(digitalRead(U6) == 0)&&(digitalRead(U7) == 0)
    Serial.println("on U0 & U1, turning ##LEFT## by ##60##");                                        //(digitalRead(U0)==1)&&(digitalRead(U1)==1)&&(digitalRead(U2) == 1)&&(digitalRead(U3) == 1)&&(digitalRead(U4) == 1)&&(digitalRead(U5) == 1)&&(digitalRead(U6) == 1)&&(digitalRead(U7) == 1)
  }
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))

  {
    lsa.write(60);
    Serial.println("on U1 & U2, turning ##LEFT## by ##30##");
  }

  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(75);
    Serial.println("on U2 & U3, turnig ##LEFT## by ##15##");
  }
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(90);
    Serial.println("on U3 & U4,##MOVING FORWARD##");
  }

  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
  {
    lsa.write(105);
    Serial.println("on U4 & U5,turning ##RIGHT## by ##15##");
  }
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 0))
  {
    lsa.write(120);
    Serial.println("on U5 & U6,turning ##RIGHT## by ##30##");
  }
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    lsa.write(150);
    Serial.println("on U6 & U7,turning ##RIGHT## by ##60##");
  }
  else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 1))
  {
    lsa.write(180);
    Serial.println("on U7,turning ##RIGHT## by ##90##");
  }
  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
    if (left == HIGH)
    {
      lsa.write(0);
      Serial.println("##JUNCTION## turnig ##left## by ##90##");
    }
    else if (left == LOW)
    {
      lsa.write(180);
      Serial.println("##JUNCTION## turnig ##right## by ##90##");
    }
  }
}
