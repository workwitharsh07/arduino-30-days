# 🔌 Day 22 – Relay Control Project

Safely control high-voltage appliances using low-voltage Arduino signals through relay switches.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🔌 High-voltage circuit switching
- 🎚️ 4-channel relay module control
- 💡 Safe appliance automation
- 🎮 Push button sequential control
- 📊 Visual feedback with indicator LEDs

---

## 🎯 What You'll Learn

- Relay module operation
- High-voltage circuit switching
- Electromagnetic control principles
- Appliance automation
- Multi-channel relay coordination
- Safety protocols for high power

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 4-Channel Relay Module | 1 |
| Push Button | 1 |
| Indicator LEDs | 4 |
| 10kΩ Resistor | 1 |
| 220Ω Resistor | 4 |
| Jumper Wires | 10 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Relay Module VCC |
| GND | Relay Module GND + Button (other side) |
| Pin 2 | Relay IN1 |
| Pin 3 | Relay IN2 |
| Pin 4 | Relay IN3 |
| Pin 5 | Relay IN4 |
| Pin 6 | Push Button (with 10kΩ pull-up to 5V) |
| Pin 10 | LED 1 (through 220Ω resistor) |
| Pin 11 | LED 2 (through 220Ω resistor) |
| Pin 12 | LED 3 (through 220Ω resistor) |
| Pin 13 | LED 4 (through 220Ω resistor) |

**⚠️ Important:** Never touch high-voltage wiring while powered. Always verify relay terminals (NO & COM) before connecting appliances.

---

## 💻 How It Works

### Initialize All Control Pins
In setup(), Arduino sets Pins 2-5 as OUTPUT for relay control. Pins 10-13 configured as OUTPUT for indicator LEDs. Pin 6 set as INPUT_PULLUP for button.

### Read Button Input
Program continuously checks if button is pressed using digitalRead(Pin 6). When button transitions from HIGH to LOW, relay sequence activates.

### Activate Single Relay
When button pressed, Arduino sends HIGH signal to one relay channel. This activates that relay and closes the switch.

### Provide Visual Feedback
When relay activates, corresponding indicator LED turns on. Shows which appliances are currently powered and controlled.

### Cycle Through Relays
Each button press activates next relay in sequence. After all four relays tested, sequence repeats. Demonstrates independent control capability.

### Continuous Monitoring
Entire process repeats in loop() function. System monitors button and manages relay states for safe appliance control.

---

## 🚀 Getting Started

1. Connect relay module to Pins 2-5
2. Connect indicator LEDs to Pins 10-13 (through resistors)
3. Connect push button to Pin 6 with pull-up resistor
4. Connect Arduino to computer
5. Load Relay Control sketch
6. Select **Tools → Board → Arduino UNO**
7. Upload code
8. Press button to cycle through relays!

---

## 💾 Source Code (RelayControl.ino)

```cpp
int relayPins[] = {2, 3, 4, 5};
int ledPins[] = {10, 11, 12, 13};
int buttonPin = 6;
int currentRelay = 0;
boolean buttonPressed = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(relayPins[i], OUTPUT);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Read button
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    delay(50);  // Debounce
    
    // Turn off current relay
    digitalWrite(relayPins[currentRelay], LOW);
    digitalWrite(ledPins[currentRelay], LOW);
    
    // Move to next relay
    currentRelay = (currentRelay + 1) % 4;
    
    // Activate next relay
    digitalWrite(relayPins[currentRelay], HIGH);
    digitalWrite(ledPins[currentRelay], HIGH);
    
    Serial.print("Relay ");
    Serial.print(currentRelay + 1);
    Serial.println(" Activated");
  }
  
  // Reset button flag
  if (digitalRead(buttonPin) == HIGH) {
    buttonPressed = false;
  }
}
```

---

## 📸 Expected Output

- 🔴 Press button → Relay 1 ON (Red LED on)
- 🟡 Press button → Relay 2 ON (Yellow LED on)
- 🟢 Press button → Relay 3 ON (Green LED on)
- 🔵 Press button → Relay 4 ON (Blue LED on)
- 🔄 Button press cycles through all relays

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Individual relay control
if (buttonPin1Pressed) {
  digitalWrite(relayPins[0], HIGH);
}

// Timer-based switching
unsigned long switchTime = millis();
if (millis() - switchTime > 5000) {
  digitalWrite(relayPin, LOW);
}

// Multiple simultaneous relays
digitalWrite(relayPins[0], HIGH);
digitalWrite(relayPins[1], HIGH);
delay(2000);

// Manual ON/OFF buttons
if (onButton) digitalWrite(relayPin, HIGH);
if (offButton) digitalWrite(relayPin, LOW);
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Relay doesn't activate | Verify signal pin connection & 5V power |
| Appliance doesn't power | Check connections at relay NO & COM terminals |
| LEDs don't light | Verify LED connections & resistor values |
| Button doesn't work | Check Pin 6 connection & pull-up resistor |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Relay | Electromagnetic switch for high current |
| NO Terminal | Normally Open - closed when activated |
| COM Terminal | Common terminal for power distribution |
| High Voltage | Dangerous electrical power - use relay protection |
| Channel | Individual relay control circuit |

---

## 📚 Next Project

➡️ **Day 23 – Servo-Based Door Lock** - Build an electronic door lock!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
