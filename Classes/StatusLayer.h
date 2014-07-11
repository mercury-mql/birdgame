#ifndef _STATUS_LAYER_H
#define _STATUS_LAYER_H

#include "cocos2d.h"
#include "GameLayer.h"
USING_NS_CC;


class StatusLayer : public Layer, public StatusDelegate
{
public:
	StatusLayer();
	~StatusLayer();

	bool init();
	CREATE_FUNC(StatusLayer);

	void onGameStarted();
	void onGamePlaying(int score);
	void onGameEnded(int current, int best);

private:
	void showReadyStatus();
	void showStartStatus();

private:
	Node* m_scoreNode;
	Sprite* m_getReady;
	Sprite* m_tutorial;
	Size m_winSize;
};

#endif