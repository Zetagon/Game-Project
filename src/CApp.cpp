#include "../include/CApp.h"

CApp::CApp()
{
    //ctor
}

CApp::~CApp()
{
    //dtor
}
/** \brief Start the game-loop
 *  Calls first OnInit() , and then starts a while-loop(game-loop) that is dependent on \ref running. Lastly calls OnCleanup()
 *
 *
 *
 *
 */

void CApp::Start()
{
    OnInit();
    running = true;
    while(running)
    {
        OnEvent();
        OnLoop();
        OnRender();
        timer->start();
    }
    OnCleanup();
}
