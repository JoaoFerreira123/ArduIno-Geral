#include <LiquidCrystal.h>

#define btcima 8
#define btbaixo 9
#define bttiro 10

LiquidCrystal lcd (7,6,5,4,3,2);

byte nave[8]={B11000,B01100,B01110,B01111,B01111,B01110,B01100,B11000};
byte asteroide[8]={B00000,B00100,B01110,B10111,B11011,B01110,B00100,B00000};
byte explosao[8]={B10001,B10101,B01010,B10100,B00101,B01010,B10001,B10001};
byte bateria[8]={B01110,B11011,B10001,B10101,B10101,B10101,B10001,B11111};
byte tiro[8]={B00000,B00000,B00000,B00111,B00111,B00000,B00000,B00000};

int velocidade=100;
int pxnave, pynave, pxtiro, pytiro, pxast, pyast, pxbat, pybat;
bool game, vtiro, vbat;
int pontos;
double nivBat;
int vtela;
int maxpontos=10;

void setup() {
  pxnave=0;
  pynave=0;
  pxbat=0;
  pybat=0;
  pontos=0;
  pxtiro=-1;
  pytiro=0;
  pxast=12;
  pyast=0;
  nivBat=100;
  vtela=0;

  lcd.createChar(1, nave);
  lcd.createChar(2, asteroide);
  lcd.createChar(3, explosao);
  lcd.createChar(4, bateria);
  lcd.createChar(5, tiro);
  
  lcd.begin(16,2);
  lcd.clear();

  game=false;
  vbat=false;
  vtiro=false;

}

void loop() {
  if(game){
    nivBat-=0.25;
    lcd.clear();
    if(nivBat<=0){
      game=0;
      vtela=2;
    }
    painel(13);
    if(digitalRead(btcima==1)){
      pynave=0;
    }
    if(digitalRead(btbaixo==1)){
      pynave=1;
    }
    if(digitalRead(bttiro==1)){
      pxtiro=1;
      vtiro=true;
      pytiro=pynave;
    }
    pxast-=1;
    desenhaNave(pxnave, pynave);
    desenhaAsteroide(pxast, pyast);
    if(vtiro){
     desenhaTiro(pxtiro, pytiro); 
     pxtiro+=1;
    }
    if(pxast<0){
      pxast=12;
      pyast=random(0,2);
    }
    if(pxtiro>16){
      vtiro=false;
      pxtiro=-1;
    }
    if((pxtiro==pxast) and (pytiro==pyast) or ((pxtiro==pxast+1) and (pytiro==pyast))){
      vtiro=false;
      pxtiro=-1;
      desenhaExplosaoAsteroide(pxast, pyast);
      pyast=random(0,2);
      pxast=12;
      pontos+=2;
      if(pontos>=maxpontos){
        game=0;
        vtela=1;
      }
    }
     if((pxnave==pxast) and (pynave==pyast)){
      game=0;
      desenhaExplosaoNave(pxnave, pyast);
      vtela=2;
      }

      if(!vbat){
        if(random(0,60)>58){
          pxbat=12;
          vbat=true;
          pybat=random(0,2);
        }
      }else{
        pxbat-=1;
        desenhaEnergia(pxbat, pybat);
        if(((pxnave==pxbat+1)and(pynave==pybat) or (pxnave==pxbat) and (pynave==pybat))){
          vbat=false;
          pxbat=-1;
          nivBat=100;
        }
      
    delay(velocidade);
  }
  }else{
    tela(vtela);
    if(digitalRead(bttiro)==1){
      resetar();
    }
  }

}
}
void desenhaNave(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(1);
}

void desenhaAsteroide(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(2);
}

void desenhaEnergia(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(4);
}

void desenhaTiro(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(5);
}

void desenhaExplosaoNave(int px, int py){
  lcd.clear();
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void desenhaExplosaoAsteroide(int px, int py){
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void resetar(){
  pontos=0;
  nivBat=100;
  game=true;
  vtela=0;
}

void painel(int px){
  lcd.setCursor(px, 0);
  lcd.print(pontos);
  lcd.setCursor(px, 1);
  lcd.print(nivBat);
}

void tela(int cond){   //0 tela inicial, 1 para ganhou e 2 para perdeu
  if(cond<1){
    lcd.setCursor(2,0);
    lcd.print("Nave Galatica");
    lcd.setCursor(0,1);
    lcd.print("Pressione tiro");
    }else{
  String txt[6]={(cond>0 ? "PERDEU" : "GANHOU")};
  lcd.setCursor(9,0);
  lcd.print("pts:");
  lcd.setCursor(13,0);
  lcd.print(pontos);
  lcd.setCursor(1,0);
  lcd.print(txt);
  lcd.setCursor(0,1);
  lcd.print("Pressione tiro");
}
}
