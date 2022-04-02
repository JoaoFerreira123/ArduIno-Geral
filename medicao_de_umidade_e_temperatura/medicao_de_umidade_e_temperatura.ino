#include <dht.h>
#define sensor 7

dht sensUmiTemp;

void setup() {
  Serial.begin(9600);
  delay(2000);

}

void loop() {
  sensUmiTemp.read11(sensor);
  Serial.print("Temperatura: ");
  Serial.print(sensUmiTemp.temperature,0);
  Serial.println("ºC");
  Serial.print("Umidade: ");
  Serial.print(sensUmiTemp.humidity,0);
  Serial.println("%");
  Serial.println("----------------------------------");
  delay(2000);

}
