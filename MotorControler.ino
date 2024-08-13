#include "Arduino.h"
int speed1 = 1.5;
float motorConstA = 26;
float motorConstB = 26;

// Define motor pins
const int motor1Pin1 = 6;
const int motor2Pin2 = 7;
const int motor3Pin3 = 8;
const int motor4Pin4 = 9;
const int enalePina = 5;
const int enblePinb = 10;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin3, OUTPUT);
  pinMode(motor4Pin4, OUTPUT);
  pinMode(enalePina, OUTPUT);
  pinMode(enblePinb, OUTPUT);

  // Set initial speed
  analogWrite(enalePina, 255);
  analogWrite(enblePinb, 255);
}

void loop() {
  // Move forward
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin3, HIGH);
  digitalWrite(motor4Pin4, LOW);
  delay(200);

  // Move backward
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin3, LOW);
  digitalWrite(motor4Pin4, HIGH);
  delay(200);

  // Turn right
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin3, LOW);
  digitalWrite(motor4Pin4, HIGH);
  delay(100);

  // Turn left
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor3Pin3, HIGH);
  digitalWrite(motor4Pin4, LOW);
  delay(100);
}
