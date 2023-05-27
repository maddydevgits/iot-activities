int soil = A0;
int buzzer = 11;
int led = 13;


void setup() {
  Serial.begin(9600);
  pinMode(soil,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop (){
  int m =  analogRead(soil);
  Serial.println(m);
  if(m < 377) {
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,HIGH);
  }
  else {
    digitalWrite(buzzer,LOW);

    digitalWrite(led,LOW);
  }
}
