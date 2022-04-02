#include <IRremote.h>
#include <Servo.h>
float valor;
Servo s1;
#define receptor 11
IRrecv recIR(receptor); //recIR é o nome do receptor, que está coenctado na porta 11
decode_results resultado; //vai ficar armazenado o resultado do decode em resultado

void setup() {
  s1.attach(3);
  Serial.begin(9600);
  recIR.enableIRIn(); //Inicializar o receptor 

}

void loop() {
  if(recIR.decode(&resultado)){
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX);
    recIR.resume(); //Prepara o receptor para ler novamente
  switch(resultado.value){
    case (0xFF18E7):
      s1.write(90);
      break;
    case(0xFF10EF):
      s1.write(180);
      break;
    case(0xFF5AA5):
      s1.write(0);
      break;
  }
  }

}
