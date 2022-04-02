#include <LiquidCrystal.h>

/*MODIFY THOSE VALUES TO ADAPT THE TIMER*/
const int WORK_TIME_MIN = 3;
const int REST_TIME_MIN = 1;

/*LCD INITIALISATION*/

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

/*VARIABLES*/
signed short minutes, secondes, types;
signed short periodType = 0; // periodType == 0 : work time; periodType == 1 : rest time
char timeline[16];

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
  //lcd.print("Tempo Gasto ");

  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void loop() {

  lcd.setCursor(5, 0);
  sprintf(timeline, "%0.2d:%0.2d ", minutes, secondes);
  lcd.print(timeline);

  delay(1000);
  secondes++;

  if (secondes == 60)
  {
    secondes = 0;
    minutes ++;
  }
  /*PASSAGE TRAVAIL VERS REPOS*/
  if ((minutes == WORK_TIME_MIN) && (periodType == 0)) /*15*/
  {
    minutes = 0;
    periodType = 1;
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }

  /*PASSAGE REPOS VERS TRAVAIL*/
  else if ((minutes == REST_TIME_MIN) && (periodType == 1)) /*5*/
  {
    minutes = 0;
    periodType = 0;
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }

}
