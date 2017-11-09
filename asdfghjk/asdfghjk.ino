#define AllHigh 8
int Turn;
void setup() 
{
 pinMode(8, INPUT);
 Serial.begin(9600);
 // put your setup code here, to run once:

}

void loop() 
{
  Turn=analogRead(AllHigh);
  Serial.println(Turn);
  // put your main code here, to run repeatedly:

}
