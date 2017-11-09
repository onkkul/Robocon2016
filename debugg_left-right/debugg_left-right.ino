#define LS 1      // LEFT SENSOR
#define CS 2
#define RS 3

int dir_a = 7;
int dir_b = 6;
int pwm_a = 5;
int pwm_b = 4;

void setup() 
{
 pinMode(dir_a, OUTPUT);
 pinMode(dir_b, OUTPUT);
 pinMode(pwm_a, OUTPUT);
 pinMode(pwm_b, OUTPUT);
 Serial.begin(115200);
}

void left()
 {
  digitalWrite(dir_a, LOW);
  analogWrite(pwm_a, 200);
  digitalWrite(dir_b, HIGH);
  analogWrite(pwm_b, 200);
 }

void right()
{
  digitalWrite(dir_a, HIGH);
  analogWrite(pwm_a, 200);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_b, 200);
}

void loop() 
{
 if(digitalRead(LS) &&(!(digitalRead(CS)))&&  (!(digitalRead(RS))))        // turn RIGHT
 {
  right();
 }

  else if(digitalRead(LS) && (!(digitalRead(CS))) && digitalRead(LS))        // forward
 {
  digitalWrite(dir_a, HIGH);
  analogWrite(pwm_a, 200);
  digitalWrite(dir_b, HIGH);
  analogWrite(pwm_b, 200);
 }

 else if(digitalRead(RS)&&(!(digitalRead(CS)))&&(!(digitalRead(LS))))       // turn LEFT
 {
  left();
 }

 
 
}
