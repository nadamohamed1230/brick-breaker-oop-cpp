#pragma once
#include "../../CMUgraphicsLib/CMUgraphics.h"
#include "../UI/toolbar.h"
#include "../UI/grid.h"
#include "../Base/collidable.h"
#include <ctime>
#include <vector>

//8-1
class grid;
class Ball;
class Collectable;
//Main class that coordinates the game operation
class game
{
	clock_t startClock;
	bool isBallMoving = false;
	bool gameover = false;
	bool state ;
	int startTime;
	int lives=3;
	int sec = 0;
	int min = 0;
	static int score ;
	bool running = false;
	static const int MAX_COLLECTABLES=50;
	Collectable* collectables[MAX_COLLECTABLES];
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};
	
	MODE gameMode;

	/// Add more members if needed


	
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid ;
	Ball* gameBall;
	paddle* gamePaddle;
	collidable* collideobj;
	

public:

	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window

	void go();
	void move();

	void addCollectable(Collectable* coll);

	void clearStatusBar() const;	//Clears the status bar

	
	void printMessage(string msg) const;	//Print a message on Status bar
	//time
	void setStartClock();
	int getsec() const;
	time_t getstartclock();
	void time(time_t startClock);
	//mode
	void changegamemode();
	void modetodesign();
	//lives
	void decrementLives();
	void livesleft();
	int getlives();
	void setlives(int liv);

	//pause_count
	void setstate(bool s);
	bool getstate() ;
	//score
	int getScore() const;
	void showScore();
	static void setscore(int scr);

	void endGame();
	Collectable* pCollactable();

	//void removeCollectable(Collectable* collectable);

	
	//void handleCollectableCollisions();
	bool isCollectableSlotEmpty(int index);

	
	window* getWind() const;		//returns a pointer to the graphics window


	paddle* getPaddle() const;
	Ball* getBall() const;
	grid* getGrid() const;
	toolbar* getToolbar();
};
