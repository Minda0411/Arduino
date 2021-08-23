void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  for(int counter = 0; counter < 1000000000000000000; counter++) {
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
  }
}

void loop() {
  
}
