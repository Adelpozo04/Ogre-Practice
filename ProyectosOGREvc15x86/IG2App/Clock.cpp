#include "Clock.h"

Clock::Clock(SceneNode* node)
{

    mNode = node;
    mSM = mNode->getCreator();

    clockNode = mNode->createChildSceneNode();
    hoursNode = clockNode->createChildSceneNode();
    handNode = clockNode->createChildSceneNode();
    Ogre::SceneNode* mHourNode;
    Ogre::SceneNode* hourHandNode;

    double angle = (360 / 12);

    for (int i = 0; i < 12; i++) {

        Entity* hour = mSM->createEntity("sphere.mesh");
        mHourNode = hoursNode->createChildSceneNode();
        
        mHourNode->setPosition(Ogre::Math::Cos(Ogre::Degree(angle * i)) * 100, Ogre::Math::Sin(Ogre::Degree(angle * i)) * 100, 0);

        if (i % 2 == 0) {

            mHourNode->setScale(0.05, 0.05, 0.05);

        }
        else {

            mHourNode->setScale(0.1, 0.1, 0.1);

        }

        mHourNode->attachObject(hour);

    }

    for (int i = 0; i < 3; ++i) {

        Entity* hand = mSM->createEntity("cube.mesh");
        hourHandNode = handNode->createChildSceneNode();

        hourHandNode->setScale(0.025 * (i + 1), 0.20 * (4 - i), 0.02);

        
        if (i % 4 == 0) {
            hourHandNode->setPosition(0, hourHandNode->getPosition().y + 40, 0);
        }
        else if (i % 4 == 1) {
            hourHandNode->setPosition(hourHandNode->getPosition().x + 30, 0, 0);
        }
        else if (i % 4 == 2) {
            hourHandNode->setPosition(0, hourHandNode->getPosition().y - 20, 0);
        }
        else {
            hourHandNode->setPosition(hourHandNode->getPosition().x, 0, 0);
        }

        hourHandNode->roll(Ogre::Degree(-90 * i));
        

        hourHandNode->attachObject(hand);

    }

}

Clock::~Clock()
{



}

bool Clock::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    
    if (evt.keysym.sym == SDLK_g) {
        hoursNode->roll(Ogre::Degree(3));
    }
    else if (evt.keysym.sym == SDLK_h) {
        Ogre::SceneNode* nodo;
        for (int i = 0; i < 12; i++) {
            nodo = mSM->getSceneNode("Hour " + std::to_string(i + 1));

            //Si los nodos no tienen nombre, se usa Iterator
            nodo->yaw(Ogre::Degree(3));

        }
    }

    return true;

}
