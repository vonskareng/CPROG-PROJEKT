#include <iostream>
#include "MovingSprite.h"
#include "GameEngine.h"

using namespace std; 
using namespace cgame;
int main(int argc, char** argv) {
	GameEngine e; 
	MovingSprite* ms = MovingSprite::getInstance(50, 50, 100, 100);
	ms->makeTexture();
	e.add(ms);
	e.run();
	return 0;
}