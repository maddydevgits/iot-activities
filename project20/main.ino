#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig=D0;
int echo=D1;
int buzzer=D2;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Wire.begin(D3,D4);
  lcd.begin(16, 2);// initializing the LCD
  lcd.home();
  lcd.backlight(); // Enable or Turn On the backlight
  lcd.print("Hello"); // Start 
  delay(1000);
}

void loop() {
  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  long duration = pulseIn(echo, 1);
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 100) {
    digitalWrite(buzzer, 1);
    lcd.println("Water level is high");
    delay(500);
  }
  else {
    lcd.println("Water level is normal");
    digitalWrite(buzzer,0);
  }
}
