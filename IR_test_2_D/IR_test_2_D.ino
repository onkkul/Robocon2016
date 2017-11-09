int left;
int right;
int center;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  left = analogRead(2);
  right = analogRead(4);
  center = analogRead(3);
  Serial.println(left);
  /*Serial.println("_");
  Serial.println(center);
  Serial.println("_");
  Serial.println(right);
  Serial.println("_");*/
}
