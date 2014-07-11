#ifndef _GLOBALS_H
#define _GLOBALS_H

#define MOVE_SPEED 1

#define BIRD_RADIUS 15

#define PIPE_COUNT 2
#define PIPE_WIDTH 52
#define PIPE_HEIGHT 320
#define PIPE_DISTANCE 100
#define PIPE_INTERVAL 180
#define WAIT_DISTANCE 200

#define TAG_UP_PIPE  21
#define TAG_DOWN_PIPE 12
#define TAG_PIPE_PASS 30
#define TAG_PIPE_NEW 31

#define ZORDER_BACKGROUND 0
#define ZORDER_PIPE 10
#define ZORDER_LAND 20
#define ZORDER_BIRD 30
#define ZORDER_STATUS 40



enum BirdState
{
	Bird_IDLE,
	Bird_FLY,
	Bird_DIE,
};


enum GameStatus
{
	Game_READY,
	Game_PLAYING,
	Game_Ended,
};

#endif