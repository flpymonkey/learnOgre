/*
-----------------------------------------------------------------------------
Filename:    Ball.h
-----------------------------------------------------------------------------
*/

#ifndef __Ball_h_
#define __Ball_h_

#include "BaseApplication.h"
#include <string>

//---------------------------------------------------------------------------

class Ball
{
public:
    Ball(Ogre::SceneManager*, Ogre::Vector3, Ogre::Vector3, int);
    Ogre::Real getSpeed(void);
    Ogre::Vector3 getDirection(void);
    Ogre::Vector3 getPosition(void);
    void translate(Ogre::Vector3 translation);

protected:
    // Ball variables
    Ogre::Real mMoveSpd;
    Ogre::Vector3 mDirection;
    Ogre::Entity* mBallEntity;
    Ogre::SceneNode* mBallNode;
    // End of Ball variables

};

//---------------------------------------------------------------------------

#endif // #ifndef __Ball_h_

//---------------------------------------------------------------------------
