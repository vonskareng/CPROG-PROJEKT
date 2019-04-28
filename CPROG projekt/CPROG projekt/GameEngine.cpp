#include "GameEngine.h"
#include <iostream>
#include "System.h"
#include <stdexcept>

using namespace std; 

namespace cgame {
	GameEngine::GameEngine()
	{
	}

	void GameEngine::addSprite(shared_ptr<Sprite> s) {
		added.push_back(s);
	}

	void GameEngine::remove(shared_ptr<Sprite> s) {
		removed.push_back(s);
	}

	void GameEngine::setFramerate(int f) {
		framerate = f; 
	}

	void GameEngine::installCommand(void(*fpek)(), const SDL_Keycode& value) {
		commands[value] = *fpek;
	}



	void GameEngine::setBackground(const char* txt) {
		SDL_Surface* bgSurf = IMG_Load(txt);
		backgroundTexture = SDL_CreateTextureFromSurface(sys.getRen(), bgSurf);
		SDL_FreeSurface(bgSurf);
	}

	void GameEngine::loadLevel() {
		if (!levels[currentLevel]->levelSprites.empty()) {
			for (shared_ptr<Sprite> s : levels[currentLevel]->levelSprites) {
				sprites.push_back(s);
			}
			if(levels[currentLevel]->background)
				setBackground(levels[currentLevel]->background);
		}
	}

	void GameEngine::increaseLevel() {
		currentLevel++; 
		sprites.clear();
		if(backgroundTexture)
			SDL_DestroyTexture(backgroundTexture);
		loadLevel();
		newLevel = false;
	}

	void GameEngine::levelUp() {
		newLevel = true;
	}

	int GameEngine::getRemainingSprites()
	{
		return sprites.size();
	}

	void GameEngine::addLevel(Level* lvl) {
		levels.push_back(lvl);
	}

		
	
	void GameEngine::run() {
		const int tickInterval = 1000 / framerate;
		
		if (levels.empty()) {
			throw runtime_error("Måste addera levels");
		}
		
		loadLevel();
		
		
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event; 
			
			while (SDL_PollEvent(&event)) {
				for (shared_ptr<Sprite> s : sprites) {
					s->textInput(event);
					s->perform(event);
				}
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (shared_ptr<Sprite> s : sprites) {
						s->mouseDown(event);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (shared_ptr<Sprite> s : sprites) {
						s->mouseUp(event);
					}
					break;
				case SDL_MOUSEMOTION:
					for (shared_ptr<Sprite> s : sprites) {
						s->mouseMotion(event);
					}
					break;
				case SDL_KEYDOWN:
					if (memberFuncs.count(event.key.keysym.sym) != 0) {
						memberFuncs[event.key.keysym.sym]->doFunc();
					}
					if (commands.count(event.key.keysym.sym) != 0) {
						commands[event.key.keysym.sym]();
					}
					switch (event.key.keysym.sym) {
					case SDLK_UP:
						for (shared_ptr<Sprite> s : sprites) {
							s->arrowKeyUp();
						}
						break;
					case SDLK_DOWN:
						for (shared_ptr<Sprite> s : sprites) {
							s->arrowKeyDown();
						}
						break;
					case SDLK_LEFT:
						for (shared_ptr<Sprite> s : sprites) {
							s->arrowKeyLeft();
							newLevel = true;
						}
						break;
					case SDLK_RIGHT:
						for (shared_ptr<Sprite> s : sprites) {
							s->arrowKeyRight();
						}
						break;
					}
				}

			}
			
			for (shared_ptr<Sprite> s : added) {
				sprites.push_back(s);
			}
			added.clear();
			
			for (shared_ptr<Sprite> s : sprites) {
				s->tick();
				s->onCollision(sprites);
			}

			for (shared_ptr<Sprite> s : removed) {
				for (std::vector<shared_ptr<Sprite>>::iterator i = sprites.begin(); i != sprites.end(); ) {
					if (*i == s) {
						
						i = sprites.erase(i);
						
					}
					else {
						i++;
					}
				}
			}
			removed.clear();

			
	
			SDL_RenderClear(sys.getRen());
			SDL_RenderCopy(sys.getRen(), backgroundTexture, NULL, NULL);
			
			for (shared_ptr<Sprite> s : sprites) {
				s->draw();
			}
			
			SDL_RenderPresent(sys.getRen());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
			if (newLevel && currentLevel != levels.size() - 1) {
				increaseLevel();
			}
			
		}
	}
	GameEngine::~GameEngine()
	{
		if(backgroundTexture)
			SDL_DestroyTexture(backgroundTexture);


	}
}