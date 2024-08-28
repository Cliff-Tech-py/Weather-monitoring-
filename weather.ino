#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2          // GPIO pin connected to the DHT11 data pin
#define DHTTYPE DHT11     // Define the type of DHT sensor
#define LCD_ADDRESS 0x27  // I2C address of the LCD

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2); // Initialize LCD with 16 columns and 2 rows

void setup() {
  Serial.begin(115200);   // Initialize serial communication for debugging
  dht.begin();            // Initialize the DHT sensor
  lcd.begin(16, 2);       // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight();        // Turn on the backlight of the LCD
}

void loop() {
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if readings failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  // Print values to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("C");

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("H: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(2000); // Wait a few seconds between readings
}
