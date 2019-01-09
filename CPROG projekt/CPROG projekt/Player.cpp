#include "Player.h"

using namespace cgame;

	Player::Player(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr, GameEngine& g) : MovableSprite(x, y, w, h, txt, m, tr), ge(g)
	{
	}


	Player::~Player()
	{
	}

	Player* Player::getInstance(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr, GameEngine& g) {
		return new Player(x, y, w, h, txt, m, tr,g);
	}

	void Player::shoot() {

	}

	void Player::onCollision(std::vector <Sprite*> sprites) {
		for (Sprite* s : sprites) {
			if (checkCollision(s)) {
				ge.remove(this);
			}
		}
	}
	
