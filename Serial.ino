void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
int value = 65;
// 以各種格式列印 65
Serial.println(value); // 印出 2 個 ASCII 字元 "65"
Serial.println(value, DEC); // 同上
Serial.println(value, HEX); // 印出 "41" 兩個 ASCII 字元
Serial.println(value, BIN); // 印出 "01000001" 八個 ASCII 字元
//Serial.println(value, BYTE); // 把 65 當成一個 byte 印出
}
void loop() {
// put your main code here, to run repeatedly:
}
