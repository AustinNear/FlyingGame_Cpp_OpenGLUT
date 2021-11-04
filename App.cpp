#include <iostream>
#include "App.h"


App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
} 

void App::draw() const{
    game.plyr->movePlayer(game.movdir);
    for(auto& it: game.bads){
        it->moveEnemy();
    }
    game.drawGame();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    game.setDir(key);


}


void App::keyUp(unsigned char key, float x, float y){
    game.setDir('x'); 
}


App::~App(){   
    std::cout << "Exiting..." << std::endl;
}
