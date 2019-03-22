#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
using namespace cgame;
using namespace std;
Game::Game()
{
	initialize();
}

void Game::initialize() {
	shared_ptr<Player> player = Player::getInstance(300, 300, "assets/1.png", enableMouseXandY, 0, e);
	shared_ptr<Enemy> e1 = Enemy::getInstance(0, 200, "assets/11B.png", 1, 0, 0, e);
	shared_ptr<Enemy> e2 = Enemy::getInstance(0, 50, "assets/11B.png", 1, 0, 0, e);
	shared_ptr<Enemy> e3 = Enemy::getInstance(0, 350, "assets/11B.png", 1, 0, 0, e);
	one = new Level();
	one->levelSprites.push_back(player);
	one->levelSprites.push_back(e1);
	one->levelSprites.push_back(e2);
	one->levelSprites.push_back(e3);
	one->background = "assets/2.bmp";
	e.addLevel(one);
}

void Game::run() {
	e.run();
}
Game::~Game()
{
}
