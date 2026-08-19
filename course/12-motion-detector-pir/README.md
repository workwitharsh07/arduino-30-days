# 💡 Day 12 – Motion Detector PIR

Build a motion detection security system that detects movement and triggers LED and buzzer alarms.

**⏱️ Time:** 25-30 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 👁️ Detect human movement with infrared sensing
- 🚨 Automatic alarm activation on motion
- 💡 Visual alert with LED indicator
- 🔊 Audio alarm with buzzer
- 🔒 Real-world security system application

---

## 🎯 What You'll Learn

- How PIR (Passive Infrared) sensors work
- Detecting infrared radiation changes
- Motion detection principles
- Sensor warm-up and initialization
- Automated alert system design
- Security system applications

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| PIR Motion Sensor | 1 |
| Red LED | 1 |
| 220Ω Resistor | 1 |
| Passive Buzzer | 1 |
| Jumper Wires | 5 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | PIR VCC (Power) |
| GND | PIR GND, LED Cathode, Buzzer (−) |
| Pin 6 | PIR OUT (Output) |
| Pin 2 | LED Anode (through 220Ω resistor) |
| Pin 3 | Buzzer (+) positive terminal |

**⚠️ Important:** PIR sensor needs 30-60 seconds to warm up after power-on. Wait before testing!

---

## 💻 How It Works

### Configure All Pins
Setup: Pin 6 (INPUT for motion), Pin 2 (OUTPUT for LED), Pin 3 (OUTPUT for buzzer).

### Read Motion Sensor
Continuously read digital signal from PIR. LOW = no motion detected. HIGH = motion detected.

### Activate Alarm
When motion detected (HIGH signal), immediately turn ON the red LED and start buzzer tone.

### Manage Alarm Duration
LED and buzzer stay active for 5-10 seconds. Then system returns to standby monitoring mode.

### Continuous Monitoring
Motion detection loop repeats constantly, ready to detect and respond to any movement instantly.

---

## 🚀 Getting Started

1. Connect PIR sensor to breadboard
2. Wire VCC to 5V, GND to GND, OUT to Pin 6
3. Connect LED to Pin 2 with 220Ω resistor
4. Connect buzzer to Pin 3
5. Connect Arduino to computer
6. Load the Motion Detector sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Wait 60 seconds for sensor warm-up
10. Move in front of sensor to trigger alarm

---

## 💾 Source Code (MotionDetector.ino)

```cpp
int motionPin = 6;    // PIR output pin
int ledPin = 2;       // LED pin
int buzzerPin = 3;    // Buzzer pin
int alarmDuration = 5000;  // Alarm for 5 seconds

void setup() {
  pinMode(motionPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Motion Detector Ready!");
  Serial.println("Waiting 60 seconds for sensor warm-up...");
  delay(60000);  // 60 second warm-up
  Serial.println("Sensor Ready! Monitoring...");
}

void loop() {
  int motionDetected = digitalRead(motionPin);
  
  if (motionDetected == HIGH) {
    // Motion detected!
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    Serial.println("MOTION DETECTED!");
    
    delay(alarmDuration);  // Alarm for 5 seconds
    
    // Turn off alarm
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    
    delay(1000);  // Wait before next detection
  }
}
```

---

## 📸 Expected Output

- ⏳ 60 seconds warm-up period after power-on
- 🟢 LED off, buzzer silent (no motion)
- 🔴 Motion detected: Red LED turns ON
- 🔊 Buzzer sounds alarm (HIGH frequency tone)
- ⏱️ Alarm active for 5 seconds
- 🔄 System returns to standby after alarm

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Adjust alarm duration
int alarmDuration = 10000;  // 10 seconds instead of 5

// Add different buzzer tones
tone(buzzerPin, 800);   // Lower tone
tone(buzzerPin, 2000);  // Higher tone

// Create LED blinking
digitalWrite(ledPin, HIGH);
delay(100);
digitalWrite(ledPin, LOW);
delay(100);

// Add Serial output for debugging
Serial.print("Motion Sensor Read: ");
Serial.println(motionDetected);

// Multiple alarm sounds
tone(buzzerPin, 1000);
delay(100);
noTone(buzzerPin);
delay(100);
tone(buzzerPin, 1000);
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Motion not detected | Wait 60 seconds for initialization, move in front of lens |
| False alarms occur | Adjust sensor potentiometer, move away from heat sources |
| LED doesn't turn on | Check Pin 2 connection and LED polarity |
| Buzzer silent | Verify Pin 3 connection and buzzer polarity |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| PIR Sensor | Detects infrared radiation (body heat) |
| Infrared | Heat radiation invisible to human eyes |
| Motion Detection | Sense changes in infrared patterns |
| Warm-Up Time | Time sensor needs to stabilize (30-60 sec) |
| Threshold | Sensitivity level for motion detection |

---

## 📚 Congratulations! 🎉

You've completed **Stage 2: Sensors and Sound!** Master concepts like:
- Light detection (LDR)
- Sound generation (Buzzer)
- Distance measurement (Ultrasonic)
- Environmental sensing (Temperature/Humidity)
- Motion detection (PIR)

Ready for the next stage with wireless communication and autonomous systems!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
