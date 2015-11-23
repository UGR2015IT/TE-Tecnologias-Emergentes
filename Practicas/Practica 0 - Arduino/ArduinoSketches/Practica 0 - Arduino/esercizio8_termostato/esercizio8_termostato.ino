int led=5; 
int ntc=0;
int motor=10;
int medida=0;
int nivel=205;
void setup(){ 
  pinMode(led,OUTPUT); 
  pinMode(motor,OUTPUT); 
  Serial.begin(9600); 
  }

void monitoriza(){ 
  Serial.print("La medida es ...");
  Serial.println(medida); 

  delay(1000);
  }
  
  
void loop(){ 
  medida=analogRead(ntc);
  analogWrite(5,medida/4);
  Serial.print("valore");
  Serial.println(medida/4);
 monitoriza(); 
  if(medida/4>nivel){ 
  digitalWrite(led,HIGH);
  analogWrite(motor,HIGH);
  } 
  else{
    digitalWrite(led,LOW);
    digitalWrite(motor,LOW); 
    } 
}
