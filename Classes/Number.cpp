#include "Number.h"

NumberManager::NumberManager()
{

}

NumberManager::~NumberManager()
{

}

Node* NumberManager::convertNumberToNode(const std::string& serialName, int base, int number)
{
	int totalWidth = 0;
	auto node = Node::create();
	std::string fontNameForZero = serialName + String::createWithFormat("_0%d.png", base)->getCString();
	auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(fontNameForZero);
	if (NULL == spriteFrame)
	{
		return NULL;
	}

	auto spriteForZero = Sprite::createWithSpriteFrame(spriteFrame);
	auto size = spriteForZero->getContentSize();
	int numberWidth = size.width;
	int numberHeight = size.height;

	if (0 == number)
	{		
		node->addChild(spriteForZero);
		spriteForZero->setAnchorPoint(Point::ZERO);
		spriteForZero->setPosition(Point::ZERO);
		node->setContentSize(size);
	}
	else
	{
		int temp = 0;
		while(number > 0)
		{
			temp = number % 10;
			number = number/10;

			std::string tempNumberName = serialName + String::createWithFormat("_0%d.png", temp + base)->getCString();
			auto sprite = Sprite::createWithSpriteFrameName(tempNumberName);
			sprite->setAnchorPoint(Point::ZERO);
			node->addChild(sprite);
			totalWidth += numberWidth;
		}

		auto children = node->getChildren();
		auto childrenCount = node->getChildrenCount();
		bool isOddCount = childrenCount % 2;
		auto halfCount = childrenCount/2;
		auto xdelta = isOddCount ? (-halfCount*numberWidth - numberWidth/2) : (-halfCount*numberWidth);
		for (int i = childrenCount-1, j=0; i>=0; i--, j++)
		{
			auto sprite = children.at(i);
			sprite->setPosition(Point(xdelta + j*numberWidth, 0));
		}
		node->setContentSize(Size(totalWidth, numberHeight));		
	}
	return node;
}

NumberManager* NumberManager::getInstance()
{
	static NumberManager mgr;
	return &mgr;
}