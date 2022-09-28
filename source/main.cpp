#include <iostream>
#include <wiringPi.h>

#include "Button.h"
#include "Clock_Check.h"
#include "DHT11.h"
#include "UltraSonic.h"

#include "Led.h"
#include "LCD.h"
#include "PWM.h"

#include "Listener.h"

#include "Controler.h"

#include "Service.h"
#include "Clock_Service.h"
#include "TH_Service.h"
#include "Sonic_Service.h"
#include "Motor_Service.h"

#include "Motor_View.h"
#include "Clock_View.h"
#include "Sonic_View.h"
#include "TH_View.h"
#include "View.h"


#include "time.h"


int main()
{
std::cout << "Hello Wddorld" <<std::endl;

//These are Check Instance

Button Button1(27);
Button Button2(28);
Button Button3(29);
Button Button4(6);

DHT11 dht(7);
//DHT_Data dhtData;
Clock_Check clkcheck1;

    int trigPin = 5;
    int echoPin = 4;
 

UltraSonic ultraSonic(trigPin, echoPin);

//These are OutPrint Instance 
Led led(21);
Led led2(22);
Led led3(23);
Led led4(24);
Led led5(25);
LCD lcd1(new I2C("/dev/i2c-1", 0x27));
PWM pwm1(26);

//Only View Instance
View view1(&led,&led2,&led3,&led4,&led5,&lcd1);
Clock_View clkview1(&lcd1);
TH_View thview1(&lcd1);
Sonic_View sonicview1(&lcd1);//&lcd1
Motor_View motorview1(&pwm1);//&lcd1

//Only Service Instance
TH_Service th_servicer(&thview1);
Motor_Service motorservicer(&motorview1);
Clock_Service clkservice1(&clkview1);
Sonic_Service sonicservicer(&sonicview1);
Service service1(&view1);


Controler controler1(&service1,&clkservice1,&th_servicer,&sonicservicer,&motorservicer);

Listener listener(&Button1,&Button2,&Button3,&Button4,&clkcheck1,&dht,&ultraSonic,&controler1);


// initailize anything else 
led.Off();
led2.Off();
led3.Off();
led4.Off();
led5.Off();

delay(10000);

    {  
         listener.checkEvent();
         view1.lightView();
         delay(50);

    }

return 0;
}