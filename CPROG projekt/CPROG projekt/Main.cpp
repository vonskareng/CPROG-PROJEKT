#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
#include "Player.h"
#include "MovingSprite.h"
#include "AnimatedSprite.h"

using namespace std; 
using namespace cgame;

void command() {
	
}


int main(int argc, char** argv) {
	GameEngine e; 
	
	Level* l = new Level();
	Level* ll = new Level(); 
	shared_ptr<Player> player = Player::getInstance(300, 300, 100, 100, "C:/Users/Reebbe/Pictures/gubbe.bmp", enableMouseXandY,0, e);
	shared_ptr<Bullet> bullet = Bullet::getInstance(50, 50, 100, 100, "C:/Users/Reebbe/Pictures/index.jpg",1,0,0);
	//shared_ptr<Bullet> bullet2 = Bullet::getInstance(50, 300, 100, 100, "C:/Users/Reebbe/Pictures/index.jpg", 1, 0, 0);
	//shared_ptr<AnimatedSprite> as = AnimatedSprite::getInstance(50, 50, 100, 100, "C:/Users/Reebbe/Pictures/index.jpg",20);
	l->levelSprites.push_back(player); 
	l->background = "C:/Users/Reebbe/Pictures/KittenProgression-Darling-week3.jpg";
	ll->levelSprites.push_back(bullet);
	ll->levelSprites.push_back(player);
	ll->background = "C:/Users/Reebbe/Pictures/221641.jpg";
	//as->addSpritePicture("C:/Users/Reebbe/Pictures/gubbe.bmp");
	//as->addSpritePicture("C:/Users/Reebbe/Pictures/index.jpg");
	e.addLevel(l);
	e.addLevel(ll);
	void(*fpek)() = command;
	SDL_Keycode k = SDLK_SPACE;
	//e.installCommand(fpek, k);
	//e.setBackground("C:/Users/Reebbe/Pictures/KittenProgression-Darling-week3.jpg");
	//e.add(player);
	//e.add(bullet);
	//e.add(bullet2);
	//e.add(as);
	e.run();
	return 0;
}

