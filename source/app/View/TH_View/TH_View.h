#ifndef TH_VIEW_H
#define TH_VIEW_H

#pragma once
#include <iostream>
#include "LCD.h"

class TH_View
{
public:
    //TH_View();
    TH_View(LCD *lcd);
    ~TH_View();
char TH_buf1[50];
char TH_buf2[50];
void updateView();
void Emergency();
LCD *lcd;
private:

};

#endif