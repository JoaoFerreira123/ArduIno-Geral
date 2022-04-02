#define som 11

void setup() {
  pinMode(som, OUTPUT);

}

void loop() {
    tone(som, 1350);
    delay(150);
    tone(som, 1050);
    delay(150);
  }
