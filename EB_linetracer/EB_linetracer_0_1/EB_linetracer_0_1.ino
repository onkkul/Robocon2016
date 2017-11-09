// Onkar Kulkarni
// SE computer
// program for line follower using servo motor

/* Assumptions:
 * maximum anglular displacement=+/-45*
 * no. of sensors used = 7 viz l1,l2,l3,n,r1,r2,r3.
 * sensors are mounted on front side of bot
 * bot is quad wheeled, front power wheels n rear dummy
 * sensors sense white line & are placed one cm apart from eachother
 * senser used is Size: 3.5x 1cm
 *                      Work Power : 5V DC
 *                      Detector distance: 10MM
 *                      Build-in Tcrt5000 Sensor NSOR
 */

#include <Servo.h>

Servo onkservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position
int l1,l2,l3,n,r1,r2,r3; // veriable to the sensors

void setup() {
  onkservo.attach(13);  // attaches the servo on pin 13 to the servo object
  pinMode(3,INPUT); // generally the pins of aruino are input, need not to specify
  pinMode(4,INPUT); // @akshay kachor need not to use all 6 sensers, only 3 are enough
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(13, OUTPUT); // need to specify the output pins
  l1 = digitalRead(3);
  l2 = digitalRead(4);
  l3 = digitalRead(5);
  n = digitalRead(6);
  r1 = digitalRead(7);
  r2 = digitalRead(8);
  r3 = digitalRead(9);
  }

void loop() {
 if (l1==0&&n==0&&r1==0)
  { onkservo.write(pos);
  }
 else if (n==0&&l1==0)
 { for (pos = 0; pos >= -15; pos -= 1)  // goes from 0 degrees to -15 degrees
                                       // in steps of 1 degree
    {
      onkservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
  }}
 else if (l1==0&&l2==0)
 { for (pos = 0; pos >= -30; pos -= 1)
    {onkservo.write(pos);
     delay(15);
     }
 }
 else if (l2==0&&l3==0)
 { for (pos = 0; pos >= -45; pos -= 1)
    {onkservo.write(pos);
     delay(15);}
 }
 else if (n==0&&r1==0)
 { for (pos = 0; pos >= 15; pos += 1)
    {
      onkservo.write(pos);
     delay(15);}
 }
 else if (r1==0&&r2==0)
 { for (pos = 0; pos >= 30; pos += 1)
    {onkservo.write(pos);
     delay(15);}
 }
 else if (r2==0&&r3==0)
 { for (pos = 0; pos >= 45; pos += 1)
    {onkservo.write(pos);
     delay(15);}
 }
 }
 
