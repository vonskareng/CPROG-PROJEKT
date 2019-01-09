#include "AnimatedSprite.h"


namespace cgame {
	AnimatedSprite::AnimatedSprite(int x, int y, int w, int h, const char* txt, int tr) : Sprite(x,y,w,h,txt, tr)
	{
	}


	AnimatedSprite::~AnimatedSprite()
	{
	}

	void AnimatedSprite::tick(const std::vector<Sprite*> s) {
		
		if (getTickRate() == 0 || getTickRate() == getTickCounter()) {

			resetTickCounter();
			setTexture(spritePictures[counter]);

			if (counter == spritePictures.size() - 1) {
				counter = 0;
			}
			else {
				counter++;
			}
		}

		if (getTickRate() != 0) {
			increaseTickCounter();
		}
	}

	void AnimatedSprite::addSpritePicture(const char* sp) {
		spritePictures.push_back(sp);
		
	}

	AnimatedSprite* AnimatedSprite::getInstance(int x, int y, int w, int h, const char* txt, int tr) {
		return new AnimatedSprite(x, y, w, h, txt, tr);
	}
}