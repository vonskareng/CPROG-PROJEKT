#include "GameTextBox.h"


using namespace cgame;
GameTextBox::GameTextBox(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, GameEngine& ge) : TextWindow(x, y, txt, tr, font, size, color), g(ge)
{
}


std::shared_ptr<GameTextBox> GameTextBox::getInstance(int x, int y, const char * txt, int tr, const char * font, int size, SDL_Color color, GameEngine& ge)
{
	return std::shared_ptr<GameTextBox>(new GameTextBox(x,y,txt,tr,font,size, color, ge));
}


void GameTextBox::inputDone()
{
	g.levelUp();
}

GameTextBox::~GameTextBox()
{
}
