int pin1 = 3;
int pin2 = 4;
void setup(){
Serial.begin(9600);
}
void loop(){
if(Serial.available()){
int x = Serial.read();
Serial.println(x);
}
}
