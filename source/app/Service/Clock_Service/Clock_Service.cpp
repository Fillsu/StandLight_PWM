#include "Clock_Service.h"

Clock_Service::Clock_Service(Clock_View *clkview)
{
curTime=0;
clkviewer=clkview;
led_count=0;
lcd_toggle=0;
counter_count_start=0;
counter_count=0;
count_stop=0;
sonic_count_stop=0;
}

Clock_Service::~Clock_Service()
{

}

 void Clock_Service::updateClock(std::string clkstr)
{   
    curTime=time(NULL);
    timeDate=localtime(&curTime);
    
    
   if(clkstr=="Off_LCD_f")
   {
      return ;
   }
   if(clkstr=="clean")
   {
      clkviewer->clear=1;

   }
 
    if(clkstr=="counterup")
   {
      sprintf(clkviewer->led_lcd,"Count Time:%d ",counter_count);
      clkviewer->updateTime();
   }

    
   if(clkstr=="timerclock")
   {
    sprintf(clkviewer->led_lcd,"Count Time:%d   ",counter_count);
    sprintf(clkviewer->buff,"%d:%d:%d  ",timeDate->tm_hour,timeDate->tm_min,timeDate->tm_sec);
    clkviewer->updateTime();
   }

    
}

void Clock_Service::updatePower()
{   
    lcd_toggle=!lcd_toggle;
    if(lcd_toggle)
    clkviewer->off_lcd();
    else
    clkviewer->on_lcd();
}