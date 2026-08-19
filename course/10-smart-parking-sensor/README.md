# 💡 Day 10 – Smart Parking Sensor

Build an intelligent parking system that uses distance measurement to provide color-coded alerts and warnings.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐ Advanced

---

## ✨ Features

- 🟢 Multi-level distance detection system
- 🚗 Real-world parking assistance simulation
- 💡 Color-coded LED alerts (Green/Yellow/Red)
- 🔊 Audio alarm when too close
- ⚡ Automatic response to changing distances

---

## 🎯 What You'll Learn

- Integrating multiple sensors and outputs
- Creating alert levels based on sensor data
- How real parking systems work
- Conditional logic for multi-stage automation
- Combining visual and audio feedback
- Real-world safety application design

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220Ω Resistor | 3 |
| Passive Buzzer | 1 |
| Jumper Wires | 8 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND, All LED Cathodes, Buzzer (−) |
| Pin 9 | HC-SR04 TRIG |
| Pin 10 | HC-SR04 ECHO |
| Pin 3 | Green LED Anode (through 220Ω) |
| Pin 4 | Yellow LED Anode (through 220Ω) |
| Pin 5 | Red LED Anode (through 220Ω) |
| Pin 8 | Buzzer (+) positive terminal |

**⚠️ Important:** All sensor pins must be correct. Double-check HC-SR04 and LED connections before uploading.

---

## 💻 How It Works

### Configure All Pins
Setup: Pin 9 (OUTPUT), Pin 10 (INPUT), Pins 3/4/5 (OUTPUT LEDs), Pin 8 (OUTPUT buzzer).

### Measure Distance Continuously
HC-SR04 sensor continuously measures distance using ultrasonic sound waves.

### Evaluate Distance Ranges
Compare distance against three thresholds: Safe (>50cm), Warning (30-50cm), Danger (<30cm).

### Control Alert Outputs
Safe: Green ON. Warning: Green OFF, Yellow ON. Danger: Yellow OFF, Red flashing, Buzzer ON.

### Update System Continuously
Loop repeats every 200ms to provide real-time feedback to the driver.

---

## 🚀 Getting Started

1. Assemble all components on breadboard
2. Connect HC-SR04 sensor correctly
3. Connect three LEDs to Pins 3, 4, 5
4. Connect buzzer to Pin 8
5. Connect Arduino to computer
6. Load the Smart Parking sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Test by moving obstacle toward sensor

---

## 💾 Source Code (SmartParkingSensor.ino)

```cpp
int trigPin = 9, echoPin = 10;
int greenLED = 3, yellowLED = 4, redLED = 5;
int buzzer = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;
  
  // Safe range (>50 cm)
  if (distance > 50) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  }
  // Warning range (30-50 cm)
  else if (distance > 30) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  }
  // Danger range (<30 cm)
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);  // Sound alarm
  }
  
  delay(200);
}
```

---

## 📸 Expected Output

- 🟢 Distance > 50cm: Green LED on (Safe)
- 🟡 Distance 30-50cm: Yellow LED on (Warning)
- 🔴 Distance < 30cm: Red LED flashing + Buzzer alarm (Danger)
- 🔄 Real-time updates as obstacle distance changes

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust alert thresholds
if (distance > 100) {  // Very safe
if (distance > 50) {   // Safe
if (distance > 20) {   // Warning
// Danger below 20cm

// Add different alarm tones
if (distance < 20) {
  tone(buzzer, 1500);  // Higher frequency
}
if (distance < 10) {
  tone(buzzer, 2000);  // Even higher for extreme danger
}

// Add LED blinking in danger zone
if (distance < 30) {
  digitalWrite(redLED, HIGH);
  delay(100);
  digitalWrite(redLED, LOW);
  delay(100);
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| LEDs don't change | Verify LED pins and polarity, check distance thresholds |
| Buzzer silent | Check Pin 8 connection and buzzer polarity |
| Unstable readings | Move sensor away from reflective surfaces |
| One LED always on | Check conditional logic and sensor connections |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Multi-Level Alert | Different responses for different conditions |
| Alert System | Visual and audio warnings combined |
| Threshold | Reference value for decision making |
| Real-Time Feedback | Instant response to changing conditions |
| Sensor Integration | Combining multiple components in one system |

---

## 📚 Next Project

**Day 11 – Temperature Monitor DHT11**

Read temperature and humidity with the DHT11 sensor!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
