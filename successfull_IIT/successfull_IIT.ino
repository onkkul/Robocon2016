#define LS 1      //left sensor
#define CS 2
#define RS 3      // right sensor
// WALL sensor

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
  digitalWrite(dir_a, LOW);
  Serial.begin(9600);
}

void loop()
{
  /*if(!(digitalRead(WS)))       // stop
    {
    digitalWrite(13, HIGH);
    digitalWrite(dir_a, LOW);
    digitalWrite(dir_b, LOW);
    analogWrite(pwm_a, 0);
    analogWrite(pwm_b, 0);*/

}

else if (digitalRead(LS) && (!(digitalRead(CS))) && digitalRead(RS))   //forward
{
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);   //dir_a == right motor
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 250);
}

else if ((!(digitalRead(RS)) && digitalRead(LS)) && digitalRead(CS)) //misalighned--left sensor on the track
{
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);             //dir_a == right motor
  analogWrite(pwm_a, 0);
  analogWrite(pwm_b, 250);
  /*digitalWrite(dir_b, HIGH);
  analogWrite(pwm_b, 250);*/
}

else if ((!(digitalRead(LS)) && digitalRead(RS)) && (digitalRead(CS)))   //misalighned-- right sensor on the track
{
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);              //dir_a == right motor
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 0);


}

else if ((!(digitalRead(LS)) && (!(digitalRead(RS))) && (!(digitalRead(CS))))) // all high, turn left
{
  digitalWrite(dir_b, HIGH);
  digitalWrite(dir_a, LOW);            //dir_a == right motor
  analogWrite(pwm_b, 250);
  analogWrite(pwm_a, 250);
  digitalWrite(13, HIGH); 
}

else if ((digitalRead(LS) && digitalRead(CS)) && digitalRead(RS)) // u turn
{
  /*digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);     //dir_a == right motor
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 250);*/

  digitalWrite(dir_a, HIGH);
  analogWrite(pwm_a, 250);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_b, 250);
}

else if (digitalRead(LS)) && (!(digitalRead(CS))) && (!(digitalRead(RS))) //left turn

{
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);            //dir_a == right motor
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 0);
}

else if ((!(digitalRead(LS))) && (!(digitalRead(CS)))  && digitalRead(RS))   //right turn
{
  digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);            //dir_a == right motor
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 250);
}
}
