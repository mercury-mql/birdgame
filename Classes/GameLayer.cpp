#include "GameLayer.h"
#include "Globals.h"
#include <cstdlib>


GameLayer::GameLayer()
	: m_statusDelegator(NULL), m_world(NULL), m_bird(NULL),
	m_score(0), m_status(Game_READY)
{

}

GameLayer::~GameLayer()
{

}

bool GameLayer::init()
{
	bool ret = false;
	do 
	{
		if (!Layer::init())
		{
			break;
		}

		auto winSize = Director::getInstance()->getWinSize();

		auto birdCircle = PhysicsBody::createCircle(BIRD_RADIUS);
		birdCircle->setDynamic(true);
		birdCircle->setLinearDamping(0.0f);
		birdCircle->setGravityEnable(false);
		birdCircle->setCategoryBitmask(1);
		birdCircle->setCollisionBitmask(1);
		birdCircle->setContactTestBitmask(1);
		

		m_bird = Bird::create();
		m_bird->setGlobalZOrder(ZORDER_BIRD);
		m_bird->setPhysicsBody(birdCircle);
		m_bird->setPosition(Vec2(winSize.width/2, winSize.height/2));
		m_bird->idle();
		this->addChild(m_bird);

		auto grandBody = PhysicsBody::createEdgeBox(Size(288, 112));
		grandBody->setDynamic(false);
		grandBody->setLinearDamping(0.0f);
		grandBody->setCategoryBitmask(1);
		grandBody->setCollisionBitmask(1);
		grandBody->setContactTestBitmask(1);

		auto grandNode = Node::create();
		grandNode->setGlobalZOrder(ZORDER_LAND);
		grandNode->setPhysicsBody(grandBody);
		grandNode->setPosition(Point(144, 56));
		this->addChild(grandNode);

		auto listener = EventListenerPhysicsContact::create();
		listener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegan, this);
		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

		this->schedule(schedule_selector(GameLayer::onScroll));
		this->scheduleUpdate();

		ret = true;
	} while (0);
	return ret;
}

void GameLayer::onTouch()
{
	if (m_status == Game_Ended)
	{
		return;
	}

	if (m_status == Game_READY)
	{
		m_status = Game_PLAYING;
		createPipes();
		m_statusDelegator->onGameStarted();
		m_bird->fly();
		m_bird->getPhysicsBody()->setGravityEnable(true);
	} 
	else
	{
		m_bird->getPhysicsBody()->setVelocity(Vect(0, 260));
	}
}

void GameLayer::createPipes()
{
	for (int i=0; i<PIPE_COUNT; i++)
	{
		auto pipeUp = Sprite::createWithSpriteFrameName("pipe_up.png");
		auto pipeDown = Sprite::createWithSpriteFrameName("pipe_down.png");
		auto pipePair = Node::create();

		//pipeUp->setAnchorPoint(Point::ZERO);
		pipeUp->setPosition(Point::ZERO);
		//pipeDown->setAnchorPoint(Point::ZERO);
		pipeDown->setPosition(Point(0, PIPE_HEIGHT + PIPE_DISTANCE));

		auto pipePairBody = PhysicsBody::create();
		pipePairBody->addShape(PhysicsShapeBox::create(pipeDown->getContentSize()));
		pipePairBody->addShape(PhysicsShapeBox::create(pipeUp->getContentSize(),PHYSICSBODY_MATERIAL_DEFAULT, Vec2(0, PIPE_HEIGHT + PIPE_DISTANCE)));
		pipePairBody->setDynamic(false);
		pipePairBody->setCategoryBitmask(1);
		pipePairBody->setCollisionBitmask(1);
		pipePairBody->setContactTestBitmask(1);

		pipePair->addChild(pipeDown, 0, TAG_DOWN_PIPE);
		pipePair->addChild(pipeUp, 0, TAG_UP_PIPE);
		
		pipePair->setPhysicsBody(pipePairBody);
		pipePair->setPosition(Point(WAIT_DISTANCE + i*PIPE_INTERVAL, pipeRandomHeight()));
		pipePair->setTag(TAG_PIPE_NEW);
		pipePair->setGlobalZOrder(ZORDER_BIRD);

		this->addChild(pipePair);

		m_pipes.pushBack(pipePair);
	}
}

int GameLayer::pipeRandomHeight()
{
	Size size = Director::getInstance()->getVisibleSize();
	int height = rand() % (int)( 2*PIPE_HEIGHT + PIPE_DISTANCE - size.height - 50 )/2;
	return height;
}

void GameLayer::onScroll(float dt)
{
	for (Node* pipePair : m_pipes)
	{
		auto x = pipePair->getPositionX();
		auto y = pipePair->getPositionY();
		x -= 3;
		if (x < -PIPE_WIDTH)
		{
			x = Director::getInstance()->getVisibleSize().width;
			pipePair->setTag(TAG_PIPE_NEW);
		}

		pipePair->setPosition(x, y);
	}
}

bool GameLayer::onContactBegan(PhysicsContact& contact)
{
	this->gameOver();
	return true;
}

void GameLayer::rotateBird() 
{
	float verticalSpeed = m_bird->getPhysicsBody()->getVelocity().y;
	m_bird->setRotation(std::min(std::max(-90, (int)(verticalSpeed*0.2 + 60)), 30));
}

void GameLayer::checkHit()
{
	for (Node* pipePair : m_pipes)
	{
		auto pipeX = pipePair->getPositionX();
		auto birdX = m_bird->getPositionX();
		if (pipeX < birdX)
		{
			m_score++;
			m_statusDelegator->onGamePlaying(m_score);
			pipePair->setTag(TAG_PIPE_PASS);
		}
	}
	
}

void GameLayer::update(float dt)
{
	if (m_status == Game_PLAYING)
	{
		this->rotateBird();
		this->checkHit();
	}	
}

void GameLayer::gameOver()
{

}