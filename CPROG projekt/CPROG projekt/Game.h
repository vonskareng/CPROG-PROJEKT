#ifndef GAME_H
#define GAME_H
#include "GameEngine.h"
#include "TextWindow.h"
#include "AnimatedEnemy.h"

class Game
{
public:
	Game();
	void addKill();
	int getKills();
	void initialize();
	void run();
	void changeLevel();
	~Game();
private:
	int killCount = 0;
	cgame:: GameEngine e;
	cgame::Level* one;
	cgame::Level* two;
	cgame::Level* three;
};

#endif
