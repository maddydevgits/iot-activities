#include<SoftwareSerial.h>
int Light1 = 6; // Relay pin 1 (IN1)
int Light2 = 5;   // Relay pin 2 (IN2)
/* Create object named bt of the class SoftwareSerial */
SoftwareSerial bt(2, 3); /* (Rx,Tx) */
void setup() {
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
  // Set Relay pins as OUTPUT
   pinMode(Light1, OUTPUT);
   pinMode(Light2, OUTPUT);
   digitalWrite(Light1, HIGH);
   digitalWrite(Light2, HIGH);
}
void loop() {
  String data="";
  char ch;
  while (bt.available()) /* If data is available on serial port */
    { ch = bt.read(); /* Print character received on to the serial monitor */
      data=data+ch;
    }
   Serial.print(data);
  // Control the devices using voice command
    if ((data == "turn on light one")||(data == "turn on light 1"))               // turn on Device1
    {
      digitalWrite(Light1, LOW);
      delay(200);
    }
    else if ((data == "turn off light one")||(data == "turn off light 1"))          // turn off Device1
    {
      digitalWrite(Light1, HIGH);
      delay(200);
    }  
    // Control the devices using voice command
    else if ((data == "turn on light two")||(data == "turn on light to")||(data == "turn on light 2")) // turn on Device2
    {
      digitalWrite(Light2, LOW);
      delay(200);
    }
    else if ((data== "turn off light two")||(data == "turn off light to")||(data == "turn off light 2")) // turn off Device2
    {
      digitalWrite(Light2, HIGH);
      delay(200);
    }
}
