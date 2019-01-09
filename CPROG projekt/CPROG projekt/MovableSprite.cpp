#include "MovableSprite.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>
using namespace std; 

namespace cgame {
	MovableSprite::MovableSprite(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr) : Sprite(x,y,w,h,txt, tr), m(m)
	{
	}

	void MovableSprite::mouseDown(const SDL_Event& event) {
		SDL_Point p = { event.button.x, event.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			moving = true;

		}
	}

	MovableSprite* MovableSprite::getInstance(int x, int y, int w, int h, const char* txt, mouseMovement m, int tr) {
		return new MovableSprite(x, y, w, h, txt, m, tr);
	}

	void MovableSprite::mouseUp(const SDL_Event& event) {
		SDL_Point p = { event.button.x, event.button.y };
		if (SDL_PointInRect(&p, &getRect())) {
			moving = false;

		}
	}

	void MovableSprite::mouseMotion(const SDL_Event& event) {
		if (moving) {
			switch (m) {
			case enableMouseX:
				setX(getRect().x + event.motion.xrel);
				break;
			case enableMouseY:
				setY(getRect().y + event.motion.yrel);
				break;
			case enableMouseXandY:
				setY(getRect().y + event.motion.yrel);
				setX(getRect().x + event.motion.xrel);
				break;
			}
		}

	}

	void MovableSprite::arrowKeyDown() {
		setY(getRect().y + yVelocity);
	}

	void MovableSprite::arrowKeyUp() {
		setY(getRect().y - yVelocity);
	}
	void MovableSprite::arrowKeyLeft() {
		setX(getRect().x - xVelocity);
	}

	void MovableSprite::arrowKeyRight() {
		setX(getRect().x + xVelocity);
	}


	void MovableSprite::enableKeyMovement(int xSpeed, int ySpeed) {
		xVelocity = xSpeed; 
		yVelocity = ySpeed; 
		enableArrowkeys = true; 

	}

	void MovableSprite::tick(const std::vector<Sprite*> s) {

	}

	MovableSprite::~MovableSprite()
	{
	}

}