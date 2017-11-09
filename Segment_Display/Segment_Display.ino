//Setup_ShiftRegister_A
int latchPin_A = 4;
int ClockPin_A = 5;
int DataPin_A = 6;
byte led_A = 0;

//Setup_ShiftRegister_B
int latchPin_B = 7;
int ClockPin_B = 8;
int DataPin_B = 9;
byte led_B = 0;

//Setup_ShiftRegister_C
int latchPin_C = 10;
int ClockPin_C = 11;
int DataPin_C = 12;
byte led_C = 0;

void setup()
{
  pinMode(latchPin_A, OUTPUT);
  pinMode(latchPin_B, OUTPUT);
  pinMode(latchPin_C, OUTPUT);
  pinMode(ClockPin_A, OUTPUT);
  pinMode(ClockPin_B, OUTPUT);
  pinMode(ClockPin_C, OUTPUT);
  pinMode(DataPin_A, OUTPUT);
  pinMode(DataPin_B, OUTPUT);
  pinMode(DataPin_C, OUTPUT);
  Serial.begin(9600);
}

void ShiftRegister_A()
{
  digitalWrite(latchPin_A, LOW);
  shiftOut(DataPin_A, ClockPin_A, LSBFIRST, led_A);
  digitalWrite(latchPin_A, LOW);
}

void ShiftRegister_C()
{
  digitalWrite(latchPin_C, LOW);
  shiftOut(DataPin_C, ClockPin_C, LSBFIRST, led_C);
  digitalWrite(latchPin_C, LOW);
}

void ShiftRegister_B()
{
  digitalWrite(latchPin_B, LOW);
  shiftOut(DataPin_B, ClockPin_B, LSBFIRST, led_B);
  digitalWrite(latchPin_B, LOW);
}


void loop()
{
  led_A = 0;
  led_B = 0;
  led_C = 0;
  ShiftRegister_A();
  ShiftRegister_B();
  ShiftRegister_B();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; i < 6; j++)
    {

      bitSet(led_B, j);
      bitSet(led_C, j);
      while (i == 0 || i == 7)
      {
        bitSet(led_A, j);
      }
      while (i > 0 || i < 5)
      {
        if (j == 0 || j == 5)
        {
          bitSet(led_A, j);
          ShiftRegister_A();
          Serial.print(j);
        }
      }

      ShiftRegister_B();
      ShiftRegister_C();
      delay(500);

    }

  }
}


