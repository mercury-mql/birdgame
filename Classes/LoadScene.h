#ifndef _LOADSCENE_H
#define _LOADSCENE_H

#include "cocos2d.h"
USING_NS_CC;

class LoadScene : public Scene
{
public:
	LoadScene();
	~LoadScene();

	bool init();

	void onEnter();

	CREATE_FUNC(LoadScene);

private:
	void onLoadImageDone(Texture2D* texture);
	void loadBirdAnimation(int birdIndex, int picNum);

};

#endif