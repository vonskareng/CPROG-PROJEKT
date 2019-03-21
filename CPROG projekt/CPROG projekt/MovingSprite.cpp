#include "MovingSprite.h"
#include "System.h"
#include <SDL_image.h>


using namespace std;

namespace cgame {

	MovingSprite::MovingSprite(int x, int y, const char* txt, int xrel, int yrel, int tr) : Sprite(x, y, txt, tr), xrel(xrel), yrel(yrel)
	{
	}

	void MovingSprite::draw() {
		setX(getRect().x + xrel);
		setY(getRect().y + yrel);
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}



	MovingSprite::~MovingSprite()
	{
	}

}