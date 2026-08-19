# 💡 Day 20 – Automatic Light Control LDR

Build an intelligent lighting system that automatically turns lights on/off based on ambient light levels.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐⭐ Advanced

---

## ✨ Features

- 💡 Automatic light detection
- 🌙 Turn lights on at night
- ☀️ Turn lights off during day
- 🔌 Relay-controlled lighting
- ⚡ Energy conservation

---

## 🎯 What You'll Learn

- LDR light sensor operation
- Voltage divider circuits
- Threshold-based decisions
- Relay control of lights
- Automatic lighting systems
- Energy-saving automation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LDR (Light Dependent Resistor) | 1 |
| LED or Light Bulb | 1 |
| 10kΩ Resistor | 2 |
| 220Ω Resistor | 1 |
| Relay Module | 1 |
| Jumper Wires | 7 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | LDR (one leg) + Relay VCC |
| A0 | LDR (via voltage divider) |
| GND | 10kΩ resistor (voltage divider) + Relay GND |
| Pin 9 | Relay Signal (IN) |
| Relay NO/COM | Light/LED Terminals |

**⚠️ Important:** LDR + 10kΩ form voltage divider at A0. Light on relay terms (high current).

---

## 💻 How It Works

### Initialize Sensor and Relay
Pin 9 set as OUTPUT for relay control. Pin A0 configured for analog LDR input. Serial starts.

### Read Light Level Continuously
analogRead(A0) reads LDR value continuously. High values = bright. Low values = dark.

### Establish Threshold
Define threshold (usually 400-600). Below = darkness detected. Above = brightness detected.

### Control Light Based on Light
Below threshold: Pin 9 HIGH, relay activates light. Above threshold: Pin 9 LOW, light off.

### Display Status Information
Current light level and light status printed to Serial Monitor. Shows real-time operation.

---

## 🚀 Getting Started

1. Connect LDR and resistor as voltage divider to A0
2. Connect relay module to Pin 9
3. Connect light to relay terminals
4. Connect Arduino to computer
5. Load Automatic Light Control sketch
6. Select **Tools → Board → Arduino UNO**
7. Upload code
8. Test by changing light level

---

## 💾 Source Code (AutomaticLight.ino)

```cpp
int ldrPin = A0;
int relayPin = 9;
int threshold = 500;  // Adjust for your lighting

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Light OFF initially
  Serial.begin(9600);
}

void loop() {
  // Read light level
  int lightValue = analogRead(ldrPin);
  
  // Print current reading
  Serial.print("Light Level: ");
  Serial.println(lightValue);
  
  // Check if it's dark
  if (lightValue < threshold) {
    // It's dark - turn light ON
    digitalWrite(relayPin, HIGH);
    Serial.println("Light: ON");
  } else {
    // It's bright - turn light OFF
    digitalWrite(relayPin, LOW);
    Serial.println("Light: OFF");
  }
  
  delay(500);  // Check every 500ms
}
```

---

## 📸 Expected Output

- ☀️ Bright light: Relay OFF, light off
- 🌙 Cover LDR: Relay clicks, light ON
- 📊 Serial shows light level readings
- 🔄 Real-time response to light changes
- ⚡ Automatic energy-saving operation

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust threshold
int threshold = 300;  // Turns on earlier
int threshold = 700;  // Waits until very dark

// Hysteresis (prevent flickering)
if (lightValue < 400) {
  digitalWrite(relayPin, HIGH);  // Turn on at 400
} else if (lightValue > 600) {
  digitalWrite(relayPin, LOW);   // Turn off at 600
}

// Gradually dim LED
int brightness = map(lightValue, 1023, 0, 0, 255);
analogWrite(relayPin, brightness);

// Display threshold
Serial.print("Threshold: ");
Serial.println(threshold);
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Light doesn't turn on | Check relay Pin 9, verify light on relay |
| Light always on/off | Adjust threshold value, check LDR position |
| LDR readings don't change | Ensure LDR exposed to light, check connections |
| Relay clicks constantly | Add hysteresis to prevent flickering |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| LDR | Light Dependent Resistor (changes resistance) |
| Voltage Divider | Two resistors creating variable voltage |
| Threshold | Reference value separating dark/bright |
| Relay | Switch controlling high-current loads |
| Automation | System responds automatically |

---

## 📚 Congratulations! 🎉

You've completed **Stage 3: Displays and Control!** Mastered:
- LCD and OLED displays
- 7-segment numeric displays
- Servo motor control
- Joystick input control
- Interactive gaming
- Advanced automation systems

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
