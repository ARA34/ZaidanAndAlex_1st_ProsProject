#include "main.h"
void homeShoulder(int homePosition) {
  printf("homing started, stand by \n");

// start a while loop with the condition limitSwitch == 1
while(LIMIT_SWITCH == 1) {

}
//turn on shoulder in neg direction
//wait unitll limitSwitch == 1 is no longer true
//stop shoulder motor
//reset sholderEncoder
//start while loop with condition sholderEncoder < homePosition(or another home position)
//turn on shouldMoter in pos direction
//wait untill sholderEncoder < homePosition (or other home position)
//stop sholderMotor (the shoulder joint is now "homed") }

  printf("homing complete \n");
}
