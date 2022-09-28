#ifndef LISTENER_H
#define LISTENER_H
#include "Listener.h"
#include "Controler.h"
#include "Button.h"
#include "Clock_Check.h"
#include "Led.h"
#include "DHT11.h"
#include "UltraSonic.h"
#include "wiringPi.h"
#pragma once

class Listener
{
    
  private:
  //listener has tis componet
  //And this must be point, beucause of memory
  int distance;
  
  Button *ledButton;
  Button *powerButton;
  Button *counterButton;
  Button *motorButton;
  Clock_Check *clkcheck;
  DHT11 *dht;
  UltraSonic *Sonic_Checker;

 Controler *cont;
  
  public :
  Listener(Button *modbutton,Button *powerbutton,Button *counterbutton,Button *motor,  Clock_Check *clk,DHT11 *dht,  UltraSonic *soniccheck,Controler *cont);
  ~Listener();
  void checkEvent();


};

#endif