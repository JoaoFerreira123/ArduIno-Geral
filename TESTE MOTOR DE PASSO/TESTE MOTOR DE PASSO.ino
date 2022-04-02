#define pot A0 

int i,j, pins[] = {8,9}, side = 0, velocidade;

void setup() {
  Serial.begin(9600);
  Serial.print("Digite 0 ou 1");
  for(i=0;i<2;i++){
    pinMode(pins[i],OUTPUT); // Configura os pinos como saída
  }
}

void loop() {
  
  if(Serial.available() > 0){  
    side = Serial.read();
  }
  velocidade = analogRead(pot); // Faz a leitura do potenciometro
  velocidade = map(velocidade,0,1023,1,100);
      
  if(side == 49){ // Aciona o motor no sentido Horário
    digitalWrite(pins[1],HIGH); // Defini a direção de rotação
    Serial.println("Horario");
    Serial.println(velocidade);
  	digitalWrite(pins[0],HIGH); // Envia um pulso de um passo
    delay(velocidade); 
    digitalWrite(pins[0],LOW);
  }
  if(side == 48){ // Aciona o motor no sentido Anti-Horário
    digitalWrite(pins[1],LOW); // Defini a direção de rotação
    Serial.println("Anti-Horario");
    Serial.println(velocidade);
    digitalWrite(pins[0],HIGH); // Envia um pulso de um passo
    delay(velocidade);
    digitalWrite(pins[0],LOW); 
  }
}