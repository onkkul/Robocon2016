#define LED 13
#define FIVE 10
#define WS 8
int count = 1;
int five = 0;
//int val;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //val = count - 1;
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);

  if (digitalRead(WS))
  {
    digitalWrite(13, LOW);
    count++;
  }

  if (count != 0)
  {
    if ((count % 5 == 0)&&(digitalRead(WS)))
      {
        digitalWrite(10, HIGH);
        five++;
      }
  }
  Serial.println(count);
  Serial.println("....................................");
  Serial.println(five);
  Serial.println("_______________________________________");
}
