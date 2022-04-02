#include<HCSR04.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

#define trig 12
#define echo 13
UltraSonicDistanceSensor sensor(trig, echo);

float dis_cm=0;
float dis_m=0;


void setup() {
  lcd.begin(16,2); 
  Serial.begin(9600);
}

void loop() {
  
  dis_cm=sensor.measureDistanceCm();
  dis_m=dis_cm/100;
  lcd.setCursor(0,0);
  lcd.print("Dist CM: ");
  lcd.print(9,0);
  lcd.print(dis_cm);
  lcd.setCursor(0,1);
  lcd.print("Dist M: ");
  lcd.print(dis_m);
  delay(500);
}
