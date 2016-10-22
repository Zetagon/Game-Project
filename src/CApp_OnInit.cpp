#include "../include/CApp.h"
/** \brief Initializes SDL and other things
 *
 *
 */

void CApp::OnInit()
{
    std::cout << "Initiating...\n";
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Rect temprect;
    SDL_GetDisplayBounds(0,&temprect);
    std::cout << SDL_GetError();
    SDL_Window* tempWindow = SDL_CreateWindow("Game", 0,0,temprect.w/2, temprect.h, SDL_WINDOW_BORDERLESS);
    window = tempWindow;

    SDL_Renderer* tempRenderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED||SDL_RENDERER_TARGETTEXTURE);
    renderer = tempRenderer;

    SDL_Texture* tempTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, temprect.w/2, temprect.h);
    render_texture = tempTexture;

    timer = std::make_shared<Timer>();

    SDL_Rect entityRect = { 300, 500, 100, 100};
    std::unique_ptr<Entity> temp(new Entity(entityRect, 1000, timer, renderer));
    tempEntity = std::move(temp);
    SDL_Rect rect = {0,0, 1000,100};
    std::unique_ptr<Block> tempB(new Block(rect));
    blockV.push_back(std::move(tempB));
    SDL_Rect rect1 = {200,99, 100,100};
    std::unique_ptr<Block> tempB1(new Block(rect1));
    blockV.push_back(std::move(tempB1));
    SDL_Rect rect2 = {300,400, 1000,100};
    std::unique_ptr<Block> tempB2(new Block(rect2));
    blockV.push_back(std::move(tempB2));
    std::cout << "Initalisation done!\n";
}
