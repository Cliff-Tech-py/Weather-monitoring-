#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define the DHT sensor pin and type
#define DHTPIN 5          // GPIO pin connected to the DHT11 data pin
#define DHTTYPE DHT11     // Define the type of DHT sensor

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// LCD settings
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Timing variables
unsigned long lastTextDisplayTime = 0;
unsigned long lastWeatherUpdateTime = 0;
unsigned long displayInterval = 5000;  // Interval to show the text (5 seconds)
unsigned long textDisplayDuration = 3000;  // Duration to show the text (3 seconds)
unsigned long weatherUpdateInterval = 2000;  // Weather update interval (2 seconds)
bool showingStaticText = false;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();

  // Determine if it's time to show the static text
  if (currentMillis - lastTextDisplayTime >= displayInterval && !showingStaticText) {
    showingStaticText = true;
    lastTextDisplayTime = currentMillis;
    
    // Display the static text
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CLIFF-TECH");
    lcd.setCursor(0, 1);
    lcd.print("Weather Station");
  }

  // Keep showing the static text for 3 seconds
  if (showingStaticText && (currentMillis - lastTextDisplayTime >= textDisplayDuration)) {
    showingStaticText = false;
    lastTextDisplayTime = currentMillis;  // Reset the last display time for the next interval
  }

  // Only update weather data when not showing the static text
  if (!showingStaticText && currentMillis - lastWeatherUpdateTime >= weatherUpdateInterval) {
    lastWeatherUpdateTime = currentMillis;

    // Display temperature and humidity readings
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Check if readings failed
    if (isnan(humidity) || isnan(temperature)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error");
    } else {
      // Display temperature and humidity only if the text isn't already on the screen
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print("C   ");  // Add spaces to clear any leftover characters

      lcd.setCursor(0, 1);
      lcd.print("Humid: ");
      lcd.print(humidity);
      lcd.print("%   ");  // Add spaces to clear any leftover characters
    }
  }
}
