#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <SDL_keycode.h>
#include <OgreEntity.h>

using namespace Ogre;

class Clock : public OgreBites::InputListener
{

public:

	Clock(SceneNode* node);
	~Clock();

	SceneNode* clockNode, * hoursNode, * handNode;

protected:

	bool keyPressed(const OgreBites::KeyboardEvent& evt);

	SceneNode* mNode;
	SceneManager* mSM;

};

