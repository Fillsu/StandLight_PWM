#ifndef MOTOR_SERVICE_H
#define MOTOR_SERVICE_H

#pragma once
#include "Motor_View.h"
#include <string>

enum {MOTOR_STOP,MOTOR_START};

class Motor_Service
{
public:
    Motor_Service(Motor_View *Motor_view);
    ~Motor_Service();
 Motor_View *Motor_viewer;
 void updateMotor(std::string motor);
 int th_warn;
 int motor_led_recover;
 int motor_state;
private:
   
};

#endif