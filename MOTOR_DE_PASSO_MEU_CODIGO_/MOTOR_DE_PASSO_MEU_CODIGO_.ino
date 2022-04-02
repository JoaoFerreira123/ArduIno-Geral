#include <Stepper.h>

#define e1 8
#define e2 9
#define e3 10
#define e4 11

#define pot A0

const int passosPorGiro = 64;

Stepper mp(passosPorGiro, e1, e3, e2, e4);


void setup(){}


void loop(){
  motor(500, 1, 1, 1000);
  motor(500, -1, 0.5,100);

  
  }

 void motor(int vel, int sentido, int voltas, int tempo){
  mp.setSpeed(vel); //RPM - vai de 1 a 500
    for(int i=0; i<(32*voltas); i++){
    mp.step(passosPorGiro*sentido); //+ é sentido horário e se colocar - é sentido anti horário. Essa função faz com que ele dê um passo.
  }
  delay(tempo);
  
 }
