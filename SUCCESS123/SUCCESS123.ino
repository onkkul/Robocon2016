int dira = 7;
int dirb = 6;
int pwma = 5;
int pwmb = 4;
int LS = 8;
int CS = 9;
int RS = 3;


void setup() {

  pinMode(dira, OUTPUT);
  pinMode(dirb, OUTPUT);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(3, INPUT);
  digitalWrite(dira,1);
digitalWrite(dirb,1);
  digitalWrite(pwma,1);
  digitalWrite(pwmb,1);
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  int LS = digitalRead(8);
  int CS = digitalRead(9);
  int RS = digitalRead(3);
  Serial.println("..........................");
  Serial.println(LS);

  Serial.println(CS);
  Serial.println(RS);
  if ( LS == 1 && CS == 0 && RS == 1)
  {
    digitalWrite(dira, LOW);
    digitalWrite(dirb, LOW);
    digitalWrite(pwma, 1);
    digitalWrite(pwmb, 1);
  }
  else if ( LS == 0&& CS == 0 && RS == 1|| LS == 0 )
  {
    digitalWrite(dira, HIGH);
    digitalWrite(dirb, LOW);
    digitalWrite(pwma, 1);
    digitalWrite(pwmb, 1);
  }

  else if ( LS == 1 && CS == 0 && RS == 0 || RS== 0)
  {
    digitalWrite(dira, LOW);
    digitalWrite(dirb, HIGH);
    digitalWrite(pwma, 1);
    digitalWrite(pwmb, 1);
  }
  /*else if ( LS == 1 && CS == 1 && RS == 1 )
  {
    digitalWrite(dira, HIGH);
    digitalWrite(dirb, HIGH);
    digitalWrite(pwma, 1);
    digitalWrite(pwmb, 1);
  }*/
 else if ( LS == 0&& CS == 0 && RS == 0 )
  {
   digitalWrite(dira, HIGH);
    digitalWrite(dirb, LOW);
    digitalWrite(pwma, 1);
    digitalWrite(pwmb, 1);  }

}
