int PIN_INPUT = A1;   // Connect AN output of LSA08 to analog pin 0
int junctionPulse = 4;   // Connect JPULSE of LSA08 to pin 4

int ENA = 13;
int IN1 = 12;
int IN2 = 11;
int IN3 = 10;
int IN4 = 9;
int ENB = 8;
int u7 = 14;
int u0 = 15;

int positionVal, RawInput;  // Variables to store analog and line position value
double RawV;
unsigned int junctionCount = 0;   // Variable to store junction count value

void setup() {
  pinMode(junctionPulse, INPUT);

  // Setting pin 10 - 13 as digital output pin
  for (int i = 8; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(u0, INPUT);
  pinMode(u7, INPUT);
  digitalWrite(ENA, LOW); // Setting the initial condition of motors
  digitalWrite(ENB, LOW);// make sure both PWM pins are LOW

  // State of DIR pins are depending on your physical connection
  // else else if your robot behaves strangely, try changing thses two values
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.begin(9600);
}

void loop()
{
  RawInput = analogRead(PIN_INPUT);
  RawV =  RawInput * (5.0 / 1023.0);
  positionVal = ((RawV / 4.5) * 70);
  Serial.print("the LCD_Pos is");
  Serial.println(positionVal);
  Serial.print("u0 is");
  Serial.println(digitalRead(u0));
  Serial.print("u7 is");
  Serial.println(digitalRead(u7));


  // Checking for junction crossing, else else if juction detected,
  // keep moving forward
  if (digitalRead(junctionPulse) && digitalRead(u0) == 1 && digitalRead(u7) == 1)
  {
    Serial.println("Junction detected");
    while (digitalRead(junctionPulse) && digitalRead(u0) == 1 && digitalRead(u7) == 1)
    {
      moveLeft();
      Serial.println("Moving left");
    }
    // Increment junction count by 1 after the junction
    // You can do whatever you want with the junction count
    junctionCount++;
  }

  else if (digitalRead(u0) == 1 && digitalRead(u7) == 0 && positionVal > 70)
  {
    moveLeft();
    Serial.println("Moving left");
  }

  else if (digitalRead(u0) == 0 && digitalRead(u7) == 1 && positionVal > 70)
  {
    moveRight();
    Serial.println("Moving Right");
  }

  else if (digitalRead(u0) == 0 && digitalRead(u7) == 0 && positionVal > 70) //if no line is detected, stay at the position
  {
    Serial.print("LCD_Pos is");
    Serial.println(positionVal);
    wait();
    Serial.println("Moving reverse");
  }


  else if (digitalRead(u0) == 0 && digitalRead(u7) == 0 && positionVal < 70)
  {
    if (positionVal <= 18)
    {
      Serial.print("LCD_Pos is");
      Serial.println(positionVal);
      moveLeft();
      Serial.println("Moving left");// Line at left when 0 - 18, move left
    }


    // Line at middle when 19 - 52, move forward
    else if (positionVal <= 52)
    {
      Serial.print("LCD_Pos is");
      Serial.println(positionVal);
      moveForward();
      Serial.println("Moving Forward");
    }

    // Line at right when 53 - 70, move right
    else if (positionVal <= 70)
    {
      Serial.print("LCD_Pos is");
      Serial.println(positionVal);
      moveRight();
      Serial.println("Moving Right");
    }
  }
}

// The values work good in my case, you could use other values set
// to archieve a performance that satisfy you
void moveLeft()
{
  // For robot to move left, right motor has to be faster than left motor
  analogWrite(ENA, 255);
  analogWrite(ENB, 50);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveRight()
{
  // For robot to move right, left motor has to be faster than right motor
  analogWrite(ENA, 55);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveForward() {
  // For robot to move forward, both motors have to be same speed
  analogWrite(ENA, 200);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void wait() {
  // Function to makes the robot stay
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
