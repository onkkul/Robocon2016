
#include <Servo.h>

Servo servoA;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int A,B,C,n,r1,r2,r3; // veriable to the sensors

int led1=12;
int led2=13;

void setup() {
pinMode(12,OUTPUT);
pinMode(13,OUTPUT); 
pinMode(2,OUTPUT);
pinMode(1,OUTPUT); 
 servoA.attach(10);  // attaches the servo on pin 13 to the servo object
  pinMode(3,INPUT); // generally the pins of aruino are input, need not to specify
  pinMode(4,INPUT); 
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10, OUTPUT); // need to specify the output pins
  A = digitalRead(3);
  B = digitalRead(4);
  C = digitalRead(5);
  n = digitalRead(6);
  r1 = digitalRead(7);
  r2 = digitalRead(8);
  r3 = digitalRead(9);
 
  // put your setup code here, to run once:

}

void loop() {


  led()&&led4();
  // put your main code here, to run repeatedly:

}

int led()
{
  digitalWrite(12,OUTPUT);
  digitalWrite(13,OUTPUT);
  digitalWrite(1,OUTPUT);
  digitalWrite(2,OUTPUT);
  return 0;
  }
  int led4()
  {
    if (A==0&&n==0&&r1==0)
  {
    servoA.write(pos);
  }
 else if (n==0&&A==0)
 { for (pos = 0; pos >= -15; pos -= 1)  // goes from 0 degrees to -15 degrees
                                       // in steps of 1 degree
    {
      servoA.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
 else if (A==0&&B==0)
 { for (pos = 0; pos >= -30; pos -= 1)
    {
      servoA.write(pos);
     delay(15);
     }
 }
 else if (B==0&&C==0)
 { for (pos = 0; pos >= -45; pos -= 1)
    {
      servoA.write(pos);
     delay(15);
     }
 }
 else if (n==0&&r1==0)
 { for (pos = 0; pos >= 15; pos += 1)
    {servoA.write(pos);
     delay(15);}
 }
 else if (r1==0&&r2==0)
 { for (pos = 0; pos >= 30; pos += 1)
    {servoA.write(pos);
     delay(15);}
 }
 else if (r2==0&&r3==0)
 { for (pos = 0; pos >= 45; pos += 1)
    {servoA.write(pos);
     delay(15);}
 }   
    return 0;
    }


 
