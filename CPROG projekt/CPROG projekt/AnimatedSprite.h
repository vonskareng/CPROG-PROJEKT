#ifndef ANIMATEDSPRITE_H 
#define ANIMATEDSPRITE_H 
#include "Sprite.h"

namespace cgame {

	class AnimatedSprite : public Sprite, public std::enable_shared_from_this<AnimatedSprite>
	{
	public:
		
		~AnimatedSprite();
		void tick(const std::vector<std::shared_ptr<Sprite>> s);
		void addSpritePicture(const char* txt);
		static std::shared_ptr<AnimatedSprite> getInstance(int x, int y, const char* txt, int tr);
	protected:  
		AnimatedSprite(int x, int y, const char* txt, int tr);
	private: 
		std::vector<const char*> spritePictures;
		int counter = 0; 
	};

}

#endif