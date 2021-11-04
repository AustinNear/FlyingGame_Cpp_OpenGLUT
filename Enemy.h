#pragma once

#include "Sprite.h"

class Enemy: public Sprite{
    int movestep;

public:
    Enemy(int start);

    void moveEnemy();    

	~Enemy();
};
