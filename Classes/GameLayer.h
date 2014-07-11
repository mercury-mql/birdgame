#ifndef _GAME_LAYER_H
#define _GAME_LAYER_H

#include "cocos2d.h"
#include "OptionLayer.h"
#include "Bird.h"
#include "Globals.h"
#include "Delegates.h"
USING_NS_CC;

class GameLayer : public Layer, public OptionDelegate
{
public:
	GameLayer();
	~GameLayer();

	bool init();
	CREATE_FUNC(GameLayer);

	void onTouch();
	void update(float dt);

	CC_SYNTHESIZE(StatusDelegate*, m_statusDelegator, StatusDelegator);
    CC_SYNTHESIZE(PhysicsWorld*, m_world, PhysicsWorld);

private:
	void createPipes();
	void onScroll(float dt);
	bool onContactBegan(PhysicsContact& contact);

	int pipeRandomHeight();
	void rotateBird();
	void checkHit();
	void gameOver();

private:
	Bird* m_bird;
	int m_score;
	GameStatus m_status;
	Vector<Node*> m_pipes;
};

#endif