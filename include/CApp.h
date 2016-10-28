#ifndef CAPP_H
#define CAPP_H
#include <SDL.h>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include "Entity.h"
#include "Block.h"
#include "Timer.h"

class CApp
{
    public:
        CApp();
        virtual ~CApp();
        void    Start();
        void    OnInit();
        void    OnEvent();
        void    OnLoop();
        void    OnRender();
        void    OnCleanup();

        std::shared_ptr<Timer> timer;

    protected:
        SDL_Window* window;/**< the window that the program is displayed on */
        SDL_Renderer* renderer;/**< the SDL_Renderer associated with \ref window */
        SDL_Texture* render_texture;/**< The final texture to be rendered on screen */
        std::unique_ptr<Entity> tempEntity;
        std::vector<std::unique_ptr<Block>> blockV;
        SDL_Texture* tex;
        bool running;/**< Set this to false for quitting the program. Used in Start() */
    private:


//        std::vector<string> keyswentdown;
};

#endif // CAPP_H
