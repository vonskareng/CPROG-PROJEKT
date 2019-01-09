#include "GameEngine.h"
#include <SDL.h>
#include <iostream>
#include "System.h"


namespace cgame {
	GameEngine::GameEngine()
	{
	}

	void GameEngine::add(Sprite* s) {
		sprites.push_back(s);
	}

	void GameEngine::remove(Sprite* s) {
		removed.push_back(s);
	}

	void GameEngine::setFramerate(int f) {
		framerate = f; 
	}


	void GameEngine::run() {
		SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		bool quit = false;
		const int tickInterval = 1000 / framerate;

		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event; 
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite* s : sprites) {
						s->mouseDown(event);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite* s : sprites) {
						s->mouseUp(event);
					}
					break;
				case SDL_MOUSEMOTION: 
					for (Sprite* s : sprites) {
						s->mouseMotion(event);
					}
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_UP:
						for (Sprite* s : sprites) {
							s->arrowKeyUp();
						}
						break;
					case SDLK_DOWN:
						for (Sprite* s : sprites) {
							s->arrowKeyDown();
						}
						break;
					case SDLK_LEFT:
						for (Sprite* s : sprites) {
							s->arrowKeyLeft();
						}
						break;
					case SDLK_RIGHT:
						for (Sprite* s : sprites) {
							s->arrowKeyRight();
						}
						break;
					}
				}



			}
			for (Sprite* s : removed) {
				for (std::vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end(); ) {
					if (*i == s) {
						
						i = sprites.erase(i);
						delete s;
					}
					else {
						i++;
					}
				}
			}
			removed.clear();

			SDL_RenderClear(sys.getRen());
			for (Sprite* s : sprites) {
				s->tick(sprites);
				s->onCollision(sprites);
				s->draw();

			}
			SDL_RenderPresent(sys.getRen());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		}
	}
	GameEngine::~GameEngine()
	{
		for (Sprite* s : sprites) {
			delete s;
		}
	}
}