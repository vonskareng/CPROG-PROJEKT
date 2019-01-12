#include "Bullet.h"



using namespace cgame;
using namespace std;
	Bullet::Bullet(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) : MovingSprite(x,y,w,h,txt,xrel,yrel, tr)
	{
	}


	Bullet::~Bullet()
	{
	}

	shared_ptr<Bullet> Bullet::getInstance(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) {
		return shared_ptr<Bullet>(new Bullet(x, y, w, h, txt, xrel, yrel, tr));
	}

