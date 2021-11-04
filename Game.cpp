#include "Game.h"
#include "App.h"
#include <iostream>
static Game* singleton;
static App* doubleton;

void timer(int id){
    singleton->plyr->advance();
    for(auto& it: singleton->bads){
            it->advance();
    }
    doubleton->redraw();
    if (singleton->plyr->isDone()){
        singleton->plyr->reset();
    }
    for(auto& it: singleton->bads){
        if (it->isDone()){
            it->reset();
        }
    }
    singleton->detectHit();
    glutTimerFunc(singleton->interval, timer, id);
}

void scoreTimer(int id){
    singleton->board->add();
    glutTimerFunc(1000, scoreTimer, id);
}

void platformTimer(int id){
    singleton->platform->setX(singleton->platform->getX() - 0.03);
    singleton->platform2->setX(singleton->platform2->getX() - 0.03);

    if (singleton->platform->getX() < -5){
        singleton->platform->setX(singleton->platform2->getX() + 4);
    }

    if (singleton->platform2->getX() < -5){
        singleton->platform2->setX(singleton->platform->getX() + 4);
    }
    doubleton->redraw();
    glutTimerFunc(17, platformTimer, id);
}


Game::Game(){
    bads.push_back(new Enemy(1));
    bads.push_back(new Enemy(2));
    bads.push_back(new Enemy(3));
    board = new Scoreboard();
    plyr = new Player();
    bg = new Rect(-1, 1, 2, 2, 0.32, 0.04, 0.05);
    platform = new TexRect("images/back2.png", -1, 1, 4, 2);
    platform2 = new TexRect("images/back2.png", 0, 1, 4, 2);
    interval = 125;
    singleton = this;
    movdir = 'x';
    endFace = new Sprite("images/endFace.png", 32, 4, -1, 1, 1, 1);
    gameOver = false;
    timer(1);
    platformTimer(3);
    scoreTimer(4);
}




void Game::drawGame() const{
    bg->draw();
    
    platform->draw();
    platform2->draw();

    plyr->draw(0.5);
    for(auto& it : bads){
        it->draw(0.5);
    }
    board->draw(0.5);
    }



unsigned char Game::getDir(){
    return movdir;
}

void Game::setDir(unsigned char key){
    if(key == 'w')
        movdir = 'w';
    else if( key == 'a')
        movdir = 'a';
    else if(key == 's')
        movdir = 's';
    else if(key == 'd')
        movdir = 'd';
    else
        movdir = 'x';
    
}

void Game::detectHit(){
    for(auto& it: bads){
        if(it->contains(plyr->getX(), plyr->getY()))
            gameOver = true;
    }
    if(gameOver == true){
        board->reset();
        gameOver = false;
    }
}

Game::~Game(){
    delete plyr;
    delete bg;
    delete platform;
    delete board;
    delete endFace;
}