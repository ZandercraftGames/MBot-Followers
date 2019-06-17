/****************************************************************
*    _____                _                          __ _       *
*   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     *
*   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    *
*    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     *
*   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     *
*                                                               *
*  Project: Simple Line/Circle Follower                         *
*                                                               *
****************************************************************/


/**************** Global Variables *********************/
#include <MeMCore.h>
#include <Wire.h>
MeLineFollower lineFinder(PORT_2);
MeUltrasonicSensor ultraSensor(PORT_3);
MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
int moveSpeed = 255;
int turnSpeed = 245;
int distance = 15;
boolean leftflag,rightflag;

uint8_t mode = 0;

/************* End of Global Variables *****************/


/********************** Setup **************************/
void setup(){
    leftflag=false;
    rightflag=false;
    randomSeed(analogRead(0));
}
/****************** End of Setup **********************/

/********************** Loop **************************/
void loop(){
    int sensorState = lineFinder.readSensors();
    switch(sensorState){
        case S1_IN_S2_IN:
            TurnLeft();
            break;
        case S1_IN_S2_OUT:
            TurnLeft();
            break;
        case S1_OUT_S2_IN:
            Forward();
            break;
        case S1_OUT_S2_OUT:
            TurnRight();
            break;
        default:
            break;
    }

    if(ultraSensor.distanceCm() < distance){
      Stop();
    } else{
    }
}
/******************* End of Loop ***********************/


/***************** Moving Functions *********************/
void Forward(){
    MotorL.run(-moveSpeed);
    MotorR.run(moveSpeed);
}

void TurnLeft(){
    MotorL.run(0);
    MotorR.run(turnSpeed);
}

void TurnRight(){
    MotorL.run(-turnSpeed);
    MotorR.run(0);
}

void Stop(){
    MotorL.run(0);
    MotorR.run(0);
}
