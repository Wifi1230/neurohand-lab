#include <Arduino.h>

constexpr int kActivityLedPin = 4;

void setup() {
  pinMode(kActivityLedPin, OUTPUT);
}

void loop() {
  digitalWrite(kActivityLedPin, HIGH);
  delay(500);
  digitalWrite(kActivityLedPin, LOW);
  delay(500);
}
