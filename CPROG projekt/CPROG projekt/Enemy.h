#ifndef ENEMY_H 
#define ENEMY_H 
#include "MovingSprite.h"
#include "GameEngine.h"

class Enemy : public cgame::MovingSprite, public std::enable_shared_from_this<Enemy>
{
public:
	static std::shared_ptr<Enemy> getInstance(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g);
	void onCollision(const std::vector<std::shared_ptr<Sprite>> sprites);
	void tick();
	
	~Enemy();
private:	
	Enemy(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g);
	cgame::GameEngine ge;
};

#endif