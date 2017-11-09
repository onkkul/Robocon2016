#include <QTRSensors.h>
#include <Servo.h>

int A = 1;
int B = 2;
int C = 3;
int D = 4;
int E = 5;
int F = 6;
int G = 7;
int H = 8;
int I = 9;
int J = 10;
int K = 11;
int L = 12;
int M = 13;
int N = 14;
int O = 15;
int P = 16;
int Q = 17;
Servo servo;


void setup() {
  // put your setup code here, to run once:
pinMode(A,INPUT);
pinMode(B,INPUT);
pinMode(C,INPUT);
pinMode(D,INPUT);
pinMode(E,INPUT);
pinMode(F,INPUT);
pinMode(G,INPUT);
pinMode(H,INPUT);
pinMode(I,INPUT);
pinMode(J,INPUT);
pinMode(K,INPUT);
pinMode(L,INPUT);
pinMode(M,INPUT);
pinMode(N,INPUT);
pinMode(O,INPUT);
pinMode(P,INPUT);
pinMode(Q,INPUT);
servo.attach(13);
}
int j,i;
void loop() {
  // put your main code here, to run repeatedly:

}


void pid()

{
int arr2[17];
char arr1[A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q];
for(i=0;i<17;i++)
{
unsigned long lastTime=0;
double Input=arr1[i];
double Output=arr2[j];
double Setpoint;
double errSum;
double lastErr;
double kp=1;
double ki=1;
double kd=1;

void Compute()
{
   /*How long since we last calculated*/
   unsigned long now = millis();
   double timeChange = (double)(now - lastTime);
  
   /*Compute all the working error variables*/
   double error = Setpoint - Input;
   errSum += (error * timeChange);
   double dErr = (error - lastErr) / timeChange;
  
   /*Compute PID Output*/
   Output = kp * error + ki * errSum + kd * dErr;
  
   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
}
  
void SetTunings(double Kp, double Ki, double Kd)
{
   kp = Kp;
   ki = Ki;
   kd = Kd;
}
}                                                                                           
