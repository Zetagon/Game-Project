#ifndef AABB_H
#define AABB_H
#include <SDL.h>
#include <cmath>
#include <glm.hpp>

class AABB
{
    public:
        /** Default constructor */
        AABB(SDL_Rect pRect);
        /** Default destructor */
        virtual ~AABB();

        SDL_Rect GetSDL_Rect();
        double getMax(){}



        double x; //!< Member variable "x"
        double y; //!< Member variable "y"
        int w; //!< Member variable "w"
        int h; //!< Member variable "h"

    protected:

    private:
};

#endif // AABB_H
