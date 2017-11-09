#include <Servo.h>

Servo myservo;
Servo urservo;
int potpin_1 = A0;
int potpin_2 = A7;
int val_1;
int val_2;
void setup()
{
  myservo.attach(9);
  urservo.attach(10);
  Serial.begin(9600);
}


void loop()
{
  val_1 = analogRead(potpin_1);
  val_1 = map(val_1, 0, 1023, 0, 180);
  myservo.write(val_1);
  Serial.println(val_1);
  Serial.println(".............");
  delay(15);

  val_2 = analogRead(potpin_2);
  val_2 = map(val_2, 0, 1023, 0, 180);
  urservo.write(val_2);
  Serial.println(val_2);
  Serial.println("_______________");
  delay(15);
}

