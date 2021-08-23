int pin1 = 3;
int pin2 = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  int x=Serial.read();
  Serial.println(x);
  if(x==114)
  { // 1: HIGH
  digitalWrite(pin1, 1);
  digitalWrite(pin2, 0);
  delay(1000);
    //blink red led
  }
  else
  {
    //blink green led
    digitalWrite(pin2, 1);
    digitalWrite(pin1, 0);
    delay(1000);
  }
}
}
