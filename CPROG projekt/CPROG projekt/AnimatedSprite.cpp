#include "AnimatedSprite.h"

using namespace std;
namespace cgame {
	AnimatedSprite::AnimatedSprite(int x, int y, const char* txt, int tr) : Sprite(x,y,txt, tr)
	{
	}


	AnimatedSprite::~AnimatedSprite()
	{
	}

	void AnimatedSprite::tick(const vector<shared_ptr<Sprite>> s) {
		
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

	shared_ptr<AnimatedSprite> AnimatedSprite::getInstance(int x, int y, const char* txt, int tr) {
		return shared_ptr<AnimatedSprite>(new AnimatedSprite(x, y, txt, tr));
	}
}