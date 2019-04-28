#ifndef ANIMATEDENEMY_H
#define ANIMATEDENEMY_H
#include "GameEngine.h"
#include "AnimatedSprite.h"


class AnimatedEnemy : public cgame::AnimatedSprite, public std::enable_shared_from_this<AnimatedEnemy>
{
public:
	void onCollision(const std::vector<std::shared_ptr<Sprite>> sprites);


	static std::shared_ptr<AnimatedEnemy> getInstance(int x, int y, const char* txt, int tr, cgame::GameEngine& ge);
	~AnimatedEnemy();
private:
	cgame::GameEngine& ge;
	int life;
	AnimatedEnemy(int x, int y, const char* txt, int tr, cgame::GameEngine& ge);
};

#endif

