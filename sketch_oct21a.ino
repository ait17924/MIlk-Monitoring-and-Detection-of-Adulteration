
#include<LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins
char s;
void setup()
{
   sensors.begin();
  Serial.begin(9600);
 lcd.begin(16, 2);  // initializes the 16x2 LCD
 Serial.begin(9600);

}

void loop()
{

 sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");

  delay(1000); 
  lcd.setCursor(0,0);           //sets the cursor at row 0 column 0
  lcd.print("X"); // prints 16x2 LCD MODULE
  lcd.print(Celsius);
   lcd.print(" "); 
   lcd.setCursor(1,1);        
  lcd.print("Y"); // prints 16x2 LCD MODULE
  lcd.print(Fahrenheit);
   
}
