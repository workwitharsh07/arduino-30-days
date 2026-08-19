# 📍 Day 26 – Line Follower Robot

Build a robot that autonomously follows a black line on white floor using proportional motor control.

**⏱️ Time:** 35-40 mins | **📊 Level:** ⭐⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 📍 Infrared line detection
- 🔄 Proportional motor control
- 🎯 Autonomous path following
- 📊 Precision line tracking
- 🔁 Complex route navigation

---

## 🎯 What You'll Learn

- Infrared sensor operation
- Line detection algorithms
- Proportional control systems
- Motor coordination
- Autonomous path following
- Complex route navigation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Robot Chassis | 1 |
| DC Motors | 2 |
| Motor Driver (L298N) | 1 |
| Infrared Line Sensors | 2 |
| Battery Pack (6V-9V) | 1 |
| Caster Wheel | 1 |
| Jumper Wires | 15 |
| USB Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Motor Driver VCC + IR Sensor VCC |
| GND | Motor Driver GND + IR Sensor GND + Battery GND |
| Pin 5 | Motor Driver ENA (Left speed) |
| Pin 6 | Motor Driver ENB (Right speed) |
| Pin 2 | Motor Driver IN1 |
| Pin 3 | Motor Driver IN2 |
| Pin 4 | Motor Driver IN3 |
| Pin A0 | Left IR Sensor Output |
| Pin A1 | Right IR Sensor Output |

**⚠️ Important:** Mount IR sensors 2-3mm above floor facing downward. Sensors should be 5cm apart for optimal line detection.

---

## 💻 How It Works

### Initialize Sensors and Motors
In setup(), Arduino configures pins 2-6 as outputs for motor control. Pins A0-A1 configured as analog inputs for infrared sensors. Serial Monitor starts.

### Read Infrared Sensor Values
Inside main loop, Arduino reads both IR sensors using analogRead(). Sensor values range 0-1023, where low = black line, high = white surface.

### Determine Robot Position Relative to Line
Program compares sensor readings to determine if robot centered, drifting left, or drifting right. If both sensors read similar low values, robot is centered.

### Calculate Motor Speed Adjustment
Based on sensor readings, program calculates different motor speeds. If drifting left, right motor speeds up. If drifting right, left motor speeds up.

### Continuous Correction Loop
Process repeats many times per second inside loop() function. This rapid feedback allows continuous small corrections, keeping robot centered.

---

## 🚀 Getting Started

1. Assemble robot chassis with both motors
2. Mount left IR sensor on left front
3. Mount right IR sensor on right front (5cm apart)
4. Connect motor driver to battery pack
5. Connect all sensors to correct Arduino pins
6. Connect Arduino to computer
7. Load Line Follower Robot sketch
8. Select **Tools → Board → Arduino UNO**
9. Upload code
10. Place robot on black line and run!

---

## 💾 Source Code (LineFollower.ino)

```cpp
int enA = 5;
int in1 = 2;
int in2 = 3;
int enB = 6;
int in3 = 4;
int in4 = 5;

int leftSensor = A0;
int rightSensor = A1;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Read both IR sensors
  int leftValue = analogRead(leftSensor);
  int rightValue = analogRead(rightSensor);
  
  Serial.print("L: ");
  Serial.print(leftValue);
  Serial.print(" R: ");
  Serial.println(rightValue);
  
  int leftSpeed = 200;
  int rightSpeed = 200;
  
  // Both sensors on line - move straight
  if (leftValue < 500 && rightValue < 500) {
    leftSpeed = 200;
    rightSpeed = 200;
  }
  // Drift left - speed up right motor
  else if (leftValue > rightValue) {
    leftSpeed = 150;
    rightSpeed = 255;
  }
  // Drift right - speed up left motor
  else {
    leftSpeed = 255;
    rightSpeed = 150;
  }
  
  // Control motors
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
  
  delay(50);
}
```

---

## 📸 Expected Output

- 🤖 Robot searches for black line
- 📍 Detects line with IR sensors
- 🔄 Follows line smoothly around corners
- 🎯 Maintains center position continuously
- 🔁 Navigates complex paths accurately
- 📊 Serial Monitor shows sensor readings

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust speed sensitivity
leftSpeed = 100;  // Slower following

// Create S-curve track
// Add curved turns to path

// Speed boost on straights
if (leftValue > 400 && rightValue > 400) {
  baseSpeed = 250;  // Speed up on white
}

// Lap counting
if (lineDetected) {
  lapCount++;
}

// Add buzzer on turn
if (turning) {
  tone(buzzerPin, 800);
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Robot oscillates side to side | Reduce motor speed difference |
| Doesn't follow smoothly | Clean IR sensors & adjust angle |
| Inconsistent readings | Check lighting & calibrate sensors |
| Motor speed unbalanced | Adjust PWM values per motor |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Infrared Sensor | Detects light reflection changes |
| Proportional Control | Response matches input intensity |
| Line Detection | Identifying path on floor |
| Motor Coordination | Synchronized movement for tracking |
| Path Following | Autonomous navigation along defined route |

---

## 📚 Next Project

➡️ **Day 27 – Weather Station** - Build professional weather system!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
