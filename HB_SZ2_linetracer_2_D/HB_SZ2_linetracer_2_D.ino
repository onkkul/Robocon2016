int S1 = 1;
int S2 = 2;
int S3 = 3;
int S1 = 4;
int S1 = 5;
int S1 = 6;
int S1 = 7;
int S1 = 8;
int T1 = ?;
int T2 = ?;
int dir_LF = 9;
int dir_LR = 10;
int dir_RF = 11;
int dir_RR = 12;
int pwm_LF = 13;
int pwm_LR = ?;
int pwm_RF = ?;
int pwm_RR = ?;



void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(S7, INPUT);
  pinMode(S8, INPUT);
  pinMode(T1, INPUT);
  pinMode(T2, INPUT);
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
  if (digitalRead(S1) && digitalRead(S2) && digitalRead(S3)&& (!(digitalRead(S4)))&& (!(digitalRead(S5)))&& digitalRead(S6)&&digitalRead(S7)&& digitalRead(S8)  )  if (digitalRead(S1) && digitalRead(S2) && digitalRead(S3)&& (!(digitalRead(S4)))&& (!(digitalRead(S5)))&& digitalRead(S6)&&digitalRead(S7)&& digitalRead(S8)  )    // MOVE FORWARD
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
    if (digitalRead(S1) && digitalRead(S2) && digitalRead(S3)&& (digitalRead(S4)&& (!(digitalRead(S5)))&& (!(digitalRead(S6)))&&digitalRead(S7)&& digitalRead(S8)  ) // misalighned to the left
  {
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    Serial.println("LITTLE LEFT, ADJUSTING");
  }

   if (digitalRead(S1) && digitalRead(S2) && (!(digitalRead(S3)))&& (!(digitalRead(S4)))&& digitalRead(S5)&& digitalRead(S6)&&digitalRead(S7)&& digitalRead(S8)  ) // misalighned to the right
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    Serial.println("LITTLE RIGHT, ADJUSTING");
  }

   if ((!(digitalRead(S1))) && (!(digitalRead(S2))) && (!(digitalRead(S3)))&& (!(digitalRead(S4)))&& (!(digitalRead(S5)))&& (!(digitalRead(S6)))&&(!(digitalRead(S7)))&& (!(digitalRead(S8)))  )   // ALL HIGH, GO FORWARD
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

 /* if ((!(digitalRead(LS))) && digitalRead(CS) && digitalRead(RS)) // HARD LEFT
  {
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_RF, 250);
    analogWrite(pwm_RR, 250);
    Serial.println("HARD LEFT");
  }

  if ((!(digitalRead(LS))) && digitalRead(CS) && digitalRead(RS))  // HARD RIGHT
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    analogWrite(pwm_LF, 250);
    analogWrite(pwm_LR, 250);
    Serial.println("HARD LEFT");
  }
*/
  if ((!(digitalRead(T1))) && (!(digitalRead(T2))))  // BREAK
  {
    digitalWrite(dir_LF, HIGH);
    digitalWrite(dir_LR, HIGH);
    digitalWrite(dir_RF, HIGH);
    digitalWrite(dir_RR, HIGH);
    analogWrite(pwm_LF, 0);
    analogWrite(pwm_LR, 0);
    analogWrite(pwm_RF, 0);
    analogWrite(pwm_RR, 0);
    Serial.println("STOP");
  }
}

