#ifndef PLAYER_H
#define PLAYER_H 
#include "MovableSprite.h"
#include <vector>
#include "GameEngine.h"



class Player : public cgame::MovableSprite, public std::enable_shared_from_this<Player>
	{
	public:
		static std::shared_ptr<Player> getInstance(int x, int y, int w, int h, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g);
		~Player();
		void shoot();
		void onCollision(std::vector<std::shared_ptr<Sprite>> sprites);
		void kill() {
			killCount++;
		}
		int getKills() {
			return killCount;
		}
	private: 
		Player(int x, int y, int w, int h, const char* txt, cgame::mouseMovement m, int tr, cgame::GameEngine& g);
		cgame::GameEngine& ge;
		int killCount = 0;
	};



#endif