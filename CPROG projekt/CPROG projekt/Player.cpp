#include "Player.h"
#include<iostream>
#include "Enemy.h"
#include "Bullet.h"

using namespace cgame;
using namespace std;

	Player::Player(int x, int y, const char* txt, mouseMovement m, int tr, GameEngine& g) : MovableSprite(x, y, txt, m, tr), ge(g)
	{
	}


	Player::~Player()
	{
	}

	shared_ptr<Player> Player::getInstance(int x, int y, const char* txt, mouseMovement m, int tr, GameEngine& g) {
		return shared_ptr<Player>(new Player(x, y, txt, m, tr,g));
	}

	void Player::perform(SDL_Event e) {
		
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
			shared_ptr<Bullet> b = Bullet::getInstance(getRect().x, getRect().y, "assets/bullet.png", -1, 0, 0, ge);
			ge.addSprite(b);
		}
	}

	void Player::onCollision(const vector<shared_ptr<Sprite>> sprites) {
		Enemy* e;
		for (shared_ptr<Sprite> s : sprites) {
			if (checkCollision(s) && (e = dynamic_cast<Enemy*>(s.get()))) {
				ge.remove(shared_from_this());
				
			}
		}
		
			
	}
	
