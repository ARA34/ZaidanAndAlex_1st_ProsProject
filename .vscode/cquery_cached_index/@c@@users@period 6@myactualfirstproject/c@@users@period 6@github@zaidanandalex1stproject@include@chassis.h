#include "main.h" //includes  API and other headers


//sets the speeds of the left and right wheels of the chassis
void chassisSet(int left, int right) {
  motorSet(1, right);
  motorSet(10, left);
}

void liftSet(int speed) {
  motorSet(4,speed);
}
