#ifndef _NUMBER_H
#define _NUMBER_H

#include "cocos2d.h"
USING_NS_CC;

class NumberManager : public Ref
{
public:
	static NumberManager* getInstance();
	~NumberManager();

	Node* convertNumberToNode(const std::string& serialName, int base, int number);

private:
	NumberManager();

};

#endif