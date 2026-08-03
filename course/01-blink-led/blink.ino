/*
  ---------------------------------------------------------
  Project : Day 01 - Blink LED
  Course  : Arduino 30 Days Challenge
  Author  : LifeTronix
  Board   : Arduino UNO
  ---------------------------------------------------------
  Description:
  This project blinks an LED connected to digital Pin 13.
  The LED turns ON for 1 second and OFF for 1 second
  repeatedly, demonstrating the basics of digital output.
  ---------------------------------------------------------
*/

// Digital pin where the LED is connected
const int ledPin = 13;

void setup() {

  // Configure the LED pin as an OUTPUT
  pinMode(ledPin, OUTPUT);

}

void loop() {

  // Turn the LED ON by sending HIGH (5V)
  digitalWrite(ledPin, HIGH);

  // Keep the LED ON for 1 second
  delay(1000);

  // Turn the LED OFF by sending LOW (0V)
  digitalWrite(ledPin, LOW);

  // Keep the LED OFF for 1 second
  delay(1000);

  // The loop() function repeats forever,
  // creating a continuous blinking effect.
}