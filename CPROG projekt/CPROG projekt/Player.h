#ifndef PLAYER_H
#define PLAYER_H 
#include "MovableSprite.h"
#include <vector>
#include "GameEngine.h"
#include <iostream>


class Player : public cgame::MovableSprite
	{
	public:
		static Player* getInstance(int x, int y, int w, int h, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g);
		~Player();
		void shoot();
		void onCollision(std::vector<Sprite*> sprites);
	private: 
		Player(int x, int y, int w, int h, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g);
		cgame::GameEngine& ge;
	};



#endif