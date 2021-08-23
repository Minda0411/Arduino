void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  if(Serial.available()) {
    char ch = Serial.read();
    
    if(ch == 'O') {
      digitalWrite(13, HIGH);
    }
    else if(ch == 'C') {
      digitalWrite(13, LOW);
    }
    else {
      Serial.println("Invalid character.");
    }
  }
}

void loop() {
  
}
