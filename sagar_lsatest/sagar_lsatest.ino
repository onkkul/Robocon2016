#include <Servo.h>
int U0 = 2;
int U1 = 3;
int U2 = 4;
int U3 = 5;
int U4 = 6;
int U5 = 7;
int U6 = 8;
int U7 = 9;

int left = 10;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
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
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
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

  if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
  {
      for (pos = 90; pos <= 180; pos += 1) 
      {                               // goes from 0 degrees to 180 degrees
                                      // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(150);                       // waits 15ms for the servo to reach the position
      }
      Serial.println("##JUNCTION## turnig ##left## by ##90##");
    }
   /* else 
    {
      
     for (pos = 180; pos >= 0; pos -= 1)
     {                                    // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(150);                       // waits 15ms for the servo to reach the position
     }
      Serial.println("##JUNCTION## turnig ##right## by ##90##");
    }*/
  }



