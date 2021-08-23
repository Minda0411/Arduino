//2 color LED閃爍的範例程式
int ledPin1 = 3;
int ledPin2 = 4;
void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
Serial.println(Serial.read());
}

digitalWrite(ledPin1, HIGH); // 設定PIN3腳位為高電位
digitalWrite(ledPin2, LOW); // 設定PIN4腳位為低電位，亮紅燈
delay(1000); //持續1秒
digitalWrite(ledPin2, HIGH); // 設定PIN4腳位為高電位
digitalWrite(ledPin1, LOW); // 設定PIN3腳位為低電位，亮綠燈
delay(1000); //持續1秒
}
