#include "PWM.h"

PWM:: PWM(int pin)
{
pinNumber=pin;
softPwmCreate(pinNumber,0,100);
}

PWM::~PWM()
{

}

void PWM:: motor_on()
{
    softPwmWrite(pinNumber,70);
}


void PWM:: motor_off()
{
    softPwmWrite(pinNumber,0);
}
