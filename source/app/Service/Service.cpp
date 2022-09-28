#include "Service.h"

Service::Service(View *view)
{
viewer=view;
lightState=LIGHT_OFF;
sonic_warn=0;
th_warn=0;

sonic_led_recover=0;
motor_led_recover=0;
}

Service::~Service()
{

}

void Service::updateservice(std::string strServ)
{


    if(sonic_warn==1)
    {
        viewer->Emergency();
        sonic_led_recover=1;
    }

    if(sonic_warn==0)
    {

        if(sonic_led_recover==1)
        {
            viewer->UpdateView("ViewRecover");
            sonic_led_recover=0;
        }

        if(strServ=="ServiceOn")
        {
            viewer->UpdateView("ViewOn");
        }
       
    }

}