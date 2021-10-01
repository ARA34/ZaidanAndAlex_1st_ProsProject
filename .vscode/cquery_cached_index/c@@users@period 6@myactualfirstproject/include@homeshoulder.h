#include "main.h"
#include "chassis.h"
Encoder sEncoder;
void initialize1() {
  sEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);
}
//int sEncoderValue = encoderGet(sEncoder);


void homeShoulder(int homePosition) {
  printf("homing started, stand by \n");

// start a while loop with the condition limitSwitch == 1
if (LIMIT_SWITCH == 1) {
  liftSet(-1);
} else {
  liftSet(0);//change back to while loop
}

if(encoderGet(sEncoder) < homePosition) {
  liftSet(1);
} else {
  liftSet(0);
}
/*while(LIMIT_SWITCH == 1) {
  liftSet(-1);
}
liftSet(0);

while(encoderGet(sEncoder) < homePosition) {
  liftSet(1);
}
liftSet(0);*/
//turn on shoulder in neg direction

//wait unitll limitSwitch == 1 is no longer true
//stop shoulder motor
//reset sholderEncoder
//start while loop with condition sholderEncoder < homePosition(or another home position)
//turn on shouldMoter in pos direction
//wait untill sholderEncoder < homePosition (or other home position)
//stop sholderMotor (the shoulder joint is now "homed") }

  printf("homing of shoulder complete \n");
}
