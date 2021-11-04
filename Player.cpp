#include "Player.h"

	Player::Player():Sprite("images/egg.png", 41, 1, -1.15, -0.2, 0.5, 0.25){
	}


	void Player::movePlayer(unsigned char movdir){
    switch(movdir){
        case 'w':
            if(y < 1.1)
				y+=0.1;
            break;
        case 's':
            if(y > -0.4)
				y-= 0.1;
            break;
        case 'x':
            break;
    }
}

	Player::~Player(){

	}