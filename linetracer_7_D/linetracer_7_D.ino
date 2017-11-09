

int dir_a = 7;
int dir_b = 6;
int pwm_a = 5;     //dir_a == right motor
int pwm_b = 4; 
int led=12;
void setup() {
  // put your setup code here, to run once:

pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
pinMode(12,OUTPUT);
  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
 digitalWrite(dir_a, LOW);
Serial.begin(9600);

}

void loop() {
  digitalWrite(12,LOW);
  // put your main code here, to run repeatedly:
int sensor2 =analogRead(A2);
int sensor3 =analogRead(A1);
int sensor1 = analogRead(A0);
Serial.println("p1....................................");
Serial.println(sensor1);
Serial.println("p2....................................");
Serial.println(sensor2);
Serial.println("p3....................................");
Serial.println(sensor3);


if( (sensor1 < 700) && (sensor2 > 700) && (sensor3 < 700))  //move forward
{
 digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, HIGH);   
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 250);
 
  
  }
 
 else if( (sensor1 > 700) && (sensor2 > 700) && (sensor3 < 700))//move left
{
 digitalWrite(dir_a, HIGH);
  digitalWrite(dir_b, LOW);   
  analogWrite(pwm_a, 250);
  analogWrite(pwm_b, 0);
 
  }
 
  else if( (sensor1 < 700) && (sensor2 > 700) && (sensor3 > 700))//move right
{
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, HIGH);   
  analogWrite(pwm_a, 0);
  analogWrite(pwm_b, 250);
 
  
  }
  else if( (sensor1 < 700) && (sensor2 < 700) && (sensor3 < 700))
{
  digitalWrite(dir_a, LOW);
  digitalWrite(dir_b, LOW);  
  analogWrite(pwm_a, 0);
  analogWrite(pwm_b, 0);
 
  }
}
