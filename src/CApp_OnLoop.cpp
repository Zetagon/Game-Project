#include "../include/CApp.h"
/** \brief Handles changes of variables etc. that are not dependent on user input
 *
 *
 */

void CApp::OnLoop()
{
//    tempEntity->ApplyForce(1,0);
    tempEntity->ApplyGravity();
    tempEntity->Uppdate();
    for(unsigned int i = 0; i < blockV.size(); i++)
    {
        tempEntity->CheckCollisionWithBlock(*blockV[i]);
    }

}
