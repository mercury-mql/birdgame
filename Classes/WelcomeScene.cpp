#include "WelcomeScene.h"
#include "BackgroundLayer.h"
#include "GameScene.h"
#include "Bird.h"
#include "Globals.h"
#include <time.h>


WelcomeLayer::WelcomeLayer()
{

}

WelcomeLayer::~WelcomeLayer()
{

}

bool WelcomeLayer::init()
{
	bool ret = false;
	do 
	{
		if (!Layer::init())
		{
			break;
		}

		auto winSize = Director::getInstance()->getWinSize();

		auto background = BackgroundLayer::create();
		this->addChild(background);

		auto title = Sprite::createWithSpriteFrameName("title.png");
		title->setPosition(Vec2(winSize.width/2, winSize.height*4/5));
		this->addChild(title);

		auto copyright = Sprite::createWithSpriteFrameName("brand_copyright.png");
		copyright->setPosition(Vec2(winSize.width/2, winSize.height/5));
		this->addChild(copyright);

		auto bird = Bird::create();
		bird->idle();
		bird->setPosition(Point(winSize.width/2, winSize.height*3/5));
		this->addChild(bird);

		auto playSpriteNormal = Sprite::createWithSpriteFrameName("button_play.png");
		auto menuItemSprite = MenuItemSprite::create(playSpriteNormal, playSpriteNormal, NULL, CC_CALLBACK_1(WelcomeLayer::startPlay, this));
		menuItemSprite->setPosition(Vec2(winSize.width/2, winSize.height*2/5));
		auto menu = Menu::create(menuItemSprite, NULL);
		menu->setPosition(Point::ZERO);
		this->addChild(menu);

		ret = true;
	} while (0);
	return ret;
}


void WelcomeLayer::startPlay(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create());
}

Scene* WelcomeLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = WelcomeLayer::create();
	scene->addChild(layer);
	return scene;
}