#include <Stepper.h>
#include <IRremote.h>

#define e1 8
#define e2 9
#define e3 10
#define e4 11
#define receptor 7
float valor;

IRrecv recIR(receptor); //recIR é o nome do receptor, que está coenctado na porta 11
decode_results resultado; //vai ficar armazenado o resultado do decode em resultado

const int passosPorGiro = 64;

Stepper mp(passosPorGiro, e1, e3, e2, e4);

void setup() {
   Serial.begin(9600);
   recIR.enableIRIn(); //Inicializar o receptor 

}

void loop() {
  if(recIR.decode(&resultado)){
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX);
    recIR.resume(); //Prepara o receptor para ler novamente
  switch(resultado.value){
    case (0xFF38C7):
      motor(0, 1,1,0);
      break;
    case(0xFF10EF):
      motor(500, -1,1,0);
      break;
    case(0xFF5AA5):
      motor(500, 1,1,0);
      break;
  }
  }

}


void motor(int vel, int sentido, int voltas, int tempo){
  mp.setSpeed(vel); //RPM - vai de 1 a 500
    for(int i=0; i<(32*voltas); i++){
    mp.step(passosPorGiro*sentido); //+ é sentido horário e se colocar - é sentido anti horário. Essa função faz com que ele dê um passo.
  }
  delay(tempo);
  
 }