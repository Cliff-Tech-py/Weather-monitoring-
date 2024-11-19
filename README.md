This project is a **Weather Station Display System** using an ESP32, a DHT11 sensor, and a 16x2 I2C LCD screen. It continuously measures and displays temperature and humidity levels while intermittently showing a custom static message ("CLIFF-TECH Weather Station"). 

### Key Features:
1. **Temperature and Humidity Monitoring**:
   - Utilizes the DHT11 sensor to measure environmental temperature and humidity.
   - Updates the readings on the LCD every 2 seconds.

2. **Dynamic and Static Text Display**:
   - Alternates between displaying weather data and a static message ("CLIFF-TECH Weather Station").
   - Shows the static message for 3 seconds every 5 seconds.

3. **LCD Integration**:
   - The I2C LCD screen is used for clear and compact data visualization.
   - Handles message clearing to prevent overlapping or residual characters.

4. **Error Handling**:
   - Detects and displays an error message if the DHT11 sensor fails to provide valid data.

This system is ideal for small-scale weather monitoring projects, providing real-time environmental data in a user-friendly format. It is suitable for classrooms, hobby projects, or as an educational demonstration of IoT and embedded systems.
