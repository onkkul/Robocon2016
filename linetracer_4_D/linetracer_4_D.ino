#define LS 1      // central sensor
#define CS 2      // left sensor
#define RS 3      // right sensor

int dir_a = 7;
int dir_b = 6;
int pwm_a = 5;
int pwm_b = 4;

void setup() 
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  digitalWrite(pwm_a, 0);  
  digitalWrite(pwm_b, 0);
  
  Serial.begin(115200);
}

void loop() 
{
 if(digitalRead(LS)&& (!(digitalRead(CS))) && digitalRead(RS))     //forward
 {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);
  digitalWrite(pwm_a, HIGH);
  digitalWrite(pwm_b, HIGH);
 }

 if((!(digitalRead(LS)) && digitalRead(RS))&& digitalRead(CS))  //misalighned--left sensor on the track
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);
  digitalWrite(pwm_a, LOW);
  digitalWrite(pwm_b, HIGH);
 }

 if((!(digitalRead(RS)) && digitalRead(LS)) && (digitalRead(CS)))    //misalighned-- right sensor on the track
 {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);
  digitalWrite(pwm_a, HIGH);
  digitalWrite(pwm_b, LOW);
 }

 if((!(digitalRead(LS)) && (!(digitalRead(RS)))&&(!(digitalRead(CS)))))    // all high, turn left
 {

digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);
  digitalWrite(pwm_a, LOW);
  digitalWrite(pwm_a, HIGH);
  
  
 }

 if ((digitalRead(LS)&&digitalRead(CS))&&digitalRead(RS))     // u turn
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);
  digitalWrite(pwm_a, HIGH);
  digitalWrite(pwm_b, HIGH);
 }

 if((!(digitalRead(LS)) && digitalRead(RS))&& (!(digitalRead(CS))))  //left turn
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);
  digitalWrite(pwm_a, LOW);
  digitalWrite(pwm_b, HIGH);
 }

 if((!(digitalRead(RS)) && digitalRead(LS)) && (!(digitalRead(CS))))    //right turn
 {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);
  digitalWrite(pwm_a, HIGH);
  digitalWrite(pwm_b, LOW);
 }
}

