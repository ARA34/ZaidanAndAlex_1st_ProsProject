/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "chassis.h"
#include "claw.h"
//hello this is just a comment...


/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 int joystickGetAnalog( unsigned char joystick, // the joystick slot to check(1 f/or master, 2 for partner)
	 											unsigned char axis // one of the joystick channels on a VEX jotstick: 1, 2, 3, 4, ACCEL_X, ACCEL_Y
 );

 void motorSet (unsigned char channel,  // motor channel to set from 1-10
 								int speed // new signed speed -127 is full reverse, 127 is full forward, 0 off
							);
Encoder encoder;
void initialize() {
  encoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);
}

void switchFunction () {
  //do work..
  if (digitalRead(LIMIT_SWITCH)==LOW) {
    //..
  }
  //..
}

void encoderFuncton() {
  //dowork
  int counts = encoderGet(encoder);

    //digitalRead() will return low if pressed and high if released
  if (digitalRead(LIMIT_SWITCH)==LOW) {
    //..
  }
  encoderReset(encoder);
  //encoderReset(encoder);
  //..
}


void operatorControl() {
  int pot = 0;
  int power, turn;
  while(1) {
  		power = joystickGetAnalog(1,1); //vertical axis on right joystick
  		turn = joystickGetAnalog(1,2); //horizontal axis on right
      pot = analogRead(5);
      printf("the pot value %d \n", pot);
      chassisSet(power - turn, power + turn);
  		//motorSet(1, power - turn);// right wheels
  		//motorSet(10,power + turn); // left wheels
      clawSet(joystickGetAnalog(1, 4));

      if (joystickGetAnalog(1,6), JOY_UP) {
        liftSet(1);
      }
      else if (joystickGetAnalog(1,6), JOY_DOWN) {
        liftSet(-1);
      }
      else {
        liftSet(0);
      }

  		delay(200);

  }
}
