#include "Player.h"

using namespace cgame;
using namespace std;

	Player::Player(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr, GameEngine& g) : MovableSprite(x, y, w, h, txt, m, tr), ge(g)
	{
	}


	Player::~Player()
	{
	}

	shared_ptr<Player> Player::getInstance(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr, GameEngine& g) {
		return shared_ptr<Player>(new Player(x, y, w, h, txt, m, tr,g));
	}

	void Player::shoot() {

	}

	void Player::onCollision(vector<shared_ptr<Sprite>> sprites) {
		for (shared_ptr<Sprite> s : sprites) {
			if (checkCollision(s)) {
				ge.remove(shared_ptr<Sprite>(shared_from_this()));
			}
		}
	}
	
