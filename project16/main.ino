int buttonPin = D2;     // Pin where the push-button switch is connected
int buttonState = 0;         // Variable to store the state of the button
int pushUpCount = 0;         // Variable to store the count of push-ups

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    // Increment the push-up count when the button is pressed
    pushUpCount++;
    Serial.print("Push-ups: ");
    Serial.println(pushUpCount);
    delay(1000);  // Delay to debounce the button
  }
}
