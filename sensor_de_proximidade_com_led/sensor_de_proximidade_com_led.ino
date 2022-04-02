#include <HCSR04.h>

#define ledVerm 5
#define ledAmar 6
#define ledVerd 7
#define p_trigger 3
#define p_echo 4

UltraSonicDistanceSensor sensor (p_trigger, p_echo);
float dist_cm;
float dist_m;

void setup() {
Serial.begin(9600);
pinMode(ledVerm, OUTPUT);
pinMode(ledAmar, OUTPUT);
pinMode(ledVerd, OUTPUT);

}

void loop() {
dist_cm=sensor.measureDistanceCm();
dist_m=dist_cm/100;
Serial.print("Distancia: ");
Serial.print(dist_cm);
Serial.print("cm | ");
Serial.print(dist_m);
Serial.println("m");
Serial.println("-----------------------------------------------");
delay(300);


if(dist_cm<=15){
  digitalWrite(ledVerm, HIGH);
  digitalWrite(ledAmar, LOW);
  digitalWrite(ledVerd, LOW);
}else if((dist_cm > 15) and (dist_cm <=25)){
  digitalWrite(ledVerm, LOW);
  digitalWrite(ledAmar, HIGH);
  digitalWrite(ledVerd, LOW);
}else if(dist_cm >25){
  digitalWrite(ledVerm, LOW);
  digitalWrite(ledAmar, LOW);
  digitalWrite(ledVerd, HIGH);
}


}
