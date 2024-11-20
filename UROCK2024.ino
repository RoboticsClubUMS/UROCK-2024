#include <main.h>

int counter = 0;
int counter_two = 1;

bool flag = true;

void setup() {
  Serial.begin(115200);
  
  // SETUP GYRO
  setupGyro();

  // SETUP SERVO
  setupLeg();

  // SETUP OBJECT DETECTOR
  setupOBJD();

  updateGyro();
}

void loop() {
  updateGyro();
  getOBJD();

  if (counter == 3) counter = 0;
  if (counter_two == 3) counter = 0;

    if (isRamp()) {
      // MOVEMENT RAMP
      // IF TOO SENSITIVE, EITHER DUMP THE SENSORS OR CALIBRATE AT FINEST
    } else {
      if (getAvgGyro() > 20) {
  // MOVEMENT TO THE LEFT
  // WORK WITH MECHA TO GET THE ANGLE
      } else if (getAvgGyro() < -20) {
  // MOVEMENT TO THE RIGHT
  // WORK WITH MECHA TO GET THE ANGLE
      } else {
      // NORMAL MOVEMENT
        L1Move(counter);
        L2Move(counter_two);
        L3Move(counter);
        L4Move(counter_two);
      }
    }

  counter++;
  counter_two++;
  delay(200);

}
