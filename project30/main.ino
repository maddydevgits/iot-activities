#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Adafruit_Sensor.h>

// Replace with your network credentials
const char* ssid = "Redmi";
const char* password = "123456789";

// Telegram Bot Token
const char* botToken = "6030559283:AAHhCTEKPyEFetI5_Fes8cfCxfcH5m9aLmc";

// Telegram Chat ID
const char* chatId = "5281166334";

// Sensor Pins
const int soilMoisturePin = A0;


// Sensor Thresholds
const int moistureThreshold = 50; // Moisture threshold for indicating when the nappy needs changing

// Initialize Telegram bot
WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);


void sendTelegramMessage(const String& message) {
  if (WiFi.status() == WL_CONNECTED) {
    bot.sendMessage(chatId, message, "");
  }
}

void setup() {
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize serial communication
  Serial.begin(9600);
  delay(1000);

  // Connect to Telegram bot
  client.setInsecure();
  Serial.println("Connected to Telegram bot");

  // Initialize DHT sensor

}

void loop() {
  // Read soil moisture sensor value
  int moistureValue = analogRead(soilMoisturePin);

  

  // Check if the nappy needs changing
  if (moistureValue < moistureThreshold) {
    String message = "The nappy needs changing!";
    sendTelegramMessage(message);
  }

 

  delay(1000); // Check every minute
}
