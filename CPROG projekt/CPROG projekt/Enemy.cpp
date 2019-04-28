#include "Enemy.h"
#include "Bullet.h"


using namespace std;
Enemy::Enemy(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g) : MovingSprite(x,y,txt,xrel,yrel,tr), ge(g)
{
}

shared_ptr<Enemy> Enemy::getInstance(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine& g) {
	return shared_ptr<Enemy>(new Enemy(x, y, txt, xrel, yrel, tr, g));
}

void Enemy::onCollision(const vector<std::shared_ptr<Sprite>> sprites) {
	Bullet* b;
	for (shared_ptr<Sprite> s : sprites) {
		if (checkCollision(s) && (b = dynamic_cast<Bullet*>(s.get()))) {
			ge.remove(shared_from_this());

			
		}
	}
}

void Enemy::tick() {
	if (getRect().x > 800) {
		setX(0);
	}
}



Enemy::~Enemy()
{
}
