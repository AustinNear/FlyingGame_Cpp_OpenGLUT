#include "Scoreboard.h"
#include <string>


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Scoreboard::Scoreboard(){
    x = -0.85;
    y = 0.85;
    r = 1;
    g = 1;
    b = 1;
    width = 1000;
    score = 0;
    highscore = 0;
    font = GLUT_BITMAP_TIMES_ROMAN_24;
}

void Scoreboard::draw(float z){
    auto s = std::to_string(score);
    auto h = std::to_string(highscore);

    text = "Score: " + s;
    glColor3f(r, g, b);
    float offset = 0;
	x = -0.85;
    for (int i = 0; i < text.length(); i++){
    glRasterPos3f(x+offset, y, z);
    glutBitmapCharacter(font, text[i]);
    int w = glutBitmapWidth(font, text[i]);
    offset += ((float)w / width)*2;
    }
    text = "HighScore: " + h;
    x = 0.4;
    for (int i = 0; i < text.length(); i++){
    glRasterPos3f(x+offset, y, z);
    glutBitmapCharacter(font, text[i]);
    int w = glutBitmapWidth(font, text[i]);
    offset += ((float)w / width)*2;
    }
}

void Scoreboard::add(){
    score++;
    if(score > highscore)
        highscore = score;
}

void Scoreboard::reset(){
    score = 0;
}

Scoreboard::~Scoreboard(){}