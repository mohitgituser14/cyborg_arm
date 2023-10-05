int flag = 0, count = 2;
float start_time;
float stop_time;
int ar[3];
#include <LiquidCrystal.h>

const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

}


void loop() {
  start_time = 0;
  //int value = 1.5*analogRead(A0);
  //lcd.print("Analog value : ");
  //lcd.print(value);
  int x = digitalRead(8);
  if (x == 0)
  {
    if (!(count % 2 == 0))
    {
      stop_time = millis();
      ar[0] = stop_time;    
      count++;

      lcd.print("stop time : ");
      //lcd.print(stop_time);
      float z = (ar[0] - ar[1])/100;
      

      //lcd.print(z);
      //float frequency = (1.0/z);

      float omega = 60*z;
      lcd.setCursor(0,0);
      lcd.print("RPM: ");
      lcd.print(omega);
      Serial.print("RPM: ");
      Serial.print(omega);

    }

    else
    {

      start_time = millis();
      ar[1] = start_time;
      delay(350);
      count++;
      lcd.print("start time : ");
      //lcd.print(start_time);

    }

  }

  // lcd.print("count value : ");

  // lcd.print(count);



  delay(100);
}
