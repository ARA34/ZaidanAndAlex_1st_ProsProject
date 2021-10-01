#include "main.h"
#include "claw.h"

void clawSet(int speed) {
  motorSet(5, -speed);//wrong port changed from 9 to 5
}
