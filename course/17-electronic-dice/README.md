# 💡 Day 17 – Electronic Dice

Create an interactive dice roller using random numbers and a 7-segment display.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐ Advanced

---

## ✨ Features

- 🎲 Random number generation
- 🔄 Animated dice roll effect
- 🎮 Interactive button control
- 📊 7-segment display output
- 🎯 Game application example

---

## 🎯 What You'll Learn

- Random number generation
- Button press detection
- Animation timing
- Display pattern arrays
- Game logic programming
- Interactive user interface

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 7-Segment Display (Common Cathode) | 1 |
| 220Ω Resistor | 7 |
| Push Button | 1 |
| 10kΩ Resistor | 1 |
| Jumper Wires | 10 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| Pins 2-9 | 7-Segment Segments (through 220Ω) |
| Pin 7 | Push Button |
| GND | 7-Segment Common Cathode + Button |
| 5V | 10kΩ Pull-Up Resistor (other end to Pin 7) |

**⚠️ Important:** Each segment needs 220Ω resistor. Button needs pull-up resistor.

---

## 💻 How It Works

### Configure Pins
Segment pins set as OUTPUT. Button pin set as INPUT_PULLUP. Random seed initialized from noise.

### Create Patterns
Arrays store segment patterns for numbers 1-6. Each pattern defines which segments turn ON.

### Read Button Input
Loop checks if button pressed. Button press triggers dice roll animation.

### Animate Dice Roll
When rolling, cycle through 1-6 repeatedly. Each number displays briefly creating rolling effect.

### Generate Random Result
After animation, random() generates number 1-6. Display stops on random result.

---

## 🚀 Getting Started

1. Setup 7-segment with resistors on breadboard
2. Connect segments to Pins 2-9 (through resistors)
3. Connect button to Pin 7 with pull-up resistor
4. Connect common cathode to GND
5. Connect Arduino to computer
6. Load Electronic Dice sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Press button to roll dice

---

## 💾 Source Code (ElectronicDice.ino)

```cpp
int segmentPins[] = {2, 3, 4, 5, 6, 8, 9};  // A, B, C, D, E, F, G
int buttonPin = 7;

// Segment patterns for dice (1-6)
byte dicePatterns[6][7] = {
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1}   // 6
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  
  randomSeed(analogRead(A0));  // Initialize random
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    rollDice();
    delay(500);  // Debounce
  }
}

void rollDice() {
  // Animate rolling
  for (int roll = 0; roll < 20; roll++) {
    displayNumber(random(1, 7));
    delay(100);
  }
  
  // Final result
  int result = random(1, 7);
  displayNumber(result);
}

void displayNumber(int num) {
  for (int seg = 0; seg < 7; seg++) {
    digitalWrite(segmentPins[seg], dicePatterns[num-1][seg]);
  }
}
```

---

## 📸 Expected Output

- 🎲 Display shows number 1
- 🔄 Press button to roll dice
- ⚡ Display cycles 1-6 rapidly
- 🎯 Slows down and lands on random number
- 🔁 Press again to roll again

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Faster rolling
delay(50);  // Faster animation

// Slower rolling
delay(200);  // Slower animation

// More dice rolls
for (int roll = 0; roll < 50; roll++) {

// Add sound with buzzer
tone(buzzerPin, 1000);
delay(50);
noTone(buzzerPin);

// Display on Serial Monitor
Serial.print("Dice: ");
Serial.println(result);
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Display doesn't show numbers | Check segment connections and resistors |
| Button doesn't trigger roll | Verify button connection to Pin 7 |
| Same number always rolls | Check random() seed initialization |
| Segments flicker | Check resistor values and connections |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Random | Generate unpredictable numbers |
| Random Seed | Starting value for randomness |
| Animation | Quick image changes create motion |
| Debounce | Delay to prevent multiple presses |
| Pattern Array | Store display configurations |

---

## 📚 Next Project

**Day 18 – OLED System Monitor**

Display real-time data on advanced OLED screen!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
