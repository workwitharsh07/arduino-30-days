# 🤖 Day 25 – Obstacle Avoiding Robot

Build an autonomous robot that detects obstacles and avoids them automatically without human control.

**⏱️ Time:** 40-45 mins | **📊 Level:** ⭐⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🤖 Autonomous navigation
- 🛑 Obstacle detection & avoidance
- 💨 Dual motor coordination
- 🧭 Intelligent decision logic
- 🔄 Continuous environment adaptation

---

## 🎯 What You'll Learn

- Autonomous navigation systems
- Motor coordination for movement
- Obstacle detection response
- Robot chassis assembly
- Decision-making algorithms
- Robotics fundamentals

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Robot Chassis | 1 |
| DC Motors | 2 |
| Motor Driver (L298N) | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| Battery Pack (6V-9V) | 1 |
| Caster Wheel | 1 |
| Jumper Wires | 15 |
| USB Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | Motor Driver VCC + Sensor VCC |
| GND | Motor Driver GND + Sensor GND + Battery GND |
| Pin 5 | Motor Driver ENA (Left speed) |
| Pin 6 | Motor Driver ENB (Right speed) |
| Pin 2 | Motor Driver IN1 (Left direction) |
| Pin 3 | Motor Driver IN2 (Left direction) |
| Pin 4 | Motor Driver IN3 (Right direction) |
| Pin 9 | HC-SR04 TRIG |
| Pin 10 | HC-SR04 ECHO |
| Pin 8 | Servo Signal (scanner) |

**⚠️ Important:** Battery powers motor driver directly. Arduino GND connected to motor driver GND for common reference.

---

## 💻 How It Works

### Initialize Motors and Sensor
In setup(), Arduino configures pins 2-6 as outputs for motor control. Pins 9-10 configured for ultrasonic sensor. Pin 8 controls servo scanner.

### Measure Distance Continuously
Inside main loop, Arduino measures distance using HC-SR04 sensor. If distance greater than 20 centimeters, obstacle is far away and safe.

### Move Forward Automatically
When no obstacle detected or obstacle far away, Arduino sends forward movement commands to both motors. Both motors receive equal PWM values for straight movement.

### Detect Obstacle Approach
When distance reading drops below 20 centimeters, Arduino recognizes obstacle is too close and initiates avoidance behavior immediately.

### Execute Avoidance Sequence
First, motors stop completely. Then robot backs up by reversing motor direction for half second. Next, robot rotates for one full second. Finally, motors resume forward movement.

### Repeat Cycle Continuously
Obstacle avoidance cycle repeats indefinitely. Robot continuously scans environment and makes navigation decisions independently.

---

## 🚀 Getting Started

1. Assemble robot chassis with both motors
2. Mount HC-SR04 sensor on servo for scanning
3. Connect motor driver to battery pack
4. Connect all sensors to correct Arduino pins
5. Connect Arduino to computer
6. Load Obstacle Avoiding Robot sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Place robot on floor and run!

---

## 💾 Source Code (ObstacleRobot.ino)

```cpp
#include <Servo.h>

Servo scannerServo;
int enA = 5;    // Left motor speed
int in1 = 2;    // Left motor direction
int in2 = 3;

int enB = 6;    // Right motor speed
int in3 = 4;    // Right motor direction
int in4 = 5;

int trigPin = 9;
int echoPin = 10;
int servoPin = 8;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  scannerServo.attach(servoPin);
  scannerServo.write(90);  // Center servo
  
  Serial.begin(9600);
}

void loop() {
  int distance = getDistance();
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance > 20) {
    moveForward();
  } else {
    stopMotors();
    delay(300);
    backUp();
    delay(500);
    turnRight();
    delay(600);
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  return distance;
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

void backUp() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  analogWrite(enA, 250);
  analogWrite(enB, 250);
}

void stopMotors() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
```

---

## 📸 Expected Output

- 🚗 Robot moves forward autonomously
- 🛑 Detects wall/obstacle ahead
- 🤖 Stops and backs up
- 🔄 Rotates to find clear path
- 🚗 Continues forward movement
- 🔁 Repeats indefinitely avoiding obstacles

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Add speed control
analogWrite(enA, 150);  // Slower speed

// Turn left instead
turnLeft();
digitalWrite(in1, LOW);
digitalWrite(in3, HIGH);

// Scan for best path
for (int angle = 45; angle <= 135; angle += 10) {
  scannerServo.write(angle);
  int dist = getDistance();
}

// LED obstacle indicator
if (distance < 20) {
  digitalWrite(ledPin, HIGH);
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Robot moves in circles | Balance motor speeds with PWM values |
| Obstacle detection fails | Check TRIG to Pin 9 & ECHO to Pin 10 |
| Motors don't respond | Verify motor driver connections |
| Robot gets stuck | Increase backup distance or rotation angle |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Autonomous | Self-governing without human control |
| Motor Coordination | Synchronized dual motor control |
| Obstacle Avoidance | Detecting and preventing collisions |
| Navigation Logic | Decision-making for movement |
| Robotics | Design and control of robots |

---

## 📚 Next Project

➡️ **Day 26 – Line Follower Robot** - Track black lines autonomously!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
