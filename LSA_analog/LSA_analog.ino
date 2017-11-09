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
int pos = 90;

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
  lsa.write(pos);                                                                                                
  if ((!(digitalRead(U0))))
  {
    for (pos = 90; pos >= 0; pos--)
    {
      lsa.write(pos);
    }
    Serial.println("on U0, turning ##LEFT## by ##90##");
  }
  else if ((!(digitalRead(U0))) && (!(digitalRead(U1))))
  {
    for (pos = 90; pos >= 30; pos--)
    {
      lsa.write(pos);
    }

    Serial.println("on U1 & U2, turning ##LEFT## by ##60##");
  }
  /*else if ((!(digitalRead(U1))) && (!(digitalRead(U2))))
  {
    for (pos = 90; pos >= 60; pos--)
    {
      lsa.write(pos);
    }
    Serial.println("on U2 & U3, turning ##LEFT## by ##30##");
  }

  else if ((!(digitalRead(U2))) && (!(digitalRead(U3))))
  {
    for (pos = 90; pos >= 75; pos--)
    {
      lsa.write(pos);
    }
    Serial.println("on U2 & U3, turnig ##LEFT## by ##15##");
  }
  else if ((!(digitalRead(U3))) && (!(digitalRead(U4))))
  {
    lsa.write(pos);
    Serial.println("on U3 & U4,##MOVING FORWARD##");
  }
  else if ((!(digitalRead(U4))) && (!(digitalRead(U5))))
  {
    for (pos = 90; pos <= 105; pos++)
    {
      lsa.write(pos);
    }
    Serial.println("on U4 & U5,turning ##RIGHT## by ##15##");
  }
  else if ((!(digitalRead(U5))) && (!(digitalRead(U6))))
  {
    for (pos = 90; pos <= 120; pos++)
    {
      lsa.write(pos);
    }
    Serial.println("on U5 & U6,turning ##RIGHT## by ##30##");
  }
  else if ((!(digitalRead(U6))) && (!(digitalRead(U7))))
  {
    for (pos = 90; pos <= 150; pos++)
      lsa.write(pos);
    Serial.println("on U6 & U7,turning ##RIGHT## by ##60##");
  }
  else if ((!(digitalRead(U7))))
  {
    for (pos = 90; pos <= 180; pos++)
    {
      lsa.write(pos);
    }
    Serial.println("on U7,turning ##RIGHT## by ##90##");
  }
  else if ((!(digitalRead(U0))) && (!(digitalRead(U1))) && (!(digitalRead(U2))) && (!(digitalRead(U3))) && (!(digitalRead(U4))) && (!(digitalRead(U5))) && (!(digitalRead(U6))) && (!(digitalRead(U7))))
  {
    if (left == HIGH)
    {
      for (pos = 90; pos >= 0; pos--)
      {
        lsa.write(pos);
      }
      Serial.println("##JUNCTION## turnig ##left## by ##90##");
    }
    else if (left == LOW)
    {
      for (pos = 90; pos <= 180; pos++)
      {
        lsa.write(pos);
      }
      Serial.println("##JUNCTION## turnig ##right## by ##90##");
    }
  }
  else
  {
    delay (200);
    Serial.println("NO LINE DETECTED, WAITING FOR ACTION");
  }*/
}

