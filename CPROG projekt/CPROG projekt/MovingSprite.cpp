#include "MovingSprite.h"
#include "System.h"
#include <SDL_image.h>


using namespace std;

namespace cgame {

	MovingSprite::MovingSprite(int x, int y, const char* txt, int xrel, int yrel, int tr) : Sprite(x, y, txt, tr), xrel(xrel), yrel(yrel)
	{
		
	}



	void MovingSprite::tick(const vector<shared_ptr<Sprite>> s) {
		setX(getRect().x + xrel);
		setY(getRect().y + yrel);


	}

	MovingSprite::~MovingSprite()
	{
		
	}

}