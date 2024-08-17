#include "MotorControler.h"
#include "Arduino.h"


MotorControler::MotorControler(const int motor1Pin1, const int motor2Pin2, const int motor3Pin3, const int motor4Pin4, const int enalePina, const int enblePinb, float motorConstA, float motorConstB) {
  _motorConstA_m = motorConstA;
  _motorConstB_m = motorConstB;
  _motor1Pin1_m = motor1Pin1;
  _motor2Pin2_m = motor2Pin2;
  _motor3Pin3_m = motor3Pin3;
  _motor4Pin4_m = motor4Pin4;
  _enblePinb_m = enblePinb;
  _enalePina_m = enalePina;


  pinMode(_motor1Pin1_m, OUTPUT);
  pinMode(_motor2Pin2_m, OUTPUT);
  pinMode(_motor3Pin3_m, OUTPUT);
  pinMode(_motor4Pin4_m, OUTPUT);
  pinMode(_enalePina_m, OUTPUT);
  pinMode(_enblePinb_m, OUTPUT);

}


void MotorControler::move(int leftSpeed_m, int rightSpeed_m, int minabsSpeed_m) {
  if (rightSpeed_m < 0)
  {
    rightSpeed_m = min(rightSpeed_m, -1 * minabsSpeed_m);
    rightSpeed_m = max(rightSpeed_m, -255);
  }
  else if (rightSpeed_m > 0)
  {
    rightSpeed_m = max(rightSpeed_m, minabsSpeed_m);
    rightSpeed_m = min(rightSpeed_m, 255);
  }

  int realRightSpeed_m = map(abs(rightSpeed_m), 0, 255, minabsSpeed_m, 255);
  if (leftSpeed_m < 0)
  {
    leftSpeed_m = min(leftSpeed_m, -1 * minabsSpeed_m);
    leftSpeed_m = max(leftSpeed_m, -255);
  }
  else if (leftSpeed_m > 0)
  {
    leftSpeed_m = max(leftSpeed_m, minabsSpeed_m);
    leftSpeed_m = min(leftSpeed_m, 255);
  }

  int realLeftSpeed_m = map(abs(leftSpeed_m), 0, 255, minabsSpeed_m, 255);
  digitalWrite(_motor1Pin1_m, leftSpeed_m  > 0 ? HIGH : LOW);
  digitalWrite(_motor2Pin2_m, leftSpeed_m  > 0 ? LOW : HIGH);
  digitalWrite(_motor3Pin3_m, rightSpeed_m > 0 ? HIGH : LOW);
  digitalWrite(_motor4Pin4_m, rightSpeed_m > 0 ? LOW : HIGH);

  analogWrite(_enalePina_m, realRightSpeed_m *  _motorConstA_m);
  analogWrite(_enblePinb_m, realLeftSpeed_m *  _motorConstB_m);

}

void MotorControler::move(int speed , int minabsSpeed_m)
{
  int direction = 1;
  if (speed < 0)
  {
    direction = -1;
    speed = min(speed, -1 * minabsSpeed_m);
    speed = max(speed, -255);
  }
  else
  {
    speed = max(speed,  minabsSpeed_m);
    speed = max(speed,  255);
  }
  if (speed = _currentSpeed_m)return;

  int realSpeed_m = max(minabsSpeed_m, abs(speed));
  digitalWrite(_motor1Pin1_m, speed  > 0 ? HIGH : LOW);
  digitalWrite(_motor2Pin2_m, speed  > 0 ? LOW : HIGH);
  digitalWrite(_motor3Pin3_m, speed  > 0 ? HIGH : LOW);
  digitalWrite(_motor4Pin4_m, speed  > 0 ? LOW : HIGH);

  analogWrite(_enalePina_m, realSpeed_m *  _motorConstA_m);
  analogWrite(_enblePinb_m, realSpeed_m *  _motorConstB_m);
  _currentSpeed_m = speed;
}

void MotorControler::turnleft(int speed , bool kick_m)
{
  digitalWrite(_motor1Pin1_m, HIGH);
  digitalWrite(_motor2Pin2_m, LOW);
  digitalWrite(_motor3Pin3_m, LOW);
  digitalWrite(_motor4Pin4_m, HIGH);
  if (kick_m)
  {
    analogWrite(_enalePina_m, 255);
    analogWrite(_enblePinb_m, 255);
    delay(100);
  }
  analogWrite(_enalePina_m, speed * _motorConstA_m);
  analogWrite(_enblePinb_m, speed * _motorConstB_m);
}

void MotorControler::turnright(int speed, bool kick_m)
{
  digitalWrite(_motor1Pin1_m, LOW);
  digitalWrite(_motor2Pin2_m, HIGH);
  digitalWrite(_motor3Pin3_m, HIGH);
  digitalWrite(_motor4Pin4_m, LOW);
  if (kick_m)
  {
    analogWrite(_enalePina_m, 255);
    analogWrite(_enblePinb_m, 255);
    delay(100);
  }
  analogWrite(_enalePina_m, speed * _motorConstA_m);
  analogWrite(_enblePinb_m, speed * _motorConstB_m);
}

void MotorControler::stopmove()
{
  digitalWrite(_motor1Pin1_m, LOW);
  digitalWrite(_motor2Pin2_m, LOW);
  digitalWrite(_motor3Pin3_m, LOW);
  digitalWrite(_motor4Pin4_m, LOW);
  digitalWrite(_enalePina_m, LOW);
  digitalWrite(_enblePinb_m, LOW);
  _currentSpeed_m = 0;
}
