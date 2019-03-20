#ifndef MOVABLESPRITE_H
#define MOVABELSPRITE_H
#include "Sprite.h"
#include <string>
#include "gameEnum.h"

namespace cgame {
	
	class MovableSprite : public Sprite
	{
		
	public:
		
		void mouseDown(const SDL_Event& event);
		void mouseUp(const SDL_Event& event);
		void mouseMotion(const SDL_Event& event);
		void enableKeyMovement(int xSpeed, int ySpeed);
		void arrowKeyDown(); 
		void arrowKeyUp();
		void arrowKeyLeft();
		void arrowKeyRight();

		~MovableSprite();
	protected: 
		MovableSprite(int x, int y, const char* txt, mouseMovement m, int tr);
	private:
		bool moving, enableArrowkeys;
		int xVelocity = 0;
		int yVelocity = 0;
		mouseMovement m; 
		
	};

}
#endif
