void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int s = analogRead(A0);
  Serial.println(s);
  delay(1000);
}
