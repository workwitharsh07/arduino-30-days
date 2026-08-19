# 🔐 Day 23 – Servo-Based Door Lock

Build an intelligent electronic door lock that unlocks with button press and automatically re-locks after time.

**⏱️ Time:** 30-35 mins | **📊 Level:** ⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🔐 Electronic door lock mechanism
- ⏱️ Automatic re-locking system
- 🔘 Push button unlock control
- 💡 LED status indicators
- 🔄 Timed locking sequence

---

## 🎯 What You'll Learn

- Servo motor control for mechanical systems
- Access control logic
- Timed automation sequences
- Status indicator systems
- Smart lock applications
- Security system integration

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Servo Motor (SG90) | 1 |
| Push Button | 1 |
| Indicator LEDs | 2 |
| 10kΩ Resistor | 1 |
| 220Ω Resistor | 2 |
| Jumper Wires | 8 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Servo VCC |
| GND | Servo GND + Button (other side) + LED Cathodes |
| Pin 9 | Servo Signal (orange wire) |
| Pin 6 | Push Button (with 10kΩ pull-up to 5V) |
| Pin 3 | Red LED Anode (through 220Ω) - LOCKED |
| Pin 4 | Green LED Anode (through 220Ω) - UNLOCKED |

**⚠️ Important:** Mount servo securely for lock control. Servo brown wire = GND, red wire = VCC, orange wire = Signal.

---

## 💻 How It Works

### Initialize Servo and Pins
In setup(), Arduino attaches Servo object to Pin 9. All LED pins configured as outputs. Button pin set as INPUT_PULLUP. Servo starts at locked position (0°).

### Read Button Input
Program continuously checks if unlock button pressed using digitalRead(Pin 6). When button transitions from HIGH to LOW, unlock sequence begins.

### Control Lock Position
When button pressed, Arduino moves servo to 180° representing unlocked position. Green LED turns on, red LED turns off for visual indication.

### Implement Auto-Lock Timer
System monitors time while door unlocked. After exactly 10 seconds automatically expire, Arduino moves servo back to 0° for locked state.

### Display Lock Status
During operation, system displays door status on Serial Monitor with countdown timer. Shows "DOOR LOCKED" or "DOOR UNLOCKED - X seconds remaining".

---

## 🚀 Getting Started

1. Mount servo motor securely for lock control
2. Connect servo to Pin 9, 5V, and GND
3. Connect button to Pin 6 with pull-up resistor
4. Connect red LED to Pin 3 (locked indicator)
5. Connect green LED to Pin 4 (unlocked indicator)
6. Connect Arduino to computer
7. Load Servo Door Lock sketch
8. Select **Tools → Board → Arduino UNO**
9. Upload code
10. Press button to unlock!

---

## 💾 Source Code (DoorLock.ino)

```cpp
#include <Servo.h>

Servo lockServo;
int buttonPin = 6;
int redLED = 3;
int greenLED = 4;
boolean isUnlocked = false;
unsigned long unlockTime = 0;

void setup() {
  lockServo.attach(9);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  // Lock door initially
  lockServo.write(0);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  
  Serial.begin(9600);
  Serial.println("Door Lock System Ready");
}

void loop() {
  // Check button press
  if (digitalRead(buttonPin) == LOW) {
    delay(50);  // Debounce
    
    if (!isUnlocked) {
      // Unlock door
      lockServo.write(180);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      isUnlocked = true;
      unlockTime = millis();
      Serial.println("DOOR UNLOCKED");
    }
  }
  
  // Auto-lock after 10 seconds
  if (isUnlocked && (millis() - unlockTime) > 10000) {
    lockServo.write(0);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    isUnlocked = false;
    Serial.println("DOOR LOCKED - Auto-lock activated");
  }
  
  // Display remaining time
  if (isUnlocked) {
    int remaining = 10 - ((millis() - unlockTime) / 1000);
    Serial.print("Unlocked - ");
    Serial.print(remaining);
    Serial.println(" seconds remaining");
    delay(1000);
  }
}
```

---

## 📸 Expected Output

- 🔴 Startup → Red LED on (Door LOCKED)
- 🔘 Press button → Servo rotates
- 🟢 Door UNLOCKS → Green LED on
- ⏱️ Wait 10 seconds
- 🔴 Auto-locks → Red LED on

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust auto-lock timer
if ((millis() - unlockTime) > 20000) {  // 20 seconds

// Add buzzer feedback
if (!isUnlocked) {
  tone(buzzerPin, 1000, 200);
}

// Unlock attempt counter
int failedAttempts = 0;
if (wrongPassword) {
  failedAttempts++;
}

// Serial password entry
if (enteredPassword == "1234") {
  unlockDoor();
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Servo doesn't move | Verify servo to Pin 9, 5V, & GND |
| Button doesn't trigger | Check Pin 6 connection & pull-up resistor |
| LEDs don't change | Verify LED connections to Pins 3 & 4 |
| Door doesn't auto-lock | Check servo.write(0) command & delay |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Servo | Motor with precise angle control |
| Lock Mechanism | Mechanical position control |
| Auto-lock | Automatic return to secure state |
| Debouncing | Removing electrical noise from button |
| Access Control | Authentication and authorization system |

---

## 📚 Next Project

➡️ **Day 24 – Automatic Gate System** - Create motion-activated gate!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
