#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "Sprite.h"
#include "SDL_ttf.h"

namespace cgame {
	class TextBox : public Sprite{
	public:
		void loadText();
		static TextBox* getInstance(int x, int y, int w, int h, const char* txt, int tr);
		void setText(std::string txt);
		std::string getText();
		~TextBox();
	protected:
		TextBox(int x, int y, int w, int h, const char* txt, int tr);
	private:
		SDL_Surface* textSurface;
		TTF_Font *gFont = TTF_OpenFont("C:/Windows/Fonts/Arial.ttf", 20);
		SDL_Color textColor = { 255, 0, 0, 0xFF };
		std::string textToWrite ="";
		SDL_Texture* tempT;
	};
}
#endif