#include <Servo.h>
Servo s1;
int angs1;

void setup() {
s1.attach(4);
angs1=0;
}

void loop() {
  
  s1.write(0);
  delay(100);
  s1.write(180);
  delay (100);
  
 
  
}
