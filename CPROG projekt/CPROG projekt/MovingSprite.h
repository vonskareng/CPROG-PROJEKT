#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace cgame {
	class MovingSprite : public Sprite
	{

	public:
		static MovingSprite* getInstance(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr);
		void tick(const std::vector<std::shared_ptr<Sprite>> s);

		~MovingSprite();
	protected: 
		MovingSprite(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr);
	private: 
		
		int xrel, yrel; 


		
	};

}
#endif
