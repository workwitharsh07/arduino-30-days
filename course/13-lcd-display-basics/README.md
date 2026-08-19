# 💡 Day 13 – LCD Display Basics

Learn to display text and information on a 16×2 LCD screen using I2C communication protocol.

**⏱️ Time:** 20-25 mins | **📊 Level:** ⭐⭐ Intermediate

---

## ✨ Features

- 📺 Display text on 16×2 LCD screen
- 💡 I2C simplified wiring
- 📝 Custom messages and formatting
- 🔌 Simple 4-wire connection
- 💬 Create information displays

---

## 🎯 What You'll Learn

- How LCD displays work
- I2C communication protocol basics
- Text positioning and formatting
- Display initialization and control
- Creating multi-line displays
- Real-world display applications

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| LCD 16×2 Display | 1 |
| I2C LCD Adapter | 1 |
| Jumper Wires | 4 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | I2C VCC |
| GND | I2C GND |
| A4 | I2C SDA (Data) |
| A5 | I2C SCL (Clock) |

**⚠️ Important:** I2C adapter simplifies wiring from 8+ wires to just 4. Always use I2C adapter for LCD projects.

---

## 💻 How It Works

### Initialize LCD Library
Arduino loads LiquidCrystal I2C library and initializes with I2C address. Display turns on with backlight activated.

### Configure Display Settings
Display size set to 16 columns by 2 rows. Cursor position initialized to starting point for text display.

### Display Welcome Message
Custom text printed to LCD using print() function. First message on top line, second message on bottom line.

### Control Text Positioning
setCursor() function positions text at any location. Changing cursor creates formatted displays with organized information.

### Create Dynamic Updates
clear() removes all text. New text printed for animations and real-time sensor value updates on display.

---

## 🚀 Getting Started

1. Attach I2C adapter to back of LCD
2. Connect VCC to 5V, GND to GND
3. Connect SDA to Pin A4, SCL to Pin A5
4. Connect Arduino to computer
5. Open Arduino IDE
6. Install LiquidCrystal I2C library
7. Load LCD Display sketch
8. Select **Tools → Board → Arduino UNO**
9. Upload code

---

## 💾 Source Code (LCDDisplay.ino)

```cpp
#include <LiquidCrystal_I2C.h>

// Set I2C address to 0x27 (adjust if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Print welcome message
  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
  
  lcd.setCursor(0, 1);
  lcd.print("Arduino LCD");
  
  delay(2000);
}

void loop() {
  // Clear display
  lcd.clear();
  
  // First message
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  
  lcd.setCursor(0, 1);
  lcd.print("Line 2");
  
  delay(2000);
  
  // Clear and show new message
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Display Test");
  
  lcd.setCursor(0, 1);
  lcd.print("Working!");
  
  delay(2000);
}
```

---

## 📸 Expected Output

- 💡 Blue backlight illuminates
- 📺 Welcome message displays on line 1
- 📝 Second message appears on line 2
- 🔄 Text changes every 2 seconds
- ✅ Clear display and show new messages

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Display sensor values
int sensorValue = analogRead(A0);
lcd.setCursor(0, 0);
lcd.print("Sensor: ");
lcd.print(sensorValue);

// Create scrolling text
for (int i = 0; i < 16; i++) {
  lcd.clear();
  lcd.setCursor(i, 0);
  lcd.print("Scroll");
  delay(100);
}

// Display on custom positions
lcd.setCursor(5, 0);
lcd.print("Col 5");

lcd.setCursor(0, 1);
lcd.print("Row 2");
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| No text on display | Adjust contrast with potentiometer, check I2C address |
| Backlight off | Verify 5V power connection to I2C adapter |
| Garbled text | Verify I2C address matches your display |
| No I2C communication | Check SDA/SCL connections, install library |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| LCD | Liquid Crystal Display for text/info |
| I2C | Two-wire communication protocol |
| Adapter | Simplifies LCD wiring from 8 to 4 wires |
| setCursor() | Position cursor at specific location |
| Backlight | LED lighting for display visibility |

---

## 📚 Next Project

**Day 14 – Digital Counter 7-Segment**

Display numbers using seven-segment LED display!

---

## ⭐ Support

Give this repo a **⭐ Star** if you found it helpful!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
