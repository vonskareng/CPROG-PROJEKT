#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>

using namespace std;
namespace cgame {


	Sprite::Sprite(int x, int y, int w, int h, const char* txt, int tr) : rect{ x,y,w,h }, tickRate(tr)
	{
		SDL_Surface* bgSurf = IMG_Load(txt);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
		SDL_FreeSurface(bgSurf);
		setWH(bgSurf->w, bgSurf->h);
	}

	SDL_Rect Sprite::getRect() const {
		return rect;
	}

	//GameEngine& Sprite::getGameEngine() const { return ge; }

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

	void Sprite::draw() const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	bool Sprite::checkCollision(shared_ptr<Sprite> const &other) {
			
			SDL_Rect rect2 = (*other).getRect();

			if (other.get() == this) {
				return false;
			}
			return SDL_HasIntersection(&rect, &rect2);
	}
	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
	}

}