int button = 4;
int leds[]={5,6,7,8};
int timing = 100;
int n = 0;
int flag=0;

void setup(){
  for (n=0; n<4; n++){
   pinMode (leds[n],OUTPUT); 
  }
  pinMode (button,INPUT);
}

void flashRG(){
 for (n=0;n<4;n++){
  digitalWrite(leds[n], HIGH);
  delay(timing);
  digitalWrite(leds[n], LOW);
  delay(timing);
 }
 flag=1;
}

void flashGR(){
 for (n=3;n>=0;n--){
   digitalWrite(leds[n], HIGH);
   delay(timing);
   digitalWrite(leds[n], LOW);
   delay(timing);
 } 
 flag=0;
}

void chooseFlash(){
 if (flag==0)
   flashRG();
  else flashGR();
}

void loop(){
 if (digitalRead(button)==HIGH)
   chooseFlash(); 
}
