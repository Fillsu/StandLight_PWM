#include "Motor_View.h"

Motor_View::Motor_View(PWM *pwm)
{
pwmer=pwm;
}

Motor_View::~Motor_View()
{

}

void Motor_View::on()
{
pwmer->motor_on();
}

void Motor_View::off()
{
std::cout << "stop"<<std::endl;
pwmer->motor_off();
}

void Motor_View::UpdateView(std::string strmotor)
{
    
if(strmotor=="motor_on")
{
pwmer->motor_on();
}

if(strmotor=="motor_off")
{
pwmer->motor_off();
    
}

}

