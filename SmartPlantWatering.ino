#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soilPin = A0;
const int waterPin = A1;
const int relayPin = 7;

bool pumpOn = false;

void setup()
{
Serial.begin(9600);

lcd.init();
lcd.backlight();

pinMode(relayPin, OUTPUT);
digitalWrite(relayPin, LOW);

lcd.setCursor(0, 0);
lcd.print("Smart Plant");

lcd.setCursor(0, 1);
lcd.print("Starting...");

delay(2000);
}

void loop()
{
// Read sensors
int soilValue = analogRead(soilPin);
int waterValue = analogRead(waterPin);

// Serial output
Serial.print("Soil: ");
Serial.print(soilValue);
Serial.print(" | Water: ");
Serial.println(waterValue);

// Calculate moisture percentage
int moisture = map(soilValue, 0, 700, 0, 100);
moisture = constrain(moisture, 0, 100);

// Determine water level
String waterStatus;

if (waterValue < 400)
{
waterStatus = "NONE";
}
else if (waterValue < 600)
{
waterStatus = "LOW";
}
else if (waterValue < 660)
{
waterStatus = "MED";
}
else
{
waterStatus = "HIGH";
}

// Hysteresis control

if (!pumpOn && moisture < 30 && waterValue >= 500)
{
pumpOn = true;
}

if (pumpOn && moisture > 45)
{
pumpOn = false;
}

if (waterValue < 500)
{
pumpOn = false;
}

digitalWrite(relayPin, pumpOn ? HIGH : LOW);

// LCD display

lcd.clear();

lcd.setCursor(0, 0);
lcd.print("M:");
lcd.print(moisture);
lcd.print("%");

lcd.setCursor(10, 0);
lcd.print(waterStatus);

lcd.setCursor(0, 1);

if (pumpOn)
{
lcd.print("WATERING");
}
else if (moisture < 30)
{
lcd.print("SOIL DRY");
}
else
{
lcd.print("SOIL OK ");
}

lcd.setCursor(10, 1);

if (pumpOn)
{
lcd.print("P:ON ");
}
else
{
lcd.print("P:OFF");
}

delay(1000);
}
