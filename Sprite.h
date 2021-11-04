#pragma once

#include "TexRect.h"

class Sprite: public TexRect{




public:
	int rows;
	int cols;

	float xinc;
	float yinc;

	int curr_row;
	int curr_col;

	float left;
	float right;
	float top;
	float bottom;

	bool done;
	float xvel;
	float yvel;
	
	Sprite(const char* filename, int rows, int cols, float x, float y, float w, float h);

	void draw(float z);
	
	bool isDone() const;

	void reset();

	void advance();

	~Sprite();
};
