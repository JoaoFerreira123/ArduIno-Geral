#include <IRremote.h>
#define receptor 11

IRrecv recIR(receptor);
decode_results resultado;

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  recIR.enableIRIn();
}



void loop() {
  if(recIR.decode(&resultado)){
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX);
    recIR.resume();
switch(resultado.value){
  case(0xFF629D):
    digitalWrite(5, HIGH);
    break;
  case(0xFFA25D):
    digitalWrite(5, LOW);
    break;
 
}

}
}
