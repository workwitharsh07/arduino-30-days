# 🌡️ Day 21 – Temperature-Based Fan Control

Build an intelligent cooling system that automatically adjusts fan speed based on environmental temperature.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🌡️ Real-time temperature monitoring
- 💨 Automatic fan speed control
- 📊 PWM-based speed adjustment
- 🔌 Motor driver integration
- ⚡ Smart thermal management

---

## 🎯 What You'll Learn

- Temperature sensor operation
- PWM motor speed control
- Proportional control systems
- Fan speed modulation
- Thermal management
- Smart cooling automation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| DHT11 Temperature Sensor | 1 |
| DC Motor (Fan) | 1 |
| Motor Driver (L298N) | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 8 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | DHT11 VCC + Motor Driver VCC |
| GND | DHT11 GND + Motor Driver GND |
| Pin 7 | DHT11 DATA Pin |
| Pin 9 | Motor Driver ENA (PWM) |
| Pin 8 | Motor Driver IN1 |
| GND | Motor Driver IN2 |
| Motor Terminals | Motor Driver OUT1 & OUT2 |

**⚠️ Important:** Pull-up resistor 10kΩ between Pin 7 & 5V for DHT11. Motor driver protects Arduino from motor current.

---

## 💻 How It Works

### Initialize Sensor and Motor
In setup(), Arduino initializes DHT11 library and sensor pin. Pin 9 set as OUTPUT for PWM motor control. Pin 8 configured for direction.

### Read Temperature Continuously
dht.readTemperature() retrieves current temperature in Celsius. Sensor updates every 2 seconds minimum.

### Map Temperature to Fan Speed
Temperature value mapped to PWM range 0-255. Lower temp = slower fan. Higher temp = faster fan.

### Calculate Proportional Response
Fan speed changes proportionally with temperature. Formula: PWM = (temp - baseTemp) × multiplier.

### Control Motor with PWM
analogWrite() sends calculated PWM to Pin 9. Motor driver adjusts voltage to fan accordingly.

### Display System Status
Temperature reading and current fan speed printed to Serial Monitor. Shows real-time operation.

---

## 🚀 Getting Started

1. Connect DHT11 sensor to Pin 7 with pull-up resistor
2. Connect motor driver to Pin 9, 8, and GND
3. Connect DC motor to driver output terminals
4. Connect Arduino to computer
5. Load Temperature-Based Fan Control sketch
6. Select **Tools → Board → Arduino UNO**
7. Upload code
8. Open Serial Monitor at 9600 baud
9. Watch fan speed change with temperature!

---

## 💾 Source Code (TempFanControl.ino)

```cpp
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int motorPin = 9;
int dirPin1 = 8;
int dirPin2 = GND;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read temperature
  float temp = dht.readTemperature();
  
  if (isnan(temp)) {
    Serial.println("DHT11 Error!");
    return;
  }
  
  // Map temperature to fan speed (20-35°C = 0-255)
  int fanSpeed = map(temp, 20, 35, 0, 255);
  fanSpeed = constrain(fanSpeed, 0, 255);
  
  // Control fan speed
  analogWrite(motorPin, fanSpeed);
  digitalWrite(dirPin1, HIGH);
  
  // Display status
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | Fan Speed: ");
  Serial.println(fanSpeed);
  
  delay(1000);
}
```

---

## 📸 Expected Output

- 🌡️ Serial Monitor shows current temperature
- 💨 Fan speed increases as temperature rises
- 💨 Fan slows down as temperature decreases
- 📊 Real-time temperature and speed display
- 🔄 Smooth proportional response to changes

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust temperature thresholds
int fanSpeed = map(temp, 15, 40, 0, 255);

// Add temperature alert
if (temp > 35) {
  Serial.println("WARNING: High Temperature!");
  tone(buzzerPin, 1000, 200);
}

// Hysteresis for stability
if (temp > 30) {
  motorSpeed = 255;  // Full speed
} else if (temp < 25) {
  motorSpeed = 0;    // Off
}

// Display in Fahrenheit
float tempF = (temp * 9/5) + 32;
Serial.println(tempF);
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Fan won't spin | Verify motor driver Pin 9 connection |
| Temperature shows 0 | Check DHT11 to Pin 7 with pull-up resistor |
| Fan runs at full speed always | Verify temperature reading & mapping values |
| Fan doesn't respond to temperature | Check sensor connections & delay timing |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| DHT11 | Digital Temperature & Humidity Sensor |
| PWM | Pulse Width Modulation for speed control |
| Proportional | Response matches input intensity |
| Motor Driver | Protects Arduino from motor current |
| Thermal Management | System maintains optimal temperature |

---

## 📚 Next Project

➡️ **Day 22 – Relay Control Project** - Control high-voltage appliances safely!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
