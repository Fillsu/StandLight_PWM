#ifndef SERVICE_H
#define SERVICE_H

#pragma once
#include <string>
#include "View.h"


class Service
{
public:
    Service(View *view);
    ~Service();
    void updateservice(std::string strServ);
    int th_warn;
    int sonic_warn;
    int sonic_led_recover;
    int motor_led_recover;
private:
 int lightState;
 View *viewer;
};

#endif