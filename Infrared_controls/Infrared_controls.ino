/****************************************************************
*    _____                _                          __ _       *
*   / _  / __ _ _ __   __| | ___ _ __ ___ _ __ __ _ / _| |_     *
*   \// / / _` | '_ \ / _` |/ _ \ '__/ __| '__/ _` | |_| __|    *
*    / //\ (_| | | | | (_| |  __/ | | (__| | | (_| |  _| |_     *
*   /____/\__,_|_| |_|\__,_|\___|_|  \___|_|  \__,_|_|  \__     *
*                                                               *
*  Project: Infrared Controls                                   *
*  Runs On: Makeblock mBot (arduino uno)                        *
*                                                               *
****************************************************************/
#include <MeMCore.h>

MeIR ir; 
void setup()
{
    ir.begin();
    Serial.begin(9600);
    Serial.println("Infrared Receiver Decoder");
}

void loop()
{
    if(ir.decode())
    {
      uint32_t value = ir.value;
      Serial.print("Raw Value: ");
      Serial.println(value);
      value = value >> 16 & 0xff;
      Serial.print("Button Code: ");
      Serial.println(value);
      Serial.print("Button: ");
       switch(value)
        {
            case IR_BUTTON_A: Serial.println("A");break;
            case IR_BUTTON_B: Serial.println("B");break;
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
            default:break;
        }
    }
}
