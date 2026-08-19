# 💡 Day 09 – Distance Meter HC-SR04

Build a distance measurement system using an ultrasonic sensor that displays real-time distance readings.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 📏 Measure distance up to 4 meters
- 📡 Use ultrasonic sound waves for detection
- 🎯 Real-time distance readings
- 🔄 Instant response to object movement
- 📊 Display results on Serial Monitor

---

## 🎯 What You'll Learn

- How ultrasonic sensors measure distance
- Understanding sound wave reflection
- The `pulseIn()` function for timing measurement
- Distance calculation from echo time
- Sensor calibration techniques
- Real-time data display and monitoring

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Jumper Wires | 4 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Sensor Pin |
|-------------|-----------|
| 5V | VCC (Power) |
| GND | GND (Ground) |
| Pin 9 | TRIG (Trigger) |
| Pin 10 | ECHO (Echo) |

**⚠️ Important:** The HC-SR04 has 4 pins: VCC, GND, TRIG, and ECHO. Verify all connections before uploading code.

---

## 💻 How It Works

### Configure Sensor Pins
Pin 9 is OUTPUT for sending trigger signal. Pin 10 is INPUT to receive echo signal.

### Send Trigger Pulse
A 10-microsecond pulse is sent to TRIG pin to activate the ultrasonic sensor.

### Measure Echo Duration
The `pulseIn()` function measures how long ECHO pin stays HIGH after trigger signal.

### Calculate Distance
Distance = (Echo Duration × Speed of Sound) ÷ 2. The divisor is 2 because sound travels to object and back.

### Display Results
Distance is printed to Serial Monitor every 500ms for continuous real-time readings.

---

## 🚀 Getting Started

1. Connect HC-SR04 sensor to breadboard
2. Wire VCC to 5V, GND to GND
3. Wire TRIG to Pin 9, ECHO to Pin 10
4. Connect Arduino to computer
5. Open Arduino IDE
6. Load the Distance Meter sketch
7. Open Serial Monitor at 9600 baud
8. Place objects in front of sensor to measure distance

---

## 💾 Source Code (DistanceMeter.ino)

```cpp
int trigPin = 9;    // Trigger pin
int echoPin = 10;   // Echo pin

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance (speed of sound = 343 m/s)
  int distance = duration * 0.0343 / 2;
  
  // Display results
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);
}
```

---

## 📸 Expected Output

- 📊 Serial Monitor displays distance in centimeters
- 🎯 No object detected = large distance value
- 👋 Move hand in front = real-time distance updates
- 🔄 Readings update every 500ms

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Display in both cm and inches
int inches = distance / 2.54;
Serial.println(inches);

// Add distance ranges
if (distance < 10) {
  Serial.println("Very Close!");
} else if (distance < 50) {
  Serial.println("Close");
} else {
  Serial.println("Far");
}

// Use trigger on different pin
int trigPin = 8;  // Different pin

// Increase measurement frequency
delay(200);  // Check every 200ms instead of 500ms
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| No distance readings | Check all 4 sensor pins, verify Serial Monitor open |
| Shows zero or max value | Verify TRIG on Pin 9 and ECHO on Pin 10 |
| Unstable readings | Move sensor away from reflective surfaces |
| Sensor not responding | Check 5V power and GND connection |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Ultrasonic | Sound waves above human hearing (40 kHz) |
| Trigger | Signal that tells sensor to send sound |
| Echo | Sound wave reflecting back to sensor |
| pulseIn() | Measures how long a signal stays HIGH |
| Duration | Time echo takes to return (microseconds) |

---

## 📚 Next Project

**Day 10 – Smart Parking Sensor**

Combine HC-SR04 with LEDs and buzzer for a parking assistance system!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
