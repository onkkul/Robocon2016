float val;

void setup() {
pinMode(7, INPUT);
val= analogRead(7);
Serial.begin(9600);

}

void loop() {
 if (val>2.23)
 {
  Serial.println("the colour is white");
 }
 if (val>...&&val<***)
 {
  Serial.println("the colour is orange");
 }
 if (val>...&&val<***)
 {
  Serial.println("the colour is green");
 }
 if (val>...&&val<***)
 {
  Serial.println("the colour is blue");
 }
 if (val>...&&val<***)
 {
  Serial.println("the colour is yellow");
 }

}
