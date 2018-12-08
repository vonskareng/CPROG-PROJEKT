#include "GameEngine.h"
#include <SDL.h>
#include "System.h"

namespace cgame {
	GameEngine::GameEngine()
	{
	}

	void GameEngine::add(Sprite* s) {
		sprites.push_back(s);
	}

	void GameEngine::remove() {

	}

	void GameEngine::run() {
		SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		bool quit = false;

		while (!quit) {
			SDL_Event event; 
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT: quit = true; break;
				}
			}
			SDL_RenderClear(sys.getRen());
			for (Sprite* s : sprites) {
				s->draw();
			}
			SDL_RenderPresent(sys.getRen());
			
		}
	}
	GameEngine::~GameEngine()
	{
		for (Sprite* s : sprites) {
			delete s;
		}
	}
}