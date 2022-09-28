#ifndef SONIC_VIEW_H
#define SONIC_VIEW_H

#pragma once
#include "LCD.h"
class Sonic_View
{
public:
    Sonic_View(LCD *lcd);
    ~Sonic_View();
    char buf[50];
    void lcd_on();
    LCD *lcd;
private:

};

#endif