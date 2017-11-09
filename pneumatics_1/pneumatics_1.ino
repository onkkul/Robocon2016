
int en1=7;
int in1=6;
int in2=5;
int en2=10;
int in3=8;
int in4=9;
int i;



void setup() {
 pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

Serial.begin(9600);
}

void loop()

 {
   
  for(i=0;i<6;i++)
  {
  //FIRST
 digitalWrite(en1,HIGH);
 digitalWrite(en2,LOW);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
delay(5000);

  //SECOND
 digitalWrite(en1,HIGH);
 digitalWrite(en2,HIGH);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(1000);

//third
 digitalWrite(en1,LOW);
 digitalWrite(en2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(5000);

//FOURTH
 digitalWrite(en1,HIGH);
 digitalWrite(en2,HIGH);
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(1000);
  }















}
