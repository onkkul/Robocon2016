#include<Servo.h>
Servo test;
void setup()
{
  test.attach(13);
  // put your setup code here, to run once:

}

void loop()
{
  test.write(0);
  delay(200);
  //test.write(60);
  //delay(200);
  //test.write(120);
  //delay(200);
}
