#include <Servo.h>
#define PIN_INPUT A1

Servo lsa;


void setup()
{

  lsa.attach(12);
  //Input = analogRead(PIN_INPUT);
  
  Serial.begin(9600);

}


void loop()
{
  int Input=0;
  float InputV=0;
  int Output=0;
  int pos=0;
  Input = analogRead(PIN_INPUT);
  InputV = ((Input*5)/1023); 
  pos = ((InputV /4.5) * 70);
  lsa.write(pos);
  Serial.print("input value is=");
  Serial.println(Input);
  Serial.println(".......................");
  Serial.print("output value is=");
  Serial.println(Output);
  Serial.println(".......................");
  Serial.print("Servo angle is=");
  Serial.println(pos);
  Serial.println("________________________");
  delay(500);
}

