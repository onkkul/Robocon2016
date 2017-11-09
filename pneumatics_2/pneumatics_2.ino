int en_a = 3;
int in1 = 4;
int in2 = 5;
int en_b = 6;
int in3 = 7;
int in4 = 8;
int en_c = 9;
int in5 = 10;
int in6 = 11;
int en_d = 12;
int in7 = 13;
int in8 = 2;



void setup()
{
  pinMode(en_a, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en_b, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en_c, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(en_d, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

  digitalWrite(en_a, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(en_b, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(en_c, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(en_d, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

}

void loop() {
  for (int i = 0; i <=2; i++)
  {
    //condition1
    digitalWrite(en_a, HIGH);
  
    digitalWrite(en_b, LOW);
  
    digitalWrite(en_c, LOW);
  
    digitalWrite(en_d, LOW);
  
    delay(1000);

    //conition2

    digitalWrite(en_b, HIGH);
  
    digitalWrite(en_c, LOW);
  
    delay(4000);

    digitalWrite(en_d, HIGH);
  
    delay(3000);

    digitalWrite(en_a, LOW);
  
    delay(3000);

    //conition3

    digitalWrite(en_b, LOW);
  
    digitalWrite(en_c, HIGH);
  
    delay(3000);

    digitalWrite(en_a, HIGH);
  
    delay(3000);

    digitalWrite(en_d, LOW);
  
    delay(2000);
  }

  digitalWrite(en_a, HIGH);
  digitalWrite(en_b, LOW);
  digitalWrite(en_c, LOW);
  digitalWrite(en_d, HIGH);
  

}
