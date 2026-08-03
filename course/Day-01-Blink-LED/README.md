# 💡 Day 01 – Blink LED

Build your first Arduino project by making an LED blink every second. This beginner-friendly project introduces digital outputs, basic circuit wiring, and the structure of an Arduino program.

---

## ✨ Features

- 🚀 Beginner-friendly project
- 💡 Learn digital output control
- 🔌 Simple breadboard wiring
- ⚡ Safe LED connection using a 220Ω resistor
- 📚 Foundation for future Arduino projects

---

## 🎯 What You'll Learn

- Arduino program structure (`setup()` & `loop()`)
- Digital output using GPIO pins
- LED polarity (Anode & Cathode)
- Breadboard wiring basics
- Using `digitalWrite()` and `delay()`

---

## 🛠️ Hardware Required

| Component | Quantity |
|-----------|:--------:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 5mm LED | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | 2 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino UNO | Component |
|-------------|-----------|
| GND | Breadboard (-) Rail |
| Pin 13 | LED Anode (through 220Ω resistor) |
| GND | LED Cathode |

> **Note:** LEDs are polarized components. If connected in reverse, they will not light up.

### Circuit Diagram

<p align="center">
  <img src="circuit.png" width="600">
</p>

---

## 🚀 Getting Started

1. Assemble the circuit as shown above.
2. Connect the Arduino UNO to your computer.
3. Open **Blink.ino** in the Arduino IDE.
4. Select **Tools → Board → Arduino UNO**.
5. Select the correct **COM Port**.
6. Click **Upload**.
7. Watch the LED blink every second.

---

## 💻 Source Code

The complete Arduino sketch is available in **Blink.ino**.

---

## 📸 Expected Result

After uploading the code:

- 💡 LED turns **ON** for **1 second**
- 🌑 LED turns **OFF** for **1 second**
- 🔄 The blinking sequence repeats continuously

---

## ⚙️ Try It Yourself

Experiment with the project by:

- Changing the blink speed
- Using another digital pin
- Connecting multiple LEDs
- Creating your own blinking pattern

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| LED doesn't turn ON | Check LED polarity and wiring |
| Upload failed | Verify the board, COM port, and USB cable |
| LED stays ON | Ensure the correct sketch is uploaded |

---

## 📚 Next Project

➡ **Day 02 – Push Button LED**

Learn how to use a push button as a digital input and control an LED in real time.

---

## ⭐ Support

If you found this project helpful, consider giving this repository a **⭐ Star**.

It helps more people discover the project and supports the **LifeTronix** community.

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
