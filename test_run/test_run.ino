#include <PID_v1.h>

#define PinIn A0
#define ENA 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENB 7

double SetPoint, InPut, OutPut;
double Kp = 2, Ki = 1, Kd = 0.1;
PID lpid(&InPut, &OutPut, &SetPoint, Kp, Ki, Kd, DIRECT);


void setup()
{
  pinMode(PinIn, INPUT);
  InPut = analogRead(A0);
  SetPoint = 2.25;
  lpid.SetMode(AUTOMATIC);
  Serial.begin(19200);// put your setup code here, to run once:

}

void loop()
{
  analogWrite(ENA, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 255);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 // Serial.print(analogWrite(ENA));
  /// put your main code here, to run repeatedly:
}
