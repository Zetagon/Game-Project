#include "AABB.h"

AABB::AABB(SDL_Rect pRect)
{
    //ctor
    x = pRect.x;
    y = pRect.y;
    w = pRect.w;
    h = pRect.h;
}

AABB::~AABB()
{
    //dtor
}

SDL_Rect AABB::GetSDL_Rect()
{
    return SDL_Rect{round(x), round(y), w, h};
}
