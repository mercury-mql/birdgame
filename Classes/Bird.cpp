#include "Bird.h"
#include <math.h>

Bird::Bird()
	: m_swingAction(NULL), 
	m_nativeAction(NULL),
	m_currentState(Bird_IDLE)
{

}

Bird::~Bird()
{

}


bool Bird::init()
{
	bool ret = false;
	do 
	{
		int index = rand()%3;
		std::string name = String::createWithFormat("bird%d", index)->_string;

		if (!Sprite::initWithSpriteFrameName(name + "_0.png"))
		{
			break;
		}

		auto nativeAnimation = AnimationCache::getInstance()->getAnimation(name);
		auto nativeAnimate = Animate::create(nativeAnimation);
		this->m_nativeAction= RepeatForever::create(nativeAnimate);

		auto upAction = MoveBy::create(0.4f, Point(0, 8));
		auto downAction = upAction->reverse();
		this->m_swingAction = RepeatForever::create(Sequence::create(upAction, downAction, NULL));

		ret = true;
	} while (0);
	return ret;
}

void Bird::idle()
{
	changeState(Bird_IDLE);
	this->runAction(this->m_nativeAction);
	this->runAction(this->m_swingAction);
}

void Bird::fly()
{
	changeState(Bird_FLY);
	this->stopAction(this->m_swingAction);
}

void Bird::die()
{
	changeState(Bird_DIE);
	this->stopAllActions();
}

void Bird::changeState(BirdState state)
{
	m_currentState = state;
}