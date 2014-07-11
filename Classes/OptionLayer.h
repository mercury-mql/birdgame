#ifndef _OPTION_LAYER_H
#define _OPTION_LAYER_H

#include "cocos2d.h"
#include "Delegates.h"
USING_NS_CC;


class OptionLayer : public Layer
{
public:
	OptionLayer();
	~OptionLayer();

	bool init();
	CREATE_FUNC(OptionLayer);

	CC_SYNTHESIZE(OptionDelegate*, m_delegator, Delegator);
};

#endif