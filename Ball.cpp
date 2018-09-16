/*
-----------------------------------------------------------------------------
Filename:    Ball.cpp
-----------------------------------------------------------------------------
*/

#include "Ball.h"

Ball::Ball(Ogre::SceneManager* scnMgr,
	Ogre::Vector3 pos, Ogre::Vector3 dir, int spd)
: mMoveSpd(spd), 
mDirection(dir),
mBallEntity(0),
mBallNode(0),
Ogre::SceneManager* scnMgr(scnMgr)
{
	mBallEntity = scnMgr->createEntity("1", Ogre::SceneManager::PT_SPHERE);
  mBallEntity->setMaterialName("grass.material");

  mBallNode = scnMgr->getRootSceneNode()->createChildSceneNode();
  mBallNode->setPosition(pos);
  mBallNode->roll(Ogre::Degree(-90));
  mBallNode->scale(0.1,0.1,0.1);
  mBallNode->attachObject(mBallEntity);
}

Ogre::Real Ball::getSpeed(void){
	return mMoveSpd;
}

Ogre::Vector3 getDirection(void){
	return mDirection;
}

Ogre::Vector3 getPosition(void){
	return mBallNode->getPosition();
}

void translate(Ogre::Vector3 translation){
	mBallNode->translate(translation);
}