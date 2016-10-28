#ifndef ENTITY_H
#define ENTITY_H
#include <cmath>
#include <memory>
#include <iostream>
#include <SDL.h>
#include <Block.h>
#include "Timer.h"
#include "Direction.h"


class Entity
{
    public:
        Entity(SDL_Rect pRect, int pmass,const std::shared_ptr<Timer>& T , SDL_Renderer* renderer);
        virtual ~Entity();

        void ApplyForce(double newton, double angle);
        void ApplyGravity();
        void Uppdate();
        void UppdateVelocity();
        void UppdatePosition();
        void CheckCollisionWithBlock(Block block);
        bool CheckCollision(const SDL_Rect& pRect);
        bool CheckCollision(const SDL_Rect& pRect, SDL_Rect& returnMinkowski);
        SDL_Texture* Tex;

        double     Getx() { return round(x); }
        void    Setx(int val) { x = val; hurtbox.x = x;}

        double     Gety() { return round(y); }
        void    Sety(int val) { y = val; hurtbox.y = y;}

        int     Getmass() { return mass; }
        void    Setmass(int val) { mass = val; }

        SDL_Rect Gethurtbox() { return hurtbox; }
        void    Sethurtbox(SDL_Rect val) { hurtbox = val; }

        double  GetvelocityX() { return velocityX; }
        void    SetvelocityX(double val) { velocityX = val; }

        double  GetvelocityY() { return velocityY; }
        void    SetvelocityY(double val) { velocityY = val; }

        void    SetaccX(double val) { accX = val; }
        double  GetaccX() { return accX; }

        void    SetaccY(double val) { accY = val; }
        double  GetaccY() { return accY; }

        void    Setangle(double val) { angle = val; }
        double  Getangle() { return angle; }

        int     GetstunTime() { return stunTime; }
        void    SetstunTime(int val) { stunTime = val; }

        bool    GetisOnGround() { return isOnGround;}
    protected:
        std::shared_ptr<Timer> timer;
        double x;/**< x-coordinate */
        double y;/**< y-coordinate */
        int mass;/**< mass, used with physics */
        double velocityX;/**< horizontal velocity */
        double velocityY;/**< vertical velocity */
        double accX;/**< horizontal acceleration */
        double accY;/**< vertical acceleration */
        SDL_Rect hurtbox;/**< An SDL_Rect that represents the entitiy's hurtbox */
        double angle;
        double stunTime;
        const double gravitationalAcceleration = 0.001;
        bool isOnGround;

        SDL_Renderer* CApp_Renderer;//not needed

    private:
};

#endif // ENTITY_H
