//led aceso enquanto conta e led apagado após terminar


#define led 7
#define button 8
 int minutos=0;
 int segundos=0;
 
void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT);
 Serial.begin(9600);
Serial.println("Aperte para iniciar");
}

void loop() {
  if(digitalRead(button) == 1){
    minutos=30;
    segundos=59;
    //dai para o intervalo eu faria para setar o minutos em 5 
    segundos--;
    Serial.print("Tempo Restante: ");
    Serial.print(minutos);
    Serial.print(":");
    Serial.print(segundos);
    if(segundos==0){
      segundos=60;
      minutos--;
    }
    if(segundos==-1){
      segundos=59;
      minutos--;
    }
    delay(1000);
  }
  
}
