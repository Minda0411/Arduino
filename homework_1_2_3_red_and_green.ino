  int pin1=3;
  int pin2=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available()) {
    char ch = Serial.read();
    
    if(ch == '2') {
        digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); 
    }
    else if(ch == '1') {
    digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); digitalWrite(pin1,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  delay(1000); 
        digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin2,LOW);
  delay(1000); 

    }
    else if(ch == '3') {
    for(int counter = 0; counter < 10000; counter++) {
    digitalWrite(pin1,1);
    digitalWrite(pin2,0);
    delay(1000); 
    digitalWrite(pin2,1);
    digitalWrite(pin1,0);
    delay(1000);;
  }
    
    }
    else {
      Serial.println("Invalid character.");
    }
  }
      
      
}
  
