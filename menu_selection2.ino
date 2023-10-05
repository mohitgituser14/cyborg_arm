
  // put your setup code here, to run once:
#include <LiquidCrystal.h>
// button red is 6 then onwards 7 8 
const int but1=6;
const int but2=7;
const int but3=8;
int volt_buttonState = 0;        
int resist_buttonState = 0;    
int back_buttonState = 0; 
float voltage = 0;
float sen = 0;
float sen2 = 0;
float res = 0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int num=0;

 /*
// defines variables
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement
*/
void setup() {

  lcd.begin(16, 2);
  
}
void loop() {

  volt_buttonState = digitalRead(but1);
  resist_buttonState = digitalRead(but2);
  back_buttonState = digitalRead(but3);
  if(volt_buttonState == LOW && resist_buttonState == HIGH )
  {
      num=1;
    
  }
  else num=4;

  if(volt_buttonState == HIGH && resist_buttonState == LOW )
  {
      num=2;
    
  }
  else num=4;  
  if((num==1 ||num==2) && back_buttonState == LOW  )
  {
      num=3;
    
  }
  else num=4;  
  
  switch(num)
  {

     case 1 : 
     sen=analogRead(A0);
     voltage = sen * (5.0 / 1023.0);
    lcd.setCursor(0,0);
  lcd.print("Voltage: "); // Prints Sensor Val: to LCD
  lcd.print(voltage);  
  break;
  
    case 2 :
    sen2=analogRead(A1);
    res=(50/sen2)-10;
    lcd.setCursor(0,0);
  lcd.print("Resistance: "); // Prints Sensor Val: to LCD
  lcd.print(res);
  break;
  
    case 3 :
    num=0;
    break;
    case 4 :
    lcd.setCursor(0,0);
  lcd.print("Error !");
  break;
    
    

  
     
  }
  
  // Clears the trigPin condition
 /* digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  // Sets the trigPin LOW (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, LOW);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Displays the distance on the Serial Monitor
  lcd.setCursor(0,0);
  lcd.print("SensorVal1: "); // Prints Sensor Val: to LCD
  lcd.print(distance);*/
  delay(500);
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
