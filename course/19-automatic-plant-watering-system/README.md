# 💡 Day 19 – Automatic Plant Watering System

Build a smart watering system that automatically waters plants based on soil moisture.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐ Advanced

---

## ✨ Features

- 💧 Automatic watering control
- 📊 Soil moisture monitoring
- 🔌 Relay-based pump control
- ⚡ Threshold-based automation
- 🌱 Smart resource management

---

## 🎯 What You'll Learn

- Soil moisture sensor operation
- Relay module control
- Pump automation
- Threshold decision making
- Smart automation design
- Practical automation systems

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Soil Moisture Sensor | 1 |
| Water Pump Module | 1 |
| Relay Module | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 6 |
| USB Type-B Cable | 1 |
| Water Container | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Sensor VCC + Relay VCC |
| GND | Sensor GND + Relay GND |
| A0 | Soil Moisture Analog Output |
| Pin 9 | Relay Signal (IN) |
| Relay NO/COM | Water Pump Terminals |

**⚠️ Important:** Pump connects to relay terminals (high current). Relay switches pump ON/OFF safely.

---

## 💻 How It Works

### Initialize System
Pin 9 set as OUTPUT for relay. Pin A0 configured for analog sensor input. Serial Monitor starts.

### Read Moisture Level
analogRead(A0) reads soil moisture continuously. Value ranges 0-1023 (wet to dry).

### Compare Against Threshold
Moisture reading compared to predefined threshold (usually 400-600). Below = dry, above = wet.

### Control Relay and Pump
Below threshold: Pin 9 goes HIGH, relay activates, pump turns ON. Above threshold: Pin 9 LOW, pump OFF.

### Display Status
Current moisture level and pump status printed to Serial Monitor. Shows real-time system operation.

---

## 🚀 Getting Started

1. Connect soil moisture sensor to A0
2. Connect relay module to Pin 9
3. Connect water pump to relay terminals
4. Fill water container
5. Position pump tube in soil
6. Connect Arduino to computer
7. Load Plant Watering sketch
8. Select **Tools → Board → Arduino UNO**
9. Upload code

---

## 💾 Source Code (PlantWatering.ino)

```cpp
int sensorPin = A0;
int relayPin = 9;
int threshold = 500;  // Adjust based on soil type

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Pump OFF initially
  Serial.begin(9600);
}

void loop() {
  // Read soil moisture
  int moistureValue = analogRead(sensorPin);
  
  // Print current reading
  Serial.print("Moisture: ");
  Serial.println(moistureValue);
  
  // Check if soil is dry
  if (moistureValue < threshold) {
    // Soil is dry - turn pump ON
    digitalWrite(relayPin, HIGH);
    Serial.println("Pump: ON (Watering)");
  } else {
    // Soil is wet - turn pump OFF
    digitalWrite(relayPin, LOW);
    Serial.println("Pump: OFF (Soil Moist)");
  }
  
  delay(1000);  // Check every second
}
```

---

## 📸 Expected Output

- 📊 Serial Monitor shows moisture readings
- 💧 When dry: Pump activates (relay clicks)
- 💦 Water flows into soil
- 📈 Moisture reading increases
- 🛑 When wet enough: Pump stops automatically

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust sensitivity
int threshold = 300;  // More sensitive (waters less often)
int threshold = 700;  // Less sensitive (waters more often)

// Add watering duration
if (moistureValue < threshold) {
  digitalWrite(relayPin, HIGH);
  delay(5000);  // Pump for 5 seconds
  digitalWrite(relayPin, LOW);
}

// Display threshold
Serial.print("Threshold: ");
Serial.println(threshold);

// Log to SD card
// Save moisture readings for analysis
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Pump won't start | Check relay connections, verify 5V power |
| Pump runs continuously | Raise threshold value, check sensor position |
| Sensor readings don't change | Ensure sensor is in soil, check connections |
| Relay clicks but pump silent | Check pump power at relay terminals |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Soil Moisture | Water content in soil (0-1023 readings) |
| Relay | Switch that controls high-current devices |
| Threshold | Reference value for decision making |
| Automation | System operates without user interaction |
| Smart Control | Responds to sensor data automatically |

---

## 📚 Next Project

**Day 20 – Automatic Light Control LDR**

Create an automatic lighting system with light-level detection!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
