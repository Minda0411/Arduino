#include <ESP8266WiFi.h>
//
const char* ssid = "minda0411"; //"ssid name";
const char* password = "0225058922"; //"ssid password";
 
// Socket Server
const char* host = "192.168.43.64"; //"192.168.0.45";
const int port = 7000; //3000;
int i = 0;
WiFiClient client;
void setup() {
  Serial.begin(115200);
  Serial.print( "Start..." );
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("Connected to server...");
  }
}
void loop() {
  if (!client.connected()& i< 10) {
    client.connect(host, port);
    client.println("connected...");
  }
  int degree = random(10, 100);
  client.println(degree);
  Serial.println(degree);
  if (i==10){
    //i =0; // restart from 0
    client.stop();
  }
  if (i==20){
    i=0; // restart
  }
  delay(1000);
}
