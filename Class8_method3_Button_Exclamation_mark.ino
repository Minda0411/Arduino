void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  digitalWrite(7,HIGH);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7)!=HIGH)
  {digitalWrite(13,LOW);
  }
  else{
    digitalWrite(13,HIGH);
    }
}
