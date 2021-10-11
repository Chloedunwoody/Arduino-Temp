#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int  Degree_buttonPin = 12;

byte degree[8] = {
  B01100,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(7, degree);
  dht.begin();
  pinMode( Degree_buttonPin , INPUT_PULLUP);
}

void loop() {
  delay(3000);
  lcd.clear();
  float humi = dht.readHumidity();
  delay(20);
  float temp = dht.readTemperature();
  delay(20);
  float tempF = dht.convertCtoF(temp);
  delay(20);
  float tempC = dht.convertFtoC(tempF);
  delay(20);

  int val = digitalRead(Degree_buttonPin);
  lcd.setCursor(0, 0);
  lcd.print("Temp:");

  if (val != 0) {
    lcd.print(tempF);
    lcd.write(7);
    lcd.print("F");

  }
  else {
    lcd.print(tempC);
    lcd.write(7);
    lcd.print("C");

  }

  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.print(humi);
  lcd.print(char(37));

}
