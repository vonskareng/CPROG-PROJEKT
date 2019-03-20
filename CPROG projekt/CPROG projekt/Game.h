#ifndef GAME_H
#define GAME_H
#include "GameEngine.h"

class Game
{
public:
	Game();
	void initialize();
	void run();
	~Game();
private:
	cgame:: GameEngine e;
	cgame::Level* one;
	cgame::Level* two;

};

#endif
