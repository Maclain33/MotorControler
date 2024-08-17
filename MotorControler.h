#ifndef MotorControler_H
#define MotorControler_H
#include "Arduino.h"

class MotorControler {
  private:
    int _motor1Pin1_m;
    int _motor2Pin2_m;
    int _motor3Pin3_m;
    int _motor4Pin4_m;
    int _enalePina_m;
    int _enblePinb_m;
    float _motorConstA_m;
    float _motorConstB_m;
    int _currentSpeed_m;
  public:
    MotorControler(const int motor1Pin1, const int motor2Pin2, const int motor3Pin3, const int motor4Pin4, const int enalePina, const int enalePinb, float motorConstA, float motorConstB);
    void move(int leftSpeed_m, int rightSpeed_m, int minabsSpeed_m);
    void move(int speed);
    void move(int speed, int minabsSpeed_m);
    void turnright(int speed, bool kick_m);
    void turnleft(int speed, bool kick_m);
    void stopmove();

};
#endif
