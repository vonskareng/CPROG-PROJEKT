#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "MyTextBox.h"
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
	shared_ptr<MyTextBox> t = MyTextBox::getInstance(30, 30, "assets/tw.png", 0, "assets/ARLRDBD.TTF", 50, { 255,255,255,255 }, e);
	one = new Level();
	one->levelSprites.push_back(t);
	two = new Level();
	two->levelSprites.push_back(player);
	two->levelSprites.push_back(e1);
	two->levelSprites.push_back(e2);
	two->levelSprites.push_back(e3);
	two->background = "assets/2.bmp";
	e.addLevel(one);
	e.addLevel(two);
}

void Game::run() {
	e.run();
}
Game::~Game()
{
}
