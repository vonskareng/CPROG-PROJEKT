#include "MyTextBox.h"


using namespace cgame;
MyTextBox::MyTextBox(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, GameEngine& ge) : TextWindow(x, y, txt, tr, font, size, color), g(ge)
{
}


std::shared_ptr<MyTextBox> MyTextBox::getInstance(int x, int y, const char * txt, int tr, const char * font, int size, SDL_Color color, GameEngine& ge)
{
	return std::shared_ptr<MyTextBox>(new MyTextBox(x,y,txt,tr,font,size, color, ge));
}

void MyTextBox::perform(SDL_Event & e)
{
	if (SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
		g.levelUp();
	}
}

MyTextBox::~MyTextBox()
{
}
