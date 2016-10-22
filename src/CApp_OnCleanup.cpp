#include "../include/CApp.h"
/** \brief Handles all the cleanup
 *
 *
 *
 *
 *
 */

void CApp::OnCleanup()
{
    SDL_DestroyTexture(render_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
