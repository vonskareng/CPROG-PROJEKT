#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace cgame {
	class MovingSprite : public Sprite
	{

	public:
		static MovingSprite* getInstance(int x, int y, int w, int h);
		void draw() const;
		void makeTexture();
		~MovingSprite();
	protected: 
		MovingSprite(int x, int y, int w, int h);
		SDL_Texture* getTexture() const;
	private: 
		SDL_Texture* texture = nullptr;

	};

}
#endif
