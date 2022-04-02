#define sensorPin A0 //define entrada analógica A0

int sensorValue = 0; //variavel inteiro igual a 0
float voltage; //variavel numero fracionário

void setup()
{
  Serial.begin(9600); //monitor serial - velocidade 9600bps
  delay(100); 
}
void loop()
{
  sensorValue = analogRead(sensorPin); // leitura da entrada A0
  voltage = sensorValue * (5.0 / 1024); //calculo da tensão

  Serial.print ("Tensão do potenciometro: "); //imprime no monitor serial
  Serial.print(voltage); //imprime a tensao
  Serial.print("       Valor: "); //imprime no monitor serial
  Serial.println(sensorValue); //imprime o valor
  delay(500); 
}
