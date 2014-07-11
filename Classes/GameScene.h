#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
	bool init();
	void restart();
	CREATE_FUNC(GameScene);
};

#endif