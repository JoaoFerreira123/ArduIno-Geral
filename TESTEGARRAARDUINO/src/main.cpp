#include <Arduino.h>
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
   //angs1=map(analogRead(pot),0,1023,0,180);
   //s1.write(angs1);
   s1.write(0);
   for(int i=0; i<180;i++){
    s1.write(i);
    delay(20);
   }
   for (int j = 180; j>0; j--){
    s1.write(j);
    delay(20);
   }
}