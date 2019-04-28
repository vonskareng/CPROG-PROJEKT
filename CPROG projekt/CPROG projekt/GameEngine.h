#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include "Level.h"
#include <memory>
#include "ObjFuncs.h"


namespace cgame {
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();
		void run();
		void remove(std::shared_ptr<Sprite> s);
		void setFramerate(int f);
		void installCommand(void (*fpek)(), const SDL_Keycode& value);
		void addSprite(std::shared_ptr<Sprite> s);
		template <typename OBJ>
		void installCommand(void(OBJ::*fpek)(), OBJ* o, const SDL_Keycode& value) {
			Wrapper_ObjFuncs* obj = ObjFuncs<OBJ>::getInstance(o, fpek);
			memberFuncs[value] = obj;
		}
		void setBackground(const char* txt);
		void addLevel(Level* lvl);
		void levelUp();
		int getRemainingSprites();

	private: 
		void increaseLevel();
		void loadLevel();
		std::vector<std::shared_ptr<Sprite>> sprites;
		std::vector<std::shared_ptr<Sprite>> removed;
		std::vector<std::shared_ptr<Sprite>> added;
		int framerate = 60;
		std::unordered_map<SDL_Keycode, void(*)()> commands;
		std::unordered_map<SDL_Keycode, Wrapper_ObjFuncs*> memberFuncs;
		SDL_Texture* backgroundTexture; 
		std::vector<Level*> levels;
		int currentLevel = 0;
		bool newLevel;
		bool txtDone;
		bool quit;
		
		
	};
}
#endif