#include "StatusLayer.h"
#include "Number.h"

StatusLayer::StatusLayer()
	: m_scoreNode(NULL),
	m_getReady(NULL),
	m_tutorial(NULL)
{

}

StatusLayer::~StatusLayer()
{

}

bool StatusLayer::init()
{
	bool ret = false;
	do 
	{
		if (!Layer::init())
		{
			break;
		}

		m_winSize = Director::getInstance()->getWinSize();
		showReadyStatus();

		ret = true;
	} while (0);
	return ret;
}

void StatusLayer::onGameStarted()
{
	showStartStatus();
}

void StatusLayer::onGamePlaying(int score)
{
	m_scoreNode->removeFromParent();
	m_scoreNode = NumberManager::getInstance()->convertNumberToNode("font", 48, score);
	m_scoreNode->setPosition(m_winSize.width/2, m_winSize.height/2);
	this->addChild(m_scoreNode);
}

void StatusLayer::onGameEnded(int current, int best)
{

}

void StatusLayer::showStartStatus()
{
	m_getReady->runAction(FadeOut::create(0.4f));
	m_tutorial->runAction(FadeOut::create(0.4f));
}

void StatusLayer::showReadyStatus()
{
	m_scoreNode = NumberManager::getInstance()->convertNumberToNode("font", 48, 1234567890);
	m_scoreNode->setPosition(Point(m_winSize.width/2, m_winSize.height*5/6));
	this->addChild(m_scoreNode);

	m_getReady = Sprite::createWithSpriteFrameName("text_ready.png");
	m_getReady->setPosition(Point(m_winSize.width/2, m_winSize.height*2/3));
	this->addChild(m_getReady);

	m_tutorial = Sprite::createWithSpriteFrameName("tutorial.png");
	m_tutorial->setPosition(Point(m_winSize.width/2, m_winSize.height/2));
	this->addChild(m_tutorial);
}