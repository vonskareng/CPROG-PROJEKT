#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
#include "Player.h"
#include "MovingSprite.h"
#include "AnimatedSprite.h"

using namespace std; 
using namespace cgame;
int main(int argc, char** argv) {
	GameEngine e; 

	Player* player = Player::getInstance(300, 300, 100, 100, "C:/Users/Reebbe/Pictures/gubbe.bmp", enableMouseXandY,0, e);
	Bullet* bullet = Bullet::getInstance(50, 50, 100, 100, "C:/Users/Reebbe/Pictures/index.jpg",1,0,0);
	AnimatedSprite* as = AnimatedSprite::getInstance(50, 50, 100, 100, "C:/Users/Reebbe/Pictures/index.jpg",20);
	as->addSpritePicture("C:/Users/Reebbe/Pictures/gubbe.bmp");
	as->addSpritePicture("C:/Users/Reebbe/Pictures/index.jpg");
	e.add(player);
	e.add(bullet);
	e.add(as);
	e.run();
	return 0;
}