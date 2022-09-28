#ifndef SONIC_SERVICE_H
#define SONIC_SERVICE_H

#pragma once
#include "Sonic_View.h"
#include <iostream>
class Sonic_Service
{
public:
    Sonic_Service(Sonic_View *Sonic_view);
    ~Sonic_Service();
    void updateSonic();
    int sonic_buf;
private:
    Sonic_View *Sonic_Viewer;

};

#endif