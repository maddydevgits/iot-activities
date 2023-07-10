#include<DHT.h>
DHT dht(D1,DHT11);
void setup(){
  Serial.begin(9600);
  dht.begin();
}
void loop(){
  float humidity=dht.readHumidity();
  float temperature=dht.readTemperature();
  if (temperature > 25) {
    Serial.println("Temperature is high. Cooling activated.");
  } else if (temperature < 20) {
    Serial.println("Temperature is low. Heating activated.");
  }
  if (humidity < 50) {
    Serial.println("Humidity is low. Mist sprayer activated.");
  }
  Serial.print("Humudity=");
  Serial.print(humidity);
  Serial.print(",temperature=");
  Serial.println(temperature);
}
