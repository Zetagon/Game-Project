#include "../include/CApp.h"
/** \brief Handles events and keyboardstate
 *
 *
 */

void CApp::OnEvent()
{
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    //check keystates here
    if(keystates[SDL_SCANCODE_ESCAPE])
    {
        running = false;
    }
    if(keystates[SDL_SCANCODE_LEFT])
    {
        tempEntity->ApplyForce(1,M_PI);
    }
    if(keystates[SDL_SCANCODE_RIGHT])
    {
        tempEntity->ApplyForce(1,0);
    }
    if(keystates[SDL_SCANCODE_DOWN])
    {
        tempEntity->ApplyForce(1,-M_PI/2);
    }
    if(keystates[SDL_SCANCODE_UP])
    {
        if(tempEntity->GetisOnGround())
        {
//            tempEntity->ApplyForce(50,M_PI/2);
            tempEntity->SetvelocityY(0.8);
        }
    }


    //Handle events here
    SDL_Event e;
    while(SDL_PollEvent( &e ) )
    {
//        std::cout << e.key.keysym.sym << "\n";

    }
    SDL_PumpEvents();
}
