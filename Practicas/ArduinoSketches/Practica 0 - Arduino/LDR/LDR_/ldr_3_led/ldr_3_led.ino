int led[]={9,10,11};
int ldr=0;
int luz=0;

void setup(){
  
  for (int i=9; i<12; i++)
    pinMode(i,OUTPUT);
  Serial.begin(9600);
  
}

void monitoriza(){
  
  Serial.print("El valor de luz es ...");
  Serial.println(luz);
  delay(1000);
  
}

void loop(){
  luz=analogRead(ldr);
  monitoriza();
  if (luz >= 768 && luz <=1023){
    analogWrite(led[2],64);
    analogWrite(led[0],0);
    analogWrite(led[1],0);
  }
  else if (luz >= 512 && luz <=767){
    analogWrite (led[1], 127);
    analogWrite(led[0],0);
    analogWrite(led[2],0);
  }
  else if (luz >=256 && luz <= 511){
    analogWrite (led[0],255);
    analogWrite(led[2],0);
    analogWrite(led[1],0);
  }
  else if (luz <255){
    for (int i=0; i<3;i++)
      analogWrite (led[i],255);
  }
}
