
const int buzzerPin = 3;
const int irSensorPin = 2;
const int detectionThreshold = 1;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int irSensorValue = digitalRead(irSensorPin);
  Serial.print("IR Sensor Value: ");
  Serial.println(irSensorValue);
  if (irSensorValue == detectionThreshold) {
    Serial.println("No Drowsiness Detected");
    deactivateBuzzer();
  } else {
    Serial.println("Drowsiness Detected!");
    activateBuzzer();
  }

  delay(100);  
}

void activateBuzzer() {
  digitalWrite(buzzerPin, HIGH);
}
void deactivateBuzzer() {
  digitalWrite(buzzerPin, LOW);
}
