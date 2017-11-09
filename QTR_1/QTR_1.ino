#include <QTRSensors.h>  
#define NUM_SENSORS   8    
#define TIMEOUT       2500  
#define EMITTER_PIN   QTR_NO_EMITTER_PIN 

QTRSensorsRC qtrrc((unsigned char[]) {2, 4, 5, 6, 7, 8, 9,10},NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
unsigned int line_position=0;


int pwm_a = 3;
int pwm_b = 11;
int dir_a = 12;
int dir_b = 13;

int calSpeed = 165;  
int turnSpeed = 200;  
int turnSpeedSlow = 125; 
int drivePastDelay = 300;


float error=0;
float lastError=0;
float PV =0 ;
float kp = 0;  
float ki = 0; 
float kd =0;   
int m1Speed=0;
int m2Speed=0;
int motorspeed=0;
char path[100] = "";
unsigned char path_length = 0; 

void setup()
{
  pinMode(pwm_a, OUTPUT);  
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  analogWrite(pwm_a, 0);  
  analogWrite(pwm_b, 0);
  
  Serial.begin(115200);   
  delay(2000);
    for (int i = 0; i <= 100; i++) 
  {
     
    if (i==0 || i==60)  
    {
       digitalWrite(dir_a, LOW); 
       analogWrite(pwm_a, calSpeed);
       digitalWrite(dir_b, HIGH);  
       analogWrite(pwm_b, calSpeed);   
    }
    
    else if (i==20 || i==100)  
    {
       digitalWrite(dir_a, HIGH); 
       analogWrite(pwm_a, calSpeed);
       digitalWrite(dir_b, LOW);  
       analogWrite(pwm_b, calSpeed);   
    }
    
    qtrrc.calibrate();  
    
  }  
  line_position = qtrrc.readLine(sensorValues);
  
  while (sensorValues[6] < 200)  
  {
    line_position = qtrrc.readLine(sensorValues);
  }
  
  analogWrite(pwm_a, turnSpeedSlow);
  analogWrite(pwm_b, turnSpeedSlow); 
  
  while (line_position > 4350)
  {
    line_position = qtrrc.readLine(sensorValues);
  }
 
 
  analogWrite(pwm_b, 0);  
  analogWrite(pwm_a, 0);
  
   for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  
   for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  Serial.println("Calibration Complete");
  delay(1000);
  
}

void loop()
{
  unsigned int line_position = qtrrc.readLine(sensorValues);
  
  Serial.print(line_position); 
  Serial.print("  ");
  Serial.print(sensorValues[0]);
  Serial.print("  ");
  Serial.println(sensorValues[7]);
  
  MazeSolve(); 
  
  Serial.print("::");
  Serial.print(error);
  Serial.print('\t');
  Serial.print(PV);
  Serial.print('\t');
  Serial.print(m1Speed);
  Serial.print('\t');
  Serial.print(m2Speed);
  Serial.print('\t');
  Serial.print(lastError);
  Serial.print('\t');

}  




void follow_line()  //follow the line
{

  lastError = 0;
  
  while(1)
  {

    line_position = qtrrc.readLine(sensorValues);
    switch(line_position)
    {
   
        default:
        error = (float)line_position - 3500;
   
        kp=0.5;
        kd=1;
     
        PV = kp * error + kd * (error - lastError);
        lastError = error;
    
        if (PV > 55)
        {
         PV = 55;
        }
    
        if (PV < -55)
        {
          PV = -55;
        }
        
        m1Speed = 200 + PV;
        m2Speed = 200 - PV;
       
        //set motor speeds
        digitalWrite(dir_a, LOW);  
        analogWrite(pwm_a, m2Speed);
        digitalWrite(dir_b, LOW);  
        analogWrite(pwm_b, m1Speed);
        break;
    }
  
    if(sensorValues[1] < 100 && sensorValues[2] < 100 && sensorValues[3] < 100 && sensorValues[4] < 100 && sensorValues[5] < 100 && sensorValues[6] < 100)
    {
      return;
    }

    else if(sensorValues[0] > 200 || sensorValues[7] > 200)
    {
      return;
    }

  } 

}
     




void turn(char dir)
{
  switch(dir)
  {
    case 'L':    
      digitalWrite(dir_a, HIGH); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, turnSpeed);
      
      line_position = qtrrc.readLine(sensorValues);
      
      while (sensorValues[6] <200)  
      {
        line_position = qtrrc.readLine(sensorValues);
      }
  
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      while (line_position > 4350) 
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
      analogWrite(pwm_b, 0);  
      analogWrite(pwm_a, 0);  
      break;
      
    case 'R':        
      digitalWrite(dir_a, LOW); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, HIGH);  
      analogWrite(pwm_b, turnSpeed);
           
      line_position = qtrrc.readLine(sensorValues);
      
      while (sensorValues[1] <200) 
      {
        line_position = qtrrc.readLine(sensorValues);
      }
    
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      while (line_position < 3250)  
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
      analogWrite(pwm_a, 0);  
      analogWrite(pwm_b, 0);      
      break;
     
      case 'B':    
      digitalWrite(dir_a, LOW); 
      analogWrite(pwm_a, turnSpeed);
      digitalWrite(dir_b, HIGH);  
      analogWrite(pwm_b, turnSpeed);
      
      line_position = qtrrc.readLine(sensorValues);
  
      while (sensorValues[1] <200) 
      {
        line_position = qtrrc.readLine(sensorValues);
      }
       
      analogWrite(pwm_a, turnSpeedSlow);
      analogWrite(pwm_b, turnSpeedSlow); 
      
      while (line_position < 3250)  
      {
        line_position = qtrrc.readLine(sensorValues);
      }
     
     
      analogWrite(pwm_a, 0);  
      analogWrite(pwm_b, 0);           
      break;

     case 'S':
      break;
  }
} 





char select_turn(unsigned char found_left, unsigned char found_straight, unsigned char found_right)
{
  if(found_left)
    return 'L';
  else if(found_straight)
    return 'S';
  else if(found_right)
    return 'R';
  else
    return 'B';
} 







void simplify_path()
{
  if(path_length < 3 || path[path_length-2] != 'B')
    return;

  int total_angle = 0;
  int i;
  for(i=1;i<=3;i++)
  {
    switch(path[path_length-i])
    {
      case 'R':
        total_angle += 90;
  break;
      case 'L':
  total_angle += 270;
  break;
      case 'B':
  total_angle += 180;
  break;
    }
  }

  total_angle = total_angle % 360;

  switch(total_angle)
  {
    case 0:
  path[path_length - 3] = 'S';
  break;
    case 90:
  path[path_length - 3] = 'R';
  break;
    case 180:
  path[path_length - 3] = 'B';
  break;
    case 270:
  path[path_length - 3] = 'L';
  break;
  }

  
  path_length -= 2;
  
} 







void MazeSolve()
{
  
  while(1)
  {
    follow_line();
    digitalWrite(dir_a, LOW);  
    analogWrite(pwm_a, 200);
    digitalWrite(dir_b, LOW);  
    analogWrite(pwm_b, 200);   
    delay(25); 

    unsigned char found_left=0;
    unsigned char found_straight=0;
    unsigned char found_right=0;
    
    line_position = qtrrc.readLine(sensorValues);

    if(sensorValues[0] > 200)
    found_right = 1;
    if(sensorValues[7] > 200)
    found_left = 1;

    digitalWrite(dir_a, LOW);  
    analogWrite(pwm_a, 200);
    digitalWrite(dir_b, LOW);  
    analogWrite(pwm_b, 200);
    delay(drivePastDelay); 
  
    line_position = qtrrc.readLine(sensorValues);
    if(sensorValues[1] > 200 || sensorValues[2] > 200 || sensorValues[3] > 200 || sensorValues[4] > 200 || sensorValues[5] > 200 || sensorValues[6] > 200)
    found_straight = 1;

    if(sensorValues[1] > 600 && sensorValues[2] > 600 && sensorValues[3] > 600 && sensorValues[4] > 600 && sensorValues[5] > 600 && sensorValues[6] > 600)
    break;

    unsigned char dir = select_turn(found_left, found_straight, found_right);

    turn(dir);

    path[path_length] = dir;
    path_length ++;

    simplify_path();
  }
    while(1)
  {
    analogWrite(pwm_a, 0);  // stop both motors
    analogWrite(pwm_b, 0);
  
    // while(1){};

    
    line_position = qtrrc.readLine(sensorValues);
    
    while(sensorValues[1] > 200 && sensorValues[2] > 200 && sensorValues[3] > 200 && sensorValues[4] > 200 && sensorValues[5] > 200 && sensorValues[6] > 200)
    
    {
      line_position = qtrrc.readLine(sensorValues);
      delay(50);
    }
 
    while(1)
    {
      line_position = qtrrc.readLine(sensorValues);
      if(sensorValues[2] > 200 || sensorValues[3] > 200 || sensorValues[4] > 200 || sensorValues[5] > 200 && sensorValues[0] 
      < 200 && sensorValues[1] < 200 && sensorValues[6] < 200 && sensorValues[7] < 200)
      break;
      delay(50);
    }
 
    delay(2000);

  
    
    
    
    
    int i;
    for(i=0;i<path_length;i++)
    {
      follow_line();

      digitalWrite(dir_a, LOW);  
      analogWrite(pwm_a, 200);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, 200);
      delay(drivePastDelay); 

          turn(path[i]);
    }

  
    
    
    
    
    
    follow_line();

      digitalWrite(dir_a, LOW);  
      analogWrite(pwm_a, 200);
      digitalWrite(dir_b, LOW);  
      analogWrite(pwm_b, 200);
      delay(drivePastDelay); 
    
  } 
  
} 

