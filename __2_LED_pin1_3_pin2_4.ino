int pin1=3;
int pin2=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin1,1);
  digitalWrite(pin2,0);
  delay(1000); 
  digitalWrite(pin2,1);
  digitalWrite(pin1,0);
  delay(1000);
 
}
