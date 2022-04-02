

void setup() {  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  

}

void loop() {
 digitalWrite(8, HIGH);
 delay(180000);
 digitalWrite(8, LOW);
 digitalWrite(9, HIGH);
 delay(60000);
 digitalWrite(9, LOW);
  }
  
  



void estuda(){
  digitalWrite(8, HIGH);
  delay(240000); //4 MIN
  digitalWrite(8, LOW);
}

void intervalo(){
  digitalWrite(9, HIGH);
  delay(60000);
  digitalWrite(9, LOW);
}
