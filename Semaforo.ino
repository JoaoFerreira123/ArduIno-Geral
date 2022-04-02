#define led_vermelho 10
#define led_amarelo 11
#define led_verde 12


void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void vermelho(int temp) {
digitalWrite(led_vermelho, HIGH);
digitalWrite(led_amarelo, LOW);
digitalWrite(led_verde, LOW);
delay(temp);
}


void verde(int temp) {
digitalWrite(led_vermelho, LOW);
digitalWrite(led_amarelo, LOW);
digitalWrite(led_verde, HIGH);
delay(temp);
}

void amarelo(int temp) {
digitalWrite(led_vermelho, LOW);
digitalWrite(led_amarelo, HIGH);
digitalWrite(led_verde, LOW);
delay(temp);
}

void loop (){
  vermelho(5000);
  verde(6000);
  amarelo(2000);

}
