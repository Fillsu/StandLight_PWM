#include "Motor_Service.h"

Motor_Service::Motor_Service(Motor_View *Motor_view)
{
    Motor_viewer=Motor_view;
    th_warn=0;
    motor_led_recover=0;
    motor_state=MOTOR_STOP;
}

Motor_Service::~Motor_Service()
{

}

void Motor_Service::updateMotor(std::string strmotor)
{


    if(th_warn==1)
    {
        if(strmotor=="motor_on")
        {
            Motor_viewer->UpdateView("motor_on");
            motor_state=MOTOR_START;
            motor_led_recover=1;
        }
    }
    if(th_warn==0)
    {

        if(motor_led_recover==1)
        {
            Motor_viewer->UpdateView("motor_off");
            motor_state=MOTOR_STOP;
            motor_led_recover=0;
        }

        if(strmotor=="motor_off")
        {
            motor_state=MOTOR_STOP;
            Motor_viewer->UpdateView("motor_off");
        }

        if(strmotor=="motor_on")
         {     motor_state=MOTOR_START;
               Motor_viewer->UpdateView("motor_on");
         }

    }

}