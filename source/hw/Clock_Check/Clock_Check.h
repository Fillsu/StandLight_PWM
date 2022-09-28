#ifndef CLOCK_CHECK_H
#define CLOCK_CHECK_H
#include "time.h"
#include "wiringPi.h"
#pragma once

class Clock_Check
{
public:
    Clock_Check();
    ~Clock_Check();
    time_t prev_Sec;
    bool Is_Clock_update();
   
private:

};

#endif