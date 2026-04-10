#pragma once

#include "../Base/drawable.h"
#include "../GameObjects/Bricks.h"


class game;

class grid:public drawable
{

	brick*** brickMatrix;		//2D array of brick pointers

	int rows, cols;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	bool isGridEmpty();
	void loadGame();
	~grid();
	void draw() const;
	/*void deleteBrick(const point& clickedPoint);*/
	void deleteBrick(point clickedPoint);
	int addBrick(BrickType brkType, point clickedPoint);
	brick* getbrick();
	//brick* rightgetbrick();
	//brick* leftgetbrick();
	//brick* abovegetbrick();
	//brick* belowgetbrick(); 
	//brick* rightgetbrick();
	//brick* leftgetbrick();
	//brick* abovegetbrick();
	//brick* belowgetbrick();
	int getrows();
	int getcols();
	bool isWindowClear();
	brick*** getbrickMatrix();

	
};
