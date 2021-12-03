#include "main.h"
#include "home_elbow.h"
#include "chassis.h"
//fixed just switch the physical limit switch around


void home_Elbow(int homePosition2, Encoder the_encoder2) {

  int eValue2 = encoderGet(the_encoder2);
  //printf("homing started, stand by \n");
while(digitalRead(ELBOW_LIMIT_SWITCH) == 1)  {
  //printf("looking for limit switch\n");
  elbowSet(50);
}
elbowSet(0);
encoderReset(the_encoder2);
eValue2=encoderGet(the_encoder2);

while(eValue2 < homePosition2) {
  elbowSet(75);
  //printf("moving to home pos %d \n",eValue );
  if (eValue2 < homePosition2) {
    elbowSet(0);
  }
  eValue2=encoderGet(the_encoder2);
}


//turn on shoulder in neg direction

//wait unitll limitSwitch == 1 is no longer true
//stop shoulder motor
//reset sholderEncoder
//start while loop with condition sholderEncoder < homePosition(or another home position)
//turn on shouldMoter in pos direction
//wait untill sholderEncoder < homePosition (or other home position)
//stop sholderMotor (the shoulder joint is now "homed") }


  printf("homing of elbow complete, encoder should be 0 \n");
}
