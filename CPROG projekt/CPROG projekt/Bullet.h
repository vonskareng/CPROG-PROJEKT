#ifndef BULLET_H 
#define BULLET_H 
#include "MovingSprite.h"
#include "GameEngine.h"
#include "Game.h"

	class Bullet : public cgame::MovingSprite, public std::enable_shared_from_this<Bullet>
	{
	public:
		static std::shared_ptr<Bullet> getInstance(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g, Game& game);
		void onCollision(const std::vector<std::shared_ptr<Sprite>> sprites);
		void tick();
		~Bullet();
	private: 
		Bullet(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g, Game& game);
		Game& game;
		cgame::GameEngine& ge;
	};



#endif 