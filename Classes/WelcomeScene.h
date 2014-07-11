#ifndef _WELCOME_SCENE_H
#define _WELCOME_SCENE_H

#include "cocos2d.h"
USING_NS_CC;

class WelcomeLayer : public Layer
{
public:
	WelcomeLayer();
	~WelcomeLayer();

	bool init();
	static Scene* createScene();
	CREATE_FUNC(WelcomeLayer);

private:
	void startPlay(Ref* sender);
};

#endif