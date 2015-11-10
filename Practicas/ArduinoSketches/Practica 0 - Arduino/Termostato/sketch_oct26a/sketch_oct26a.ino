int led=5;
int ntc=0;
int motor=10;
int medida=0;
int nivel=700; //variable que guarda el límite de temperatura al que se activa el ventilador
void setup(){
pinMode(led,OUTPUT);
pinMode(motor,OUTPUT);
Serial.begin(9600);
}
void monitoriza(){ //procedimiento que envía al puerto serie, para ser leído en el monitor,
Serial.print("La medida es ...");
Serial.println(medida);
Serial.print("");
delay(1000); //para evitar saturar el puerto serie
}
void loop(){
medida=analogRead(ntc);
monitoriza();
if(medida>nivel){ //si la señal del sensor supera el nivel marcado:
digitalWrite(led,HIGH); //se enciende un aviso luminoso
digitalWrite(motor,HIGH); //arranca el motor
}
else{ // si la señal está por debajo del nivel marcado
digitalWrite(led,LOW);
digitalWrite(motor,LOW); // el motor se para
}
}
