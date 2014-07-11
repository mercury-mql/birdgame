#include "LoadScene.h"
#include "WelcomeScene.h"

LoadScene::LoadScene()
{

}

LoadScene::~LoadScene()
{

}

bool LoadScene::init()
{
	return Scene::init();
}

void LoadScene::onEnter()
{
	auto background = Sprite::create("images/splash.png");
	auto visibleSize = Director::getInstance()->getWinSize();
	background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
	this->addChild(background);

	Director::getInstance()->getTextureCache()->addImageAsync("images/atlas.png", CC_CALLBACK_1(LoadScene::onLoadImageDone, this));
}

void LoadScene::onLoadImageDone(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("images/atlas.plist", texture);
	
	loadBirdAnimation(0, 3);
	loadBirdAnimation(1, 3);
	loadBirdAnimation(2, 3);

	auto transition = TransitionFade::create(1.5f, WelcomeLayer::createScene());
	Director::getInstance()->replaceScene(transition);
}

void LoadScene::loadBirdAnimation(int birdIndex, int picNum)
{
	Vector<SpriteFrame*> frames;
	for (int i=0; i<picNum; i++)
	{
		std::string name = String::createWithFormat("bird%d_%d.png", birdIndex, i)->_string;
		frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(name));
	}
	std::string animationName = String::createWithFormat("bird%d", birdIndex)->_string;
	auto animation = Animation::createWithSpriteFrames(frames, 0.1f, 1);
	AnimationCache::getInstance()->addAnimation(animation, animationName);
}