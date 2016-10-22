#include "Block.h"
#include <iostream>
#include <thread>
Block::Block(SDL_Rect pGround)
{
    //ctor
    ground = pGround;
    rect = ground;
}

Block::~Block()
{
    //dtor
}
bool Block::isTouchingGround(const SDL_Rect& pRect)
{
    if(pRect.y < ground.y + ground.h &&
       pRect.y + pRect.h > ground.y &&
       pRect.x < ground.w  + ground.x &&
       pRect.x + pRect.w > ground.x)
    {
        return true;

    }
    else
    {
        return false;
    }
}
