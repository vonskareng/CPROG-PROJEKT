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
		void remove();
	private: 
		std::vector<Sprite*> sprites;
	};
}
#endif