#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

using namespace std;
namespace cgame {


	Sprite::Sprite(int x, int y, const char* txt, int tr) : rect{ x,y }, tickRate(tr)
	{
		SDL_Surface* bgSurf = IMG_Load(txt);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
		SDL_FreeSurface(bgSurf);
		setWH(bgSurf->w, bgSurf->h);
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
		SDL_Surface* bgSurf = IMG_Load(txt);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
		SDL_FreeSurface(bgSurf);
		setWH(bgSurf->w, bgSurf->h);
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
			
			SDL_Rect rect2 = (*other).getRect();

			if (other.get() == this) {
				return false;
			}
			if (SDL_HasIntersection(&rect, &rect2))
				return true;
	}
	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}

}