#ifndef TEXTWINDOW_H
#define TEXTWINDOW_H
#include "Sprite.h"
#include "SDL_ttf.h"
#include "System.h"
#include <memory>

namespace cgame {
	
	class TextWindow : public Sprite, public std::enable_shared_from_this<TextWindow>
	{
	public:
		~TextWindow();
		void draw();
		void textInput(SDL_Event& e);

	protected:
		TextWindow(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color);
	private:
		int rows = 1;
		bool update = false;
		int width = 0;
		int height = 0;
		SDL_Rect textRect;
		SDL_Texture* textureToText;
		std::string text;
		TTF_Font* textFont;
		SDL_Color textColor;
		int textLenght = 0;
		int w, h;
	};

}

#endif
