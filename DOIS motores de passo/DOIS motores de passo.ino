#include <Stepper.h>

#define e1 8
#define e2 9
#define e3 10
#define e4 11

#define e5 2
#define e6 3
#define e7 4
#define e8 5

#define pot A0

const int passosPorGiro = 64;

Stepper m1(passosPorGiro, e1, e3, e2, e4);

Stepper m2(passosPorGiro, e5, e7, e6, e8);



void setup(){}


void loop(){
  motor(500, 1, 1, 0);


  
  }

 void motor(int vel, int sentido, int voltas, int tempo){
  m1.setSpeed(vel);   //RPM - vai de 1 a 500
  m2.setSpeed(vel);

  
    for(int i=0; i<(32*voltas); i++){
    m1.step(passosPorGiro*sentido);
    m2.step(passosPorGiro*sentido); //+ é sentido horário e se colocar - é sentido anti horário. Essa função faz com que ele dê um passo.
  }

  delay(tempo);
  
 }


 
