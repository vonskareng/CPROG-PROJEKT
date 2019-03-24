#ifndef MYTEXTBOX_H
#define MYTEXTBOX_H
#include "TextWindow.h"
#include "GameEngine.h"


class MyTextBox : public cgame::TextWindow, public std::enable_shared_from_this<MyTextBox>
{
public:
	static std::shared_ptr<MyTextBox> getInstance(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, cgame::GameEngine& ge);
	void perform(SDL_Event& e);
	~MyTextBox();
private:
	MyTextBox(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, cgame::GameEngine& ge);
	cgame::GameEngine& g;
};

#endif