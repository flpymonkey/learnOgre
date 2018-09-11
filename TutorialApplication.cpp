/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
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

#include "TutorialApplication.h"

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    // Create your scene here :)
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));
    // mSceneMgr->setShadowTechnique(Ogre::ShadowTechnique::SHADOWTYPE_STENCIL_MODULATIVE);
    Ogre::Light* light = mSceneMgr->createLight("MainLight");


    camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    
    camNode->attachObject(mCamera);
    camNode->setPosition(0, 0, 50);

    // Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    // Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
    // ogreNode->attachObject(ogreEntity);

    // Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");
    // Ogre::SceneNode* ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(84, 48, 0));
    // ogreNode2->attachObject(ogreEntity2);

    // Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");
    // Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    // ogreNode3->setPosition(0, 104, 0);
    // ogreNode3->setScale(2, 1.2, 1);
    // ogreNode3->attachObject(ogreEntity3);

    // Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("ogrehead.mesh");
    // Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    // ogreNode4->setPosition(-84, 48, 0);
    // ogreNode4->roll(Ogre::Degree(-90));
    // ogreNode4->attachObject(ogreEntity4);

    // Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
    // spotLight->setDiffuseColour(0, 0, 1.0);
    // spotLight->setSpecularColour(0, 0, 1.0);
    // spotLight->setType(Ogre::Light::LT_SPOTLIGHT);

    // Ogre::SceneNode* spotLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    // spotLightNode->attachObject(spotLight);
    // spotLightNode->setDirection(-1, -1, 0);
    // spotLightNode->setPosition(Ogre::Vector3(200, 200, 0));

    // spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

    Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
    pointLight->setDiffuseColour(0, 0, 1.0);
    pointLight->setSpecularColour(0, 0, 1.0);
    pointLight->setType(Ogre::Light::LT_POINT);

    Ogre::SceneNode* spotLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    spotLightNode->attachObject(pointLight);
    spotLightNode->setPosition(Ogre::Vector3(-20, 0, 0));

    // Ogre::ManualObject* man = mSceneMgr->createManualObject("test");
    // man->begin("Examples/OgreLogo", Ogre::RenderOperation::OT_TRIANGLE_LIST);

    // man->position(-40, 40, -40);
    // man->normal(0, 0, 1);
    // man->textureCoord(0, 0);

    // man->position(-40, -40, -40);
    // man->normal(0, 0, 1);
    // man->textureCoord(0, 1);

    // man->position(40, -40, -40);
    // man->normal(0, 0, 1);
    // man->textureCoord(1, 1);

    // man->position(40, 40, -40);
    // man->normal(0, 0, 1);
    // man->textureCoord(1, 0);

    // man->quad(0, 1, 2, 3);

    // man->end();
    // mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(man);

    // Ogre::ManualObject* man2 = mSceneMgr->createManualObject("test2");
    // man2->begin("Examples/OgreLogo", Ogre::RenderOperation::OT_TRIANGLE_LIST);

    // man2->position(-40, -40, -40);
    // man2->normal(0, 1, 0);
    // man2->textureCoord(0, 0);

    // man2->position(-40, -40, 40);
    // man2->normal(0, 1, 0);
    // man2->textureCoord(0, 1);

    // man2->position(40, -40, 40);
    // man2->normal(0, 1, 0);
    // man2->textureCoord(1, 1);

    // man2->position(40, -40, -40);
    // man2->normal(0, 1, 0);
    // man2->textureCoord(1, 0);

    // man2->quad(0, 1, 2, 3);

    // man2->end();
    // mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(man2);

    mBallEntity = mSceneMgr->createEntity("mySphere", Ogre::SceneManager::PT_SPHERE);
    mBallEntity->setMaterialName("grass.material");

    mBallNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mBallNode->setPosition(-10, -10, -10);
    mBallNode->roll(Ogre::Degree(-90));
    mBallNode->scale(0.1,0.1,0.1);
    mBallNode->attachObject(mBallEntity);

    // Add points to the ball vector

    mPointList.push_back(Ogre::Vector3(-40, -40, -40));
    mPointList.push_back(Ogre::Vector3(40, 40, 40));
    mPointList.push_back(Ogre::Vector3(-40, 40, 40));
    mPointList.push_back(Ogre::Vector3(40, -40, -40));
    mPointList.push_back(Ogre::Vector3(-40, 40, -40));
    mPointList.push_back(Ogre::Vector3(40, 40, -40));

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

    // //Right --not working!!!!
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
        TutorialApplication app;

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
