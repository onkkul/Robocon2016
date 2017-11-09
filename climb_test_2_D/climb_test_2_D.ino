int T1=3;
int T2=4;
int dir_up1=7;
int dir_up2=8;
int dir_up3=9;
int pwm_up1=10;
int pwm_up1=11;
int pwm_up1=12;



void setup() {
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  //pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  //pinMode(12,OUTPUT);
}

void loop() {
  if ((!(digitalRead(T1))) && (!(digitalRead(T2))))
  {

    digitalWrite(dir_up1, LOW);
    digitalWrite(dir_up2, LOW);
  //  digitalWrite(dir_up3, LOW);
    analogWrite(pwm_up1, 0);
    analogWrite(pwm_up2, 0);
    //analogWrite(pwm_up3, 0);
    Serial.println("STOP");
  }
  else
  {
    digitalWrite(dir_up1, HIGH);
    digitalWrite(dir_up2, HIGH);
    //digitalWrite(dir_up3, HIGH);
    analogWrite(pwm_up1, 250);
    analogWrite(pwm_up2, 250);
    //analogWrite(pwm_up3, 250);
    Serial.println("CLIMB");
  }

}
