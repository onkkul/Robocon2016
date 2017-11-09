int pwm_a = 10;
int pwm_b = 11;
int dir_a = 12;
int dir_b = 13;

int calSpeed = 165;  
int turnSpeed = 200;  
int turnSpeedSlow = 125; 
int drivePastDelay = 300;


void setup() 
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  
  Serial.begin(115200);   
  delay(2000);
    for (int i = 0; i <= 100; i++) 
  {
     
    if (i==0 || i==60)  
    {
       digitalWrite(dir_a, LOW); 
       analogWrite(pwm_a, calSpeed);
       digitalWrite(dir_b, HIGH);  
       analogWrite(pwm_b, calSpeed);   
    }
    
    else if (i==20 || i==100)  
    {
       digitalWrite(dir_a, HIGH); 
       analogWrite(pwm_a, calSpeed);
       digitalWrite(dir_b, LOW);  
       analogWrite(pwm_b, calSpeed);   
    }

}

void loop() {
  // put your main code here, to run repeatedly:

}
