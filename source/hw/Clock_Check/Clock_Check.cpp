#include "Clock_Check.h"

Clock_Check::Clock_Check()
{
    prev_Sec=0;
}

Clock_Check::~Clock_Check()
{

}

bool Clock_Check::Is_Clock_update()
{
    time_t cur_Sec=time(NULL);
    if(cur_Sec==prev_Sec)
    {
        return false;
    }
    else
    {
        prev_Sec=cur_Sec;
        return true;
    }
    return false;
}

