#include <Bounce2.h>
#include <DualVNH5019MotorShield.h>


//THESE ARE REMAPPED PIN CONFIGURATIONS.
#define en1d 6
#define m1ina 7
#define m1inb 8
#define m1pwm 9           //pwm pins are fixed
#define m2pwm 10          //these pins cant be changed
#define m2ina 11
#define m2inb 12
#define en2d 13

#define cs1 A0
#define cs2 A1


/*
   THESE ARE ORIGINAL DEFAULT PIN CONFIGURATIONS
   THEY ARE HERE JUST FOR REFERENCE
  #define m1ina 2
  #define m1inb 4
  #define en1d 6
  #define cs1 a0
  #define m2ina 7
  #define m2inb 8
  #define en2d 12
  #define cs2 a1
  #define m1pwm 9
  #define m2pwm 10
*/


DualVNH5019MotorShield hound (m1ina, m1inb, en1d, cs1, m2ina, m2inb, en2d, cs2);

#define l1 2
#define l2 3
#define r2 4
#define r1 5



Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();
Bounce debouncer4 = Bounce();


int a;

/*void //stopIfFault()
  {
  if (hound.getM1Fault())
  {
    Serial.println("M1 fault");
    while (1);
  }
  if (hound.getM2Fault())
  {
    Serial.println("M2 fault");
    while (1);
  }
  }*/



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

  /* pinMode( m1ina, OUTPUT);
    pinMode( m1inb , OUTPUT);
    pinMode( m2ina , OUTPUT);
    pinMode( m2inb , OUTPUT);
    pinMode( m1pwm , OUTPUT);
    pinMode( m2pwm , OUTPUT);*/
  Serial.begin(9600);
}

void loop()
{
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();

  int lf = debouncer1.read();
  int lb = debouncer2.read();
  int rf = debouncer3.read();
  int rb = debouncer4.read();

  Serial.print("l1 is");
  Serial.println(lf);
  Serial.print("l2 is");
  Serial.println(lb);
  Serial.print("r1 is");
  Serial.println(rf);
  Serial.print("r2 is");
  Serial.println(rb);


  if (lf == 0 && lb == 1 && rf == 0 && rb == 1)
  {
    hound.setM1Speed(a);
    hound.setM2Speed(a);
    //stopIfFault();
    Serial.println("Both forward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 0 && rf == 1 && rb == 0)
  {
    hound.setM1Speed(a);
    hound.setM2Speed(a);
    //stopIfFault();
    Serial.println("Both backward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 0 && lb == 1 && rf == 1 && rb == 1)
  {
    hound.setM1Speed(a);
    hound.setM2Speed(0);
    //stopIfFault();
    Serial.println("left forward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 0 && rf == 1 && rb == 1)
  {
    hound.setM1Speed(-a);
    hound.setM2Speed(0);
    //stopIfFault();
    Serial.println("left bacward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }
  if (lf == 1 && lb == 1 && rf == 0 && rb == 1)
  {
    hound.setM1Speed(0);
    hound.setM2Speed(a);
    //stopIfFault();
    Serial.println("right forward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 1 && rf == 1 && rb == 0)
  {
    hound.setM1Speed(0);
    hound.setM2Speed(-a);
    //stopIfFault();
    Serial.println("right bacward");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 0 && rf == 0 && rb == 1)
  {
    hound.setM1Speed(-a);
    hound.setM2Speed(a);
    //stopIfFault();
    Serial.println("RF about turn");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 0 && lb == 1 && rf == 1 && rb == 0)
  {
    hound.setM1Speed(a);
    hound.setM2Speed(-a);
    //stopIfFault();
    Serial.println("LF about turn");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }

  if (lf == 1 && lb == 1 && rf == 1 && rb == 1)
  {
    hound.setBrakes(a, a);
    // hound.setM2Speed(0);
    //stopIfFault();
    Serial.println("STOP");
    Serial.println(" M1 current=");
    Serial.println(hound.getM1CurrentMilliamps());
    Serial.println(" M2 current=");
    Serial.println(hound.getM2CurrentMilliamps());
    Serial.println("-------------------");
  }
}
