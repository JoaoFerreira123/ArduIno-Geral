#define led 4
#define bttn 7

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bttn, INPUT);

}

void loop() {
  if(digitalRead(bttn)==0)
    digitalWrite(led, LOW);
  else 
    digitalWrite(led, HIGH);
}
