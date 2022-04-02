#define led 9
#define minimo 0
#define maximo 128
#define temp 5

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {

 for(int x=minimo; x<maximo; x=x+2){ //varia-se a velocidade para acender mudando o 1 para outro numero. Pode-se usar também o X++ incrementando de 1 em 1
 analogWrite(led,x);
 delay(temp);

 }

  for(int x=maximo; x>minimo; x=x-2){  //varia-se a velocidade para apagar mudando o 1 para outro numero. Pode-se usar também o X-- decrementando de 1 em 1
    analogWrite(led,x);
    delay(temp);
  }

}
