
//www.diyusthad.com
#include <LiquidCrystal.h>

const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define echoPin 1 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 0 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  lcd.begin(16, 2);
  
}
void loop() {

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  /*delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)*/

  // Displays the distance on the Serial Monitor
  lcd.setCursor(0,0);
  lcd.print("SensorVal1: "); // Prints Sensor Val: to LCD
  int a=digitalRead(13);
  lcd.print(a);
  delay(500);
} 
