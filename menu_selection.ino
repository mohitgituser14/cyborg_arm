#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int upbut=6;
int downbut=7;
int selbut=8;
int menu=1;

void setup()
{
  lcd.begin(16,2);
  pinMode(upbut,INPUT_PULLUP);
  pinMode(downbut,INPUT_PULLUP);
  pinMode(selbut,INPUT_PULLUP);
  updateMenu();
}
 void loop()
 {
    if(!digitalRead(downbut))
    {
  menu++;
  updateMenu();
  delay(100);
  while(!digitalRead(downbut));
      
    }
    if(!digitalRead(upbut))
    {
  menu--;
  updateMenu();
  delay(100);
  while(!digitalRead(upbut));
 }
if(!digitalRead(selbut))
    {
  Actionplay();
  updateMenu();
  delay(500);
  while(!digitalRead(selbut));
      
    }
 }
void updateMenu()
{
  switch(menu)
  {
    case 1:
    lcd.clear();
    lcd.print("=> Voltage Measure");
    lcd.setCursor(0,1);
    lcd.print("Resistance");
    
    break;

    
    case 2:
    lcd.clear();
    lcd.print("Voltage Measure");
    lcd.setCursor(0,1);
    lcd.print("=> Resistance");
    
    break;
    
  case 3:
    lcd.clear();
    lcd.print("=> MenuItem3");
    lcd.setCursor(0,1);
    lcd.print("MenuItem4");
    
    break;

    case 4:
    lcd.clear();
    lcd.print("MenuItem3");
    lcd.setCursor(0,1);
    lcd.print("=> MenuItem4");
    
    break;

     case 5:
     menu=4;
     break;

  }
}
void action1()
{
 
  int sen=analogRead(A0);
  float voltage = sen * (5.0 / 1023.0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("voltage: "); // Prints Sensor Val: to LCD
  lcd.print(voltage);
  delay(1500);
}
void action2()
{
 
  int sen=analogRead(A1);
  float res = (5/sen)-1;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("resistance: "); // Prints Sensor Val: to LCD
  lcd.print(res);
  delay(1500);
}

void action3()
{
  delay(500);
}

void Actionplay()
{
  switch(menu)
  {
    case 1:
    action1();
    break;

    case 2:
    action2();
    break;

    case 3:
    action3();
    break;
  }
}
