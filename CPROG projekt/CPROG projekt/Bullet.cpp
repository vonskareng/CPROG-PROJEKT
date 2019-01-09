#include "Bullet.h"


using namespace cgame;

	Bullet::Bullet(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) : MovingSprite(x,y,w,h,txt,xrel,yrel, tr)
	{
	}


	Bullet::~Bullet()
	{
	}

	Bullet* Bullet::getInstance(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) {
		return new Bullet(x, y, w, h, txt, xrel, yrel, tr);
	}

