#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9, 500, 2400);
  myservo.write(90); // degree
  delay(3000);
}

void loop() {
  for(int i =500; i<= 2400; i = i+100){ // step 100 microsecond
    myservo.writeMicroseconds(i);
    delay(300);  
  }
  for(int i=2400; i>=500; i = i -100){
    myservo.writeMicroseconds(i);
    delay(300);
  }
}
