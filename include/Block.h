#ifndef BLOCK_H
#define BLOCK_H
#include <SDL.h>
/** \brief An unmovable solid object ingame.
 *
 * \param
 * \param
 * \return
 *
 */

class Block
{
    public:
        /** Default constructor */
        Block(SDL_Rect pGround);
        /** Default destructor */
        virtual ~Block();

        bool isTouchingGround(const SDL_Rect& pRect);
        bool isTouchingCeiling(SDL_Rect* pRect);
        bool isTouchingLeftWall(SDL_Rect* pRect);
        bool isTouchingrightWall(SDL_Rect* pRect);

        /** Access rect
         * \return The current value of rect
         */
        SDL_Rect Getrect() { return rect; }
        /** Set rect
         * \param val New value to set
         */
        void Setrect(SDL_Rect val) { rect = val; }
        /** Access ceiling
         * \return The current value of ceiling
         */
        SDL_Rect Getceiling() { return ceiling; }
        /** Set ceiling
         * \param val New value to set
         */
        void Setceiling(SDL_Rect val) { ceiling = val; }
        /** Access ground
         * \return The current value of ground
         */
        SDL_Rect Getground() { return ground; }
        /** Set ground
         * \param val New value to set
         */
        void Setground(SDL_Rect val) { ground = val; }
        /** Access leftWall
         * \return The current value of leftWall
         */
        SDL_Rect GetleftWall() { return leftWall; }
        /** Set leftWall
         * \param val New value to set
         */
        void SetleftWall(SDL_Rect val) { leftWall = val; }
        /** Access rightWall
         * \return The current value of rightWall
         */
        SDL_Rect GetrightWall() { return rightWall; }
        /** Set rightWall
         * \param val New value to set
         */
        void SetrightWall(SDL_Rect val) { rightWall = val; }

    protected:
        SDL_Rect rect; //!< Member variable "rect", the SDL_Rect that represents the space that "this" object fills
        SDL_Rect ceiling; //!< Member variable "ceiling", an SDL_Rect that represents where instances of Entity are pushed downwards
        SDL_Rect ground; //!< Member variable "ground", an SDL_Rect that represents where instances of Entity are pushed up
        SDL_Rect leftWall; //!< Member variable "leftWall", an SDL_Rect that represents where instances of Entity are pushed to the right
        SDL_Rect rightWall; //!< Member variable "rightWall", an SDL_Rect that represents where instances of Entity are pushed to the left

    private:
};

#endif // BLOCK_H
