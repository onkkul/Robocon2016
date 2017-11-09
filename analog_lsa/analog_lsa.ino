
#include<Servo.h>
Servo lsa;
int val1;
int U0 = A0;
int U1 = A1;
int U2 = A2;
int U3 = A3;
int U4 = A4;
int U5 = A5;
int U6 = 2;
int U7 = 3;
int left = 10;


void setup()
{
  lsa.attach(12);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
}

void loop()
{
  /*Serial.println(analogRead(U0));
  Serial.println("....................");
  Serial.println(analogRead(U1));
  Serial.println("....................");
  Serial.println(analogRead(U2));
  Serial.println("....................");
  Serial.println(analogRead(U3));
  Serial.println("....................");
  Serial.println(analogRead(U4));
  Serial.println("....................");

  Serial.println(analogRead(U5));
  Serial.println("....................");
  Serial.println(analogRead(U6));
  Serial.println("....................");
  Serial.println(analogRead(U7));
  Serial.println("______________________");*/
int vala=analogRead(U0);
int valb=analogRead(U1);
int valc=analogRead(U2);
int vald=analogRead(U3);
int vale=analogRead(U4);
int valf=analogRead(U5);
int vals0=map(vala,0,70,0,180);
int vals1=map(valb,0,70,0,180);
int vals2=map(valc,0,70,0,180);
int vals3=map(vald,0,70,0,180);
int vals4=map(vale,0,70,0,180);
int vals5=map(valf,0,70,0,180);
Serial.println(vals0);
Serial.println(vals1);
Serial.println(vals2);
Serial.println(vals3);
Serial.println(vals4);
Serial.println(vals5);
}
  /*                                ------------------------------------------------ALL THE CONDITION-----------------------------------------------------
    (analogRead(U0)==0)&&(analogRead(U1)==0)&&(analogRead(U2) == 0)&&(analogRead(U3) == 0)&&(analogRead(U4) == 0)&&(analogRead(U5) == 0)&&(analogRead(U6) == 0)&&(analogRead(U7) == 0)
    (analogRead(U0)==1)&&(analogRead(U1)==1)&&(analogRead(U2) == 1)&&(analogRead(U3) == 1)&&(analogRead(U4) == 1)&&(analogRead(U5) == 1)&&(analogRead(U6) == 1)&&(analogRead(U7) == 1)
  



  //streight condition     ************   tripel condition  ************
  if ((analogRead(U0) == 1) && (analogRead(U1) == 1) && (analogRead(U2) == 1) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(65);
    Serial.println("on U0 & U1 & U2, turning ##LEFT## by ##25##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 1) && (analogRead(U2) == 1) && (analogRead(U3) == 1) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(70);
    Serial.println("on U1 & U2 & U3, turning ##LEFT## by ##15##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 1) && (analogRead(U3) == 1) && (analogRead(U4) == 1) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(75);
    Serial.println("on U2 & U3 & U4, turnig ##LEFT## by ##5##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 1) && (analogRead(U4) == 1) && (analogRead(U5) == 1) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(85);
    Serial.println("on U3 & U4 & U5, turning ##RIGHT## BY ##5##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 1) && (analogRead(U5) == 1) && (analogRead(U6) == 1) && (analogRead(U7) == 0))
  {
    lsa.write(90);
    Serial.println("on U4 & U5 & U6,turning ##RIGHT## by ##15##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 1) && (analogRead(U6) == 1) && (analogRead(U7) == 1))
  {
    lsa.write(95);
    Serial.println("on U5 & U6 & U7,turning ##RIGHT## by ##25##");
  }



  //strate condition     ************   double condition  ************

 else if ((analogRead(U0) >= 0) && (analogRead(U1) <= 10) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(65);
    Serial.println("on U0 & U1, turning ##LEFT## by ##30##");  //(analogRead(U0)==1)&&(analogRead(U1)==1)&&(analogRead(U2) == 1)&&(analogRead(U3) == 1)&&(analogRead(U4) == 1)&&(analogRead(U5) == 1)&&(analogRead(U6) == 1)&&(analogRead(U7) == 1)
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) >= 10) && (analogRead(U2) <= 20) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(70);
    Serial.println("on U1 & U2, turning ##LEFT## by ##20##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) >= 20) && (analogRead(U3) <= 30) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(75);
    Serial.println("on U2 & U3, turnig ##LEFT## by ##10##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) >= 30) && (analogRead(U4) <= 40) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(80);
    Serial.println("on U3 & U4,##MOVING FORWARD##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) >= 40) && (analogRead(U5) <= 50) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(85);
    Serial.println("on U4 & U5,turning ##RIGHT## by ##10##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) >= 50) && (analogRead(U6) <= 60) && (analogRead(U7) == 0))
  {
    lsa.write(90);
    Serial.println("on U5 & U6,turning ##RIGHT## by ##20##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) >= 60) && (analogRead(U7) <= 70))
  {
    lsa.write(95);
    Serial.println("on U6 & U7,turning ##RIGHT## by ##30##");
  }



  //strate condition     ************   single condition  ************
  else if ((analogRead(U0) == 1) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(65);
    Serial.println("on U0, turning ##LEFT## by ##30##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 1) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(70);
    Serial.println("U1 high, turnig ##left## by ##20##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 1) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(75);
    Serial.println("U2 high,turning ##left## by ##10##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 1) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(80);
    Serial.println("U3 high,moving ##forward##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 1) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(80);
    Serial.println("U4 high,moving ##forward##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 1) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(85);
    Serial.println("U5 high, turnig ##right## by ##10##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 1) && (analogRead(U7) == 0))
  {
    lsa.write(90);
    Serial.println("U6 high, turnig ##right## by ##20##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 1))
  {
    lsa.write(95);
    Serial.println("on U7,turning ##RIGHT## by ##35##");
  }





  //       move right
  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 35) && (analogRead(U4) == 35) && (analogRead(U5) == 1) && (analogRead(U6) == 1) && (analogRead(U7) == 1))
  {
    lsa.write(180);
    Serial.println("##CORNER## turnig ##right## by ##90##");
  }

  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 1) && (analogRead(U5) == 1) && (analogRead(U6) == 1) && (analogRead(U7) == 1))
  {
    lsa.write(180);
    Serial.println("##CORNER## turnig ##right## by ##90##");
  }




  // move left
  else if ((analogRead(U0) == 1) && (analogRead(U1) == 1) && (analogRead(U2) == 1) && (analogRead(U3) == 1) && (analogRead(U4) == 1) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(0);
    Serial.println("##CORNER## turnig ##left## by ##90##");
  }

  else if ((analogRead(U0) == 1) && (analogRead(U1) == 1) && (analogRead(U2) == 1) && (analogRead(U3) == ) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(0);
    Serial.println("##CORNER## turnig ##left## by ##90##");
  }





  //   All HIGH

  else if ((analogRead(U0) == 1) && (analogRead(U1) == 1) && (analogRead(U2) == 1) && (analogRead(U3) == 1) && (analogRead(U4) == 1) && (analogRead(U5) == 1) && (analogRead(U6) == 1) && (analogRead(U7) == 1))
  {
    lsa.write(0);
    Serial.println("##JUNCTION## turnig ##left## by ##90##");
  }



  // ALL LOW
  else if ((analogRead(U0) == 0) && (analogRead(U1) == 0) && (analogRead(U2) == 0) && (analogRead(U3) == 0) && (analogRead(U4) == 0) && (analogRead(U5) == 0) && (analogRead(U6) == 0) && (analogRead(U7) == 0))
  {
    lsa.write(80);

  

*/


