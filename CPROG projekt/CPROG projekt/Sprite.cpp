#include "Sprite.h"
#include <SDL.h>
#include "System.h"
namespace cgame {


	Sprite::Sprite(int x, int y, int w, int h) : rect{ x,y,w,h }
	{
	}

	SDL_Rect Sprite::getRect() const {
		return rect;
	}

	void Sprite::setWH(int w, int h) {
		rect.w = w; 
		rect.h = h;
	}
	Sprite::~Sprite()
	{
	}

}