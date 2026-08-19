# 💡 Day 07 – Automatic Street Light Using LDR

Learn how to build an automatic lighting system that turns on when it gets dark and off when it's bright using an LDR sensor.

**⏱️ Time:** 20-25 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 🌙 Automatic light detection using LDR sensor
- 💡 Learn analog input reading with Arduino
- 🔌 Build a voltage divider circuit
- ⚡ Conditional logic for automation
- 🏮 Real-world street light simulation

---

## 🎯 What You'll Learn

- How LDR (Light Dependent Resistor) sensors work
- Reading analog values using `analogRead()`
- Voltage divider circuits and how they work
- Using `if-else` conditional statements
- Automatic system control based on sensor data
- Practical automation applications

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LDR (Light Dependent Resistor) | 1 |
| LED (any color) | 1 |
| 10kΩ Resistor | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | 6 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | LDR (one leg) |
| A0 | LDR & 10kΩ resistor junction (voltage divider) |
| GND | 10kΩ resistor (other leg) |
| Pin 7 | LED Anode (through 220Ω resistor) |
| GND | LED Cathode |

**⚠️ Important:** The LDR and 10kΩ resistor form a voltage divider. This lets Arduino measure light levels through the A0 analog input pin.

---

## 💻 How It Works

### Voltage Divider Circuit
LDR and resistor work together to create changing voltage at A0 based on light intensity.

### Read Light Intensity
`analogRead(A0)` reads values from 0 to 1023, where lower values = more light, higher values = darkness.

### Set Threshold
Define a threshold value (usually 400-600) to determine when it's "dark enough" to turn on the LED.

### Conditional Control
If analog value > threshold → LED OFF. If analog value < threshold → LED ON.

### Continuous Monitoring
The loop repeats constantly, so the system responds instantly to light changes.

---

## 🚀 Getting Started

1. Connect the LDR and 10kΩ resistor as a voltage divider
2. Connect LED to Pin 7 with current-limiting resistor
3. Connect Arduino to your computer
4. Open Arduino IDE
5. Load the LDR sketch
6. Select **Tools → Board → Arduino UNO**
7. Select the correct **COM Port**
8. Click **Upload**
9. Cover the LDR and watch the LED turn ON

---

## 💾 Source Code (AutomaticLight.ino)

```cpp
int ldrPin = A0;      // LDR connected to A0
int ledPin = 7;       // LED connected to Pin 7
int threshold = 500;  // Threshold value (adjust as needed)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read light intensity
  Serial.println(ldrValue);            // Print value for debugging
  
  if (ldrValue > threshold) {
    // It's dark
    digitalWrite(ledPin, HIGH);  // Turn LED ON
  } else {
    // It's bright
    digitalWrite(ledPin, LOW);   // Turn LED OFF
  }
  
  delay(500);  // Check every 500ms
}
```

---

## 📸 Expected Output

- 🌞 In bright light: LED stays **OFF**
- 🌙 In darkness: LED turns **ON**
- 📊 Serial Monitor shows analog values (0-1023)
- 🔄 System responds automatically to light changes

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust sensitivity
int threshold = 300;  // More sensitive (turns on earlier)
int threshold = 700;  // Less sensitive (waits for darker)

// Add Serial Monitor feedback
if (ldrValue > threshold) {
  Serial.println("Too Dark - LED ON");
} else {
  Serial.println("Bright - LED OFF");
}

// Create brightness zones
if (ldrValue > 600) {
  digitalWrite(ledPin, HIGH);  // Very dark
} else if (ldrValue > 400) {
  // Medium darkness - could fade LED
} else {
  digitalWrite(ledPin, LOW);   // Bright
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| LED doesn't respond to light | Adjust threshold value in code, check LDR connections |
| Sensor values don't change | Verify voltage divider is connected correctly |
| LED always ON or always OFF | Calibrate threshold based on Serial Monitor readings |
| Unstable readings | Add delays and use averaging in code |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Analog Input | Pin reads voltage values (0-1023 = 0-5V) |
| LDR | Resistor that changes value based on light |
| Voltage Divider | Two resistors that create variable voltage |
| Threshold | Reference value used for comparison |
| Conditional Logic | If-else statements that make decisions |

---

## 📚 Next Project

**Day 08 – Nokia Tune Passive Buzzer**

Generate different sound frequencies and play melodies using Arduino!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
