#include "Sonic_Service.h"

Sonic_Service::Sonic_Service(Sonic_View *Sonic_view)
{
    Sonic_Viewer=Sonic_view;

}

Sonic_Service::~Sonic_Service()
{

}

void Sonic_Service::updateSonic()
{   

sprintf(Sonic_Viewer->buf,"%d",sonic_buf);
Sonic_Viewer->lcd_on();
}