#include "main.h"    // includes API.h and other headers
#include "claw.h"

void clawSet(int speed) {
  motorSet(5, -speed);//wrong port changed from 9 to 5
}
