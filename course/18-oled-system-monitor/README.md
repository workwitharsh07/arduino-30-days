# 💡 Day 18 – OLED System Monitor

Display real-time sensor data and information on a professional OLED screen.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 📺 Crystal-clear OLED display
- 🌡️ Real-time sensor monitoring
- 📊 Multiple data point display
- 🎨 Graphics and text rendering
- 💡 Professional information systems

---

## 🎯 What You'll Learn

- OLED display operation
- I2C communication protocol
- Real-time data visualization
- Graphics rendering basics
- Multi-sensor integration
- Professional display design

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| OLED 128×64 Display (I2C) | 1 |
| DHT11 Sensor | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 6 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | OLED VCC + DHT11 VCC |
| GND | OLED GND + DHT11 GND |
| A4 | OLED SDA |
| A5 | OLED SCL |
| Pin 7 | DHT11 DATA |
| 5V | 10kΩ pull-up (to Pin 7) |

**⚠️ Important:** OLED uses I2C (A4/A5). DHT11 needs pull-up resistor on data pin.

---

## 💻 How It Works

### Initialize Displays and Sensors
Setup initializes OLED library with I2C address. DHT11 sensor library starts reading data.

### Configure Display Settings
OLED size set to 128×64 pixels. Text size and font configured for readability.

### Read Sensor Values
Temperature and humidity read from DHT11. Values stored in variables for display.

### Format Display Information
Text, numbers, rectangles drawn on OLED. Information positioned at specific coordinates.

### Update Display Continuously
clearDisplay() clears screen. New information drawn. display() updates OLED. Repeats every few seconds.

---

## 🚀 Getting Started

1. Connect OLED SDA to A4, SCL to A5
2. Connect OLED VCC to 5V, GND to GND
3. Connect DHT11 to Pin 7 with pull-up resistor
4. Connect Arduino to computer
5. Install Adafruit SSD1306 and DHT libraries
6. Load OLED System Monitor sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code

---

## 💾 Source Code (OLEDMonitor.ino)

```cpp
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("System Monitor");
  display.display();
  
  // Initialize DHT11
  dht.begin();
  delay(2000);
}

void loop() {
  // Read sensor data
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Clear display
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  
  // Display title
  display.setCursor(0, 0);
  display.println("Monitor");
  
  // Display temperature
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  
  // Display humidity
  display.setCursor(0, 30);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  
  // Update display
  display.display();
  
  delay(2000);  // Update every 2 seconds
}
```

---

## 📸 Expected Output

- 💡 OLED backlight illuminates
- 📺 Welcome message displays
- 🌡️ Temperature shows in Celsius
- 💧 Humidity displays as percentage
- 🔄 Updates every 2 seconds

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Add more sensors
int sensorValue = analogRead(A0);
display.print("Sensor: ");
display.println(sensorValue);

// Draw shapes
display.drawRect(0, 0, 128, 64, SSD1306_WHITE);  // Rectangle

// Larger text
display.setTextSize(3);

// Display multiple lines
display.setCursor(0, 40);
display.println("Status: OK");

// Scroll text
display.setCursor(0, 50);
display.println("System Running");
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Display shows nothing | Check I2C address (typically 0x3C), verify SDA/SCL |
| Garbled text | Verify 128×64 size in code, reinstall library |
| Sensor not reading | Check DHT11 on Pin 7, verify pull-up resistor |
| Display too bright | Adjust contrast with setContrast() function |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| OLED | Organic LED display technology |
| I2C | Two-wire serial communication |
| Display Buffer | Memory holding what's shown |
| Pixel | Individual dot on display |
| Real-Time | Instant data updates |

---

## 📚 Next Project

**Day 19 – Automatic Plant Watering System**

Create smart automation using soil moisture sensing!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
