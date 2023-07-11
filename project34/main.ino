#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
bool stopFlag = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  if (!accel.begin()) {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  float x = event.acceleration.x;
  float y = event.acceleration.y;
  float z = event.acceleration.z;

  // Check for front and back orientation
  if (y > 2.0) {
    Serial.println("Front");
  } else if (y < -2.0) {
    Serial.println("Back");
  }

  // Check for left and right orientation
  if (x > 3.0) {
    Serial.println("Left");
  } else if (x < -3.0) {
    Serial.println("Right");
  }
  
  // Check for stop orientation
  if (z > 4.0) {
    Serial.println("Stop");
    stopFlag = true;
  } else {
    stopFlag = false;
  }

  if (stopFlag) {
    // Perform stop action or code here
    // For example, you can stop a motor or pause a process
    // Add your code for the stop action
  } else {
    // Continue normal operation or code here
    // Add your code for normal operation
  }

  delay(500);
}
