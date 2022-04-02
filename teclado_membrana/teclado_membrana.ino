#include <Keypad.h>

char mapaTeclas[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte pinos_linha[4]={6,7,8,9};
byte pinos_coluna[3]={10,11,12};

Keypad teclado=Keypad(makeKeymap(mapaTeclas), pinos_linha, pinos_coluna, 4, 3);


void setup() {
  Serial.begin(9600);

}

void loop() {
  char tecla=teclado.getKey();
  if(tecla != NO_KEY){
    Serial.print(tecla);
  }
}
