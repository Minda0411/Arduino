void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
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
