#ifndef CLOCK_SERVICE_H
#define CLOCK_SERVICE_H
#include "time.h"
#include "Clock_View.h"
#include "TH_Service.h"
#include <string>
#pragma once

enum {COUNTER_OFF,COUNTER_ON};

class Clock_Service
{
public:
   
    Clock_Service(Clock_View *clkview);
    ~Clock_Service();
    void updateClock(std::string clkstr);
    void updatePower();
    int led_count;
    int counter_count_start;
    int counter_count;
    int lcd_toggle;
    struct tm *timeDate;
    int count_stop;
    int sonic_count_stop;
private:
    time_t curTime;
    Clock_View *clkviewer;
     

};

#endif