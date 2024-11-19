#include <main.h>

int counter = 0;

bool flag = true;

void setup() {
  Serial.begin(115200);
  //setupGyro();
  
  setupLeg();
   


  //updateGyro();
}

void loop() {


  if (counter == 3) counter = 0;
  //updateGyro();
  //Serial.println(getAvgGyro());
  
  Serial.println(counter);
  L1Move(counter++);


  delay(200);


  // if gyro not offset
  // use this sequence
  /*
  L1Move(counter);

  delay(1000);

  if (flag && counter == 5) flag = false;
  if (!flag && counter == 0) flag = true;

  if (flag) {
    counter++;
  } else {
    counter--;
  }

*/


  // if ramp
  // use this sequence
  // put your main code here, to run repeatedly:
  /*
  if (angleDifference >= -5 && angleDifference <= 5) {
    Serial.println("You are on a straight line");
  } else if (angleDifference > 5 && angleDifference <= 15) {
    Serial.println("You are slightly left");
  } else if (angleDifference < -5 && angleDifference >= -15) {
    Serial.println("You are slightly right");
  } else if (angleDifference > 15) {
    Serial.println("You are too left");
  } else if (angleDifference < -15) {
    Serial.println("You are too right");
  }
*/

}
