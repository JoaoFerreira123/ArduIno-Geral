#include <Servo.h>
#define p1 A1
#define p2 A2
#define p3 A3
#define p4 A4
#define p5 A5 

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
int angs1=0, angs2=0, angs3=0, angs4=0, angs5=0;
void setup() {
  s1.attach(2);
  s2.attach(3);
  s3.attach(4);
  s4.attach(5);
  s5.attach(6);
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);
  pinMode(p5, INPUT);

}

void loop() {
  angs1=map(analogRead(p1),0,1023,0,180);
  s1.write(angs1);
  angs2=map(analogRead(p2),0,1023,0,180);
  s2.write(angs2);
  angs3=map(analogRead(p3),0,1023,0,180);
  s3.write(angs3);
  angs4=map(analogRead(p4),0,1023,0,180);
  s4.write(angs4);
  angs5=map(analogRead(p5),0,1023,0,180);
  s5.write(angs5);

}
//Servo 1 (giro) tem que colocar o 2º parafuso de fixação na base
//servo 2 (do braço A) necessita de elásticos para ajudar a movimentar
//servo 5 (abertura da garra) travou/não funciona