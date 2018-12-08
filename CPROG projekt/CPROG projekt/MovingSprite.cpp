#include "MovingSprite.h"
#include "System.h"
#include <SDL.h>
using namespace std;

namespace cgame {

	MovingSprite::MovingSprite(int x, int y, int w, int h) : Sprite(x, y, w, h)
	{
		
		
	}

	SDL_Texture* MovingSprite::getTexture() const{
		return texture;
	}

	void MovingSprite::makeTexture() {
		SDL_Surface* bgSurf = SDL_LoadBMP("C:/Users/Reebbe/Pictures/gubbe.bmp");
		texture = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
		SDL_FreeSurface(bgSurf);
		setWH(bgSurf->w, bgSurf->h);
		
	}
	MovingSprite* MovingSprite::getInstance(int x, int y, int w, int h) {
		return new MovingSprite(x, y, w, h);
	}
	void MovingSprite::draw() const {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}

	MovingSprite::~MovingSprite()
	{
		SDL_DestroyTexture(texture);
	}

}