#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {

lcd.begin(16,2);

}

void loop() {
lcd.setCursor(2,0);
lcd.print("Hello World!");
delay(3000);

for(int i=0; i<2; i++){
  lcd.scrollDisplayLeft();
  delay(100);
}

for(int i=0; i<4; i++){
  lcd.scrollDisplayRight();
  delay(100);
}
for(int i=0; i<2; i++){
  lcd.scrollDisplayLeft();
  delay(100);
}
  delay(1000);
lcd.noDisplay();
delay(500);
lcd.display();
delay(500);
lcd.noDisplay();
delay(500);
lcd.display();
delay(500);
lcd.noDisplay();
delay(500);
lcd.display();
delay(500);

  
}
