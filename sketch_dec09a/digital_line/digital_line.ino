#define PIN_INPUT A1
#define U0 30
#define U1 31
#define U2 32
#define U3 33
#define U4 34
#define U5 35
#define U6 36
#define U7 37

int left = 8;
int in1 = 9;
int in2 = 10;
int in3 = 11;
int in4 = 12;
int right = 13;

void setup()
{
  pinMode(left, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(right, OUTPUT);
  Serial.begin(9600);
}

void loop()

{
  Serial.print("U0=");
  Serial.println(digitalRead(U0));
  Serial.print("U1=");
  Serial.println(digitalRead(U1));
  Serial.print("U2=");
  Serial.println(digitalRead(U2));
  Serial.print("U3=");
  Serial.println(digitalRead(U3));
  Serial.print("U4=");
  Serial.println(digitalRead(U4));
  Serial.print("U5=");
  Serial.println(digitalRead(U5));
  Serial.print("U6=");
  Serial.println(digitalRead(U6));
  Serial.print("U7=");
  Serial.println(digitalRead(U7));
  Serial.println("______________________");


  // ALL HIGH
  if (digitalRead(U0) == 1 && digitalRead(U1) == 1 && digitalRead(U2) == 1 && digitalRead(U3) == 1 && digitalRead(U4) == 1 && digitalRead(U5) == 1 && digitalRead(U6) == 1 && digitalRead(U7) == 1)
  {

    analogWrite(right, 100);
    analogWrite(left, 100);
    digitalWrite(in1, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, LOW);

  }



  //ALL LOW
  if (digitalRead(U0) == 0 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && digitalRead(U3) == 0 && digitalRead(U4) == 0 && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 0)
  {
    analogWrite(right, 100);
    analogWrite(left, 100);
    digitalWrite(in1, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, LOW);

  }

  /////////////////////////###################################DO NOT CHANGE THIS CODE##############################################?///////////////////////////////////


  //move left
  else if (digitalRead(U0) == 1 && digitalRead(U1) == 1 && digitalRead(U2) == 1 && (digitalRead(U3) == 1 || digitalRead(U4) == 1) && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 0)
  {
    analogWrite(right, 200);
    analogWrite(left, 100);

    digitalWrite(in1, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in4, LOW);
  }

  else if (digitalRead(U0) == 0 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && (digitalRead(U3) == 1 || digitalRead(U4) == 1) && digitalRead(U5) == 1 && digitalRead(U6) == 1 && digitalRead(U7) == 1)
  {
    analogWrite(right, 55);
    analogWrite(left, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in4, HIGH);
  }

  else if (digitalRead(U0) == 1 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && digitalRead(U3) == 0 && digitalRead(U4) == 0 && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 0)
  {
    analogWrite(right, 255);
    analogWrite(left, 55u);

    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
  }
  else if (digitalRead(U0) == 0 && (digitalRead(U1) == 1 || digitalRead(U2) == 1) && digitalRead(U3) == 0 && digitalRead(U4) == 0 && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 0)
  {
    analogWrite(right, 255);
    analogWrite(left, 150);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
  }

  else if (digitalRead(U0) == 0 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && (digitalRead(U3) == 1 || digitalRead(U4) == 1) && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 0)
  {
    analogWrite(right, 200);
    analogWrite(left, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    delay(30);
  }

  else if (digitalRead(U0) == 0 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && digitalRead(U3) == 0 && digitalRead(U4) == 0 && (digitalRead(U5) == 0 || digitalRead(U6) == 1 ) && digitalRead(U7) == 0)
  {
    analogWrite(right, 150);
    analogWrite(left, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    delay(30);
  }

  else if (digitalRead(U0) == 0 && digitalRead(U1) == 0 && digitalRead(U2) == 0 && digitalRead(U3) == 0 && digitalRead(U4) == 0 && digitalRead(U5) == 0 && digitalRead(U6) == 0 && digitalRead(U7) == 1)
  {
    analogWrite(right, 55);
    analogWrite(left, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW);
    delay(30);
  }

}

