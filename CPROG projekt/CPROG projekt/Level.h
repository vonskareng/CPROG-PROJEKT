#ifndef LEVEL_H 
#define LEVEL_H
#include "Sprite.h"
#include <vector>


namespace cgame {
	struct Level {
		std::vector<std::shared_ptr<Sprite>> levelSprites;
		const char* background;

		~Level() {
			delete [] background; 
		}
	};

}

#endif