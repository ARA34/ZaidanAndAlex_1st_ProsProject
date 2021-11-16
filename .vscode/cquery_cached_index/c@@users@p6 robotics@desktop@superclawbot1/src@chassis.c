#include "main.h"    // includes API.h and other headers
#include "chassis.h"

void chassisSet(int left, int right) {
  motorSet(1, left);
  motorSet(10, right);
}

void liftSet(int speed) {
  motorSet(4, -speed);
}

void elbowSet(int speed2) {
  motorSet(5, -speed2);
}
