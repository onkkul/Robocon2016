#define LS 1      // central sensor++
#define CS 2      // left sensor
#define RS 3      // right sensor

int dir_a = 7;
int dir_b = 6;
int pwm_a = 5;     //dir_a == right motor
int pwm_b = 4;     //dir_b == left motor

void setup() 
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  
  Serial.begin(115200);
}

void loop() 
{
 if(digitalRead(LS)&& (!(digitalRead(CS))) && digitalRead(RS))     //forward
 {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);   //dir_a == right motor
  analogWrite(pwm_a, 200);
  analogWrite(pwm_b, 200);
 }

 if((!(digitalRead(RS)) && digitalRead(LS))&& digitalRead(CS))  //misalighned--left sensor on the track
 {
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);             //dir_a == right motor
  analogWrite(pwm_a, 0);
  analogWrite(pwm_b, 200);
  //digitalWrite(dir_b, HIGH);
  //analogWrite(pwm_b, 200);
 }

 if((!(digitalRead(LS)) && digitalRead(RS)) && (digitalRead(CS)))    //misalighned-- right sensor on the track
 {
  /*//digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);              //dir_a == right motor
  //analogWrite(pwm_a, 200);
  analogWrite(pwm_b, 200);*/

  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);            //dir_a == right motor
  analogWrite(pwm_a, 200);
  analogWrite(pwm_b, 0);
 }

 if((!(digitalRead(LS)) && (!(digitalRead(RS)))&&(!(digitalRead(CS)))))    // all high, turn left
 {
  digitalWrite(dir_b, HIGH);
  digitalWrite(dir_a, LOW);            //dir_a == right motor
  analogWrite(pwm_b, 200);
  analogWrite(pwm_a, 200);
  digitalWrite(13, HIGH);
 }

 if ((digitalRead(LS)&&digitalRead(CS))&&digitalRead(RS))     // u turn
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);     //dir_a == right motor
  analogWrite(pwm_a, 200);
  analogWrite(pwm_b, 200);
 }

 if((!(digitalRead(RS)) && digitalRead(LS)) && (!(digitalRead(CS))))    //right turn
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);            //dir_a == right motor
  analogWrite(pwm_a, 0);
  analogWrite(pwm_b, 200);
 }

 if((!(digitalRead(RS)) && digitalRead(LS))&& (!(digitalRead(CS))))  //left turn               ytdyfhuy
 {
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);            //dir_a == right motor
  analogWrite(pwm_a, 200);
  analogWrite(pwm_b, 0);
 }

 
}

