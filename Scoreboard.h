#pragma once
#include <string>

class Scoreboard{
    std::string text;
    float x, y, r, g, b;
    void* font;
    int width;
    int score;
    int highscore;



public:
	
	Scoreboard();

	void draw(float z);

    void add();

    void reset();

	~Scoreboard();
};
