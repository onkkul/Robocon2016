int left;
int right;
int center;


void setup()
{
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (2, INPUT);
  pinMode (3, INPUT);
  pinMode (4, INPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  Serial.begin(9600);
}

void loop()

{
  left = digitalRead(2);
  center = digitalRead(3);
  right = digitalRead(4);
  
  if ((left == HIGH) && (right == HIGH) && (center == LOW))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else if (((left == LOW) && (center == HIGH)) && (right == HIGH))
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (((left == HIGH) && (center == HIGH)) && (right == LOW))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (((left == LOW) && (center == LOW)) && (right == HIGH))
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if (((left == HIGH) && (center == LOW)) && (right == LOW))
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if ((left == center) && (center == right) && (right == HIGH))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(11, LOW);
  }
  else if ((left == center) && (center == right) && (right == LOW))
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
    digitalWrite(8, LOW);
  }
  Serial.println(left);
  Serial.println(".....................");
  Serial.println(center);
  Serial.println(".........................");
  Serial.println(right);
  Serial.println("________________________");
}
