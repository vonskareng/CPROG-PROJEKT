#include "MovingSprite.h"
#include "System.h"
#include <SDL_image.h>


using namespace std;

namespace cgame {

	MovingSprite::MovingSprite(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) : Sprite(x, y, w, h, txt, tr), xrel(xrel), yrel(yrel)
	{
		
	}



	MovingSprite* MovingSprite::getInstance(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr) {
		return new MovingSprite(x, y, w, h, txt, xrel, yrel, tr);
	}

	void MovingSprite::tick(const std::vector<Sprite*> s) {
		setX(getRect().x + xrel);
		setY(getRect().y + yrel);


	}

	MovingSprite::~MovingSprite()
	{
		
	}

}