#include "View.h"

View::View(Led *led,Led *led2,Led *led3,Led *led4,Led *led5,LCD *lcd)
{
    ledarry[0]=led;
    ledarry[1]=led2;
    ledarry[2]=led3;
    ledarry[3]=led4;
    ledarry[4]=led5;
    this->lcd=lcd;
    ViewState=LIGHT_OFF;//아니 이거 왜 초기화 안됨??
    count=0;
}

View::~View()
{

}

void View::lightView()
{

switch( ViewState)
{
    case LIGHT_OFF:
    
    break;

    case LIGHT_ON:
    lighton();
    ViewState=LIGHT_OFF;
    break;

}
}

void View::UpdateView(std::string strView)
{

switch( ViewState)
{
    case LIGHT_OFF:
    if(strView=="ViewOn")
    {
        ViewState=LIGHT_ON;
    }
    

    if(strView=="ViewRecover")
    {
       Recover_led();
    }
    break;

    case LIGHT_ON:
    if(strView=="ViewOff")
    { 
        ViewState=LIGHT_OFF;
    }
    break;

}
}

void View::lighton()
{


// for(int i=0;i<count;i++)
// {
//        ledarry[i]->On();
// }


if(count==5)
{ 
    for(int i=0;i<5;i++)
    {
        ledarry[i]->Off();
    }
    count=-1;
}

if(count>-1)
{
ledarry[count]->On();
count++;
}
else
count++;


}


void View::Emergency()
{
      for(int i=0;i<5;i++)
    {
        ledarry[i]->Off();
    }  
    lcd->backLightOff();
}

void View::Recover_led()
{
      for(int i=0;i<count;i++)
    {
        ledarry[i]->On();
    }  
    lcd->backLightOn();
}