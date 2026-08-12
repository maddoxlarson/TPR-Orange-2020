#include "variables.h"

using namespace vex;

void turn(int left, int right, double angle){
  if (angle > 180) {
    lft.spin(reverse, left, rpm);
    rgt.spin(forward, right, rpm);

    waitUntil(gyro_value = angle);
  } else {
    lft.spin(forward, left, rpm);
    rgt.spin(reverse, right, rpm);

    waitUntil(gyro_value = angle);
  }
}

void drive(int left, int right, double lit, int inte, int sleep){
  lft.spin(directionType::undefined, left, rpm);
  rgt.spin(directionType::undefined, right, rpm);
  lift.rotateFor(lit, deg);
  intake.spin(directionType::undefined, inte, rpm);
  task::sleep(sleep);
}