#include "../include/CApp.h"
/** \brief Handle the rendering
 *
 *
 *
 *
 *
 */

void CApp::OnRender()
{
    SDL_SetRenderTarget(renderer, render_texture);
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderClear(renderer);
    //entity
    SDL_Rect rect = tempEntity->Gethurtbox();
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderDrawRect(renderer,&rect);
    //blocks
    for(unsigned int i = 0; i < blockV.size(); i++)
    {
        SDL_Rect tempRect = blockV[i]->Getrect();
        SDL_RenderDrawRect(renderer, &tempRect);
    }

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopyEx(renderer, render_texture, NULL, NULL, 0,NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent(renderer);
}
