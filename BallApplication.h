/*
-----------------------------------------------------------------------------
Filename:    BallApplication.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#ifndef __BallApplication_h_
#define __BallApplication_h_

#include "BaseApplication.h"

//---------------------------------------------------------------------------

class BallApplication : public BaseApplication
{
public:
    BallApplication(void);
    virtual ~BallApplication(void);

protected:
    virtual void createScene(void);
    // Added methods
    virtual Ogre::Vector3 getReflectionVector(Ogre::Vector3 incident,
    	 Ogre::Plane collision);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
};

//---------------------------------------------------------------------------

#endif // #ifndef __BallApplication_h_

//---------------------------------------------------------------------------
