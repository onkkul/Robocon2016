int count=1;
void setup() {
 pinMode (13, OUTPUT);
}

void loop() {
 for(count=1; count<1000; count++)
 {
   if (count%4!=0)
   {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
   }
   else if (count%4==0)
   { 
    digitalWrite(13, LOW);
    delay(3000);
   }
 }

}
