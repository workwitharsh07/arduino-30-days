# 🌈 Day 05 – RGB LED Colors Mixing

Control Red, Green, and Blue LEDs independently to mix and create thousands of different colors!

---

## ✨ Features

- 🚀 Learn RGB color mixing
- 🌈 Create custom colors
- 💡 PWM brightness control per channel
- 🎨 Mix colors like a display
- 🔄 Automatic color sequences

---

## 🎯 What You'll Learn

- RGB LED structure
- Individual color channel control
- Color mixing theory
- Multiple PWM outputs
- Digital color generation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| RGB LED (Common Cathode) | 1 |
| 220Ω Resistor | 3 |
| Jumper Wires | 4 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

- Arduino **GND** → Breadboard **Ground Rail**
- Arduino **Pin 9** → Red Leg (through 220Ω resistor)
- Arduino **Pin 10** → Green Leg (through 220Ω resistor)
- Arduino **Pin 11** → Blue Leg (through 220Ω resistor)
- RGB LED **Common Cathode** → Breadboard **Ground Rail**

> ⚠️ **Important:** Connect longest RGB leg (Common Cathode) to GND. Use only PWM pins!

---

## 🚀 Getting Started

1. Place RGB LED on breadboard (all 4 legs in different rows)
2. Connect resistors to R, G, B pins
3. Connect to Arduino Pins 9, 10, 11
4. Connect common pin to GND
5. Open **RGBLED.ino** in Arduino IDE
6. Select **Tools → Board → Arduino UNO**
7. Select the correct **COM Port**
8. Click **Upload**

---

## 💻 How It Works

```cpp
// Red channel
analogWrite(9, 255);

// Green channel
analogWrite(10, 0);

// Blue channel
analogWrite(11, 0);
```

**Color Mixing Examples:**
- Red (255, 0, 0) + Green (0, 255, 0) = Yellow
- Red (255, 0, 0) + Blue (0, 0, 255) = Purple
- Green (0, 255, 0) + Blue (0, 0, 255) = Cyan
- All (255, 255, 255) = White

---

## 📸 Expected Result

- 🔴 Red color displays
- 🟢 Green color displays
- 🔵 Blue color displays
- 💛 Yellow (Red + Green)
- 💜 Purple (Red + Blue)
- 🩵 Cyan (Green + Blue)
- ⚪ White (All colors)
- 🔄 Sequence repeats continuously

---

## ⚙️ Try It Yourself

- Create random color sequences
- Fade between different colors smoothly
- Create color gradients
- Mix custom colors
- Sync colors with music (advanced)

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| RGB LED won't light | Check common pin to GND |
| Wrong colors appear | Verify R, G, B pin assignments |
| Only one color works | Check all resistor connections |
| Dim colors | Use PWM pins (3, 5, 6, 9, 10, 11) |

---

## 📚 Next Project

➡️ **Day 06 – Traffic Light System** - Control multiple LEDs in sequence like a real traffic signal!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
