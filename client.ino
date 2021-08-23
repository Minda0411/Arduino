#include <ESP8266WiFi.h>
const int ledPin = 5;
const char* ssid = "minda0411";
const char* password = "0225058922";
WiFiServer server(12345);
WiFiClient client;
 
void setup() {
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
   WiFi.begin(ssid,password);
   Serial.println("");
   while(WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
   Serial.print("Connected to ");
   Serial.println(ssid);
   Serial.print("IP Address: ");
   Serial.println(WiFi.localIP());
   server.begin(); // Start the TCP server
}
 
void loop() {
   WiFiClient client = server.available();
   if (!client) {
       return; }
   Serial.println("new client");
   while(!client.available()){
      delay(1);
   }
   String receivedData = client.readStringUntil('\r');
   Serial.println(receivedData);
   client.flush();
   if (receivedData.indexOf("1") == 0)
       digitalWrite(ledPin, HIGH);
   else if (receivedData.indexOf("0") == 0)
       digitalWrite(ledPin, LOW);
   else {
      Serial.println("invalid request");
      client.stop();
      return;
    } 
}
