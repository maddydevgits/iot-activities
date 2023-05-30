#include <Servo.h>


int triggerPin = D2;    // Trigger pin of the ultrasonic sensor
int echoPin = D3;       // Echo pin of the ultrasonic sen
int servoPin = D7;      // Pin to control the servo motor

Servo servo;                 // Servo object

int thresholdDistance = 20;  // Distance threshold to trigger lid movement (adjust as per your requirements)

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo.attach(servoPin);
  servo.write(0);   // Set initial position of the servo (lid closed)
  
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Read the duration of the ultrasonic pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the speed of sound
  distance = duration * 0.034 / 2;
  
  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if the dustbin is full
  if (distance < thresholdDistance) {
    openLid();   // Open the lid if the dustbin is full
  } else {
    closeLid();   // Close the lid if the dustbin is empty
  }
  
  delay(1000);   // Delay between consecutive readings
}

void openLid() {
  servo.write(90);   // Open the lid by setting the servo angle to 90 degrees
}

void closeLid() {
  servo.write(0);    // Close the lid by setting the servo angle to 0 degrees
}
