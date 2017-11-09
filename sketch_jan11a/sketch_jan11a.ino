
#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>

/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

Cytron_PS2Shield ps2(0, 1);

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 36, 37, 38, 39);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
  ps2.begin(57600);
  digitalWrite(40,HIGH);
  digitalWrite(41,LOW);
}

void loop() {
  // step one revolution  in one direction:
  if(ps2.readButton(PS2_CIRCLE)==0)
  {
  //Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  //delay(500);
  }
 else if(ps2.readButton(PS2_SQUARE)==0)
 {
  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  //delay(500);
}
}
