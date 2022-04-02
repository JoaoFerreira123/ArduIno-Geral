#include <LiquidCrystal.h>
#include <IRremote.h>
#define receptor 11
IRrecv recIR(receptor);
decode_results resultado;
LiquidCrystal lcd(7,6,5,4,3,2);

int segundos = 0;
int minutos = 30;
bool estado=false;

void setup() {

lcd.begin(16,2);
recIR.enableIRIn();
Serial.begin(9600);
}
//0 - PAUSA // OK PARA INICIAR TODOS OS TIMERS // OK=FF38C7 // 0=FF9867 // 1=FFA25D


 
void loop() {
  
 if(recIR.decode(&resultado)){
  Serial.println(resultado.value, HEX);
if(resultado.value==0xFF38C7){
    estado=true;
  }
  if(resultado.value==0xFF9867){
    estado=false;
  }


  
    if(estado=true){
      conta();
    }
    if(estado=false){
      pausa();
    }

  
 }

}

void conta(){
//digitalWrite(saida,HIGH); 
segundos--; 
lcd.clear();
lcd.setCursor(0,1);
if(minutos<10){ lcd.print("0");}
lcd.print(minutos);
lcd.print(":");
  if(segundos<10){ lcd.print("0");}
lcd.print(segundos); 
if(segundos==0){
  segundos=60;
  minutos--;   
}
if(segundos==-1){
  segundos=59;
  minutos--;
  lcd.clear();
lcd.setCursor(0,1);
lcd.print(minutos);
lcd.print(":59");
}
  if(minutos<0){
  fim();
}

delay(1000);
} 


void pausa(){

lcd.clear();
lcd.setCursor(0,1);
if(minutos<10){ lcd.print("0");}
lcd.print(minutos);
lcd.print(":");
if(segundos<10){ lcd.print("0");}
lcd.print(segundos);
lcd.print("   Parado");
delay(200);

}

void fim(){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Tempo");
lcd.setCursor(0,1);
lcd.print("Finalizado");
minutos=0;
segundos=0;
}
