#include <DHT.h>

#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int moisturePin = A0;

void setup() {
  Serial.begin(9600);
  delay(1000);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int moisture = analogRead(moisturePin);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Moisture: ");
  Serial.println(moisture);
  if (temperature > 30 && humidity > 70 && moisture < 500) {
    Serial.print("Granary Temperature is Not Available");
    }
  else {
    Serial.print("Granary Temperature is Available");
  }
  delay(5000); // Delay for 5 seconds
}
