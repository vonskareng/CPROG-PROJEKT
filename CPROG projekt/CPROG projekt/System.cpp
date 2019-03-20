#include "System.h"
#include <SDL.h>
#include "SDL_ttf.h"

using namespace std;

namespace cgame {
	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING); 
		TTF_Init();
		win = SDL_CreateWindow("Cgame", 100, 100, 800, 600, 0); 
		ren = SDL_CreateRenderer(win, -1, 0); 
		
	}

	SDL_Renderer* System::getRen() const {
		return ren; 
	}

	System::~System()
	{
		SDL_DestroyWindow(win); 
		SDL_DestroyRenderer(ren); 
		TTF_Quit();
		SDL_Quit();
	}

	System sys;

}