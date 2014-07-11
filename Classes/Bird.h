#ifndef _BIRD_H
#define _BIRD_H

#include "cocos2d.h"
#include "Globals.h"
USING_NS_CC;

class Bird : public Sprite
{
public:
	Bird();
	~Bird();
	bool init();

	void idle();
	void fly();
	void die();

	CREATE_FUNC(Bird);

private:
	void changeState(BirdState state);

private:
	Action* m_swingAction;
	Action* m_nativeAction;
	BirdState m_currentState;
};

#endif
