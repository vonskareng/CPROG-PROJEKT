#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

using namespace cgame;
using namespace std;
	Bullet::Bullet(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine g) : MovingSprite(x, y, txt, xrel, yrel, tr), ge(g)
		{
		}

	void Bullet::onCollision(const std::vector<std::shared_ptr<Sprite>> sprites) {
		Enemy* e;
		for (shared_ptr<Sprite> s : sprites) {
			if (checkCollision(s) && (e = dynamic_cast<Enemy*>(s.get()))) {
				ge.remove(shared_ptr<Sprite>(shared_from_this()));
			}
		}
	}

	void Bullet::tick() {
		if (getRect().x < 0) {
			ge.remove(shared_ptr<Sprite>(shared_from_this()));
		}
	}



	Bullet::~Bullet()
	{
	}

	shared_ptr<Bullet> Bullet::getInstance(int x, int y, const char* txt, int xrel, int yrel, int tr, cgame::GameEngine g) {
		return shared_ptr<Bullet>(new Bullet(x, y, txt, xrel, yrel, tr, g));
	}

