# 💡 Day 14 – Digital Counter 7-Segment Display

Build a digital counter that displays numbers 0-9 on a seven-segment LED display.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 🔢 Display digits 0-9
- 📊 Count up automatically
- 💡 Control individual LED segments
- ⚡ Learn 7-segment basics
- 🔄 Continuous counting loop

---

## 🎯 What You'll Learn

- How 7-segment displays work
- Segment control patterns
- Creating numeric displays
- Binary segment control
- Counting and timing logic
- Real-time data visualization

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 7-Segment Display (Common Cathode) | 1 |
| 220Ω Resistor | 7 |
| Jumper Wires | 8 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Segment | Via Resistor |
|-------------|---------|--------------|
| Pin 2 | A | 220Ω |
| Pin 3 | B | 220Ω |
| Pin 4 | C | 220Ω |
| Pin 5 | D | 220Ω |
| Pin 6 | E | 220Ω |
| Pin 8 | F | 220Ω |
| Pin 9 | G | 220Ω |
| GND | Common Cathode | Direct |

**⚠️ Important:** Each segment needs its own 220Ω resistor. Common cathode connects directly to GND.

---

## 💻 How It Works

### Configure Pins
All segment pins (2-9) set as OUTPUT. Each pin controls one LED segment independently.

### Create Segment Patterns
Arrays store patterns for digits 0-9. Each pattern specifies which segments turn ON for each digit.

### Display Numbers
To show digit, Arduino turns ON specific segments according to stored pattern. Digit 8 = all segments ON.

### Increment Counter
Variable tracks current digit. Every second counter increments. At 10, counter resets to 0.

### Update Display
Loop repeats constantly. Each second, segments update to display next digit creating counting effect.

---

## 🚀 Getting Started

1. Place 7-segment display on breadboard
2. Connect common cathode pins to GND
3. Connect segments A-G through resistors to Pins 2,3,4,5,6,8,9
4. Connect Arduino to computer
5. Load 7-Segment Counter sketch
6. Select **Tools → Board → Arduino UNO**
7. Upload code
8. Watch display count 0-9 repeatedly

---

## 💾 Source Code (SevenSegmentCounter.ino)

```cpp
int segmentPins[] = {2, 3, 4, 5, 6, 8, 9};  // A, B, C, D, E, F, G

// Segment patterns for digits 0-9
byte digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int digit = 0; digit < 10; digit++) {
    displayDigit(digit);
    delay(1000);  // Show each digit for 1 second
  }
}

void displayDigit(int digit) {
  for (int segment = 0; segment < 7; segment++) {
    digitalWrite(segmentPins[segment], digitPatterns[digit][segment]);
  }
}
```

---

## 📸 Expected Output

- 🔢 Display shows digit 0
- ⏱️ After 1 second, changes to 1
- 🔄 Continues counting 2-9
- 🔁 Resets to 0 and repeats
- ✅ All segments illuminate correctly

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Count backwards
for (int digit = 9; digit >= 0; digit--) {
  displayDigit(digit);
  delay(1000);
}

// Count faster
delay(500);  // 0.5 second per digit

// Display specific digit
displayDigit(5);  // Shows 5 only

// Blink digit
displayDigit(7);
delay(500);
clearDisplay();
delay(500);

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Some segments don't light | Check resistor connections, verify pin assignments |
| Wrong digit displays | Adjust segment pattern array values |
| Segments flicker | Check resistor values, ensure 220Ω |
| Counter doesn't increment | Verify delay() function set correctly |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| 7-Segment | Seven LED segments forming digits |
| Common Cathode | All segments share GND connection |
| Segment Pattern | Array of ON/OFF values for each digit |
| Increment | Increase counter by 1 each cycle |
| Loop | Repeat process continuously |

---

## 📚 Next Project

**Day 15 – Servo Motor Control**

Control precise motor movement with PWM signals!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
