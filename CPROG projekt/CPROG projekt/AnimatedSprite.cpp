#include "AnimatedSprite.h"
#include <iostream>

using namespace std;
namespace cgame {
	AnimatedSprite::AnimatedSprite(int x, int y, const char* txt, int tr) : Sprite(x,y,txt, tr), tickRate(tr)
	{
		spritePictures.push_back(txt);
	}


	AnimatedSprite::~AnimatedSprite()
	{
	}



	void AnimatedSprite::addSpritePicture(const char* sp) {
		spritePictures.push_back(sp);
		
	}

	void AnimatedSprite::draw()
	{
		if (counter == tickRate) {

			setTexture(spritePictures[currentSprite]);
			counter = 0;
			
			if (currentSprite < spritePictures.size() - 1) {
				currentSprite++;
			}else {
				currentSprite = 0;
			}


		}
		else if (counter < tickRate) {

			counter++;
		}

		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}


}