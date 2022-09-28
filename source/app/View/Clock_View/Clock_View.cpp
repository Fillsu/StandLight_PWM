#include "Clock_View.h"

Clock_View::Clock_View(LCD *lcd)
{
 this->lcd=lcd;
clear=0;
}

Clock_View::~Clock_View()
{

}

void Clock_View:: updateTime()
{
     if(clear)
     {
      lcd->cleardisplay();
      clear=0;
     }
     lcd->WriteStringXY(1,0,buff);
     lcd->WriteStringXY(0,0,led_lcd);
     
}

void Clock_View::off_lcd()
{

     lcd->backLightOff();
}

void Clock_View::on_lcd()
{

     lcd->backLightOn();
}