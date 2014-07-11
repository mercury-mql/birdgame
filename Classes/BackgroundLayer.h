#ifndef _BACKGROUND_LAYER_H
#define _BACKGROUND_LAYER_H

#include "cocos2d.h"
USING_NS_CC;

class BackgroundLayer : public Layer
{
public:
	BackgroundLayer();
	~BackgroundLayer();
	bool init();
	CREATE_FUNC(BackgroundLayer);

private:
	void scrollLand(float dt);

private:
	Sprite* m_land1;
	Sprite* m_land2;
};

#endif
