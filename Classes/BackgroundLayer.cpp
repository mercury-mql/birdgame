#include "BackgroundLayer.h"
#include "Globals.h"

BackgroundLayer::BackgroundLayer()
	: m_land1(NULL), m_land2(NULL)
{

}

BackgroundLayer::~BackgroundLayer()
{

}

bool BackgroundLayer::init()
{
	bool ret = false;
	do 
	{
		if (!Layer::init())
		{
			break;
		}

		Sprite* background = NULL;
		time_t now = time(NULL);
		tm* lctime = localtime(&now);
		int hour = lctime->tm_hour;

		auto winSize = Director::getInstance()->getWinSize();

		if (hour > 9 && hour < 17)
		{
			background = Sprite::createWithSpriteFrameName("bg_day.png");
		} 
		else
		{
			background = Sprite::createWithSpriteFrameName("bg_night.png");
		}
		background->setPosition(Point(winSize.width/2, winSize.height/2));
		background->setGlobalZOrder(ZORDER_BACKGROUND);
		this->addChild(background);

		this->m_land1 = Sprite::createWithSpriteFrameName("land.png");
		this->m_land2 = Sprite::createWithSpriteFrameName("land.png");
		auto landWidth = this->m_land1->getContentSize().width;

		this->m_land1->setAnchorPoint(Point::ZERO);
		this->m_land2->setAnchorPoint(Point::ZERO);
		this->m_land1->setPosition(Point::ZERO);
		this->m_land2->setPosition(Point(landWidth, 0));
		this->m_land1->setGlobalZOrder(ZORDER_LAND);
		this->m_land2->setGlobalZOrder(ZORDER_LAND);
		this->addChild(m_land1);
		this->addChild(m_land2);

		this->schedule(schedule_selector(BackgroundLayer::scrollLand));

		ret = true;
	} while (0);
	return ret;
}

void BackgroundLayer::scrollLand(float dt)
{
	auto x1 = m_land1->getPositionX();
	auto x2 = m_land2->getPositionX();

	x1 -= MOVE_SPEED;
	x2 -= MOVE_SPEED;

	auto landWidth = m_land1->getContentSize().width;

	if (x1 < -landWidth )
	{
		x1 = landWidth;
		x2 = 0;
	}

	if (x2 < -landWidth)
	{
		x1 = 0;
		x2 = landWidth;
	}

	m_land1->setPositionX(x1);
	m_land2->setPositionX(x2);

}