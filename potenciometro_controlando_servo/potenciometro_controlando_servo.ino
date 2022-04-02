#include <Servo.h>

Servo s1;
#define pot A0
int angs1;
void setup() {
  s1.attach(5);
  angs1=0;
  pinMode(pot, INPUT);
  
}

void loop() {
   angs1=map(analogRead(pot),0,1023,0,180);
   s1.write(angs1);

}
// problema com o servo que controla o braço B (porta 4) - está vibrando muito e fazendo todo o braço vibrar
// problema com o servo que controla o braço A (porta 5) - não mexe
// problema com o servo que controla a rotação (porta 6) - não mexe
// SUSPEITO QUE EM TODOS OS CASOS SEJA PROBLEMA DE NÃO TER CORRENTE O SUFICIENTE
