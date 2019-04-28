#include "AnimatedEnemy.h"
#include "Bullet.h"


using namespace std;
using namespace cgame;
AnimatedEnemy::AnimatedEnemy(int x, int y, const char* txt, int tr, GameEngine& ge) : AnimatedSprite(x, y, txt, tr), ge(ge)
{
	life = 10;
}

void AnimatedEnemy::onCollision(const std::vector<std::shared_ptr<Sprite>> sprites)
{
	Bullet* b;
	for (shared_ptr<Sprite> s : sprites) {
		if (checkCollision(s) && (b = dynamic_cast<Bullet*>(s.get()))) {
			if (life != 0)
				life--;
			else
				ge.remove(shared_from_this());
		}
	}
}

shared_ptr<AnimatedEnemy> AnimatedEnemy::getInstance(int x, int y, const char* txt, int tr, GameEngine& ge) {
	return shared_ptr<AnimatedEnemy>(new AnimatedEnemy(x, y, txt, tr, ge));
}


AnimatedEnemy::~AnimatedEnemy()
{
}
