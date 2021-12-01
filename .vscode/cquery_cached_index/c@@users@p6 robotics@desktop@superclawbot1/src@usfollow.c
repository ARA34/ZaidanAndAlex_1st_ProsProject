#include "main.h"
/*
NO WHILE LOOP ONLY WHEN BUTTON IS HELD DOWN
Read ultrasonic sensor(once)
print value of ultrasonic sensor to terminal
if(ultrasonic > targetfollowdist) {
drive forward
} else if(ultrasonic < targetfollowdist) {
drive backwards
} else {
stop
}
*/

distance = ultrasonicGet(frontSonar);
printf("fronsonar: \n %d", distance);

if(distance > 20) {
  chassisSet(50,50);
} else if(distance < 16) {
  chassisSet(-50,-50);
} else {
  chassisSet(0,0);
}
