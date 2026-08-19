# 💡 Day 11 – Temperature Monitor DHT11

Build an environmental monitoring system that reads temperature and humidity in real-time using the DHT11 sensor.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 🌡️ Read temperature in Celsius
- 💧 Measure humidity percentage
- 📊 Display data on Serial Monitor
- 🔄 Real-time environmental monitoring
- ⚙️ Learn to use sensor libraries

---

## 🎯 What You'll Learn

- How DHT11 temperature and humidity sensors work
- Installing and using Arduino libraries
- Reading data from digital sensors
- Pull-up resistor concepts
- Processing sensor data
- Environmental monitoring applications

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| DHT11 Sensor | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 3 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Sensor Pin |
|-------------|-----------|
| 5V | VCC (Power) |
| Pin 7 | DATA (Signal) |
| GND | GND (Ground) |
| 5V | 10kΩ pull-up (other end to Pin 7) |

**⚠️ Important:** The DHT11 requires a 10kΩ pull-up resistor on the data line. This stabilizes the signal from the sensor.

---

## 💻 How It Works

### Initialize Sensor
Setup configures the DHT11 library and sets Pin 7 as the data pin. Serial Monitor starts at 9600 baud.

### Read Temperature and Humidity
The `dht.readTemperature()` and `dht.readHumidity()` functions communicate with DHT11 using a digital protocol.

### Validate Data
Check if sensor readings are valid before displaying. Reject impossible values like negative humidity.

### Process Measurements
Temperature is read in Celsius (0-50°C range). Humidity is read as percentage (0-100%).

### Display Continuously
Results print to Serial Monitor every 2 seconds, allowing real-time monitoring of environmental changes.

---

## 🚀 Getting Started

1. Install DHT11 library in Arduino IDE
   - **Sketch → Include Library → Manage Libraries**
   - Search "DHT11" and install Adafruit DHT library
2. Connect DHT11 to breadboard
3. Wire Pin 7 as data pin with 10kΩ pull-up resistor
4. Connect Arduino to computer
5. Load the Temperature Monitor sketch
6. Open Serial Monitor at 9600 baud
7. Watch real-time temperature and humidity readings

---

## 💾 Source Code (TemperatureMonitor.ino)

```cpp
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Wait 2 seconds between readings
  
  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // Display results
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.println("---");
}
```

---

## 📸 Expected Output

- 🌡️ Serial Monitor shows temperature in Celsius
- 💧 Humidity displayed as percentage (0-100%)
- ✅ Readings update every 2 seconds
- 👋 Breath on sensor to increase humidity
- 🔄 Real-time response to environmental changes

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Display Fahrenheit
float temperatureF = (temperature * 9/5) + 32;
Serial.println(temperatureF);

// Add temperature alerts
if (temperature > 30) {
  Serial.println("WARNING: Very Hot!");
}
if (humidity > 80) {
  Serial.println("WARNING: High Humidity!");
}

// Display heat index
float heatIndex = temperature + (humidity - 40) * 0.1;

// Create custom display format
Serial.print("Temp: ");
Serial.print(temperature, 1);  // 1 decimal place
Serial.print("°C | Humidity: ");
Serial.print(humidity, 0);      // No decimal places
Serial.println("%");
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| No data displayed | Install DHT11 library, check Pin 7 connection |
| Shows error messages | Verify 10kΩ pull-up resistor connection |
| Inaccurate readings | Allow sensor to warm up, avoid direct sunlight |
| Humidity stuck value | Move sensor to varying humidity location |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| DHT11 | Temperature and humidity sensor |
| Pull-Up Resistor | Stabilizes digital signal from sensor |
| Library | Pre-written code for specific components |
| Celsius | Temperature scale (0-100°C water freeze to boil) |
| Humidity | Moisture content in air (0-100%) |

---

## 📚 Next Project

**Day 12 – Motion Detector PIR**

Detect movement and trigger alarms using a PIR motion sensor!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
