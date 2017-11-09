int CS = 1;
int RS = 2;
int LS = 3;
int S1 = 4;
int S2 = 5;
int T1 = 24;
int T2 = 25;
int dir_LF = 6;
//int dir_LR = 7;
int dir_RF = 8;
//int dir_RR = 9;
int pwm_LF = 10;
//int pwm_LR = 11;
int pwm_RF = 12;
//int pwm_RR = 13;
int dir_up1 = 26;
int dir_up2 = 27;
int dir_up3 = 28;
int pwm_up1 = 29;
int pwm_up2 = 30;
int pwm_up3 = 31;
void climb()
{
  if ((!(digitalRead(T1))) && (!(digitalRead(T2))))
  {

    digitalWrite(dir_up1, LOW);
    digitalWrite(dir_up2, LOW);
    digitalWrite(dir_up3, LOW);
    analogWrite(pwm_up1, 0);
    analogWrite(pwm_up2, 0);
    analogWrite(pwm_up3, 0);
    Serial.println("STOP");
  }
  else
  {
    digitalWrite(dir_up1, HIGH);
    digitalWrite(dir_up2, HIGH);
    digitalWrite(dir_up3, HIGH);
    analogWrite(pwm_up1, 250);
    analogWrite(pwm_up2, 250);
    analogWrite(pwm_up3, 250);
    Serial.println("CLIMB");
  }
}


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
  if (digitalRead(LS) && (!(digitalRead(CS))) && digitalRead(RS) && digitalRead(S1) && digitalRead(S2))    // MOVE FORWARD
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
    //digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, HIGH);
    //digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_LF, 250);
    //analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 250);
    //analogWrite(pwm_RR, 250);
    Serial.println("FORWARD");
  }

  if ((!(digitalRead(LS))) && digitalRead(CS) && digitalRead(RS)) // HARD LEFT
  {
    digitalWrite(dir_LF, LOW);
    // digitalWrite(dir_LR, LOW);
    digitalWrite(dir_RF, HIGH);
    // digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_RF, 250);
    //analogWrite(pwm_RR, 250);
    analogWrite(pwm_LF, 0);
    //analogWrite(pwm_LR, 0);
    Serial.println("HARD LEFT");
  }

  if ((!(digitalRead(LS))) && digitalRead(CS))  // HARD RIGHT
  {
    digitalWrite(dir_LF, HIGH);
    //digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, LOW);
    //digitalWrite(dir_RR, LOW);
    analogWrite(pwm_LF, 250);
    //analogWrite(pwm_LR, 250);
    analogWrite(pwm_RF, 0);
    //analogWrite(pwm_RR, 0);
    Serial.println("HARD LEFT");
  }

  if (/*digitalRead(LS) &&*/ (!(digitalRead(CS))) /*&& digitalRead(RS)*/ && (!(digitalRead(S1))) && (!(digitalRead(S2)))) // BREAK
  {
    digitalWrite(dir_LF, LOW);
    // digitalWrite(dir_LR, LOW);
    digitalWrite(dir_RF, LOW);
    //digitalWrite(dir_RR, LOW);
    analogWrite(pwm_LF, 0);
    //analogWrite(pwm_LR, 0);
    analogWrite(pwm_RF, 0);
    //analogWrite(pwm_RR, 0);
    Serial.println("STOP");
    climb();
    delay(2000);

  }

}

