#include<ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int alcohol=A0;
int threshold=400;
int buzzer=D5;
void setup()
{
  pinMode(alcohol,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Wire.begin(D2,D1);
  lcd.begin(16, 2);// initializing the LCD
  lcd.home();
  lcd.backlight();// Enable or Turn On the backlight
  lcd.print("Alcohol Detecter"); // Start 
  delay(1000);
}
void loop(){
  int m=analogRead(alcohol);
  Serial.println(m);
  if(m>threshold){
    lcd.println("Alcohol is detected");
    lcd.setCursor(0,0);
    digitalWrite(buzzer,1);

  }
  else
  {
    
    lcd.print("normal");
    lcd.setCursor(0,1);
  }
}

