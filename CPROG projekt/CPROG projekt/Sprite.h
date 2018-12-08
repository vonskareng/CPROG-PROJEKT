#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace cgame {
	class Sprite
	{
	public:
		
		~Sprite();
		virtual void mouseDown(const SDL_Event& event) {}
		virtual void mouseUp(const SDL_Event& event) {}
		virtual void keyDown(const SDL_Event& event) {}
		virtual void keyUp(const SDL_Event& event) {}
		virtual void draw() const = 0;
		SDL_Rect getRect() const;
		Sprite(const Sprite&) = delete; 
		const Sprite& operator = (const Sprite&) = delete; 
	protected: 
		Sprite(int x, int y, int w, int h); 
		void setWH(int w, int h);
	private: 
		SDL_Rect rect;
	};
}
#endif
