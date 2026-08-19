# 💡 Day 08 – Nokia Tune Passive Buzzer

Play the iconic Nokia ringtone by generating different sound frequencies with Arduino and a passive buzzer.

**⏱️ Time:** 20-25 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 🎵 Play melodies with different frequencies
- 🎶 Learn the `tone()` function for sound generation
- 📻 Understand musical notes and frequencies
- 🔊 Control buzzer timing and duration
- 🎼 Play the classic Nokia ringtone

---

## 🎯 What You'll Learn

- How passive buzzers generate sound
- The `tone()` function and frequency control
- Musical note frequencies and their values
- Creating melodies by combining notes
- Controlling note duration and timing
- Difference between active and passive buzzers

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| Passive Buzzer | 1 |
| Jumper Wires | 2 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| Pin 8 | Buzzer (+) positive terminal |
| GND | Buzzer (−) negative terminal |

**⚠️ Important:** Use a PASSIVE buzzer, not an active buzzer. Active buzzers can only beep, while passive buzzers can play melodies.

---

## 💻 How It Works

### Configure Output Pin
Pin 8 is set as OUTPUT to send frequency signals to the passive buzzer.

### Store Melody Data
Two arrays store the Nokia tune: one for note frequencies, one for note durations.

### Generate Musical Notes
The `tone()` function sends square-wave signals at different frequencies to create musical notes.

### Control Note Timing
The `delay()` function controls how long each note plays before moving to the next.

### Repeat Melody
After the tune finishes, the program pauses and repeats the Nokia melody continuously.

---

## 🚀 Getting Started

1. Connect passive buzzer to Pin 8 and GND
2. Connect Arduino to your computer
3. Open Arduino IDE
4. Load the Nokia Tune sketch
5. Select **Tools → Board → Arduino UNO**
6. Select the correct **COM Port**
7. Click **Upload**
8. Listen as the classic Nokia ringtone plays!

---

## 💾 Source Code (NokiaTune.ino)

```cpp
int buzzerPin = 8;

// Note frequencies in Hz
int notes[] = {659, 784, 659, 784, 659, 523, 587, 494, 440, 494, 587, 523};

// Note durations (in milliseconds)
int durations[] = {150, 150, 150, 150, 150, 300, 150, 150, 150, 150, 300, 300};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Play each note
  for (int i = 0; i < 12; i++) {
    tone(buzzerPin, notes[i], durations[i]);
    delay(durations[i] + 50);  // Add pause between notes
  }
  
  delay(500);  // Pause before repeating
}
```

---

## 📸 Expected Output

- 🎵 Passive buzzer plays the complete Nokia ringtone
- 🎶 Each note plays at correct frequency and duration
- 🔄 Melody repeats continuously with brief pauses
- 📻 Clear, recognizable Nokia tune

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Create a different melody
int notes[] = {262, 294, 330, 349, 392};  // C D E F G
int durations[] = {200, 200, 200, 200, 400};

// Play notes individually
tone(buzzerPin, 659);     // Single note
delay(500);
noTone(buzzerPin);        // Stop sound
delay(100);

// Create a custom tune
void playNote(int frequency, int duration) {
  tone(buzzerPin, frequency, duration);
  delay(duration + 100);
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| No sound from buzzer | Check Pin 8 connection, verify passive buzzer |
| Incorrect melody | Ensure correct code uploaded without changes |
| Very low volume | Passive buzzers are naturally quiet, move closer |
| Upload errors | Verify correct board and COM port selected |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Passive Buzzer | Buzzer without built-in oscillator |
| Frequency | Number of vibrations per second (Hz) |
| Musical Note | Specific frequency representing a pitch |
| Duration | How long a note plays (milliseconds) |
| tone() | Arduino function to generate frequency |

---

## 📚 Next Project

**Day 09 – Distance Meter HC-SR04**

Measure distance to objects using ultrasonic sensors and the HC-SR04!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
