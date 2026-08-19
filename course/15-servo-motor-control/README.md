# 💡 Day 15 – Servo Motor Control

Control a servo motor's position using PWM signals to achieve precise angular movement.

**⏱️ Time:** 20-25 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 🔄 Rotate servo 0-180 degrees
- 📍 Precise angle positioning
- 🎯 Smooth sweeping motion
- ⚡ PWM signal control
- 🤖 Foundation for robotics

---

## 🎯 What You'll Learn

- How servo motors work
- PWM signal timing basics
- Angle positioning with servo
- Smooth movement control
- Servo library usage
- Robotics fundamentals

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Servo Motor (SG90) | 1 |
| Jumper Wires | 3 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Servo Wire |
|-------------|-----------|
| GND | Brown (GND) |
| 5V | Red (Power) |
| Pin 9 | Orange (Signal) |

**⚠️ Important:** Brown = GND, Red = Power, Orange = Signal. Connect directly without resistors.

---

## 💻 How It Works

### Include Servo Library
Import Servo library for simple angle control without PWM calculations.

### Configure Servo Pin
Attach servo to Pin 9 in setup(). This tells library where control signal is sent.

### Set Servo Position
write() function sets angle in degrees (0-180). Servo instantly moves to target angle.

### Create Smooth Movement
Loop gradually changes angle in small increments. Delays between increments create smooth sweeping.

### Repeat Motion Continuously
Loop reverses direction after reaching 180 degrees. Creates back-and-forth motion indefinitely.

---

## 🚀 Getting Started

1. Connect servo to breadboard
2. Brown wire to GND, Red to 5V, Orange to Pin 9
3. Connect Arduino to computer
4. Open Arduino IDE
5. Load Servo Motor sketch
6. Select **Tools → Board → Arduino UNO**
7. Upload code
8. Watch servo sweep smoothly

---

## 💾 Source Code (ServoControl.ino)

```cpp
#include <Servo.h>

Servo myservo;
int pos = 0;  // Variable to store servo position

void setup() {
  myservo.attach(9);  // Attach servo to Pin 9
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);  // Set servo angle
    delay(15);           // Wait for servo to move
  }
  
  // Sweep back from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
```

---

## 📸 Expected Output

- 🔄 Servo arm moves from 0° to 180°
- 📍 Smooth sweeping motion
- ⏸️ Brief pause at endpoints
- 🔁 Reverses and repeats
- ✅ Continuous back-and-forth motion

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Set specific angle
myservo.write(90);  // Middle position

// Faster sweep
delay(5);  // Faster than 15ms

// Slower sweep
delay(50);  // Slower than 15ms

// Go to specific positions
myservo.write(0);
delay(1000);
myservo.write(90);
delay(1000);
myservo.write(180);
delay(1000);

// Small oscillation
for (int i = 0; i < 10; i++) {
  myservo.write(85);
  delay(100);
  myservo.write(95);
  delay(100);
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Servo doesn't move | Verify Pin 9 connection, check servo power |
| Erratic movement | Check PWM signal stability, verify voltage |
| Grinding noise | Stop immediately, check mechanical limits |
| Jittery motion | Increase delay value, check power stability |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| PWM | Pulse Width Modulation for timing control |
| Servo | Motor with built-in position feedback |
| Angle | Rotation position (0-180 degrees) |
| write() | Sets servo angle in degrees |
| Sweep | Gradual angle change over time |

---

## 📚 Next Project

**Day 16 – Joystick Controlled Servo**

Control servo position with an analog joystick!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
