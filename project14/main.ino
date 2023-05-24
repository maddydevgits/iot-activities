int buttonPin = D2;
 int buzzerPin = D3;
 int ledPin = D4;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Button is pressed
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    digitalWrite(ledPin, HIGH);     // Turn on the LED
    delay(1000);  // Delay for 1 second
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
    digitalWrite(ledPin, LOW);      // Turn off the LED
    delay(1000);  // Delay for 1 second
  }
}
