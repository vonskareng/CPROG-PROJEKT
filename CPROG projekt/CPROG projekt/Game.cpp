#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GameTextBox.h"
#include <iostream>
using namespace cgame;
using namespace std;
Game::Game()
{
	initialize();
}
void Game::addKill()
{
	killCount++;
}
int Game::
getKills()
{
	return killCount;
}
void func() {
	cout << "installerad funktion" << endl;
}

void Game::initialize() {
	shared_ptr<Player> player = Player::getInstance(300, 300, "assets/1.png", enableMouseXandY, 0, e, *this);
	shared_ptr<Enemy> e1 = Enemy::getInstance(0, 200, "assets/11B.png", 1, 0, 0, e);
	shared_ptr<Enemy> e2 = Enemy::getInstance(0, 50, "assets/11B.png", 1, 0, 0, e);
	shared_ptr<Enemy> e3 = Enemy::getInstance(0, 350, "assets/11B.png", 1, 0, 0, e);
	shared_ptr<AnimatedEnemy> a1 = AnimatedEnemy::getInstance(0, 200, "assets/10.png", 5, e);
	a1->addSpritePicture("assets/10B.png");
	shared_ptr<GameTextBox> t = GameTextBox::getInstance(30, 30, "assets/tw.png", 0, "assets/ARLRDBD.TTF", 50, { 255,255,255,255 }, e);
	
	void(*f)() = func;
	void(GameTextBox::*func)() = &GameTextBox::inputDone;
	
	e.installCommand(f, SDLK_RSHIFT);
	e.installCommand(func, t.get(), SDLK_RETURN);
	
	one = new Level();
	one->levelSprites.push_back(t);
	two = new Level();
	two->levelSprites.push_back(player);
	two->levelSprites.push_back(e1);
	two->levelSprites.push_back(e2);
	two->levelSprites.push_back(e3);
	two->background = "assets/2.bmp";
	three = new Level();
	three->levelSprites.push_back(a1);
	three->levelSprites.push_back(player);
	three->background = "assets/b.png";
	e.addLevel(one);
	e.addLevel(two);
	e.addLevel(three);
}

void Game::run() {
	e.run();
}
void Game::changeLevel()
{
	e.levelUp();
}
Game::~Game()
{
}
