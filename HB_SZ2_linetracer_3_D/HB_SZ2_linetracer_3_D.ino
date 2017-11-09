int CS = 1;
int RS = 2;
int LS = 3;
int S1 = 4;
int S2 = 5;
int dir_LF = 6;
int dir_LR = 7;
int dir_RF = 8;
int dir_RR = 9;
int pwm_LF = 10;
int pwm_LR = 11;
int pwm_RF = 12;
int pwm_RR = 13;



void setup()
{
  pinMode(LS, INPUT);
  pinMode(CS, INPUT);
  pinMode(RS, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(dir_LF, OUTPUT);
  pinMode(dir_LR, OUTPUT);
  pinMode(dir_RF, OUTPUT);
  pinMode(dir_RR, OUTPUT);
  pinMode(pwm_LF, OUTPUT);
  pinMode(pwm_LR, OUTPUT);
  pinMode(pwm_RF, OUTPUT);
  pinMode(pwm_RR, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(LS) && (!(digitalRead(CS))) && digitalRead(RS))    // MOVE FORWARD
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    Serial.println("FORWARD");

  }

  if ((!(digitalRead(LS))) && (!(digitalRead(CS))) && digitalRead(RS)) // misalighned to the left
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, LOW);
    digitalWrite(dir_RR, LOW);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    analogWrite(pwm_LF, 0);
    analogWrite(pwm_LR, 0);
    Serial.println("LITTLE LEFT, ADJUSTING");
  }

  if (digitalRead(LS) && (!(digitalRead(CS))) && (!(digitalRead(RS))) && digitalRead(S1)) // misalighned to the right
  {
    digitalWrite(dir_LF, LOW);
    digitalWrite(dir_LR, LOW);
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 0);
    analogWrite(pwm_RR, 0);
    Serial.println("LITTLE RIGHT, ADJUSTING");
  }

  if ((!(digitalRead(LS))) && (!(digitalRead(CS))) && (!(digitalRead(RS))))   // ALL HIGH, GO FORWARD
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    Serial.println("FORWARD");
  }

  if ((!(digitalRead(LS))) && digitalRead(CS) && digitalRead(RS)) // HARD LEFT
  {
    digitalWrite(dir_LF, LOW);
    digitalWrite(dir_LR, LOW);
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    analogWrite(pwm_LF, 0);
    analogWrite(pwm_LR, 0);
    Serial.println("HARD LEFT");
  }

  if ((!(digitalRead(LS))) && digitalRead(CS))  // HARD RIGHT
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, LOW);
    digitalWrite(dir_RR, LOW);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 0);
    analogWrite(pwm_RR, 0);
    Serial.println("HARD LEFT");
  }

  if (/*digitalRead(LS) && (!(digitalRead(CS))) && digitalRead(RS) &&*/ (!(digitalRead(S1))) && (!(digitalRead(S2)))) // BREAK 
  {
    digitalWrite(dir_LF, LOW);
    digitalWrite(dir_LR, LOW);
    digitalWrite(dir_RF, LOW);
    digitalWrite(dir_RR, LOW);
    analogWrite(pwm_LF, 0);
    analogWrite(pwm_LR, 0);
    analogWrite(pwm_RF, 0);
    analogWrite(pwm_RR, 0);
    Serial.println("STOP");
  }

}

