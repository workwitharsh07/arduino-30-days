# 🚪 Day 24 – Automatic Gate System

Build an intelligent gate that automatically opens when vehicles approach and closes when they pass through.

**⏱️ Time:** 35-40 mins | **📊 Level:** ⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 🚗 Vehicle detection system
- 🚪 Automatic gate opening/closing
- 📊 Distance-based decision making
- 🔔 Audio alert system
- 💡 Multi-color status indicators

---

## 🎯 What You'll Learn

- Ultrasonic sensor distance measurement
- Automated gate control logic
- Distance-based decision making
- Timing sequences for automation
- Smart entrance systems
- Alert and feedback mechanisms

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Servo Motor | 1 |
| Status LEDs | 3 |
| Buzzer | 1 |
| 220Ω Resistor | 3 |
| Jumper Wires | 10 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | HC-SR04 VCC + Servo VCC |
| GND | HC-SR04 GND + Servo GND + LED Cathodes |
| Pin 9 | HC-SR04 TRIG |
| Pin 10 | HC-SR04 ECHO |
| Pin 8 | Servo Signal (orange wire) |
| Pin 3 | Red LED (through 220Ω) - CLOSED |
| Pin 4 | Yellow LED (through 220Ω) - OPENING |
| Pin 5 | Green LED (through 220Ω) - OPEN |
| Pin 7 | Buzzer Positive |

**⚠️ Important:** Ultrasonic sensor must face vehicle approach direction. Mount servo securely for gate control.

---

## 💻 How It Works

### Initialize All Sensors and Actuators
In setup(), Arduino configures ultrasonic sensor pins 9 & 10. Servo attached to Pin 8. All LED pins set as outputs. Buzzer on Pin 7.

### Measure Distance to Approaching Vehicles
Inside main loop, Arduino continuously reads HC-SR04 sensor. Distance calculation: distance = (echo time × speed of sound) / 2.

### Detect Vehicle Approach
When distance reading drops below 80 centimeters, Arduino recognizes vehicle approaching within detection range.

### Open Gate Automatically
When vehicle detected, Arduino sends servo command to 90-180°, opening gate. Yellow LED illuminates and buzzer sounds warning.

### Wait for Vehicle to Pass
System monitors distance continuously while gate open. If no vehicle detected within gate area for 10 seconds, closing sequence begins.

### Close Gate and Return to Secure
After timeout expires, servo returns to 0°, closing gate. Red LED illuminates again indicating secure state. System ready for next vehicle.

---

## 🚀 Getting Started

1. Mount HC-SR04 sensor facing vehicle approach direction
2. Mount servo motor for gate control
3. Connect sensor to Pins 9 & 10
4. Connect servo to Pin 8
5. Connect status LEDs to Pins 3, 4, 5
6. Connect buzzer to Pin 7
7. Connect Arduino to computer
8. Load Automatic Gate System sketch
9. Select **Tools → Board → Arduino UNO**
10. Upload code
11. Approach sensor to test gate!

---

## 💾 Source Code (AutoGate.ino)

```cpp
#include <Servo.h>

Servo gateServo;
int trigPin = 9;
int echoPin = 10;
int servoPin = 8;
int redLED = 3;
int yellowLED = 4;
int greenLED = 5;
int buzzerPin = 7;

int detectionDistance = 80;  // 80cm detection threshold
boolean gateOpen = false;
unsigned long gateOpenTime = 0;

void setup() {
  gateServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Close gate initially
  gateServo.write(0);
  digitalWrite(redLED, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  int distance = getDistance();
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Vehicle detected
  if (distance < detectionDistance && !gateOpen) {
    openGate();
  }
  
  // Auto-close after 10 seconds
  if (gateOpen && (millis() - gateOpenTime) > 10000) {
    closeGate();
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

void openGate() {
  gateServo.write(180);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  tone(buzzerPin, 1000);
  gateOpen = true;
  gateOpenTime = millis();
  
  Serial.println("Gate Opening...");
}

void closeGate() {
  gateServo.write(0);
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  noTone(buzzerPin);
  gateOpen = false;
  
  Serial.println("Gate Closed");
}
```

---

## 📸 Expected Output

- 🔴 Initial → Red LED, gate CLOSED
- 🟡 Vehicle detected → Yellow LED, buzzer sounds
- 🟢 Gate OPENS completely
- ⏱️ Waits 10 seconds for vehicle to pass
- 🔴 Timeout → Gate CLOSES automatically

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust detection distance
int detectionDistance = 50;  // Closer detection

// Variable gate opening time
int gateOpenTime = 15000;  // 15 seconds

// Multiple sensors
if (distance1 < 80 || distance2 < 80) {
  openGate();
}

// Emergency close button
if (emergencyButton) {
  closeGate();
}

// Speed alerts
if (distance < 30) {
  tone(buzzerPin, 2000);  // Higher pitch for closer objects
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Sensor doesn't detect | Verify TRIG to Pin 9 & ECHO to Pin 10 |
| Gate doesn't open | Check servo to Pin 8 connection |
| LEDs don't change | Verify LED connections to Pins 3, 4, 5 |
| Buzzer silent | Check buzzer to Pin 7 & GND |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Ultrasonic Sensor | Measures distance using sound waves |
| Servo Control | Precise angle positioning for gate |
| Detection Range | Maximum distance for object detection |
| Auto-close Timer | Automatic return to secure position |
| Smart Entrance | Autonomous gate operation system |

---

## 📚 Next Project

➡️ **Day 25 – Obstacle Avoiding Robot** - Build autonomous robot!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
