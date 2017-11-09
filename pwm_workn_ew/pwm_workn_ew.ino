#include <Bounce2.h>


#define l1 2
#define l2 3
#define r2 4
#define r1 5
#define m1ina 9
#define m1inb 10
#define m2ina 11
#define m2inb 12
#define m1pwm 8
#define m2pwm 13
/*#define m1en 6
  #define m2en 12*/


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

  pinMode( m1ina, OUTPUT);
  pinMode( m1inb , OUTPUT);
  pinMode( m2ina , OUTPUT);
  pinMode( m2inb , OUTPUT);
  pinMode( m1pwm , OUTPUT);
  pinMode( m2pwm , OUTPUT);
  // pinMode( m1en, OUTPUT);
  //pinMode(  m2en, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  //digitalWrite(m1en, HIGH);
  //digitalWrite(m2en, HIGH);

  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();

  int lf = debouncer1.read();
  int lb = debouncer2.read();
  int rf = debouncer3.read();
  int rb = debouncer4.read();

  Serial.print("lF is");
  Serial.println(lf);
  Serial.print("lB is");
  Serial.println(lb);
  Serial.print("rF is");
  Serial.println(rf);
  Serial.print("rB is");
  Serial.println(rb);


  if (lf == 0 && lb == 1 && rf == 0 && rb == 1)
  {
    digitalWrite(m1ina, LOW);
    digitalWrite(m1inb, HIGH);
    digitalWrite(m2ina, HIGH);
    digitalWrite(m2inb, LOW);
    analogWrite(m2pwm, 255);
    analogWrite(m1pwm, 255);
    //stopIfFault();
    Serial.println("Both forward");
    Serial.println("-------------------");

  }

  if (lf == 1 && lb == 0 && rf == 1 && rb == 0)
  {
    
    digitalWrite(m1ina, HIGH);
    digitalWrite(m1inb, LOW);
    digitalWrite(m2ina, LOW);
    digitalWrite(m2inb, HIGH);
    analogWrite(m1pwm, 255);
    analogWrite(m2pwm, 255);
   
    //stopIfFault();
    Serial.println("Both backward");
    Serial.println("-------------------");
  }

  if (lf == 0 && lb == 1 && rf == 1 && rb == 1)
  {
    digitalWrite(m1ina, LOW);
    digitalWrite(m1inb, HIGH);
    analogWrite(m1pwm, 255);
    analogWrite(m2pwm, 0);
    //stopIfFault();
    Serial.println("left forward");
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 0 && rf == 1 && rb == 1)
  {
    digitalWrite(m1ina, HIGH);
    digitalWrite(m1inb, LOW);
    analogWrite(m1pwm, 255);
    analogWrite(m2pwm, 0);
    //stopIfFault();
    Serial.println("left bacward");
    Serial.println("-------------------");
  }
  if (lf == 1 && lb == 1 && rf == 0 && rb == 1)
  {
    digitalWrite(m2ina, HIGH);
    digitalWrite(m2inb, LOW);
    analogWrite(m1pwm, 0);
    analogWrite(m2pwm, 255);
    //stopIfFault();
    Serial.println("right forward");
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 1 && rf == 1 && rb == 0)
  {
    digitalWrite(m2ina, LOW);
    digitalWrite(m2inb, HIGH);
    analogWrite(m1pwm, 0);
    analogWrite(m2pwm, 255);
    //stopIfFault();
    Serial.println("right bacward");
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 0 && rf == 0 && rb == 1)
  {
    digitalWrite(m1ina, HIGH);
    digitalWrite(m1inb, LOW);
    digitalWrite(m2ina, HIGH);
    digitalWrite(m2inb , LOW);
    analogWrite(m1pwm, 255);
    analogWrite(m2pwm, 255);
    //stopIfFault();

    Serial.println("RF about turn");
    Serial.println("-------------------");

  }

  if (lf == 0 && lb == 1 && rf == 1 && rb == 0)
  {

     digitalWrite(m1ina, LOW);
    digitalWrite(m1inb, HIGH);
    digitalWrite(m2ina, LOW);
    digitalWrite(m2inb, HIGH);
    analogWrite(m1pwm, 255);
    analogWrite(m2pwm, 255);
    //stopIfFault();
    Serial.println("LF about turn");
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 1 && rf == 1 && rb == 1)
  {
    digitalWrite(m1ina, LOW);
    digitalWrite(m1inb, LOW);
    digitalWrite(m2ina, LOW);
    digitalWrite(m2inb, LOW);
    analogWrite(m1pwm, 0);
    analogWrite(m1pwm, 0);
    //stopIfFault();
    Serial.println("STOP");
    Serial.println("-------------------");
  }
}
