#define pwm 6
#define dir 7
void setup() 
{
 pinMode(pwm, OUTPUT);
 pinMode(dir, OUTPUT);// put your setup code here, to run once:

}

void loop() 
{
 digitalWrite(dir, HIGH);
 analogWrite(pwm, 170);// put your main code here, to run repeatedly:
}
