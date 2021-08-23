#include <ESP8266WiFi.h> 
#include "PubSubClient.h"
//#include "dht11.h"
#define DHT11PIN 5  // DHT11資料接腳

const char* ssid = "minda0411"; //你的Wi-Fi網路名稱";
const char* password = "0225058922"; //"你的Wi-Fi網路密碼";
const char* mqttServer = "140.124.75.95";//"mqtt.thingspeak.com";  // MQTT伺服器位址
const char* mqttUserName = "tien"; //"cubie";  // 使用者名稱，隨意設定。
const char* mqttPwd = "evelyn";//"你的MQTT API Key";  // MQTT密碼。不重要
const char* clientID = "t001";      // 用戶端ID，隨意設定。不重要
const char* topic = "Minda";//"channels/頻道ID/publish/你的寫入API KEY";指定誰

unsigned long prevMillis = 0;  // 暫存經過時間（毫秒）
const long interval = 1000;  // 上傳資料的間隔時間，20秒。
String msgStr = "";      // 暫存MQTT訊息字串

int temp;  // 暫存溫度 老師程式刪掉了
int hum;   // 暫存濕度 老師程式刪掉了

WiFiClient espClient;
PubSubClient client(espClient);
//dht11 DHT11;

void setup_wifi() {
  delay(10);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(clientID, mqttUserName, mqttPwd)) {
      Serial.println("MQTT connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(1000);  // 等5秒之後再重試
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqttServer, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // 等待20秒
  if (millis() - prevMillis > interval) {
    prevMillis = millis();

    // 讀取DHT11的溫濕度資料
    //int chk = DHT11.read(DHT11PIN);
    temp = random(20, 35); // pseudo temperature
    hum = random(10, 100); // pseudo humidity
    //if (chk == 0) {
    //  temp = DHT11.temperature;
    //  hum = DHT11.humidity;
    //}

    // 組合MQTT訊息；Temperature填入溫度、Humid填入濕度
    msgStr=msgStr+"Temperature="+temp+"&Humid="+hum;
    
    // 宣告字元陣列
    byte arrSize = msgStr.length() + 1;
    char msg[arrSize];

    Serial.print("Publish message: ");
    Serial.println(msgStr);
    msgStr.toCharArray(msg, arrSize); // 把String字串轉換成字元陣列格式
    client.publish(topic, msg);       // 發布MQTT主題與訊息
    msgStr = "";
  }
}
