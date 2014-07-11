#ifndef _DELEGATES_H
#define _DELEGATES_H

class OptionDelegate
{
public:
	virtual void onTouch() = 0;
};

class StatusDelegate
{
public:
	virtual void onGameStarted() = 0;
	virtual void onGamePlaying(int score) = 0;
	virtual void onGameEnded(int current, int best) = 0;
};

#endif