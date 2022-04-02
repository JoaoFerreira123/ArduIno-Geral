#include <HCSR04.h>

#define p_trigger 4
#define p_echo 5

UltraSonicDistanceSensor sensor(p_trigger, p_echo);
float dist_cm;
float dist_m;


void setup() {
Serial.begin(9600); 

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
delay(500);
}
