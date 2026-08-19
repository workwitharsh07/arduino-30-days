# 🔘 Day 03 – State Memory LED

Press a button once to turn the LED ON. Press it again to turn the LED OFF. Learn how Arduino remembers state!

---

## ✨ Features

- 🚀 Learn state management
- 🔘 Toggle LED with one button
- 💾 Arduino remembers LED state
- 🎮 Interactive ON/OFF switching
- 📊 Real-world switch behavior

---

## 🎯 What You'll Learn

- State memory and variables
- Toggle logic (ON ↔ OFF)
- Button debouncing basics
- Digital input reading
- Interactive programming

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 5mm LED | 1 |
| Tactile Push Button | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | 4 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

- Arduino **GND** → Breadboard **Ground Rail**
- Arduino **Pin 13** → LED **Anode** (through 220Ω resistor)
- Breadboard **Ground Rail** → LED **Cathode**
- Arduino **Pin 2** → Push Button **One Side**
- Breadboard **Ground Rail** → Push Button **Other Side**

> ⚠️ **Important:** Place button across the middle gap. Long LED leg = Anode (+), Short leg = Cathode (-)

---

## 🚀 Getting Started

1. Build the circuit with LED and push button
2. Connect Arduino to your computer via USB
3. Open **ToggleLED.ino** in Arduino IDE
4. Select **Tools → Board → Arduino UNO**
5. Select the correct **COM Port**
6. Click **Upload**
7. Press the button to toggle the LED!

---

## 💻 How It Works

```cpp
bool ledState = false;  // Remember LED state

if (buttonPressed) {
  ledState = !ledState;  // Flip the state
  digitalWrite(13, ledState);
}
```

**First Press:** LED OFF → ON  
**Second Press:** LED ON → OFF  
**Repeats:** Each press toggles the state

---

## 📸 Expected Result

- 🔘 Press button once → 💡 LED **ON** (stays ON)
- 🔘 Press button again → 🌑 LED **OFF** (stays OFF)
- 🔄 Each press toggles the state

---

## ⚙️ Try It Yourself

- Add a second LED to toggle on Pin 12
- Create a counter that displays button presses
- Add a delay to prevent double-triggering
- Toggle multiple LEDs with one button

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| LED toggles multiple times per press | Add delay to debounce |
| Button doesn't toggle LED | Check Pin 2 & GND connections |
| LED never changes state | Verify toggle logic in code |
| Upload fails | Check board & COM port |

---

## 📚 Next Project

➡️ **Day 04 – PWM LED Brightness** - Control LED brightness smoothly with fading effects!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
