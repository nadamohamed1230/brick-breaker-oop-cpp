#include "game.h"
#include "gameConfig.h"
#include "../GameObjects/ball.h"
#include <ctime>
#include<chrono>
#include <thread>
#include "../UI/toolbar.h"
#include "../GameObjects/Bricks.h"
#include "../GameObjects/collactable.h"
using namespace std;
game::game()

{
	// Initialize playground parameters
	gameMode = MODE_DSIGN;

	// 1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	// 2 - Create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft, 0, config.toolBarHeight, this);
	gameToolbar->draw();

	// 3 - Create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();

	// 4 - Create the Paddle
	point paddleUpperLeft;
	paddleUpperLeft.x = 600;
	paddleUpperLeft.y = 500;
	gamePaddle = new paddle(paddleUpperLeft, 100, 30, this);

	// 5 - Create the Ball
	point upperleft;
	point speed;
	float width = 20;
	float height = 20;
	upperleft.x = 650;
	upperleft.y = 460;
	speed.x = 10;
	speed.y = 10;
	gameBall = new Ball(upperleft, speed, width, height, this);

	for (int i = 0; i < MAX_COLLECTABLES; ++i) {
		collectables[i] = nullptr;
	}
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
	delete gameBall;
	delete gamePaddle;
	delete collideobj;
	for (int i = 0; i < MAX_COLLECTABLES; ++i) {
		if (collectables[i] != nullptr) {
			delete collectables[i];
		}
	}
}



void game::livesleft()
{
	

	if (gameBall->getuprlft().y + gameBall->getheight() / 2 >= pWind->GetHeight() - 50) {
		// Decrease the number of lives in the game
		decrementLives();
		isBallMoving = false;

		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(0, pWind->GetHeight() - config.paddleAreaHeight, pWind->GetWidth(), pWind->GetHeight() - config.statusBarHeight);
		
		//set paddle
		gamePaddle->setuprlft(600, 500);
		gamePaddle->setheight(30);
		gamePaddle->setwidth(100);

		gameBall->setuprlft(650, 460);
		gameBall->setheight(20);
		gameBall->setwidth(20);
		gameBall->setspeed(10, 10);

		int heartIconIndex = 18 - getlives();
		int x = heartIconIndex * config.iconWidth;  // Assuming equal width for all icons

		pWind->SetPen(LAVENDER);  // Use the background color or any other color you prefer
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(x, 0, x - config.iconWidth, config.toolBarHeight);


		//  } while (getlives() == 0);

		if (getlives() == 0)
		{
			gameover = true;
			printMessage("GAME OVER :(");
		}

	}
}

void game::setstate(bool s)
{
	state = s;
}

void game::setStartClock()
{
	startClock = clock();
}

time_t game::getstartclock()
{
	return startClock;
}


bool game::getstate()
{
	return state;
}

clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}

void game::decrementLives() {

	lives = lives--;
}

void game::time(time_t startClock)
{
	sec = 0;
	min = 0;

	
	sec += (clock() - getstartclock()) / CLOCKS_PER_SEC;

	if (sec >= 60)
	{
		min += sec / 60;
		sec %= 60;
	}

	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(780, 0, 780+ 65, 35);


	pWind->SetPen(BLACK);
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString(780, 5, "Timer: " + to_string(min) + ":" + to_string(sec));

}


int game::getsec()const
{
	return sec;
}


int game::score = 0;
int game::getScore() const
{
	return score;
}

void game::showScore()
{

	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(845, 0, 840 + 65, 40);
	pWind->SetPen(BLACK);
	pWind->SetFont(10, BOLD, BY_NAME, "Arial");
	pWind->DrawString(845, 5, "Score: " + to_string(getScore()));

}
void game::setscore(int scr)
{

	score += scr;
}

void game::endGame()
{

	if (bricksGrid->isWindowClear())
	{
		pWind->SetPen(LAVENDER);
		pWind->SetBrush(LAVENDER);
		pWind->DrawRectangle(0, 0, pWind->GetWidth(), pWind->GetHeight());
		do {

			pWind->SetPen(BLACK);
			pWind->SetFont(40, BOLD, BY_NAME, "Arial");
			pWind->DrawString(pWind->GetWidth() / 2, pWind->GetHeight() / 2 - 60, "YOU WON :)");
			pWind->DrawString(pWind->GetWidth() / 2, pWind->GetHeight() / 2, "Score: " + to_string(getScore()));

		} while (true);
	}
}




window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}


string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

paddle* game::getPaddle() const
{
	return gamePaddle;
}
Ball* game::getBall()const
{
	return gameBall;
}
grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}
toolbar* game::getToolbar() {
	return gameToolbar;
}

void game::changegamemode()
{
	gameMode = MODE_PLAY;
}

void game::modetodesign()
{
	gameMode = MODE_DSIGN;
}

void game::go()
{
	// This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	// Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	do
	{
		// Clear the window
		pWind->SetBrush(config.bkGrndColor);
		pWind->SetPen(config.bkGrndColor, 1);
		pWind->DrawRectangle(0, 0, config.windWidth, config.windHeight);

		// Draw the grid, paddle, ball, toolbar, and status bar
		bricksGrid->draw();
		gameToolbar->draw();
		clearStatusBar();

		// Print message and get user click
		printMessage("Ready...");
		getMouseClick(x, y);

		if (gameMode == MODE_DSIGN) // Game is in the Design mode
		{
			// [1] If the user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick_exit(x, y);
			}
		}
		else if (gameMode == MODE_PLAY)
		{
			

			move();

		}
	} while (!isExit);

}

int game::getlives()
{
	return lives;
}

void game::setlives(int liv)
{
	lives = liv;
}


void game::move()
{
	int x, y;
	bool isExit = false;


	pWind->FlushKeyQueue();
	pWind->FlushMouseQueue();
	char keyData;
	keytype kType;
	clicktype ctInput;
	int toolbarHeight = config.toolBarHeight;
	clock_t startClock = 0;

	state = true;
	gameBall->draw();
	gamePaddle->draw();


	do
	{

		gamePaddle->draw();
		ctInput = pWind->GetMouseClick(x, y);
		if (y >= 0 && y < config.toolBarHeight)
		{
			gameToolbar->handleClick_play(x, y);
		}

		if (getstate())
		{
			this->showScore();
			this->time(startClock);
			kType = pWind->GetKeyPress(keyData);

			if (kType == ASCII && keyData == ' ')
			{
				isBallMoving = true;
			}


			if (isBallMoving && !(gameover))
			{
				livesleft();


				gameBall->BallMovement();

				gameBall->collisionAction();

				gameBall->collisionwithscreenedges();

				if (kType == ARROW)
				{
					gamePaddle->paddleMovment();
				}

				

				endGame();
			}

		}


	} while (!(gameMode == MODE_DSIGN));
}

Collectable* game::pCollactable() {
	Collectable* newCollectable = nullptr;
			int randomType = rand() % NUM_COLLECTABLE_TYPES;
			collidable* brick = getGrid()->getbrick();


			switch (randomType)
			{
			case 1:
				newCollectable = new WindGlide(brick->getuprlft(), 30, 30, this);
				break;
			case 2:
				newCollectable = new WidePaddle(brick->getuprlft(), 30, 30, this);
				break;
			case 3:
				newCollectable = new fireball(brick->getuprlft() ,30, 30, this);
				break;
			case 4:
				newCollectable = new ReversePaddle(brick->getuprlft(), 30, 30, this);
				break;
			default:
				// Handle other types if needed
				break;
			}
		
		return newCollectable;
}

	void game::addCollectable(Collectable*coll)
	{

		for (int i = 0; i < MAX_COLLECTABLES; ++i) {
			if (coll != nullptr)
			{
				collectables[i] = coll;
				coll->draw();
				coll->move();
			}
		}
}

bool game::isCollectableSlotEmpty(int index)
{
	return collectables[index] == nullptr;
}
