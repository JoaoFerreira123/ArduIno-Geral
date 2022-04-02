#define ldr A5
#define led 3 
void setup() {
  pinMode (ldr, INPUT);
  pinMode (led, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  if (analogRead(ldr)>250){
    digitalWrite(led,LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
  Serial.println(analogRead(ldr));
  delay(100);
  
}
