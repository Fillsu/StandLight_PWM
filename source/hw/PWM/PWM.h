#ifndef PWM_H
#define PWM_H

#pragma once
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

class PWM
{
public:
    PWM(int pin);
    ~PWM();
    void motor_on();
    void motor_off();
    int pinNumber;
private:

};

#endif