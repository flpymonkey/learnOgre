/*
-----------------------------------------------------------------------------
Filename:    Ball.h
-----------------------------------------------------------------------------
*/

#ifndef __Ball_h_
#define __Ball_h_

#include "BaseApplication.h"
#include <OgreSceneManager.h>
#include <string>

//---------------------------------------------------------------------------

class Ball
{
public:
    Ball(Ogre::SceneManager*, Ogre::String, 
        Ogre::Vector3, Ogre::Vector3, int);
    Ogre::Real getSpeed(void);
    Ogre::Vector3 getDirection(void);
    Ogre::Vector3 getPosition(void);
    void setPosition(Ogre::Vector3 pos);
    void translate(Ogre::Vector3 translation);
    void setDirection(Ogre::Vector3 dir);

protected:
    // Ball variables
    Ogre::SceneManager* scnMgr;
    Ogre::Real mMoveSpd;
    Ogre::Vector3 mDirection;
    Ogre::Entity* mBallEntity;
    Ogre::SceneNode* mBallNode;
    // End of Ball variables

};

//---------------------------------------------------------------------------

#endif // #ifndef __Ball_h_

//---------------------------------------------------------------------------
