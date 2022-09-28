#include "Controler.h"


Controler::Controler(Service *servi,Clock_Service *Clock_service,TH_Service *TH_service,Sonic_Service *Sonic_service,Motor_Service *Motor_service)
{


lightState=LIGHT_OFF;
counter_state=COUNTER_OFF;

TH_servicer=TH_service;
Sonic_servicer=Sonic_service;
Motor_servicer=Motor_service;
Clock_servicer=Clock_service;
service = servi ;

recover_stop=0;
timer=0;
distance_empty=0;
timer_on=0;
lcd_recover=0;
}

Controler::~Controler()
{

}

void Controler::updateEvent(std::string strBtn)
{   
    if(strBtn=="counterup")
    { 
        
            timer=timer+1;
            Clock_servicer->counter_count=timer;
            Clock_servicer->updateClock("counterup");
    }


    if(strBtn=="SonicUpdate")
    {   


        if ((distance<0)||(distance>30))
        {
            distance_empty++;
        }
 
        if ((distance>0)&&(distance<10))
        {
            distance_empty--;
        }

            if(distance_empty>7)
            {         
                      distance_empty=0;
                      service->sonic_warn=1;
                      Sonic_servicer->sonic_buf=distance;
                      recover_stop=1;
                      lcd_recover=timer;//save time number before stop
                      timer_on=0;//dont check 1ms mst 2 listener,
                      Clock_servicer->counter_count=0;//this  looks like stop lcd 
                      service->updateservice("sonic warn");
            }

            if(distance_empty<-7)
            {
                    distance_empty=0;
                    Sonic_servicer->sonic_buf=distance;
                    service->sonic_warn=0;
                    timer_on=timer_on|recover_stop; 
                    timer=(lcd_recover&recover_stop)|(timer&(~recover_stop));
                    recover_stop=0;
                    service->updateservice("Recover_Led");

            }
    }

    if(strBtn=="THupdate")
    {   
        if((dht_data->Temp)>27)
        {
            Motor_servicer->th_warn=1;
            Motor_servicer->updateMotor("motor_on");
            TH_servicer->updateTH(dht_data);
           
        }
        else
        {   
            
            Motor_servicer->th_warn=0;
            TH_servicer->updateTH(dht_data);

        }
    }

    if(strBtn=="clockupdate")
    {
        Clock_servicer->updateClock("timerclock");
    }


    if(strBtn=="powerButton")
    {
        Clock_servicer->updatePower();
        return ;
    }

    if(strBtn=="ledButton")
    {
        service->updateservice("ServiceOn");
        Clock_servicer->led_count++;
        if((Clock_servicer->led_count)>5)
        {
            Clock_servicer->led_count=0;
        }
        return ;
    }
    

    if(strBtn=="motorButton")
    {       
        switch(Motor_servicer->motor_state)
        {
            case MOTOR_STOP:
            Motor_servicer->motor_state= MOTOR_START;
            Motor_servicer->updateMotor("motor_on");
            break;

            case MOTOR_START:
            Motor_servicer-> motor_state= MOTOR_STOP;
            Motor_servicer->updateMotor("motor_off");
            break;
        }
        return ;
    } 


    if(strBtn=="counterButton")
    { 

        timer=-1;
        return ;
    }

    if(strBtn=="counteroff")
    {   
  
        Clock_servicer->counter_count=timer;
        Clock_servicer->updateClock("counterup");

        return ;

    }

    if(strBtn=="initialize")
    {   
        timer=0;
        lcd_recover=0;
        Clock_servicer->counter_count=timer;
        Clock_servicer->updateClock("counterup");
    }
    


}