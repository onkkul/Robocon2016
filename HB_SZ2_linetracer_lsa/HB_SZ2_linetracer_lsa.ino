int U0 = 1;
int U1 = 2;
int U2 = 3;
int U3 = 4;
int U4 = 5;
int U5 = 6;
int U6 = 7;
int U7 = 8;

int dir_R1 = 10;  //right motor forward
int dir_R2 = 11; //right motor backward
int EN_B = 12;  //pwm of right motor

int dir_L1 = 14;  //left motor forward
int dir_L2 = 15; //left motor backward
int EN_A = 16;  //pwm of left motor

#define limit_1  17
#define limit_2 18

void setup()
{
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(dir_R1, OUTPUT);
  pinMode(dir_R2, OUTPUT);
  pinMode(EN_B, OUTPUT);
  pinMode(dir_L1, OUTPUT);
  pinMode(dir_L2, OUTPUT);
  pinMode(EN_A, OUTPUT);
  /*   //digitalWrite(dir_R1,HIGH);   digitalWrite(dir_R1,LOW);
       //digitalWrite(dir_R2,HIGH);   digitalWrite(dir_R2,LOW);
       //digitalWrite(dir_L1,HIGH);   digitalWrite(dir_L1,LOW);
       //digitalWrite(dir_L2,HIGH);   digitalWrite(dir_L2,LOW);
       //analogWrite(EN_B,);         analogWrite(EN_A,);
  */
}
void loop()
{
  /*                                 ------------------------------------------------ALL THE CONDITION-----------------------------------------------------
     (digitalRead(U0)==0)&&(digitalRead(U1)==0)&&(digitalRead(U2)==0)&&(digitalRead(U3)==0)&&(digitalRead(U4)==0)&&(digitalRead(U5)==0)&&(digitalRead(U6)==0)&&(digitalRead(U7)==0)
     (digitalRead(U0)==1)&&(digitalRead(U1)==1)&&(digitalRead(U2)==1)&&(digitalRead(U3)==1)&&(digitalRead(U4)==1)&&(digitalRead(U5)==1)&&(digitalRead(U6)==1)&&(digitalRead(U7)==1)
                                                             MOTOR_A = LEFT MOTOR
                                                             MOTOR_B = RIGHT MOTOR
                                                             IN1 = dir_L1
                                                             IN2 = dir_L2
                                                             IN3 = dir_R1
                                                             IN4 = dir_R2
  */

  while ((digitalRead(limit_1) == LOW) && (digitalRead(limit_2) == LOW))
  {
    if ((digitalRead(U0) == 1) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, LOW);
      digitalWrite(dir_L2, HIGH);
      analogWrite(EN_A, 250);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, LOW);
      analogWrite(EN_B, 250);

    }

    else if ((digitalRead(U0) == 1) && (digitalRead(U1) == 1) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, LOW);
      digitalWrite(dir_L2, HIGH);
      analogWrite(EN_A, 200);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, LOW);
      analogWrite(EN_B, 200);
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 1) && (digitalRead(U2) == 1) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, LOW);
      digitalWrite(dir_L2, HIGH);
      analogWrite(EN_A, 150);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, LOW);
      analogWrite(EN_B, 150);
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 1) && (digitalRead(U3) == 1) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, HIGH);
      analogWrite(EN_A, 0);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, LOW);
      analogWrite(EN_B, 200);
    }


    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 1) && (digitalRead(U4) == 1) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, LOW);
      analogWrite(EN_A, 200);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, LOW);
      analogWrite(EN_B, 200);
      digitalWrite(15, HIGH);       //left alignment indicator
      digitalWrite(16, HIGH);       //right alignment indicator
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 1) && (digitalRead(U5) == 1) && (digitalRead(U6) == 0) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, LOW);
      analogWrite(EN_A, 200);
      digitalWrite(dir_R1, HIGH);
      digitalWrite(dir_R2, HIGH);
      analogWrite(EN_B, 0);
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 1) && (digitalRead(U6) == 1) && (digitalRead(U7) == 0))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, LOW);
      analogWrite(EN_A, 150);
      digitalWrite(dir_R1, LOW);
      digitalWrite(dir_R2, HIGH);
      analogWrite(EN_B, 150);
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 1) && (digitalRead(U7) == 1))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, LOW);
      analogWrite(EN_A, 200);
      digitalWrite(dir_R1, LOW);
      digitalWrite(dir_R2, HIGH);
      analogWrite(EN_B, 200);
    }

    else if ((digitalRead(U0) == 0) && (digitalRead(U1) == 0) && (digitalRead(U2) == 0) && (digitalRead(U3) == 0) && (digitalRead(U4) == 0) && (digitalRead(U5) == 0) && (digitalRead(U6) == 0) && (digitalRead(U7) == 1))
    {
      digitalWrite(dir_L1, HIGH);
      digitalWrite(dir_L2, LOW);
      analogWrite(EN_A, 250);
      digitalWrite(dir_R1, LOW);
      digitalWrite(dir_R2, HIGH);
      analogWrite(EN_B, 250);
    }
  }

  while ((digitalRead(limit_1) == HIGH) && (digitalRead(limit_2) == HIGH))
  {
    digitalWrite(EN_A, LOW);
    digitalWrite(EN_B, LOW);
  }
}
