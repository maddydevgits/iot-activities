
#include<ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int gasSensorPin = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2); // updated the address after scanning the I2C

// Threshold for gas detection
int gasThreshold = 50; // Adjust this value based on your sensor sensitivity

void setup(){
  pinMode(gasSensorPin,INPUT);
  Serial.begin(9600);
  Wire.begin(D2,D1);
  lcd.begin(16, 2);// initializing the LCD
  lcd.home();
  lcd.backlight(); // Enable or Turn On the backlight
  lcd.print("Hello"); // Start 
  delay(1000);
  
}

void loop() {
  // Read the gas sensor value
  int gasValue = analogRead(gasSensorPin);

  // Check if gas level exceeds the threshold
  if (gasValue > gasThreshold) {
    lcd.print("Alert! Hey Food got spoiled");
    // Add any desired actions here, such as sending a notification or activating an alarm
  }
  else{
    lcd.print("Yoo, You can eat ");
  }

  delay(1000); // Adjust the delay based on your application requirements
}


