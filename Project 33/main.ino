#include<DHT.h>
DHT dht(D1,DHT11);
int soil=A0;
int threshold=700;
void setup(){
   pinMode(soil,INPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop(){
  int m= analogRead(soil);
  Serial.println(m);
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  if(isnan(h)||isnan(t)){
    return;
  }
  if(m>threshold){
    Serial.println("wet soil");
  }
  else {
    Serial.println("dry soil");
  }
  Serial.print("Humudity=");
  Serial.print(h);
  Serial.print(",temperature=");
  Serial.println(t);
}
