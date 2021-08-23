int sensorPin = A2;
int LED = 9;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(sensorPin);

  Serial.print("Read:");
  Serial.print(value,DEC);

  value=map(value,840,1024,0,255);

  Serial.print("Write");
  analogWrite(LED,value);
  Serial.println(value, DEC);         
   delay(100); 
}
