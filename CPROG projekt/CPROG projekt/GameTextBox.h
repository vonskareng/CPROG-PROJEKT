#ifndef GAMETEXTBOX_H
#define GAMETEXTBOX_H
#include "TextWindow.h"
#include "GameEngine.h"


class GameTextBox : public cgame::TextWindow, public std::enable_shared_from_this<GameTextBox>
{
public:
	static std::shared_ptr<GameTextBox> getInstance(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, cgame::GameEngine& ge);
	void inputDone();
	~GameTextBox();
private:
	GameTextBox(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color, cgame::GameEngine& ge);
	cgame::GameEngine& g;
};

#endif