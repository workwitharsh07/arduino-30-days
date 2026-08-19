# 💡 Day 16 – Joystick Controlled Servo

Control servo motor position using an analog joystick for interactive mechanical control.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐⭐ Advanced

---

## ✨ Features

- 🕹️ Joystick analog input control
- 📍 Real-time servo positioning
- 🔄 Smooth responsive movement
- 🎮 Interactive control system
- ⚡ Input-to-output mapping

---

## 🎯 What You'll Learn

- Reading analog joystick input
- Mapping value ranges
- Input-to-output control
- Interactive servo response
- Real-time system design
- Control mapping techniques

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Analog Joystick Module | 1 |
| Servo Motor (SG90) | 1 |
| Jumper Wires | 5 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Joystick VCC + Servo Red |
| GND | Joystick GND + Servo Brown |
| A0 | Joystick X-Axis |
| A1 | Joystick Y-Axis |
| Pin 9 | Servo Orange Signal |

**⚠️ Important:** Joystick reads 0-1023, Servo needs 0-180. Use map() to convert.

---

## 💻 How It Works

### Read Joystick Input
analogRead(A0) continuously reads X-axis. Values range 0-1023 based on joystick position.

### Map Input to Servo Angle
map() converts joystick range (0-1023) to servo angle range (0-180). Center position ≈ 512 = 90°.

### Handle Center Position
Joystick center = 512 reading = 90 degrees servo position = middle.

### Move Servo to Position
servo.write() sets angle based on mapped value. Servo responds instantly to input.

### Continuous Response
Loop reads input many times per second. Provides smooth responsive servo movement following joystick.

---

## 🚀 Getting Started

1. Connect joystick to breadboard
2. Connect X-Axis to A0, Y-Axis to A1
3. VCC to 5V, GND to GND
4. Connect servo to Pin 9
5. Connect Arduino to computer
6. Load Joystick Servo sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Move joystick to control servo

---

## 💾 Source Code (JoystickServo.ino)

```cpp
#include <Servo.h>

Servo myservo;
int joystickXpin = A0;  // X-axis input

void setup() {
  myservo.attach(9);    // Servo on Pin 9
  Serial.begin(9600);
}

void loop() {
  // Read joystick value (0-1023)
  int joystickValue = analogRead(joystickXpin);
  
  // Map joystick value to servo angle (0-180)
  int servoAngle = map(joystickValue, 0, 1023, 0, 180);
  
  // Move servo to mapped angle
  myservo.write(servoAngle);
  
  // Print values for debugging
  Serial.print("Joystick: ");
  Serial.print(joystickValue);
  Serial.print(" -> Servo: ");
  Serial.println(servoAngle);
  
  delay(50);  // Update 20 times per second
}
```

---

## 📸 Expected Output

- 🕹️ Center joystick = 90° servo position
- ⬅️ Move left = servo rotates toward 0°
- ➡️ Move right = servo rotates toward 180°
- 🔄 Smooth continuous response
- ✅ Real-time interactive control

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Reverse control
int servoAngle = map(joystickValue, 1023, 0, 0, 180);

// Use Y-axis instead
int joystickValue = analogRead(A1);

// Add deadzone for center
if (joystickValue > 450 && joystickValue < 550) {
  servoAngle = 90;  // Stay centered in middle zone
}

// Limit servo range
if (servoAngle < 30) servoAngle = 30;
if (servoAngle > 150) servoAngle = 150;

// Add smoothing
servoAngle = (servoAngle + previousAngle) / 2;
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Servo doesn't respond | Check A0 connection, verify servo power |
| Servo response backwards | Reverse map() parameters |
| Jerky movement | Increase delay value, check voltage |
| No joystick reading | Verify joystick VCC and GND connections |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Analog Input | Reads values 0-1023 from joystick |
| map() | Converts one range to another |
| Mapping | Converting joystick to servo values |
| Interactive | Real-time response to user input |
| Deadzone | Center area where servo stays still |

---

## 📚 Next Project

**Day 17 – Electronic Dice**

Create a random number generator game using button and display!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
