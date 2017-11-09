#define m1ina 10
#define m1inb 9
#define m1pwm 8
#define m2ina 7
#define m2inb 6
#define m2pwm 5

void setup()
{
  pinMode(m1ina, OUTPUT);
  pinMode(m1inb, OUTPUT);
  pinMode(m1pwm, OUTPUT);
  pinMode(m2ina, OUTPUT);
  pinMode(m2inb, OUTPUT);
  pinMode(m2pwm, OUTPUT);
}
void loop()
{
  digitalWrite(m1ina, LOW);
  digitalWrite(m1inb, HIGH);
  analogWrite(m1pwm, 255);
  digitalWrite(m2ina, LOW);
  digitalWrite(m2inb, HIGH);
  analogWrite(m2pwm, 255);

}
