#define NUM_SENSORS 8
#define TIMEOUT 2500
#define EMITTER_PIN 0
#define avgSpeed 255
#define ENA 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENB 7
#define PinIN A0
void calculateIntegral();

void calculateProportional();

void readValues();


int time = 0;

int kp = 1;
int kd = 1;
int ki = 1;
int error = 0;
int lastError = 0;
int proportional = 0;
int derivative = 0;
int integral = 0;

double value;
void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(1, OUTPUT);
  for (int i = 0; i < 5; i++) {
    digitalWrite(1, HIGH);
    delay(50);
    digitalWrite(1, LOW);
    delay(950);
  }
  analogWrite(ENA, avgSpeed);
  analogWrite(ENB, avgSpeed);

}
void loop()
{

  readValues();
  calculateProportional();

  derivative = error - lastError;
  integral += proportional;

  if (integral > 255)
  {
    integral = 255;
  }
  if (integral < -255)
  {
    integral = -255;
  }
  int turn = proportional * kp + derivative * kd + integral * ki;

  if (turn >= 255)
  {
    turn = 255;
  }
  if (turn <= -255)
  {
    turn = -255;
  }

  int speedA = 0;
  int speedB = 0;

  if (turn >= 0)
  {
    speedA = avgSpeed;
    speedB = avgSpeed - turn;
  }
  else
  {
    speedA = avgSpeed + turn;
    speedB = avgSpeed;
  }

  Serial.print("P=");
  Serial.print(proportional);
  Serial.print('\t');
  Serial.print("I=");
  Serial.print(integral);
  Serial.print('\t');
  Serial.print("D=");
  Serial.print(derivative);
  Serial.print('\t');
  Serial.print("Turn=");
  Serial.print(turn);
  Serial.print('\t');


  Serial.print("speedA=");
  Serial.print(speedA);
  Serial.print('\t');
  Serial.print("speedB=");
  Serial.print(speedB);
  Serial.print('\t');

  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  lastError = error;

  Serial.println();
}
void readValues()
{
  value = analogRead(PinIN);
}

void calculateProportional()
{
  int sum = 35;
  int posLeft = 0 ;
  int posRight = 70;

  for (int i = 0; i < 70 / 2; i+5) 
  {
    sum = sum + value;
      posLeft = 35 - i;
    }
  for (int i = 70; i >= 70 / 2; i-5) 
  {
    sum = sum + value;
   
      posRight = i - 35;
    }

  if (sum >= 35) 
  {
    sum = 35;
  }

  if (sum == 0) 
  {
    if (lastError < 0) 
    {
      error = -35;
    }
    else {
      error = 35;
    }
  }
  else if ((posLeft != 0) && (posRight != 35)) 
  {
    error = 0;
  }
  else if (posLeft != 35) {
    error = posLeft * 2 + sum;
  }
  else if (posRight != 35) {
    error = posRight * 2 - sum;
  }

  proportional = error;

}
