#include "Entity.h"
#include <cmath>
#include <CApp.h>
Entity::Entity(SDL_Rect pRect, int pmass,const std::shared_ptr<Timer>& T, SDL_Renderer* renderer )
{
    //ctor
    hurtbox = pRect;
    x = hurtbox.x;
    y = hurtbox.y;
    hurtbox.x = x;
    hurtbox.y = y;
    mass = pmass;
    velocityX = 0;
    velocityY= 0;
    accX = 0;
    accY = 0;
    angle = 0;
    stunTime = -1;
    isOnGround = false;
    timer = T;
    CApp_Renderer = renderer;
}

Entity::~Entity()
{
    //dtor
}
void Entity::Uppdate()
{
    UppdateVelocity();
    UppdatePosition();
    isOnGround = false;
}
/** \brief Check if touching "block". If touching push this entity towards closest edge
 *
 * \param block the Block to check if colliding with this
 *
 */

void Entity::CheckCollisionWithBlock(Block block)
{
    SDL_Rect blockRect = block.Getrect();
    SDL_Rect minkowskiDiff;
    SDL_Point penetrationVector;// Vector for pushing out this Entity from block
    //The penetrationVector is the minimum distance from origin to one of the sides of the Minkowski-Differenced rectangle
    if(CheckCollision(blockRect, minkowskiDiff))
    {

        //Calculate distance from origin to each side of resulting Minowski-rectangle
        int rightDistance = minkowskiDiff.x;
        int leftDistance = minkowskiDiff.w - abs(minkowskiDiff.x);
        int bottomDistance = minkowskiDiff.h - abs(minkowskiDiff.y);
        int topDistance = minkowskiDiff.y;

        //Save velocity, in case leftDistance is not the minimum distance
        double tempVelocityX = velocityX;


        //Set minDistance to leftDistance, if this is true, none of the conditions below will be true
        penetrationVector = {-leftDistance - 1, 0};
        int minDistance = std::abs(leftDistance);
        velocityX = 0;
        Direction direction = Direction::left;
        if(std::abs(rightDistance) < minDistance)
        {
            minDistance = std::abs(rightDistance);
            penetrationVector = {-rightDistance + 1, 0};
            direction = Direction::right;

        }
        if(std::abs(topDistance) < minDistance)
        {
            minDistance = std::abs(topDistance);
            penetrationVector = {0, -topDistance + 1};
            velocityX = tempVelocityX;
            velocityY = 0;
            direction = Direction::up;
        }
        if(std::abs(bottomDistance) < minDistance)
        {
            minDistance = std::abs(bottomDistance);
            penetrationVector = {0, -bottomDistance - 1};
            velocityX = tempVelocityX;
            velocityY = 0;
            direction = Direction::down;
        }

        switch(direction)
        {
            case Direction::up :
                    isOnGround = true;
                    std::cout << "on ground ";

            break;
            case Direction::down  :
                   std::cout << "down   ";
            break;
        }


        Setx(hurtbox.x + penetrationVector.x);
        Sety(hurtbox.y + penetrationVector.y);

    }

// std::cout << isOnGround << "\n";
}
bool Entity::CheckCollision(const SDL_Rect& pRect)
{
    SDL_Rect tempRect;
    if(CheckCollision(pRect, tempRect))
    {
        return true;
    }
    return false;
}
/** \brief Check if colliding with \r pRect
 *
 * \param pRect The SDL_Rect to check collision with
 * \param returnMinkowski An SDL_Rect to put the resulting rectangle using Minkowski Difference(the technique used for collision-detection)
 * \return return true if colliding with pRect
 *
 */

bool Entity::CheckCollision(const SDL_Rect& pRect, SDL_Rect& returnMinkowski)
{
    SDL_Rect rect = pRect;
    //Calculate Minkowski-difference
    SDL_Rect minkowskiDiff = {hurtbox.x - (rect.x + rect.w),
                            hurtbox.y - (rect.y + rect.h),
                            hurtbox.w + rect.w,
                            hurtbox.h + rect.h};
    returnMinkowski = minkowskiDiff;

    SDL_Rect temp = minkowskiDiff;//not needed
    temp.x += 100;//not needed
    temp.y += 100;//not needed
    SDL_Rect zero = { 100, 100, 10 , 10};//not needed
    SDL_SetRenderDrawColor(CApp_Renderer, 0,0,255,125);//not needed
    SDL_RenderDrawRect(CApp_Renderer, &temp);//not needed
    SDL_RenderDrawRect(CApp_Renderer, &zero);//not needed
    SDL_RenderPresent(CApp_Renderer);//not needed
    if(!(minkowskiDiff.x > 0||
       minkowskiDiff.x + minkowskiDiff.w < 0||
       minkowskiDiff.y > 0||
       minkowskiDiff.y + minkowskiDiff.h < 0))//Check if Minkowski-resultant contains origin
       {
//           std::cout << "collision\n";
            return true;
       }
       else
       {
           return false;
       }
}

/** \brief Applies a force on this entity
 *
 * \param newton How much force to be put on this entity.
 * \param radians In which direction the force shall apply in. Unit: radians
 *
 *
 */
void Entity::ApplyForce(double newton, double radians)
{
    accX = accX + cos(radians) * newton / mass;
    accY = accY + sin(radians) * newton / mass;
}

void Entity::ApplyGravity()
{
    ApplyForce(gravitationalAcceleration * mass, -0.5 * M_PI);
//    std::cout << "positionY " << y << "\n";
}

/** \brief Update velocity by adding acceleration
 *  NOTE: This function needs to be run every frame after all forces have been applied in order to function properly
 * \return void
 *
 */
void Entity::UppdateVelocity()
{
    velocityX += accX * timer->GettimeSince();
    velocityY += accY * timer->GettimeSince();
    accX = 0;
    accY = 0;

}

/** \brief Update position by adding velocity
 *  NOTE: This function needs to be run every frame after all forces have been applied in order to function properly
 * \return void
 *
 */
void Entity::UppdatePosition()
{
    x += velocityX * timer->GettimeSince();
    y += velocityY * timer->GettimeSince();
    hurtbox.x = round(x);
    hurtbox.y = round(y);
}
