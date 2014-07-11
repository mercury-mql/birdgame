#include "GameScene.h"
#include "GameLayer.h"
#include "OptionLayer.h"
#include "StatusLayer.h"
#include "BackgroundLayer.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

bool GameScene::init()
{
	bool ret = false;
	do 
	{
		if (!Scene::init())
		{
			break;
		}

		if (!Scene::initWithPhysics())
		{
			break;
		}
		this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
		this->getPhysicsWorld()->setGravity(Vect(0, -900));

		auto background = BackgroundLayer::create();
		this->addChild(background);

		auto statusLayer = StatusLayer::create();

		auto gameLayer = GameLayer::create();
		gameLayer->setPhysicsWorld(this->getPhysicsWorld());
		if (statusLayer)
		{
			gameLayer->setStatusDelegator(statusLayer);
		}
		this->addChild(gameLayer);

		auto optionLayer = OptionLayer::create();
		optionLayer->setDelegator(gameLayer);
		this->addChild(optionLayer);		

		this->addChild(statusLayer);

		ret = true;
	} while (0);
	return ret;
}

void GameScene::restart()
{

}