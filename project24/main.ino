#include<Servo.h>
int IR = D1;
Servo a;
void setup(){
  Serial.begin(9600);
  pinMode(IR, INPUT);
  a.attach(D7);
}
void loop(){
   int IRState = digitalRead(IR);
   Serial.println(IRState);
   if(IRState==0){
    a.write(180);
    delay(10);
   }
   else{
    a.write(0);
    delay(10);
   }
}
