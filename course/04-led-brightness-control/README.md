# 💡 Day 04 – PWM LED Brightness

Control LED brightness smoothly from OFF to full brightness and back. Create a realistic fading effect!

---

## ✨ Features

- 🚀 Learn Pulse Width Modulation (PWM)
- 💡 Smooth LED brightness control
- 🌅 Create fading & breathing effects
- ⚡ Analog output simulation
- 🔄 Continuous lighting patterns

---

## 🎯 What You'll Learn

- Pulse Width Modulation (PWM) basics
- `analogWrite()` function
- 8-bit PWM values (0-255)
- Loop-based value scaling
- Duty cycle control

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 5mm LED (Any Color) | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | 2 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

- Arduino **GND** → Breadboard **Ground Rail**
- Arduino **Pin 9** → LED **Anode** (through 220Ω resistor)
- Breadboard **Ground Rail** → LED **Cathode**

> ⚠️ **Important:** Use Pin 9 (PWM pin marked with ~). Long LED leg = Anode (+), Short leg = Cathode (-)

---

## 🚀 Getting Started

1. Build the LED circuit on breadboard
2. Connect Arduino to your computer via USB
3. Open **PWMLed.ino** in Arduino IDE
4. Select **Tools → Board → Arduino UNO**
5. Select the correct **COM Port**
6. Click **Upload**
7. Watch your LED fade smoothly in and out!

---

## 💻 How It Works

```cpp
// Fade in (0 to 255)
for (int brightness = 0; brightness <= 255; brightness++) {
  analogWrite(9, brightness);
  delay(10);
}

// Fade out (255 to 0)
for (int brightness = 255; brightness >= 0; brightness--) {
  analogWrite(9, brightness);
  delay(10);
}
```

**PWM Values:**
- 0 = 0% power (OFF)
- 128 = 50% power (half brightness)
- 255 = 100% power (full brightness)

---

## 📸 Expected Result

- 💡 LED fades smoothly from OFF to full brightness
- 🌑 LED fades smoothly back to OFF
- 🔄 Creates a breathing/pulsing effect
- 🔄 Sequence repeats continuously

---

## ⚙️ Try It Yourself

- Change delay() values for faster/slower fading
- Create different brightness patterns
- Use multiple LEDs on different PWM pins
- Control brightness with a potentiometer (advanced)

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| LED stays ON/OFF (no fading) | Use PWM pins: 3, 5, 6, 9, 10, 11 |
| LED won't light | Check LED polarity & connections |
| Fading too fast/slow | Adjust delay() value |
| Upload fails | Verify board & COM port |

---

## 📚 Next Project

➡️ **Day 05 – RGB LED Colors** - Mix Red, Green, Blue to create thousands of colors!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
