#ifndef VIEW_H
#define VIEW_H

#pragma once
#include "string"
#include "Led.h"
#include "LCD.h"
//#include "Controler.h"



class View
{
public:
    View(Led *led,Led *led2,Led *led3,Led *led4,Led *led5,LCD *lcd);
    ~View();
    void lightView();
    void UpdateView(std::string strView);
    void lighton();
    void lightoff();
    void Emergency();
    void Recover_led();

private:
    int ViewState;
    Led *ledarry[5];
    LCD *lcd;
    int count;

   
};

#endif