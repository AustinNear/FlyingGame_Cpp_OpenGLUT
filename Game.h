#pragma once
#include "Rect.h"
#include "TexRect.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Scoreboard.h"
#include <deque>

class Game{
    Sprite* endFace;
    Rect* bg;
    TexRect* platform;
    TexRect* platform2;
    Scoreboard* board;
    unsigned int interval;
    bool gameOver;


    
    
    public:
    std::deque<Enemy*>bads;
    Player* plyr;
    unsigned char movdir;
    Game();
    friend void timer(int id);
    friend void explosionTimer(int id);
    friend void platformTimer(int id);
    friend void scoreTimer(int id);
    void drawGame() const;
    unsigned char getDir();
    void setDir(unsigned char key);
    void detectHit();
    ~Game();

};



