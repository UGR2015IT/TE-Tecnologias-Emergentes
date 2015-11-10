int leds[] = {
  5,6,7,8,9};
int buzzer = 10;
int button = 11;
int n=0;
int timing=500;
int numeroLED=5;

void setup(){
  for (n=0; n<5; n++){
    pinMode(leds[n], OUTPUT); 
  }
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
}

void flash();
void modTime(int);
void soundWinner();

void loop(){
  flash();
}

void flash(){
  for (n=0;n<numeroLED;n++){
    digitalWrite(leds[n],HIGH);
    delay(timing);
    modTime(n);
    digitalWrite(leds[n],LOW);
  } 
}

void modTime(int led){
  if (digitalRead(button)==HIGH && led==2){
    soundWinner();
    timing=timing-50;
  }
}

void soundWinner(){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  if (timing==100){
    for (int i=0;i<3;i++){
      digitalWrite(buzzer, HIGH);
      delay(timing);
      digitalWrite(buzzer, LOW);
    }
  }
}


