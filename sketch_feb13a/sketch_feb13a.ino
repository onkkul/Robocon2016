


int s = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(s, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}

void loop() {
  int u0 = digitalRead(2);
  int u1 = digitalRead(3);
  int u2 = digitalRead(4);
  int u3 = digitalRead(5);
  int u4 = digitalRead(6);
  int u5 = digitalRead(7);



  int u6 = digitalRead(s);
  int u7 = digitalRead(9);
  /*
    Serial.print("u0=");
    Serial.println(u0);
  */
  Serial.print("u1=");
  Serial.println(u1);
  /*
    Serial.print("u2=");
    Serial.println(u2);
    Serial.print("u3=");
    Serial.println(u3);
    Serial.print("u4=");
    Serial.println(u4);
    Serial.print("u5=");
    Serial.println(u5);
    Serial.print("u6=");
    Serial.println(u6);
    Serial.print("u7=");
    Serial.println(u7);
  */
  delay(250);
}
