#include <Bounce2.h>

#define l1 8
#define l2 6
#define r2 2
#define r1 4

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();
Bounce debouncer4 = Bounce();



void setup()
{
  pinMode(l1, INPUT_PULLUP);
  debouncer1.attach(l1);
  debouncer1.interval(5); // interval in ms
  pinMode(l2, INPUT_PULLUP);
  debouncer2.attach(l2);
  debouncer2.interval(5); // interval in ms
  pinMode(r1, INPUT_PULLUP);
  debouncer3.attach(r1);
  debouncer3.interval(5); // interval in ms
  pinMode(r2, INPUT_PULLUP);
  debouncer4.attach(r2);
  debouncer4.interval(5); // interval in ms
  //pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();

  int value1 = debouncer1.read();
  int value2 = debouncer2.read();
  int value3 = debouncer3.read();
  int value4 = debouncer4.read();

  Serial.print("l1 is");
  Serial.println(value1);
  Serial.print("l2 is");
  Serial.println(value2);
  Serial.print("r1 is");
  Serial.println(value3);
  Serial.print("r2 is");
  Serial.println(value4);
  Serial.println("-------------------");
  //Serial.println("Both forward");
}
