#define led 3
#define pot A5

void setup (){
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop (){
 analogWrite(led,map(analogRead(pot), 0, 1023, 0, 255));
}
