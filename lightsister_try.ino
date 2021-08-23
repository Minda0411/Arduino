int sensorPin = 2;
int LED = 9;
int value = 0;
void setup() {
Serial.begin(9600);
pinMode(LED,OUTPUT);
}
void loop(){
value = analogRead(sensorPin);
Serial.print("Read:");
Serial.print(value, DEC);
//把AD值200-800 Scale to 0-255
value = map(value, 200, 800, 0, 255);
Serial.print(" Write:");
analogWrite(LED,value);
Serial.println(value, DEC);
delay(100);
}
