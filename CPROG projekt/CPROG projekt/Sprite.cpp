#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>
#include <algorithm>
#include <iostream>

using namespace std;
namespace cgame {


	Sprite::Sprite(int x, int y, const char* txt, int tr) : rect{ x,y }, tickRate(tr)
	{
		
		surface = IMG_Load(txt);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		setWH(surface->w, surface->h);


	}

	SDL_Rect Sprite::getRect() const {
		return rect;
	}

	SDL_Texture* Sprite::getTexture() {
		return texture;
	}

	void Sprite::freeTexture() {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}



	void Sprite::setTexture(const char* txt) {
		SDL_FreeSurface(surface);
		surface = IMG_Load(txt);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		setWH(surface->w, surface->h);
	}

	void Sprite::setWH(int w, int h) {
		rect.w = w; 
		rect.h = h;
	}

	void Sprite::setY(int y) {
		rect.y = y;
	}

	void Sprite::setX(int x) {
		rect.x = x; 
	}


	
	bool Sprite::checkCollision(shared_ptr<Sprite> const &other) {
			
			Sprite* o = other.get();
			SDL_Rect rect2 = (*other).getRect();
			

			if (o != this && SDL_HasIntersection(&rect, &rect2)) {
				return true;
			}
			else {
				return false;
			}
	}
	Sprite::~Sprite()
	{
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

}