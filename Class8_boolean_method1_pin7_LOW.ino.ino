boolean state= true;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  digitalWrite(7,state);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7)==!state)
  {digitalWrite(13,state);
  }
  else{
    digitalWrite(13,!state);
    }
}
