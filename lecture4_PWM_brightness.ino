//Fading.pde
int brightness = 0; // brightness 變數用來保存目前的燈光亮度
int fadeAmount = 5;// fadeAmount 變數用來設定每一次燈光亮度的調整值
void setup() {
pinMode(9, OUTPUT); //宣告 pin9 為 output pin, LED 接在 pin9 上
}
void loop() {
analogWrite(9, brightness); //使用 analogWrite(9, brightness) 設定 pin9 上的 LED 燈光亮度
brightness = brightness + fadeAmount;
/*調整下一次的燈光亮度改變 fadeAmount 燈光亮度調整值，假如 brightness 已達到最(255)，就將 fadeAmount
改成 -5，讓燈光下一次的變化改成漸漸變暗，假 如 brightness 已達到最暗(0)，就將 fadeAmount 改回 +5，讓燈光下一
次的變化改成漸漸變亮。
*/
if (brightness == 0 || brightness == 255) {
fadeAmount = -fadeAmount ;
}
delay(30); //延遲 30ms，這樣肉眼才能看得到 LED 調光的效果
}
