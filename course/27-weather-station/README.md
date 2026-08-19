# 🌤️ Day 27 – Weather Station

Build a professional environmental monitoring system displaying real-time temperature and humidity on OLED display.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🌡️ Temperature monitoring
- 💧 Humidity measurement
- 📊 Real-time OLED display
- 🔄 Continuous data updates
- 💾 Professional presentation

---

## 🎯 What You'll Learn

- Environmental sensor operation
- I2C protocol communication
- OLED display integration
- Data formatting and display
- Real-time monitoring systems
- Weather data visualization

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| DHT11 Sensor | 1 |
| OLED Display (128×64 I2C) | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 6 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | DHT11 VCC + OLED VCC |
| GND | DHT11 GND + OLED GND |
| Pin 7 | DHT11 DATA |
| A4 | OLED SDA (I2C data) |
| A5 | OLED SCL (I2C clock) |

**⚠️ Important:** DHT11 requires 10kΩ pull-up resistor between DATA pin & 5V. OLED uses I2C protocol on A4 & A5.

---

## 💻 How It Works

### Initialize Display and Sensor
In setup(), Arduino initializes OLED display library with correct I2C address. DHT11 sensor library initialized for temperature & humidity reading.

### Configure Display Layout
OLED display size set to 128 pixels wide by 64 pixels high. Text size configured for readability. Display powered on with full brightness.

### Read Temperature and Humidity
Inside main loop, Arduino reads temperature using dht.readTemperature() and humidity using dht.readHumidity(). Functions communicate with DHT11 sensor.

### Check Data Validity
Program verifies sensor readings are valid before displaying. If sensor fails, error message displays instead of false data.

### Format Display Information
OLED library functions draw text, numbers, and graphics at specific locations. Information organized with temperature at top, humidity below.

### Real-Time Update Cycle
Display continuously updates showing current conditions every two seconds. Users see real-time environmental changes as they happen.

---

## 🚀 Getting Started

1. Connect DHT11 to Pin 7 with pull-up resistor
2. Connect OLED via I2C (A4, A5)
3. Connect Arduino to computer
4. Load Weather Station sketch
5. Select **Tools → Board → Arduino UNO**
6. Upload code
7. Watch live weather data display!

---

## 💾 Source Code (WeatherStation.ino)

```cpp
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Weather Station");
  display.display();
  
  // Initialize DHT
  dht.begin();
  Serial.begin(9600);
  
  delay(2000);
}

void loop() {
  // Read sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Check for valid readings
  if (isnan(temperature) || isnan(humidity)) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 25);
    display.println("DHT Error!");
    display.display();
    delay(2000);
    return;
  }
  
  // Display information
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.println(temperature);
  
  display.print("Humidity: ");
  display.println(humidity);
  
  display.setTextSize(1);
  display.setCursor(0, 50);
  display.println("Real-time monitoring");
  
  display.display();
  
  // Serial output
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.println(humidity);
  
  delay(2000);  // Update every 2 seconds
}
```

---

## 📸 Expected Output

- 📊 OLED displays "Weather Station"
- 🌡️ Temperature reading updates continuously
- 💧 Humidity percentage displays
- 🔄 Auto-refreshes every 2 seconds
- 📈 Real-time environmental monitoring

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Add temperature alerts
if (temperature > 35) {
  display.println("HIGH TEMP!");
  tone(buzzerPin, 1000);
}

// Calculate heat index
float heatIndex = calculateHI(temperature, humidity);

// Log to EEPROM
eeprom_write_data(temperature);

// Display weather icons
if (humidity > 70) {
  drawRainIcon();
}

// Min/max tracking
if (temperature > maxTemp) {
  maxTemp = temperature;
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| OLED shows nothing | Verify I2C address (0x3C), check A4 & A5 |
| No temperature data | Check DHT11 to Pin 7 with pull-up resistor |
| Display updates slow | Reduce delay() value |
| Garbled text | Verify OLED size matches code (128×64) |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| DHT11 | Digital temperature & humidity sensor |
| I2C Protocol | Two-wire communication standard |
| OLED Display | Organic LED screen with I2C interface |
| Sensor Calibration | Adjusting for accurate readings |
| Real-time Monitoring | Live environmental data updates |

---

## 📚 Next Project

➡️ **Day 28 – Smart Home Automation** - Build complete home system!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
