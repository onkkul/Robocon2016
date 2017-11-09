int val = analogRead(7);
int amt = analogRead(9);

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop() {
 if ((val*1000) == (amt*1000))

    {
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
    }
    else if ((val*1000) != (amt*1000))
    {
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
    }
    Serial.println(analogRead(7));
    Serial.println(                  );
    Serial.println(analogRead(9));
    
  }

