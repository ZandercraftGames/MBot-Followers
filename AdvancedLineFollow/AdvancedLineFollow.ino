/****************************************************************
*    _____                _                          __ _       *
*   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     *
*   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    *
*    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     *
*   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     *
*                                                               *
*  Project: Advanced Line/Circle Follower With Remote Control   *
*  Runs On: Makeblock mBot (arduino uno)                        *
*                                                               *
****************************************************************/
#include <MeMCore.h>
MeLineFollower lineFinder(PORT_2);      // define port for line finder
MeUltrasonicSensor ultraSensor(PORT_3); // define port for ultrasonic sensor
MeDCMotor MotorL(M1);                   // define motor 1 as MotorL for easier readability
MeDCMotor MotorR(M2);                   // define motor 2 as MotorR for easier readability
int moveSpeed = 255;                    // define the speed the robot runs at (max: 255)
int turnSpeed = 245;                    // define the speed the robot turns at (optimal: moveSpeed-10)
int distance = 15;                      // define distance robot should stay away from objects in front of it
int buttonmode = 1;                     // do not change
boolean leftflag,rightflag;
uint8_t mode = 0;
MeIR ir; 
//int value = 0;
void setup()
{
    leftflag=false;
    rightflag=false;
    randomSeed(analogRead(0));
    ir.begin();
    Serial.begin(9600);
    Serial.println("Serial connection successfully established.");
    Intro();
}

void loop()
{
    int sensorState = lineFinder.readSensors(); // define the sensorState variable
//    Serial.println(value);
    if(ir.decode()){
      uint32_t value = ir.value;
      value = value >> 16 & 0xff;
       switch(value){
            case IR_BUTTON_A: 
              Serial.println("Button A Pressed: Line follow mode activated.");
              buttonmode = 0;
              break;
            case IR_BUTTON_B: 
              Serial.println("Button B Pressed: Break mode activated.");
              buttonmode = 1;
              break;
            case IR_BUTTON_C:
              buttonmode = 2;
              break;
            case IR_BUTTON_D: 
              buttonmode = 3;
              break;
            case IR_BUTTON_E: 
              buttonmode = 4;
              break;
            case IR_BUTTON_F: 
              buttonmode = 5;
              break;
            case IR_BUTTON_SETTING : 
              buttonmode = 6;
              break;
            case IR_BUTTON_LEFT: 
              buttonmode = 7;
              break;
            case IR_BUTTON_RIGHT: 
              buttonmode = 8;
              break;
            case IR_BUTTON_UP: 
              buttonmode = 9;
              break;
            case IR_BUTTON_DOWN: 
              buttonmode = 10;
              break;
            case IR_BUTTON_0: 
              buttonmode = 11;
              break;
            case IR_BUTTON_1: 
              buttonmode = 12;
              break;
            case IR_BUTTON_2: 
              buttonmode = 13;
              break;
            case IR_BUTTON_3: 
              buttonmode = 14;
              break;
            case IR_BUTTON_4: 
              buttonmode = 15;
              break;
            case IR_BUTTON_5: 
              buttonmode = 16;
              break;
            case IR_BUTTON_6: 
              buttonmode = 17;
              break;
            case IR_BUTTON_7: 
              buttonmode = 18;
              break;
            case IR_BUTTON_8: 
              buttonmode = 19;
              break;
            case IR_BUTTON_9: 
              buttonmode = 20;
              break;
            default:
              break;
        }
    }
  switch(buttonmode){
    case 0:
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
      break;
    case 1:
      Stop();
      break;
    default:
      Stop();
      break;
  }
}


/*void loop(){
    int sensorState = lineFinder.readSensors(); // define the sensorState variable
      if(ir.decode()){
      uint32_t value = ir.value;
      switch(value)
        {
            case IR_BUTTON_A: 
            Serial.println("A");
            buttonmode = 0;
            break;
            case IR_BUTTON_B: 
            Serial.println("B");
            buttonmode = 1;
            break;
            case IR_BUTTON_C: Serial.println("C");break;
            case IR_BUTTON_D: Serial.println("D");break;
            case IR_BUTTON_E: Serial.println("E");break;
            case IR_BUTTON_F: Serial.println("F");break;
            case IR_BUTTON_SETTING : Serial.println("Setting");break;
            case IR_BUTTON_LEFT: Serial.println("Left");break;
            case IR_BUTTON_RIGHT: Serial.println("Right");break;
            case IR_BUTTON_UP: Serial.println("Up");break;
            case IR_BUTTON_DOWN: Serial.println("Down");break;
            case IR_BUTTON_0: Serial.println("0");break;
            case IR_BUTTON_1: Serial.println("1");break;
            case IR_BUTTON_2: Serial.println("2");break;
            case IR_BUTTON_3: Serial.println("3");break;
            case IR_BUTTON_4: Serial.println("4");break;
            case IR_BUTTON_5: Serial.println("5");break;
            case IR_BUTTON_6: Serial.println("6");break;
            case IR_BUTTON_7: Serial.println("7");break;
            case IR_BUTTON_8: Serial.println("8");break;
            case IR_BUTTON_9: Serial.println("9");break;
            default:
            break;
        }
    }
}*/

void Intro(){
  Serial.println("    _____                _                          __ _       ");
  Serial.println("   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     ");
  Serial.println("   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    ");
  Serial.println("    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     ");
  Serial.println("   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     ");
  Serial.println("                                                               ");
  Serial.println("  Project: Advanced Line/Circle Follower With Remote Control   ");
  Serial.println("  Runs On: Makeblock mBot (arduino uno)                        ");
  Serial.println("                                                               ");
  Serial.println("---------------------------------------------------------------");
  Serial.println("                                                               ");
}

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
