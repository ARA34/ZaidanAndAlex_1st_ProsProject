 /** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "claw.h"
#include "homeshoulder.h"
//#include "project6.h"
#include "chassis.h"
/*hello this is just a comment... / notes for me
Language: C
Functions:
liftSet(angle)
elbowSet(angle)




*/
/*-------------------------------PORTS------------------------------------------

SHOULDER = 4

*/


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
 //int boolean = 1;

 void holdShoulderAt(int targetPos, Encoder shoulderEncoder) { //target degree
   //Encoder shoulderEncoder;
   //shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, false);

   int Kp = 2;
   int maxp = 127;
   int error;
   int output;

   while(true) {
     error = targetPos - encoderGet(shoulderEncoder);
     output = Kp * error;
     if(abs(error) < maxp) {
       liftSet(output);
     }else {
       liftSet(output / (abs(output) * maxp));
       encoderReset(shoulderEncoder);
     }
   }
   }

   void randomFunction() {
     for(int i = 0; i > 10; i ++) {
       printf("%d \n", i);
     }
   }

   void project6(int repetitions, Encoder shoulder_encoder, Encoder elbow_encoder) {
     printf("project6 starting");
     for(int count = 0; count > repetitions; count ++) {
       printf("Count:  %d \n", count);

       liftSet(encoderGet(shoulder_encoder) + count);
       elbowSet(encoderGet(elbow_encoder) + count);
     }
   }

void operatorControl() {
  int power, turn;
  Encoder sEncoder;
  Encoder eEncoder;
  sEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
  eEncoder = encoderInit(FORE_TOP_PORT, FORE_BOTTOM_PORT, true);
//joystickGetAnalog(unsigned char joystick, unsigned char axis)
  //printf("before the while loop in opcontrol \n");
  while(1) {
    //printf("Hello World! \n");
    //printf("Encoder value is at: %d \n", encoderGet(sEncoder));
  // printf("hello main loop print \n");
    //holdShoulderAt(50);
  		power = joystickGetAnalog(1,1); //vertical axis on right joystick
  		turn = joystickGetAnalog(1,2); //horizontal axis on right
      chassisSet(power - turn, power + turn);
      //printf("the pot value %d \n", pot);
      //chassisSet(power - turn, power + turn);
  		//motorSet(1 {}, power - turn);// right wheels
  		//motorSet(10,power + turn); // left wheels
      //clawSet(joystickGetAnalog(1, 4));




      if (joystickGetDigital(1,6, JOY_UP)) {
        liftSet(127);
        //printf("1 \n");
      }
      else if (joystickGetDigital(1,6, JOY_DOWN)) {
        liftSet(-127);
        //printf("2 \n");
      }
      else {//if not moving then dont move
        liftSet(0);
        //printf("3 \n");
      }
      if(joystickGetDigital(1,8, JOY_RIGHT )) {
        //printf("calling holdShoulderAt \n");
        //holdShoulderAt(50, sEncoder);
        printf("Calling homeshoulder \n");
        homeShoulder(50);
        //project6();
      }
      while(joystickGetDigital(1, 8, JOY_UP)) {
        //printf("Encoder value is at: %d \n", encoderGet(sEncoder));
      }
      if(joystickGetDigital(1,8,JOY_LEFT)) {
        //printf("test \n");
      }
      if (joystickGetDigital(1,8, JOY_DOWN)) {
        //boolean = 0;
      }
      if (joystickGetDigital(1, 8,JOY_UP)) {
        project6(5, sEncoder, eEncoder);
      }

      if(joystickGetDigital(1,7, JOY_UP)) {
        printf("Shoulder Encoder is at: %d \n", encoderGet(sEncoder));
      }
        //printf("Encoder value is at: %d \n", encoderGet(sEncoder));
        //printf("Calling homeshoulder its commented out rn tho \n");
      //commenting out for now  homeShoulder(50);



  		delay(200);

  }
}
