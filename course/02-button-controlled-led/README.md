# 🔘 Day 02 – Push Button LED

Control an LED with a push button. When you press the button, the LED turns ON. Release it, and the LED turns OFF.

---

## ✨ Features

- 🚀 Learn digital input control
- 🔘 Use a tactile push button switch
- 💡 Real-time button control of LED
- 📊 Serial Monitor feedback
- 🎮 Interactive user input

---

## 🎯 What You'll Learn

- Digital input reading with GPIO pins
- Push button interfacing
- `digitalRead()` function usage
- `INPUT_PULLUP` mode
- Connecting outputs to user input
- Serial Monitor debugging

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

> ⚠️ **Important:** Place push button across the middle gap on breadboard. Long LED leg = Anode (+), Short leg = Cathode (-)

---

## 🚀 Getting Started

1. Assemble the circuit with LED and push button
2. Connect Arduino to your computer via USB
3. Open **ButtonLED.ino** in Arduino IDE
4. Select **Tools → Board → Arduino UNO**
5. Select the correct **COM Port**
6. Click **Upload**
7. Open **Tools → Serial Monitor** (9600 baud)
8. Press the button and watch the LED respond!

---

## 💻 How It Works

```cpp
pinMode(13, OUTPUT);      // LED output
pinMode(2, INPUT_PULLUP); // Button input with pull-up

buttonState = digitalRead(2);  // Read button state

if (buttonState == LOW) {      // Button pressed
  digitalWrite(13, HIGH);      // LED ON
  Serial.println("1");
} else {                       // Button released
  digitalWrite(13, LOW);       // LED OFF
  Serial.println("0");
}
```

**Button Pressed:** Voltage drops to LOW (0V) → LED turns ON  
**Button Released:** Voltage rises to HIGH (+5V) → LED turns OFF

---

## 📸 Expected Result

- 🔘 Press button → 💡 LED **ON** instantly
- 🔘 Release button → 🌑 LED **OFF** instantly
- 📊 Serial Monitor shows **1** when pressed, **0** when released

---

## ⚙️ Try It Yourself

- Add a second LED on Pin 12
- Control LED brightness with button press duration
- Create a counter that increments on each button press
- Add buzzer sound when button is pressed
- Use multiple buttons to control different LEDs

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| LED won't respond to button | Check button placement across breadboard gap |
| Button doesn't work | Verify connections to Pin 2 and Ground |
| Serial Monitor shows nothing | Check baud rate is 9600 & Serial.begin() in code |
| LED stays on always | Verify INPUT_PULLUP is used in setup() |

---

## 📚 Next Project

➡️ **Day 03 – Toggle LED** - Make one button press toggle LED ON/OFF!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
