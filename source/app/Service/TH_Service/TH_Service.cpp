#include "TH_Service.h"

TH_Service::TH_Service(TH_View *th_view)
{
    th_viewer=th_view;
    clock_mode=0;
}

TH_Service::~TH_Service()
{

}

void TH_Service::updateTH(DHT_Data *dht)
{
if(warn==1)
{
     sprintf(th_viewer->TH_buf2,"Waring: %d.%dC",dht->Temp,dht->TempDec);
      th_viewer->Emergency();
}

if(warn==0)
{

 sprintf(th_viewer->TH_buf2,"%d.%dC",dht->Temp,dht->TempDec);
th_viewer->updateView();

}
}