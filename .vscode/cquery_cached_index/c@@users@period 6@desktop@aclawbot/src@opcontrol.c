#include "main.h"
//#include "shoulder.c"
#include "chassis.h"
//#include "forearm.c"

void operatorControl() {
	int power;
	int turn;
	int pot = 0;
	int count = 0;
	Encoder encoder;
	    // configure the pin that the limit switch is plugged into as an input
	    pinMode(LIMIT_SWITCH, INPUT);
	    encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);


  while (1) {
    power = joystickGetAnalog(1, 1); //vertial axis on left Joystick
    turn = joystickGetAnalog(1, 2); //horizontal axis on left joystick
		pot = analogRead(5);
		count = encoderGet(encoder);

		printf("the pot value %d \n", pot);
		printf("the encoder value %d \n", count);

		    encoderReset(encoder);


    chassisSet(power - turn, power + turn);

//-----------------------------------FOREARM  v


if(joystickGetDigital(1, 5, JOY_UP)) {
	foreSet(127);
}
	else if(joystickGetDigital(1, 5, JOY_DOWN)) {
	foreSet(-127);
}
	else {
	foreSet(0);
}
//---------------------------------} SHOULDER   V


if(joystickGetDigital(1, 6, JOY_UP)) {
	liftSet(127); //pressing up, so lift should go up
}
		else if(joystickGetDigital(1, 6, JOY_DOWN)) {
			liftSet(-127); //pressing down so lift should go down
		}

		else {
			liftSet(0); //no buttons are pressed, stop lift
		}
		//--------------------}  SHOULDER ^
    delay(20);

  }
}
