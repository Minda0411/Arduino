#include <ESP8266WiFi.h>
const int ledPin = 5;
const char* ssid = "minda0411";
const char* password = "0225058922";
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    Serial.print("Trying to connect to ");
    Serial.println(ssid);
    // attempt to connect to Wifi network:
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
   }
 
   Serial.println("");
   Serial.println("WiFi connected");
   Serial.println(WiFi.macAddress());
   Serial.print("IP:");
   Serial.println(WiFi.localIP());
   Serial.print("Subnet:");
   Serial.println(WiFi.subnetMask());
   Serial.print("Gateway:");
   Serial.println(WiFi.gatewayIP());
   Serial.print("Channel:");
   Serial.println(WiFi.channel());
   Serial.print("Status:");
   Serial.println(WiFi.status());
} // setup
void loop() {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}
