/*
-----------------------------------------------------------------------------
This source file is part of ogre-procedural

For the latest info, see http://code.google.com/p/ogre-procedural/

Copyright (c) 2010-2012 Michael Broutin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef LUATESTS_H
#define LUATESTS_H

#include "BaseApplication.h"
#include "Procedural.h"
#include "Ogre.h"
using namespace Ogre;
using namespace Procedural;

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}



class LuaTests : public BaseApplication
{

	Ogre::OverlayElement* mTextMessage;
	
	void reloadScript();
	void checkScriptModified();
	void peekFirstScript();

protected:

	bool keyReleased( const OIS::KeyEvent &arg )
	{
		if (arg.key == OIS::KC_F5)
		{
			reloadScript();
		}
		return BaseApplication::keyReleased(arg);
	}

	bool keyPressed(const OIS::KeyEvent &arg)
	{
		return BaseApplication::keyPressed(arg);
	}

	virtual void createScene(void);

	virtual void createCamera(void);

	virtual void createViewports(void);

	virtual bool frameStarted(const FrameEvent& evt);

	virtual void destroyScene(void);

	static LuaTests* mInstance;

	std::vector<Entity*> mEntities;
	std::vector<MaterialPtr> mMaterials;
	std::vector<SceneNode*> mSceneNodes;

	Ogre::String mCurrentScriptName;
	time_t mCurrentScriptReloadTime;

public:

	void addMesh(const char* meshName, const char* materialName="Examples/Rockwall")
	{
		Entity* entity = mSceneMgr->createEntity(meshName);
		entity->setMaterialName(materialName);
		SceneNode* sceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		sceneNode->attachObject(entity);
		mSceneNodes.push_back(sceneNode);
		mEntities.push_back(entity);
	}

	void addMaterial(const char* textureName, const char* materialName)
	{
		Ogre::MaterialPtr demoMaterial = Ogre::MaterialManager::getSingletonPtr()->create(std::string(materialName), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);			
		demoMaterial->getTechnique(0)->getPass(0)->setDiffuse(Ogre::ColourValue::White);
		demoMaterial->getTechnique(0)->getPass(0)->createTextureUnitState(std::string(textureName));
		mMaterials.push_back(demoMaterial);
	}
		

	static LuaTests* getInstance()
	{
		return mInstance;
	}

	LuaTests()
	{
		mInstance = this;
	}

};

#endif