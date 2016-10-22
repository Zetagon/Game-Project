#include "Timer.h"
#include <iostream>
Timer::Timer()
{
    //ctor
    prevSysTime = 0;
    timeSince = 0;
}

Timer::~Timer()
{
    //dtor
}
/** \brief Start or restart the timer
 *
 */

void Timer::start()
{
    timeSince = SDL_GetTicks() - prevSysTime;
    prevSysTime = SDL_GetTicks();
//    std::cout << "TimeSince: " << timeSince << "\n";

}
/** \brief
 *
 * \return the time that has passed since \r start was called, or 0
 *
 */

double Timer::getTime()
{
    double temp =  (SDL_GetTicks() - prevSysTime);
//    std::cout << temp << "  " << SDL_GetTicks()<< "   " << prevSysTime << "\n";
    return temp;
}

