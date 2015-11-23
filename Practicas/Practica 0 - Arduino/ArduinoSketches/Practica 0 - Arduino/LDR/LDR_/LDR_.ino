int led=9;
int ldr=0;
int luz=0;
void setup(){
pinMode(9,OUTPUT);
Serial.begin(9600);
}
void monitoriza(){
Serial.print("El valor de luz es ...");
Serial.println(luz);
delay(100);
}
void loop(){
luz=analogRead(ldr);
monitoriza();
if(luz<512 && luz>=0){
analogWrite(led,255);
}
if(luz>=512 && luz<=1024) {
analogWrite(led,64);
}
}
