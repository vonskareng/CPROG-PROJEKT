#include "Player.h"
#include<iostream>
#include "Enemy.h"
#include "Bullet.h"

using namespace cgame;
using namespace std;

	Player::Player(int x, int y, const char* txt, mouseMovement m, int tr, GameEngine& g, Game& game) : MovableSprite(x, y, txt, m, tr), ge(g), game(game)
	{
	}


	Player::~Player()
	{
	}

	shared_ptr<Player> Player::getInstance(int x, int y, const char* txt, mouseMovement m, int tr, GameEngine& g, Game& game) {
		return shared_ptr<Player>(new Player(x, y, txt, m, tr,g, game));
	}

	void Player::perform(SDL_Event& e) {
		
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
			shared_ptr<Bullet> b = Bullet::getInstance(getRect().x, getRect().y, "assets/bulet_3.png", -1, 0, 0, ge, game);
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
	
