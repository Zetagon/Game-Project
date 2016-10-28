#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>

class Timer
{
    public:
        Timer();
        virtual ~Timer();

        void start();
        double getTime();

        unsigned GettimeSince(){return timeSince;}
    protected:

    private:
        unsigned int prevSysTime;
        unsigned int timeSince;
};

#endif // TIMER_H
