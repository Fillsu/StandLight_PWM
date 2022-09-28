#ifndef TH_SERVICE_H
#define TH_SERVICE_H

#pragma once
#include "DHT11.h"
#include "TH_View.h"
#include <string>

class TH_Service
{
public:
    TH_Service(TH_View *th_view);
    ~TH_Service();
   void updateTH(DHT_Data *dht);
   TH_View *th_viewer;
   int warn=0;
   int clock_mode;
private:

};

#endif