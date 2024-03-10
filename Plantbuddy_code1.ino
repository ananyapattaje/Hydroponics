#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;
void setup() 
{
 Serial.begin(9600);
 pinMode(A0, INPUT);
 dht.begin();
 pinMode(7, INPUT);
 lcd.begin(16,2);
 lcd.setCursor(0,1);
 lcd.print("Ph/temp/hum");
}

  

void loop() {
  delay(2000);
  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();
  
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1500);
  delay(1000);
  float pHvalue = (7 + ((2.5 - voltage)/0.167));
 
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("pH:");
 lcd.setCursor(0, 1);
 lcd.print(pHvalue);
 lcd.setCursor(3, 1);
 lcd.print(" ");
 lcd.setCursor(4, 0);
 lcd.print("Temp:");
 lcd.setCursor(4, 1);
 lcd.print(Temperature,1);
 lcd.print((char)223);
 lcd.print("C");
 lcd.setCursor(10, 1);
 lcd.print(" ");
 lcd.setCursor(11, 0);
 lcd.print("Hum:");
 lcd.setCursor(11, 1);
 lcd.print(Humidity,1);
 lcd.print("%");
 delay(1000);
 pinMode(6, OUTPUT);
 analogWrite(6, 5);
}









