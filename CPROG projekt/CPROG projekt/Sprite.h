#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <vector> 
#include <memory>


namespace cgame {
	class Sprite
	{
	public:
		~Sprite();
		virtual void mouseDown(const SDL_Event& event) {}
		virtual void mouseUp(const SDL_Event& event) {}
		virtual void keyDown(const SDL_Event& event) {}
		virtual void keyUp(const SDL_Event& event) {}
		virtual void arrowKeyDown(){}
		virtual void arrowKeyUp(){}
		virtual void arrowKeyLeft(){}
		virtual void arrowKeyRight(){}
		virtual void mouseMotion(const SDL_Event& event){}
		virtual void perform(SDL_Event& e){}
		virtual void textInput(SDL_Event& e) {}
		virtual void tick(){}
		virtual void onCollision(const std::vector<std::shared_ptr<Sprite>> sprites) {}
		virtual void draw() {}

		bool checkCollision(std::shared_ptr<Sprite> const &other);
		SDL_Rect getRect() const;
		int getTickCounter() const { return tickCounter; }
		int getTickRate() const { return tickRate; }
		void increaseTickCounter() { tickCounter++; }
		void resetTickCounter() { tickCounter = 0; }
		SDL_Texture* getTexture();
		
	protected: 
		Sprite(int x, int y, const char* txt, int tr); 
		void setWH(int w, int h);
		void setY(int y);
		void setX(int x);
		void setTexture(const char* txt);
		void freeTexture();
	private: 
		Sprite(const Sprite&) = delete;
		const Sprite& operator = (const Sprite&) = delete;
		SDL_Texture* texture = nullptr;
		SDL_Rect rect;
		int tickRate; 
		int tickCounter = 0;
	
	};
}
#endif
