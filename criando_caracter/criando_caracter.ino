#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

byte coracao[8]={B00000,B01010,B11111,B11111,B11111,B01110,B00100,B00000};
byte batL[8]={B01110,B11011,B10001,B10001,B10001,B10001,B10001,B11111};
byte batM[8]={B01110,B11011,B10001,B10001,B11111,B11111,B11111,B11111};
byte batF[8]={B01110,B11111,B11111,B11111,B11111,B11111,B11111,B11111};

void setup() {
  lcd.begin(16,2);
  lcd.createChar(1,coracao);
  lcd.createChar(2, batL);
  lcd.createChar(3, batM);
  lcd.createChar(4, batF);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(2);
  lcd.setCursor(0,1);
  lcd.write(1);
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.setCursor(0,1);
  lcd.write(1);
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(4);
  lcd.setCursor(0,1);
  lcd.write(1);
  delay(3000);
  
  
  

}
