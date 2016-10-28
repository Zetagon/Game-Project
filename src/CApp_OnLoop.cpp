#include "../include/CApp.h"
/** \brief Handles changes of variables etc. that are not dependent on user input
 *
 *
 */

void CApp::OnLoop()
{

    tempEntity->ApplyGravity();
//    if(!(tempEntity->GetisOnGround()))
//    {
//        tempEntity->SetvelocityX(tempEntity->GetvelocityX() * 1);
//    }
//    else
//    {
//
//        tempEntity->SetvelocityX(tempEntity->GetvelocityX() * 0);
//    }
    tempEntity->Uppdate();
    for(unsigned int i = 0; i < blockV.size(); i++)
    {
        tempEntity->CheckCollisionWithBlock(*blockV[i]);
    }

}
