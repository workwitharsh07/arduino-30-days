# 🚦 Day 06 – Traffic Light System

Build a realistic traffic light system! Red means STOP, Yellow means WAIT, Green means GO. Learn sequential automation!

---

## ✨ Features

- 🚀 Learn sequential programming
- 🚦 Real-world traffic light logic
- 🔄 Automated timing control
- 💡 Multiple LED sequencing
- ⏱️ Realistic traffic timing

---

## 🎯 What You'll Learn

- Multiple output control
- Sequential programming
- Timing and delays
- Automation systems
- Real-world logic patterns

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| 220Ω Resistor | 3 |
| Jumper Wires | 6 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

- Arduino **GND** → Breadboard **Ground Rail**
- Arduino **Pin 8** → Red LED **Anode** (through 220Ω resistor)
- Arduino **Pin 9** → Yellow LED **Anode** (through 220Ω resistor)
- Arduino **Pin 10** → Green LED **Anode** (through 220Ω resistor)
- All LED **Cathodes** → Breadboard **Ground Rail**

> ⚠️ **Important:** Each LED needs its own 220Ω resistor. Long leg = Anode (+), Short leg = Cathode (-)

---

## 🚀 Getting Started

1. Build three LED circuits on breadboard
2. Connect Red LED to Pin 8
3. Connect Yellow LED to Pin 9
4. Connect Green LED to Pin 10
5. Open **TrafficLight.ino** in Arduino IDE
6. Select **Tools → Board → Arduino UNO**
7. Select the correct **COM Port**
8. Click **Upload**

---

## 💻 How It Works

```cpp
// STOP - Red ON
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
delay(5000);  // 5 seconds

// READY - Red + Yellow ON
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delay(2000);  // 2 seconds

// GO - Green ON
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
delay(5000);  // 5 seconds

// CAUTION - Yellow ON
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delay(2000);  // 2 seconds
```

---

## 📸 Expected Result

- 🔴 Red ON for 5 seconds (STOP)
- 🔴🟡 Red + Yellow ON for 2 seconds (READY)
- 🟢 Green ON for 5 seconds (GO)
- 🟡 Yellow ON for 2 seconds (CAUTION)
- 🔄 Sequence repeats like a real traffic signal

---

## ⚙️ Try It Yourself

- Adjust timing values for different patterns
- Add a buzzer that beeps during transitions
- Create custom traffic sequences
- Add a button to manually control lights
- Sync multiple traffic lights together

---

## ⚠️ Quick Troubleshooting

| Issue | Fix |
|-------|-----|
| One LED won't turn on | Check LED polarity & resistor |
| Wrong sequence | Verify each LED is on correct pin |
| All LEDs stay on | Check your code pin assignments |
| Upload fails | Verify board & COM port |

---

## 📚 Next Project

➡️ **Day 07 – Buzzer & Sounds** - Add sound to your projects with a buzzer!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
