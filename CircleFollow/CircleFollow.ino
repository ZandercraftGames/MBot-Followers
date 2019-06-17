/****************************************************************
*    _____                _                          __ _       *
*   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     *
*   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    *
*    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     *
*   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     *
*                                                               *
*  Project: Stay Inside Circle                                  *
*                                                               *
****************************************************************/

/**************** Global Variables *********************/
#include <MeMCore.h>
#include <Wire.h>
#include <SoftwareSerial.h>
MeLineFollower lineFinder(PORT_2);
MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
int moveSpeed = 200;
int turnSpeed = 250;
int randnum = 0;
boolean leftflag,rightflag;
int minSpeed = 45;
int factor = 23;

uint8_t mode = 0;

/************* End of Global Variables *****************/

/********************** Setup **************************/
void setup(){
    leftflag=false;
    rightflag=false;
    randomSeed(analogRead(0));
    Serial.begin(9600);
}
/****************** End of Setup **********************/

/********************** Loop **************************/
void loop() {
  int sensorState = lineFinder.readSensors();
  Serial.println(sensorState);
  if(sensorState==0){
    TurnLeft();  
  } else{
    TurnRight();
  }
}
/******************* End of Loop ***********************/

/**************** Moving Functions ********************/
void Forward(){
    MotorL.run(-moveSpeed);
    MotorR.run(moveSpeed);
}

void Backward(){
    MotorL.run(moveSpeed);
    MotorR.run(-moveSpeed);
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

void ChangeSpeed(int spd){
    moveSpeed = spd;
}
/*********** End of Moving Functions ***************/

/* Copyright(C) 2019 Zandercraft*/
