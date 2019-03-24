#include "TextWindow.h"
#include <iostream>


namespace cgame {
	using namespace std;
	TextWindow::TextWindow(int x, int y, const char* txt, int tr, const char* font, int size, SDL_Color color) : Sprite(x, y, txt, tr)
	{
		textRect.x = getRect().x;
		textRect.y = getRect().y;
		text = "";
		textFont = TTF_OpenFont(font, size);
		textColor = color;
	}


	TextWindow::~TextWindow()
	{
		TTF_CloseFont(textFont);
		SDL_DestroyTexture(textureToText);
	}


	void TextWindow::draw()
	{
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), textureToText, NULL, &textRect);
	}

	void TextWindow::textInput(SDL_Event& e)
	{
		int cW = 0, cH = 0;
		if(e.type == SDL_TEXTINPUT){
			TTF_SizeText(textFont, e.text.text, &cW, &cH);
			if ( textRect.h + cH <= getRect().h && (w/rows) + cW > getRect().w) {
				rows++;
				text = text + '\n';
			}
			
			
			if (textRect.h < getRect().h && (w/rows) + cW < getRect().w) {
				text = text + e.text.text;
				update = true;
				TTF_SizeText(textFont, text.c_str(), &w, &h);
			}
			
		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
				if (text.back() == '\n') {
					text.pop_back();
					rows--;
					text.pop_back();
				}
				else {
					text.pop_back();
				}
				TTF_SizeText(textFont, text.c_str(), &w, &h);
				update = true;
			}
		}

		if (update) {
			update = false;
			SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(textFont, text.c_str(), textColor, getRect().w);
			textureToText = SDL_CreateTextureFromSurface(sys.getRen(), surface);
			SDL_FreeSurface(surface);
			SDL_QueryTexture(textureToText, NULL, NULL, &width, &height);
			textRect.w = width;
			textRect.h = height;
		
		}

	}

}