//6++++++/*------ Program for Line Follower Robot using Arduino----- */
/*-------definning Inputs------*/
#define LS 1      // central sensor
#define CS 2      // left sensor
#define RS 3      // right sensor

/*-------definning Outputs------*/
       // left motor
#define LM1 6       // right motor
#define RM1 7       // right motor
#define pwm1 4
#define pwm2 5
void setup()
{
  pinMode(CS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  /*digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);*/
}

void loop()
{
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM1, HIGH); //pwmL non zero

    digitalWrite(RM1, HIGH);
    digitalWrite(pwm2, HIGH);
   digitalWrite(pwm1, HIGH);//pwmR non zero
  }
}
  

