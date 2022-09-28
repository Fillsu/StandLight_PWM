#ifndef MOTOR_VIEW_H
#define MOTOR_VIEW_H

#pragma once
#include "PWM.h"
#include <iostream>
#include <string>


class Motor_View
{
public:
    Motor_View(PWM *pwm);
    ~Motor_View();
    PWM *pwmer;
    void on();
    void off();
    void UpdateView(std::string strmotor);
private:

};

#endif