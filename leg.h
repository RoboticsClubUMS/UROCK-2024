#ifndef LEG_H
#define LEG_H

#include <ESP32Servo.h>

int err[4][2] = {{5, 7}, {1, 1}, {1, 1}, {1, 1}};
//int invKinA[10] = {29, 16, 7, 3, 6, 15, 21, 25, 28, 29};
int invKinA[3] = {90, 94, 117};  
//int invKinB[10] = {29, 27, 30, 36, 45, 57, 54, 50, 44, 37};
int invKinB[3] = {26, 43, 40};

Servo LEG1S1;
Servo LEG1S2;

Servo LEG2S1;
Servo LEG2S2;

Servo LEG3S1;
Servo LEG3S2;

Servo LEG4S1;
Servo LEG4S2;

#define LEG1PIN1 15
#define LEG1PIN2 4

#define LEG2PIN1 13
#define LEG2PIN2 12

#define LEG3PIN1 22
#define LEG3PIN2 23

#define LEG4PIN1 33
#define LEG4PIN2 32

#define SERVO_MIN_PULSE 500
#define SERVO_MAX_PULSE 2500
#define SERVO_HERTZ 300

void setupLeg() {
  //ledcAttachChannel(LEG1PIN1, SERVO_HERTZ, 8, 0);
  //ledcAttachChannel(LEG1PIN2, SERVO_HERTZ, 8, 1);


  LEG1S1.setPeriodHertz(SERVO_HERTZ);
  LEG1S2.setPeriodHertz(SERVO_HERTZ);

  LEG2S1.setPeriodHertz(SERVO_HERTZ);
  LEG2S2.setPeriodHertz(SERVO_HERTZ);

  LEG3S1.setPeriodHertz(SERVO_HERTZ);
  LEG3S2.setPeriodHertz(SERVO_HERTZ);

  LEG4S1.setPeriodHertz(SERVO_HERTZ);
  LEG4S2.setPeriodHertz(SERVO_HERTZ);

  LEG1S1.attach(LEG1PIN1, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  LEG1S2.attach(LEG1PIN2, SERVO_MIN_PULSE, SERVO_MAX_PULSE);

  LEG2S1.attach(LEG2PIN1, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  LEG2S2.attach(LEG2PIN2, SERVO_MIN_PULSE, SERVO_MAX_PULSE);

  LEG3S1.attach(LEG3PIN1, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  LEG3S2.attach(LEG3PIN2, SERVO_MIN_PULSE, SERVO_MAX_PULSE);

  LEG4S1.attach(LEG4PIN1, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  LEG4S2.attach(LEG4PIN2, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
}

void L1Move(int index) {
  
  LEG1S1.write(invKinA[index] + err[0][0]);
  LEG1S2.write(invKinB[index] + err[0][1]);
}

void L2Move(int index) {
  LEG2S1.write(invKinA[index] + err[1][0]);
  LEG2S2.write(invKinB[index] + err[1][1]);
}

void L3Move(int index) {
  LEG3S1.write(invKinA[index] + err[2][0]);
  LEG3S2.write(invKinB[index] + err[2][1]);
}

void L4Move(int index) {
  LEG4S1.write(invKinA[index] + err[3][0]);
  LEG4S2.write(invKinB[index] + err[3][1]);
}
#endif
