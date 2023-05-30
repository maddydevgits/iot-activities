int ir1=D3;
int ir2=D4;
int ir3=D5;
void setup(){
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  Serial.begin(9600);
}
void loop(){
  int slot1=digitalRead(ir1);
  int slot2=digitalRead(ir2);
  int slot3=digitalRead(ir3);
  if (slot1==1 && slot2==1 && slot3==1){
      Serial.println("All slots are available");
  }
  else if (slot1==0 && slot2==1 && slot3==1){
      Serial.println("Slot 2 and 3 is available");
     
  }
  else if (slot1==0 && slot2==0 && slot3==1){
      
      Serial.println("slot 3 is available");
  }
  else if (slot1==0 && slot2==1 && slot3==0){
      
      Serial.println("slot 2 is available");
  }
   else if (slot1==1 && slot2==0 && slot3==0){
      
      Serial.println("slot 1 is available");
  }
  else if (slot1==1 && slot2==0 && slot3==1){
      Serial.println("Slot 1 and 3 is available");
     
  }
  else if (slot1==1 && slot2==1 && slot3==0){
      Serial.println("Slot 1 and 2 is available");
     
  }
  else{
    Serial.println("ALL SLOTS AREE FULL");
  }
      
}
