# 💡 Day 01 – Blink LED

> Build your first Arduino project by making an LED blink every second. Learn the basics of Arduino programming, digital outputs, and breadboard wiring.

---

## 📖 Overview

The Blinking LED project is the perfect starting point for learning Arduino and embedded systems. In this project, an LED connected to **Pin 13** turns **ON** and **OFF** every second.

Although simple, this project introduces the fundamental concepts you'll use in almost every Arduino project, including digital outputs, program structure, and safe circuit building.

---

## 🎯 What You'll Learn

After completing this project, you will understand:

- How digital output pins work
- The structure of an Arduino program (`setup()` and `loop()`)
- Basic breadboard wiring
- LED polarity (Anode & Cathode)
- Why a resistor is required with an LED
- How `digitalWrite()` and `delay()` work

---

## ✨ Features

- ✅ Beginner-friendly project
- ✅ Uses Arduino UNO
- ✅ Simple LED blinking effect
- ✅ Easy breadboard circuit
- ✅ Foundation for future Arduino projects

---

## 🛠️ Components Required

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

### Step 1 – Connect Ground
Connect one **GND** pin from the Arduino to the **negative (-) rail** of the breadboard.

### Step 2 – Connect the LED
- Connect the **long leg (Anode)** of the LED to **Digital Pin 13** through a **220Ω resistor**.
- Connect the **short leg (Cathode)** directly to the **GND rail**.

### Step 3 – Verify the Circuit
Before uploading the code, check:
- LED polarity
- Resistor placement
- Jumper wire connections

> **Note:** LEDs are polarized components. If connected backwards, they will not light up.

**Circuit Diagram**

![Circuit Diagram](images/circuit.png)

---

## 📚 Source Code

Open the `Blink.ino` file included in this project.

---

## 🚀 Getting Started

1. Connect the circuit as shown above.
2. Connect the Arduino UNO to your computer.
3. Open the project in the Arduino IDE.
4. Select **Arduino UNO** from **Tools → Board**.
5. Select the correct **COM Port**.
6. Upload the code.
7. Watch the LED blink every second.

---

## 🧠 How It Works

When the Arduino powers on, the `setup()` function runs once and configures **Pin 13** as an output.

The `loop()` function then runs continuously:

1. Turn the LED ON.
2. Wait for one second.
3. Turn the LED OFF.
4. Wait for one second.
5. Repeat forever.

This repeating process creates the blinking effect.

---

## 📸 Expected Output

After uploading the code:

- 💡 LED turns ON for 1 second.
- 🌑 LED turns OFF for 1 second.
- 🔄 The cycle repeats continuously.

![Output](images/output.jpg)

---

## ⚡ Troubleshooting

### LED doesn't turn ON
- Check the LED polarity.
- Verify the resistor placement.
- Check all jumper wire connections.

### Upload Failed
- Select the correct Arduino board.
- Select the correct COM Port.
- Use a USB cable that supports data transfer.

### LED stays ON continuously
- Make sure the correct code is uploaded.
- Verify that both `digitalWrite()` and `delay()` functions are present.

---

## 🎓 Challenge Yourself

Try these small improvements:

- Change the blink speed to **500 ms**.
- Change the blink speed to **200 ms**.
- Blink the LED three times before pausing.
- Use another digital pin.

---

## 📖 Next Project

➡ **Day 02 – Push Button LED**

In the next project, you'll learn how to use a push button as a digital input to control an LED in real time.

---

## ⭐ Support

If this project helped you, consider giving this repository a ⭐.

Your support helps us create more free Arduino, ESP32, IoT, and Robotics tutorials.

---

Made with ❤️ by **LifeTronix**
