void setup() {
  pinMode(1, INPUT);
  pinMode(2, INPUT); // centre
  pinMode(3, INPUT); //right
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() 
{
 int val1 = digitalRead(4);
 int val2 = digitalRead(2);
 int val3 = digitalRead(3); 
 Serial.println(val1);
 Serial.println(".........................................");
 Serial.println(val2);
 Serial.println(".........................................");
 Serial.println(val3);
 Serial.println("________________________________________");
  // put your main code here, to run repeatedly:

}
