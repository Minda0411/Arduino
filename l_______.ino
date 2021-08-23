int pin=9;
int brightness=0;
int fade=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin,brightness);
  brightness=brightness+fade; //increase the brightness
  if(brightness==0 || brightness==255)
  {
    fade=-(fade);
    }
  delay(100);
}
