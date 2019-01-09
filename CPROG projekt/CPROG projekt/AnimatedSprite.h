#ifndef ANIMATEDSPRITE_H 
#define ANIMATEDSPRITE_H 
#include "Sprite.h"

namespace cgame {

	class AnimatedSprite : public Sprite
	{
	public:
		
		~AnimatedSprite();
		void tick(const std::vector<Sprite*> s);
		void addSpritePicture(const char* txt);
		static AnimatedSprite* getInstance(int x, int y, int w, int h, const char* txt, int tr);
	protected:  
		AnimatedSprite(int x, int y, int w, int h, const char* txt, int tr);
	private: 
		std::vector<const char*> spritePictures;
		int counter = 0; 
	};

}

#endif