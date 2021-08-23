/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int ledPin1 = 3;
int ledPin2 = 4;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT); 
}

// the loop function runs over and over again forever
void loop() {
   if(Serial.available()){
      int x = Serial.read();
      Serial.println(x);
      
      if (x =='1'){
         //blink red led
         for(int i=1 ; i<=5 ; i=i+1 ){
          digitalWrite(ledPin2,HIGH);
          digitalWrite(ledPin2,LOW);
          delay(100);
         }
      }else{
        //blink green led
         for( int i=1 ; i<=5 ; i=i+1 ){
          digitalWrite(ledPin2,HIGH);
          digitalWrite(ledPin1,LOW);
          delay(100);
        }
      }
   }
}
