//6++++++/*------ Program for Line Follower Robot using Arduino----- */
/*-------definning Inputs------*/
#define LS 1      // central sensor
#define CS 2      // left sensor
#define RS 3      // right sensor

/*-------definning Outputs------*/
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 6       // right motor
#define RM2 7       // right motor

void setup()
{
  pinMode(CS, INPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  /*digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);*/
}

void loop()
{
  if(digitalRead(LS)&& (!(digitalRead(CS))) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if((!(digitalRead(LS)) && digitalRead(RS))&& digitalRead(CS))     // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if((!(digitalRead(RS)) && digitalRead(LS))&&digitalRead(CS))   // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  
  if((!(digitalRead(LS)) && (!(digitalRead(RS)))&&(!(digitalRead(CS)))))     // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

  if ((digitalRead(LS)&&digitalRead(CS))&&digitalRead(RS))           // ALL HIGH, TURN LEFT
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}

