#include "Enemy.h"
Enemy::Enemy(int start) : Sprite("images/GremlinDance.png", 1, 5, 0, 0, 0.5, 0.5){
        switch(start){
        case 1:
            x = 0;
            y = 1;
            break;
        case 2:
            x = 2;
            y = 0.35;
            break;
        case 3:
            x = 4;
            y = -0.30;
        }
}

void Enemy::moveEnemy(){
    if(x < -2){
        x=2;
        y-=0.65;
        if(y < -0.9)
            y = 1;
    }
    x-= 0.05;    
}

Enemy::~Enemy(){}