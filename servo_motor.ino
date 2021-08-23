#include <Servo.h>  //include the package
Servo myservo; // declare the object
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i< 180; i= i+1){
    myservo.write(i);
    delay(20);
  }
  for(int i = 180; i>=0; i = i-1){
    myservo.write(i);
    delay(20);
  }
}
