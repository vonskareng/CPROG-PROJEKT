#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"

namespace cgame {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();
		void run();
		void add(Sprite*); 
		void remove(Sprite* s);
		void setFramerate(int f);
		
	private: 
		std::vector<Sprite*> sprites;
		std::vector<Sprite*> removed; 
		int framerate = 60;
	};
}
#endif