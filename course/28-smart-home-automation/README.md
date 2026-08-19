# 🏠 Day 28 – Smart Home Automation

Build a complete smart home system controlling lights, fans, and appliances based on multiple sensors and user input.

**⏱️ Time:** 40-50 mins | **📊 Level:** ⭐⭐⭐⭐⭐ Advanced

---

## ✨ Features

- 💡 Automatic light control
- 💨 Temperature-based fan control
- 🔌 Relay appliance switching
- 🎮 Manual override buttons
- 📊 Real-time OLED display
- 🔄 Multi-sensor coordination

---

## 🎯 What You'll Learn

- System integration design
- Multi-sensor coordination
- Automated device control
- User interface design
- Smart home architecture
- Priority logic implementation

---

## 🛠️ Hardware Required

| Component | Qty |
|-----------|:---:|
| Arduino UNO | 1 |
| Breadboard | 2 |
| LDR (Light Sensor) | 1 |
| DHT11 Sensor | 1 |
| 4-Channel Relay Module | 1 |
| OLED Display | 1 |
| Push Buttons | 3 |
| 10kΩ Resistor | 3 |
| 220Ω Resistor | 3 |
| Jumper Wires | 20 |
| USB Type-B Cable | 1 |

---

## 🔌 Circuit Connections

| Arduino Pin | Component |
|-------------|-----------|
| 5V | LDR + DHT11 VCC + Relay VCC + OLED VCC |
| GND | All GND connections |
| Pin A0 | LDR (voltage divider with 10kΩ) |
| Pin 7 | DHT11 DATA (pull-up to 5V) |
| Pin 2 | Relay IN1 (Lights) |
| Pin 3 | Relay IN2 (Fan) |
| Pin 8 | Button 1 (Manual light) |
| Pin 9 | Button 2 (Manual fan) |
| Pin 10 | Button 3 (Manual mode) |
| A4 | OLED SDA |
| A5 | OLED SCL |

**⚠️ Important:** Buttons need 10kΩ pull-up resistors. LDR needs voltage divider configuration.

---

## 💻 How It Works

### Initialize All Subsystems
In setup(), Arduino initializes OLED display library with I2C address. DHT11 sensor library initialized. All relay control pins set as outputs. Button pins set as INPUT_PULLUP.

### Read All Sensor Inputs Continuously
Inside main loop, Arduino reads LDR on A0, DHT11 temperature on Pin 7, and checks button presses on Pins 8-10. All readings collected within 100ms.

### Apply Automatic Light Control
LDR reading checked against brightness threshold. If light levels below threshold, relay activates lights automatically. If above, relay deactivates lights.

### Apply Automatic Fan Control
DHT11 temperature checked against comfort threshold. If temperature above threshold, relay activates fan. If below, relay stops fan.

### Handle Manual Override Controls
When manual control button pressed, Arduino immediately activates or deactivates device. Manual control takes priority over automatic.

### Display Real-Time System Status
OLED display continuously updates showing temperature, humidity, light level, and status of all devices. Users can view complete system at any time.

---

## 🚀 Getting Started

1. Connect all sensors to correct Arduino pins
2. Connect relay module for lights and fan
3. Mount push buttons for manual control
4. Connect OLED display via I2C
5. Connect Arduino to computer
6. Load Smart Home Automation sketch
7. Select **Tools → Board → Arduino UNO**
8. Upload code
9. Test automatic and manual modes!

---

## 💾 Source Code (SmartHome.ino)

```cpp
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int ldrPin = A0;
int relayLight = 2;
int relayFan = 3;
int buttonLight = 8;
int buttonFan = 9;
int buttonMode = 10;

boolean autoMode = true;
boolean lightOn = false;
boolean fanOn = false;

void setup() {
  pinMode(relayLight, OUTPUT);
  pinMode(relayFan, OUTPUT);
  pinMode(buttonLight, INPUT_PULLUP);
  pinMode(buttonFan, INPUT_PULLUP);
  pinMode(buttonMode, INPUT_PULLUP);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  
  digitalWrite(relayLight, LOW);
  digitalWrite(relayFan, LOW);
  
  Serial.begin(9600);
}

void loop() {
  // Read sensors
  int lightLevel = analogRead(ldrPin);
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Check manual buttons
  if (digitalRead(buttonLight) == LOW) {
    delay(50);
    lightOn = !lightOn;
    digitalWrite(relayLight, lightOn ? HIGH : LOW);
    autoMode = false;
  }
  
  if (digitalRead(buttonFan) == LOW) {
    delay(50);
    fanOn = !fanOn;
    digitalWrite(relayFan, fanOn ? HIGH : LOW);
    autoMode = false;
  }
  
  // Auto mode
  if (autoMode) {
    if (lightLevel < 400) {
      digitalWrite(relayLight, HIGH);
      lightOn = true;
    } else {
      digitalWrite(relayLight, LOW);
      lightOn = false;
    }
    
    if (temp > 28) {
      digitalWrite(relayFan, HIGH);
      fanOn = true;
    } else {
      digitalWrite(relayFan, LOW);
      fanOn = false;
    }
  }
  
  // Display information
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.println(temp);
  display.print("Humidity: ");
  display.println(humidity);
  display.print("Light: ");
  display.println(lightLevel);
  
  display.print("Lights: ");
  display.println(lightOn ? "ON" : "OFF");
  display.print("Fan: ");
  display.println(fanOn ? "ON" : "OFF");
  display.print("Mode: ");
  display.println(autoMode ? "AUTO" : "MANUAL");
  
  display.display();
  
  delay(1000);
}
```

---

## 📸 Expected Output

- 📊 OLED displays all sensor readings
- 🌙 Sun sets → Lights automatically ON
- 🌡️ Temperature rises → Fan automatically ON
- 🔘 Button press → Manual override active
- 🔄 Seamless auto/manual switching
- 💡 Real-time status display

---

## ⚙️ Experiments

Try these modifications:

```cpp
// Add motion sensor for security
if (motionDetected) {
  lights_ON();
}

// Create time-based scheduling
if (hour > 18) {
  autoLightsON();
}

// Add energy monitoring
totalPower = calculatePower();

// Build priority logic
if (emergency) {
  allDevicesOFF();
  buzzerON();
}

// Temperature alerts
if (temp > 40) {
  fanMaxSpeed();
  alertUser();
}
```

---

## ⚠️ Troubleshooting

| Problem | Solution |
|---------|----------|
| Lights don't auto-activate | Calibrate LDR threshold in code |
| Fan doesn't respond to temp | Verify DHT11 & relay connections |
| Buttons don't work | Check Pins 8-10 with pull-up resistors |
| OLED shows old data | Increase refresh rate & clear display |

---

## 🎓 Key Concepts

| Term | Meaning |
|------|---------|
| System Integration | Combining multiple components |
| Multi-sensor | Reading from multiple input devices |
| Automation Logic | Decision-making for device control |
| Priority System | Determining action precedence |
| User Override | Manual control over automatic systems |

---

## 📚 Next Project

➡️ **Day 29 – Password Door Lock** - Secure access control!

---

<p align="center">
Made with ❤️ by <strong>LifeTronix</strong>
</p>
