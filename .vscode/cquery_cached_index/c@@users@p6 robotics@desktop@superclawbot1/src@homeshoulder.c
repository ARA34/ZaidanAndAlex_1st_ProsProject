#include "main.h"
#include "homeshoulder.h"
#include "chassis.h"



void homeShoulder(int homePosition, Encoder the_encoder) {

  int eValue = encoderGet(the_encoder);
  //printf("homing started, stand by \n");
while(digitalRead(LIMIT_SWITCH) == 1)  {
  //printf("looking for limit switch\n");
  liftSet(-50);
}
liftSet(0);
encoderReset(the_encoder);
eValue=encoderGet(the_encoder);

while(eValue < homePosition) {
  liftSet(100);
  //printf("moving to home pos %d \n",eValue );
  if (eValue < homePosition) {
    liftSet(0);
  }
  eValue=encoderGet(the_encoder);
}


//turn on shoulder in neg direction

//wait unitll limitSwitch == 1 is no longer true
//stop shoulder motor
//reset sholderEncoder
//start while loop with condition sholderEncoder < homePosition(or another home position)
//turn on shouldMoter in pos direction
//wait untill sholderEncoder < homePosition (or other home position)
//stop sholderMotor (the shoulder joint is now "homed") }


  printf("homing of shoulder complete, encoder should be 0 \n");
}
