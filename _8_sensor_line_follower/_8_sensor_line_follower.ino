
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int sensor7 = 4;
int sensor8 = 5;
int leddd = 13;


void setup() {

  // put your setup code here, to run once:
  pinMode (sensor1, INPUT);
  pinMode (sensor2, INPUT);
  pinMode (sensor3, INPUT);
  pinMode (sensor4, INPUT);
  pinMode (sensor5, INPUT);
  pinMode (sensor6, INPUT);
  pinMode (sensor7, INPUT);
  pinMode (sensor8, INPUT);

  pinMode (leddd, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int val4 = 0;
  int val5 = 0;
  int val6 = 0;
  int val7 = 0;
  int val8 = 0;
  val1 = analogRead(sensor1);
  val2 = analogRead(sensor2);
  val3 = analogRead(sensor3);
  val4 = analogRead(sensor4);
  val5 = analogRead(sensor5);
  val6 = analogRead(sensor6);
  val7 = analogRead(sensor7);
  val8 = analogRead(sensor8);


  // put your main code here, to run repeatedly:
  float voltage1 = val1 * (5.0 / 1023.0);
  float voltage2 = val2 * (5.0 / 1023.0);
  float voltage3 = val3 * (5.0 / 1023.0);
  float voltage4 = val4 * (5.0 / 1023.0);
  float voltage5 = val5 * (5.0 / 1023.0);
  float voltage6 = val6 * (5.0 / 1023.0);
  float voltage7 = val7 * (5.0 / 1023.0);
  float voltage8 = val8 * (5.0 / 1023.0);

  Serial.println(voltage1);
  Serial.print("/t");
  Serial.println(voltage2);
  Serial.print("/t");
  Serial.println(voltage3);
  Serial.print("/t");
  Serial.println(voltage4);
  Serial.print("/t");
  Serial.println(voltage5);
  Serial.print("/t");
  Serial.println(voltage6);
  Serial.print("/t");
  Serial.println(voltage7);
  Serial.print("/t");
  Serial.println(voltage8);
  Serial.print("/n");
  if ((voltage1 > 3.3) || (voltage2 > 3.3) || (voltage3 > 3.3) || (voltage4 > 3.3) || (voltage5 > 3.3) || (voltage6 > 3.3) || (voltage7 > 3.3) || (voltage8 > 3.3))
  {
    if ((val1 == LOW) || (val1 == LOW && val2 == LOW))
    {
      //    //servo.write(45);
      //  //delay(20);
      digitalWrite(leddd, LOW);
    }
    else if ((val2 == LOW) || (val3 == LOW && val2 == LOW))
    {
      digitalWrite(leddd, LOW);
      ////servo.write(35);
      ////delay(20);
    }
    else if ((val3 == LOW) || (val3 == LOW && val4 == LOW))
    {
      digitalWrite(leddd, LOW);
      //  //servo.write(25);
      // //delay(20);
    }
    else if (val4 == LOW)
    {
      digitalWrite(leddd, LOW);
      //  //servo.write(15);
      // //delay(20);
    }

    else if (val3 == LOW)
    {
      digitalWrite(leddd, LOW);
      //  //servo.write(-15);
      // //delay(20);
    }

    else if (val4 == LOW && val3 == LOW)
    {
      digitalWrite(leddd, LOW);
      //  //servo.write(0);
      // //delay(20);
    }
    if ((val8 == LOW) || (val8 == LOW && val7 == LOW))
    {
      digitalWrite(leddd, LOW);
      // //servo.write(-45);
      // //delay(20);
    }
    else if ((val7 == LOW) || (val4 == LOW && val7 == LOW))
    {
      // //servo.write(-35);
      digitalWrite(leddd, LOW);
      ////delay(20);
    }
    else if ((val4 == LOW) || (val4 == LOW && val3 == LOW))
    {
      digitalWrite(leddd, LOW);
      ////servo.write(-25);
      // //delay(20);

    }

    else if ((val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW && val6 == LOW && val7 == LOW) ||
             (val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW && val6 == LOW && val7 == LOW && val8 == LOW) ||
             (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW && val6 == LOW && val7 == LOW) ||
             (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW && val6 == LOW && val7 == LOW && val8 == LOW))
    {
      //servo.write(90);
      //delay(20);

      digitalWrite(leddd, LOW);

    }
    else if ((val1 == LOW && val2 == LOW && val3 == LOW) ||
             (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW) ||
             (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW))
    {
      //servo.write(-90);
      //delay(20);

      digitalWrite(leddd, LOW);
    }
    else if ((val6 == LOW && val7 == LOW && val8 == LOW) ||
             (val5 == LOW && val6 == LOW && val7 == LOW && val8 == LOW) ||
             (val4 == LOW && val5 == LOW && val6 == LOW && val7 == LOW && val8 == LOW))
    {
      //servo.write(90);
      //delay(20);
      digitalWrite(leddd, LOW);
    }
    else
    {
      digitalWrite(leddd, HIGH);
    }
  }
  else
  {

  }
}
