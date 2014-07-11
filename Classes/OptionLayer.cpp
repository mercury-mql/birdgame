#include "OptionLayer.h"

OptionLayer::OptionLayer()
	: m_delegator(NULL)
{

}

OptionLayer::~OptionLayer()
{

}

bool OptionLayer::init()
{
	bool ret = false;
	do 
	{
		if (!Layer::init())
		{
			break;
		}

		auto dispatcher = Director::getInstance()->getEventDispatcher();
		auto listener = EventListenerTouchAllAtOnce::create();
		listener->onTouchesBegan = [&]( const std::vector< Touch * >& touches, Event * event){
			if (m_delegator)
			{
				m_delegator->onTouch();
			}			
		};
		dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

		ret = true;
	} while (0);
	return ret;
}