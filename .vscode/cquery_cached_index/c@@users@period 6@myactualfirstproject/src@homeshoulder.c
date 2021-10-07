#include "main.h"
#include "homeshoulder.h"
#include "chassis.h" 



void homeShoulder(int homePosition) {
  Encoder sEncoder;

  sEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);

  int eValue = encoderGet(sEncoder);
  printf("homing started, stand by \n");

// start a while loop with the condition limitSwitch == 1
/*if (LIMIT_SWITCH == 1) {
  liftSet(-1);
} else {
  liftSet(0);//change back to while loop
}

if(encoderGet(sEncoder) < homePosition) {
  liftSet(1);
} else {
  liftSet(0);
}*/
while(digitalRead(LIMIT_SWITCH) == 1)  {
  printf("looking for limit switch\n");
  liftSet(-50);
}
liftSet(0);
encoderReset(sEncoder);
eValue=encoderGet(sEncoder);

while(eValue < homePosition) {
  liftSet(50);
  printf("moving to home pos %d \n",eValue );
  if (eValue > homePosition) {
    liftSet(0);
  }
  eValue=encoderGet(sEncoder);
}

/*while(1) {
  liftSet(-1);
  if (LIMIT_SWITCH != 1) {
    liftSet(0);
    encoderReset(sEncoder);
  }
  if (encoderGet(sEncoder < homePosition)) {
    liftSet(1);
  }
}
liftSet(0);
//
liftSet(-1);
while (LIMIT_SWITCH != 1) {
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
