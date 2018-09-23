/*
-----------------------------------------------------------------------------
Filename:    BallApplication.cpp
-----------------------------------------------------------------------------
*/

#include "BallApplication.h"

//---------------------------------------------------------------------------
BallApplication::BallApplication(void)
: balls()
{
}
//---------------------------------------------------------------------------
BallApplication::~BallApplication(void)
{
}

// Calculates a reflection vector from an incident ray colliding with a plane.
// Based on formula on slide 20 found here: 
// http://www.cs.utexas.edu/users/theshark/courses/cs354r/lectures/cs354r-5.pdf
Ogre::Vector3 BallApplication::getReflectionVector(Ogre::Vector3 incident, Ogre::Plane collision){
    Ogre::Vector3 normal = collision.normal;

    Ogre::Vector3 reflection = incident - 2 * (normal.dotProduct(incident)) * normal;
    return reflection;
}

//---------------------------------------------------------------------------
void BallApplication::createScene(void)
{
    // Create your scene here :)
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));
    // mSceneMgr->setShadowTechnique(Ogre::ShadowTechnique::SHADOWTYPE_STENCIL_MODULATIVE);
    Ogre::Light* light = mSceneMgr->createLight("MainLight");


    camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    
    camNode->attachObject(mCamera);
    camNode->setPosition(0, 0, 50);

    Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
    pointLight->setDiffuseColour(0, 0, 1.0);
    pointLight->setSpecularColour(0, 0, 1.0);
    pointLight->setType(Ogre::Light::LT_POINT);

    Ogre::SceneNode* spotLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    spotLightNode->attachObject(pointLight);
    spotLightNode->setPosition(Ogre::Vector3(-20, 0, 0));

    // Set ball destination at random location between -40 and 39 on each axis
    Ogre::Vector3 initPos = Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);
    Ogre::Vector3 initDest = Ogre::Vector3(rand() % 80 - 40, rand() % 80 - 40, rand() % 80 - 40);
    Ogre::Vector3 initDir = initDest - Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);

    // initalize a ball with a random speed
    Ball b1 = Ball(mSceneMgr, "1", initPos, initDir, rand() % 8 - 2);

    // Set ball destination at random location between -40 and 39 on each axis
    Ogre::Vector3 initPos2 = Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);
    Ogre::Vector3 initDest2 = Ogre::Vector3(rand() % 80 - 40, rand() % 80 - 40, rand() % 80 - 40);
    Ogre::Vector3 initDir2 = initDest2 - Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);

    // initalize a ball with a random speed
    Ball b2 = Ball(mSceneMgr, "2", initPos2, initDir2, rand() % 8 - 2);

    // Set ball destination at random location between -40 and 39 on each axis
    Ogre::Vector3 initPos3 = Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);
    Ogre::Vector3 initDest3 = Ogre::Vector3(rand() % 80 - 40, rand() % 80 - 40, rand() % 80 - 40);
    Ogre::Vector3 initDir3 = initDest3 - Ogre::Vector3(rand() % 40 - 20, rand() % 40 - 20, rand() % 40 - 20);

    // initalize a ball with a random speed
    Ball b3 = Ball(mSceneMgr, "3", initPos3, initDir3, rand() % 8 - 2);

    balls.push_back(b1);
    balls.push_back(b2);
    balls.push_back(b3);
    // mBallEntity = mSceneMgr->createEntity("mySphere", Ogre::SceneManager::PT_SPHERE);
    // mBallEntity->setMaterialName("grass.material");

    // mBallNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    // mBallNode->setPosition(20, 20, 20);
    // mBallNode->roll(Ogre::Degree(-90));
    // mBallNode->scale(0.1,0.1,0.1);
    // mBallNode->attachObject(mBallEntity);

    // Add walls
    //Bottom
    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -40);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground1",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane,
        150, 150, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground1");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setMaterialName("Examples/Rockwall");

    // Back
    Ogre::Plane plane2(Ogre::Vector3::UNIT_Z, -40);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground2",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane2,
        150, 150, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);

    Ogre::Entity* groundEntity2 = mSceneMgr->createEntity("ground2");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity2);
    groundEntity2->setMaterialName("Examples/Rockwall");

    //Top
    Ogre::Plane plane3(Ogre::Vector3::UNIT_Y.reflect(Ogre::Vector3::UNIT_Y), -40);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground3",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane3,
        150, 150, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Z);

    Ogre::Entity* groundEntity3 = mSceneMgr->createEntity("ground3");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity3);
    groundEntity3->setMaterialName("Examples/Rockwall");

    //Left
    Ogre::Plane plane4(Ogre::Vector3::UNIT_X, -40);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground4",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane4,
        150, 150, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);

    Ogre::Entity* groundEntity4 = mSceneMgr->createEntity("ground4");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity4);
    groundEntity4->setMaterialName("Examples/Rockwall");

    //Right
    Ogre::Plane plane5(Ogre::Vector3::UNIT_X.reflect(Ogre::Vector3::UNIT_X), -40);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground5",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane5,
        150, 150, 1, 1,
        true,
        1, 5, 5,
        Ogre::Vector3::UNIT_Y);

    Ogre::Entity* groundEntity5 = mSceneMgr->createEntity("ground5");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity5);
    groundEntity5->setMaterialName("Examples/Rockwall");

}

bool BallApplication::frameRenderingQueued(const Ogre::FrameEvent& evt){
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    // Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    // Move the balls each frame
    std::list<Ball>::iterator it;
    for (it = balls.begin(); it != balls.end(); ++it){
        Ogre::Real move = it->getSpeed() * evt.timeSinceLastFrame;
        it->translate(move * it->getDirection());

        if (it->getPosition().y <= -36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(it->getPosition().x, -35, it->getPosition().z));
        }

        if (it->getPosition().y >= 36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_Y.reflect(Ogre::Vector3::UNIT_Y), -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(it->getPosition().x, 35, it->getPosition().z));
        }

        if (it->getPosition().x <= -36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_X, -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(-35, it->getPosition().y, it->getPosition().z));
        }

        if (it->getPosition().x >= 36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_X.reflect(Ogre::Vector3::UNIT_X), -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(35, it->getPosition().y, it->getPosition().z));
        }

        if (it->getPosition().z <= -36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_Z, -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(it->getPosition().x, it->getPosition().y, -35));
        }

        if (it->getPosition().z >= 36){
            Ogre::Plane plane(Ogre::Vector3::UNIT_Z.reflect(Ogre::Vector3::UNIT_Z), -40);
            it->setDirection(getReflectionVector(it->getDirection(), plane));
            it->setPosition(Ogre::Vector3(it->getPosition().x, it->getPosition().y, 35));
        } 
    }
    return true;
}

//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        BallApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
