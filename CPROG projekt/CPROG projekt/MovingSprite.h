#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace cgame {
	class MovingSprite : public Sprite
	{

	public:
		void draw();
		~MovingSprite();
	protected: 
		MovingSprite(int x, int y, const char* txt, int xrel, int yrel, int tr);
	private: 
		
		int xrel, yrel; 


		
	};

}
#endif
