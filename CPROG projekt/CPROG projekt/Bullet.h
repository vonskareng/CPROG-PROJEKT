#ifndef BULLET_H 
#define BULLET_H 
#include "MovingSprite.h"
#include "GameEngine.h"


	class Bullet : public cgame::MovingSprite
	{
	public:
		static Bullet* getInstance(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr);
		~Bullet();
	private: 
		Bullet(int x, int y, int w, int h, const char* txt, int xrel, int yrel, int tr);
		
	};



#endif 