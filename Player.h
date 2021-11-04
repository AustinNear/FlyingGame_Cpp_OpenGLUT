#pragma once

#include "TexRect.h"
#include "Sprite.h"
#include <deque> 

class Player: public Sprite{



public:
	Player();

	void movePlayer(unsigned char movedir);

	~Player();
};
