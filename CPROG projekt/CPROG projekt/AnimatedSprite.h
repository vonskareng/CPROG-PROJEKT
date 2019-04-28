#ifndef ANIMATEDSPRITE_H 
#define ANIMATEDSPRITE_H 
#include "Sprite.h"
#include "System.h"

namespace cgame {

	class AnimatedSprite : public Sprite
	{
	public:
		
		~AnimatedSprite();
		
		void addSpritePicture(const char* txt);
		void draw();
	protected:  
		AnimatedSprite(int x, int y, const char* txt, int tr);
	private: 
		std::vector<const char*> spritePictures;
		int currentSprite = 0;
		int counter = 0; 
		int tickRate;
	};

}

#endif