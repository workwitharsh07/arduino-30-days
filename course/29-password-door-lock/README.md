# 🔐 Day 29 – Password Door Lock

Build a secure access control system with 4×4 keypad for password entry and electronic door lock.

**⏱️ Time:** 40-45 mins | **📊 Level:** ⭐⭐⭐⭐⭐ Advanced

---

## ✨ Features

- ⌨️ 4×4 matrix keypad input
- 🔐 Secure password validation
- 🔓 Servo motor door unlock
- 📊 OLED password display
- 🔔 Audio/visual feedback
- ⭐ Security integration

---

## 🎯 What You'll Learn

- Matrix keypad operation
- Password validation logic
- Secure access control
- User feedback systems
- Security applications
- Input validation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 1 |
| 4×4 Matrix Keypad | 1 |
| Servo Motor | 1 |
| OLED Display | 1 |
| Buzzer | 1 |
| LED (Red & Green) | 2 |
| 220Ω Resistor | 2 |
| Jumper Wires | 12 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| Pin 2 | Keypad Row 1 |
| Pin 3 | Keypad Row 2 |
| Pin 4 | Keypad Row 3 |
| Pin 5 | Keypad Row 4 |
| Pin 6 | Keypad Column 1 |
| Pin 7 | Keypad Column 2 |
| Pin 8 | Keypad Column 3 |
| Pin 9 | Keypad Column 4 |
| Pin 10 | Servo Signal |
| Pin 11 | Red LED (Denied) |
| Pin 12 | Green LED (Granted) |
| Pin 13 | Buzzer |
| A4 | OLED SDA |
| A5 | OLED SCL |

**⚠️ Important:** Install Keypad library from Arduino IDE. Servo red = VCC, brown = GND, orange = Signal.

---

## 💻 How It Works

### Initialize Keypad and Display
In setup(), Arduino initializes keypad library with correct pin assignments. OLED display initialized and shows welcome message.

### Create Secure Password Storage
Stored password defined as constant in code. Only Arduino knows this password. Password should be unique and kept secure.

### Accept Keypad Input
Inside main loop, Arduino monitors keypad for key presses. getKey() function retrieves pressed keys. Each key stored in password entry string.

### Display Asterisks for Security
As user enters password, each keystroke displays as asterisk instead of actual number. Prevents shoulder surfing and password observation.

### Validate Password When Complete
When user presses enter or after set number of digits, Arduino compares entered password with stored. If match, access granted.

### Provide Feedback
Correct password: Green LED on, servo unlocks, buzzer sounds. Wrong password: Red LED on, error buzzer tone.

---

## 🚀 Getting Started

1. Connect keypad rows to Pins 2-5
2. Connect keypad columns to Pins 6-9
3. Connect OLED to A4 & A5
4. Connect servo to Pin 10
5. Connect status LEDs & buzzer
6. Install Keypad library in Arduino IDE
7. Connect Arduino to computer
8. Load Password Door Lock sketch
9. Select **Tools → Board → Arduino UNO**
10. Upload code
11. Enter password on keypad!

---

## 💾 Source Code (PasswordLock.ino)

```cpp
#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Servo doorServo;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

String correctPassword = "1234";
String enteredPassword = "";

int redLED = 11;
int greenLED = 12;
int buzzerPin = 13;

void setup() {
  doorServo.attach(10);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10, 25);
  display.println("Enter Code");
  display.display();
  
  Serial.begin(9600);
  lockDoor();
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key == '#') {
      // Clear password
      enteredPassword = "";
      displayPassword("");
    } else if (key == '*') {
      // Submit password
      if (enteredPassword == correctPassword) {
        unlockDoor();
      } else {
        wrongPassword();
      }
      enteredPassword = "";
    } else {
      // Add to password
      enteredPassword += key;
      displayPassword(enteredPassword);
    }
  }
}

void displayPassword(String pwd) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Enter Password:");
  
  display.setTextSize(2);
  String display_pwd = "";
  for (int i = 0; i < pwd.length(); i++) {
    display_pwd += "*";
  }
  display.println(display_pwd);
  display.display();
}

void unlockDoor() {
  doorServo.write(90);
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  tone(buzzerPin, 1000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(20, 25);
  display.println("ACCESS OK");
  display.display();
  
  delay(3000);
  lockDoor();
}

void wrongPassword() {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  tone(buzzerPin, 200, 500);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10, 25);
  display.println("DENIED");
  display.display();
  
  delay(2000);
  displayPassword("");
}

void lockDoor() {
  doorServo.write(0);
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  noTone(buzzerPin);
}
```

---

## 📸 Expected Output

- ⌨️ Keypad presses show as asterisks
- ✅ Correct password (1234) → Green LED, servo unlocks
- ❌ Wrong password → Red LED, buzzer error
- 🔐 Door unlocks for 10 seconds then auto-locks
- 📊 OLED prompts for new password

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Change password
String correctPassword = "9876";

// Add multiple user passwords
String user1 = "1111";
String user2 = "2222";

// Log failed attempts
int failedAttempts = 0;
if (wrongPassword) failedAttempts++;

// Timing lock after failures
if (failedAttempts > 3) {
  systemLocked = true;
}

// Buzzer melody on success
playMelody();

// Add admin code
if (enteredPassword == "0000") {
  adminMode();
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Keypad doesn't register | Verify Keypad library installed |
| OLED shows nothing | Check I2C address & A4/A5 pins |
| Servo doesn't unlock | Verify servo to Pin 10 connection |
| No buzzer sound | Check buzzer to Pin 13 & GND |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| Keypad Matrix | 4×4 grid of buttons with row/column |
| Password Validation | Comparing entered with stored password |
| Access Control | Authentication system for authorization |
| User Feedback | Visual and audio indicators for results |
| Security | Protecting sensitive access with passwords |

---

## 📚 Next Project

➡️ **Day 30 – Ultimate Smart Living Hub** - Your capstone project!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
