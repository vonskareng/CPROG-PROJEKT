#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"
#include <SDL.h>
#include <unordered_map>
#include "Level.h"
#include <memory>

namespace cgame {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();
		void run();
		void add(std::shared_ptr<Sprite> s);
		void remove(std::shared_ptr<Sprite> s);
		void setFramerate(int f);
		void installCommand(void (*fpek)(), const SDL_Keycode& value);
		void setBackground(const char* txt);
		void increaseLevel();
		void addLevel(Level* lvl);
		void levelUp();
	private: 
		std::vector<std::shared_ptr<Sprite>> sprites;
		std::vector<std::shared_ptr<Sprite>> removed;
		int framerate = 60;
		std::unordered_map<SDL_Keycode, void(*)()> commands;
		SDL_Texture* backgroundTexture; 
		std::vector<Level*> levels;
		int currentLevel = 0;
		bool newLevel;
		//bool(*levelCondition)();
	};
}
#endif