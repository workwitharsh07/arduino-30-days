# 💡 Day 01 – Blink LED

Build your first Arduino project by blinking an LED every second. This beginner-friendly project introduces digital outputs, basic circuit wiring, and the structure of an Arduino program.

> 📷 **Demo**  
> *(Add a GIF or image here)*

---

## ✨ Features

- Beginner-friendly Arduino project
- Learn digital output control
- Simple breadboard circuit
- Safe LED connection using a 220Ω resistor
- Perfect starting point for embedded systems

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

> **Note:** LEDs are polarized. If connected backwards, they will not light up.

📷 **Circuit Diagram**

*(Add `images/circuit.png` here)*

---

## 🚀 Getting Started

1. Assemble the circuit as shown above.
2. Connect the Arduino to your computer.
3. Open the sketch in the Arduino IDE.
4. Select **Arduino UNO** from **Tools → Board**.
5. Select the correct **COM Port**.
6. Upload the code.
7. Watch the LED blink every second.

---

## 💻 Source Code

Open **`Blink.ino`** included in this project.

```cpp
// LED connected to Pin 13
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);

  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

---

## 📸 Output

After uploading the code:

- 💡 LED ON for 1 second
- 🌑 LED OFF for 1 second
- 🔄 Repeats continuously

> 📷 **Output Image / GIF**

*(Add `images/output.jpg` or `images/demo.gif` here)*

---

## ⚙️ Customization

Experiment with the project by changing:

- Blink speed (`delay()`)
- LED pin number
- ON/OFF timing
- Multiple LEDs

---

## ⚡ Troubleshooting

| Problem | Solution |
|---------|----------|
| LED doesn't turn ON | Check LED polarity and wiring |
| Upload failed | Verify board and COM port |
| LED stays ON | Ensure the correct sketch is uploaded |

---

## 📁 Project Structure

```text
Day-01-Blink-LED/
│
├── Blink.ino
├── README.md
└── images/
    ├── circuit.png
    ├── output.jpg
    └── demo.gif
```

---

## 📚 Next Project

➡ **Day 02 – Push Button LED**

Learn how to read a push button input and control an LED in real time.

---

⭐ If this project helped you, consider giving this repository a **Star**.

Made with ❤️ by **LifeTronix**
