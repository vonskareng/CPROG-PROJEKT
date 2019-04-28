#ifndef PLAYER_H
#define PLAYER_H 
#include "MovableSprite.h"
#include <vector>
#include "GameEngine.h"
#include "Game.h"



class Player : public cgame::MovableSprite, public std::enable_shared_from_this<Player>
	{
	public:
		static std::shared_ptr<Player> getInstance(int x, int y, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g, Game& game);
		~Player();
		void perform(SDL_Event& e);
		void onCollision(const std::vector<std::shared_ptr<Sprite>> sprites);
	private: 
		Player(int x, int y, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g, Game& game);
		cgame::GameEngine& ge;
		Game& game;
		
	};



#endif