#include<ESP8266WiFi.h> 
#include<ThingSpeak.h>
#include<DHT.h>
char* ssid="Redmi";
char* password="123456789";
int channel=2206752;
char* apikey="4PP7VQP4Q0JSBFYV";
DHT dht(D1,DHT11);

int moistureLevel;

#define MOISTURE_THRESHOLD 1024
#define MOISTURE_PIN A0          // Adjust this threshold to your needs


WiFiClient client;
void setup(){
  Serial.begin(9600);
  pinMode(moistureLevel,INPUT); 

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("wifi connected");
  ThingSpeak.begin(client);
}
void loop(){
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  moistureLevel = analogRead(MOISTURE_PIN);

  if(isnan(h)||isnan(t)){
    return;
  }


// Check soil moisture level
  if (moistureLevel < MOISTURE_THRESHOLD) {
    // Soil is dry, activate irrigation
    Serial.println("Soil is dry. Activating irrigation.");
  }



  
  Serial.print("Humudity=");
  Serial.print(h);
  Serial.print(",temperature=");
  Serial.println(t);
  Serial.print("moisture level=");
  Serial.println(moistureLevel);
  ThingSpeak.setField(2,h);
  ThingSpeak.setField(1,t);
  ThingSpeak.setField(3,moistureLevel);
  int status=ThingSpeak.writeFields(channel,apikey);
  if(status==100){
    Serial.println("data failure");
  }
  else{
    Serial.println("data stored");
  }
}
