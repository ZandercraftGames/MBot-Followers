/****************************************************************
*    _____                _                          __ _       *
*   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     *
*   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    *
*    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     *
*   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     *
*                                                               *
*  Project: Line/Circle Follower                                *
*  Runs On: Makeblock mBot (arduino uno)                        *
*                                                               *
****************************************************************/


/**************** Global Variables *********************/
#include <MeMCore.h>                    // include MBot library for arduino uno
MeLineFollower lineFinder(PORT_2);      // define port for line finder
MeUltrasonicSensor ultraSensor(PORT_3); // define port for ultrasonic sensor
MeDCMotor MotorL(M1);                   // define motor 1 as MotorL for easier readability
MeDCMotor MotorR(M2);                   // define motor 2 as MotorR for easier readability
int moveSpeed = 255;                    // define the speed the robot runs at (max: 255)
int turnSpeed = 245;                    // define the speed the robot turns at (optimal: moveSpeed-10)
int distance = 15;                      // define distance robot should stay away from objects in front of it
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
    int sensorState = lineFinder.readSensors(); // define the sensorState variable
    if(ultraSensor.distanceCm() < distance){
      Stop();
    } else{
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
    }
}
/******************* End of Loop ***********************/


/***************** Moving Functions ********************/
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
/************* End of Moving Functions *****************/
