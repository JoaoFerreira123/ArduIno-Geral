#include <Servo.h>
#define sensor A5
Servo s1;
bool claro=true;

void setup() {
  s1.attach(2);
  pinMode(sensor, INPUT);
  Serial.begin(9600);

}

void loop() {
  Serial.println(analogRead(sensor));
  if(analogRead(sensor)<200){
    s1.write(0);
    delay(150); 
  }else{
    s1.write(40);
    delay(50);
  }
  

}
