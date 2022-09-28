
#include "Listener.h"


Listener::  Listener(Button *modbutton,Button *powerbutton,Button *counterbutton,Button *motor, Clock_Check *clk,DHT11 *dht,UltraSonic *soniccheck, Controler *cont)
{
 ledButton=modbutton;
 powerButton=powerbutton;
 counterButton=counterbutton;
 motorButton=motor;

 this->cont = cont;
 clkcheck=clk;
 this->dht=dht;
 Sonic_Checker=soniccheck;


cont->dht_data=&(this->dht->dhtData);

distance =0;


}

Listener::~Listener()
{

}

void Listener::checkEvent()
{


       static unsigned preclk=0;
       static unsigned presonic=0;
       static unsigned pretime=0;
        if(counterButton->getState()==RELEASE_ACTIVE)
         {       

            switch(cont->timer_on)
            {
                case 0:
                cont->updateEvent("counterButton");
                break;
                case 1:
                cont->updateEvent("counteroff");
                break;
                case 2:
                cont->updateEvent("initialize");
                break;
            }
            
           cont-> timer_on=cont->timer_on+1;
           cont->timer_on%=3;
        
         }   


        if((millis()-presonic)>1000)
        {
                presonic=millis();
                distance =Sonic_Checker->readDistance();
                cont->distance=this->distance;
                cont->updateEvent("SonicUpdate");
                

        }
        if((millis()-preclk)>1000)
        {
                preclk=millis();
                dht->readData();
                if (!((dht->dhtData).error))
                {
                cont->updateEvent("THupdate");
                }

        }
       
         if(cont->timer_on==1)
         {
             if((millis()-pretime)>500)
             {
                pretime=millis();
                
                cont->updateEvent("counterup");
            }

         }



        if(ledButton->getState()==RELEASE_ACTIVE)
    {
        
            cont->updateEvent("ledButton");

    }

        if(powerButton->getState()==RELEASE_ACTIVE)
    {
        
            cont->updateEvent("powerButton");

    }   

 

    if(motorButton->getState()==RELEASE_ACTIVE)
    {
            cont->updateEvent("motorButton");
    }     
    
    if(clkcheck->Is_Clock_update()==true)
    {
        
            cont->updateEvent("clockupdate");

    }


    
}

