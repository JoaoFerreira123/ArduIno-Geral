#define pot A5
int leds []={2,3,4,5,6,7};

void setup() {
 for(int i=0; i<6; i++){
  pinMode(leds[i], OUTPUT);
 }
  pinMode(pot, INPUT);
}

void acender(int x){
  int i;
  for(i=0; i<x; i++){
    digitalWrite(leds[i], HIGH);
  }
  for(i=x; i<6; i++){
    digitalWrite(leds[i], LOW);
  }
}




void loop() {
 acender (map(analogRead(pot),0, 1023, 0, 6));
}
