void setup() {
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    int num = Serial.parseInt();
    Serial.print("The temperature is: ");
    Serial.print(num * 9 / 5 + 32);
    Serial.println(" °F");
  }
}
