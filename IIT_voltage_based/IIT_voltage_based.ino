float left;
float right;
float center;
int voltageL;
int voltageC;
int voltageR;


void setup()
{
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (2, INPUT);
  pinMode (3, INPUT);
  pinMode (4, INPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
}

void loop()

{
  voltageL = analogRead(A2);
  voltageC = analogRead(A1);
  voltageR = analogRead(A0);
  left=voltageL* (5.0 / 1023.0);
  right=voltageR* (5.0 / 1023.0);
  center=voltageC* (5.0 / 1023.0);
  if ((left>4.0) && (right > 4) && (center < 1.5))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (((left<1.5) && (center>4.0)) && (right>4.0))
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (((left>4.0) && (center > 4.0)) && (right<1.5))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (((left<1.5) && (center <1.5)) && (right >4.0))
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (((left>4.0) && (center <1.5)) && (right <1.5))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if ((left == center) && (center == right) && (right >4.0))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(11, LOW);
  }
  else if ((left == center) && (center == right) && (right <1.5))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
  }
  Serial.println(left);
  Serial.println(".....................");
  Serial.println(center);
  Serial.println(".........................");
  Serial.println(right);
  Serial.println("________________________");
}
