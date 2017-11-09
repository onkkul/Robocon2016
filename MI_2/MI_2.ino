#include <Servo.h>
#define PIN_INPUT A1

Servo lsa;
int Input = 0;
float InputV = 0;
int Output = 0;
float pos = 0;

void setup()
{

  lsa.attach(12);
  Serial.begin(9600);

}


void loop()
{

  Input = analogRead(PIN_INPUT);
  InputV = ((Input * 5) / 1023);
  if (InputV<0)
  {
    InputV=-InputV;
  }
  else
  {
    InputV;
  }
  pos = ((InputV / 4.5) * 70);
  if(pos<0)
  {
    pos=-pos;
  }
  else
  {
    pos;
  }
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
  
}

