# 💡 Day 01 – Blink LED

Build your first Arduino project by making an LED blink every second.

---

## ✨ Features

- 🚀 Beginner-friendly project
- 💡 Learn digital output control
- 🔌 Simple breadboard wiring
- ⚡ Safe LED connection using 220Ω resistor

---

## 🎯 What You'll Learn

- Arduino `setup()` and `loop()` functions
- Digital output with GPIO pins
- Using `digitalWrite()` to control LED
- LED polarity (Anode & Cathode)
- Breadboard basics

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 5mm LED | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | 2 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

- Arduino **GND** → Breadboard **Ground Rail**
- Arduino **Pin 13** → LED **Anode** (through 220Ω resistor)
- Breadboard **Ground Rail** → LED **Cathode**

> ⚠️ **Important:** Long LED leg = Anode (+), Short leg = Cathode (-)

---

## 🚀 Getting Started

1. Assemble the circuit as shown above
2. Connect Arduino to your computer via USB
3. Open **Blink.ino** in Arduino IDE
4. Select **Tools → Board → Arduino UNO**
5. Select the correct **COM Port**
6. Click **Upload**
7. Watch your LED blink!

---

## 💻 How It Works

```cpp
pinMode(13, OUTPUT);        // Set Pin 13 as output
digitalWrite(13, HIGH);     // LED ON (+5V)
delay(1000);               // Wait 1 second
digitalWrite(13, LOW);      // LED OFF (0V)
delay(1000);               // Wait 1 second
```

The LED blinks **ON** for 1 second, then **OFF** for 1 second, repeatedly.

---

## 📸 Expected Result

- 💡 LED turns **ON** for 1 second
- 🌑 LED turns **OFF** for 1 second
- 🔄 Repeats continuously

---

## ⚙️ Try It Yourself

- Change delay time to make LED blink faster/slower
- Use different digital pins (Pin 12, 11, etc.)
- Connect multiple LEDs on different pins
- Create custom blinking patterns

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| LED won't turn on | Check LED polarity & wire connections |
| Upload fails | Verify board & COM port selection |
| LED stays on | Recheck your code |

---

## 📚 Next Project

➡️ **Day 02 – Push Button LED** - Control your LED with a button!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
