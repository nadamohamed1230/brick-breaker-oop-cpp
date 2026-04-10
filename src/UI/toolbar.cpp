#include "toolbar.h"
#include "../Core/game.h"
#include "grid.h"
#include "../Core/gameConfig.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "../GameObjects/ball.h"
////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	drawable(r_uprleft, r_width, r_height, r_pGame)
{}




////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddNormalBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconAddhardBrick   //////////////////////////////////////////////
iconAddhardBrick::iconAddhardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddhardBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HARD, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_ROCK, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}
////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////

iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add bomb Bricks ==> Right - Click to stop <= = ");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BOMB, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}


////////////////////////////////////////////////////  class iconAddBrismBrick   //////////////////////////////////////////////
iconAddBrismBrick::iconAddBrismBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBrismBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Brism Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BRISM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
	////////////////////////////////////////////////////  class iconAddpowerBrick   //////////////////////////////////////////////

iconAddPowerBrick::iconAddPowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame)
	:toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}

void iconAddPowerBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Power Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_POWER, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}
////////////////////////////////////////////////////  class iconsave   //////////////////////////////////////////

iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}
#include <iostream>
#include <fstream>

void iconSave::onClick()
{

		ofstream writefile("savefile.txt");

		for (int i = 0; i < pGame->getGrid()->getrows(); i++)
		{
			for (int j = 0; j < pGame->getGrid()->getcols(); j++)
			{
				if (pGame->getGrid()->getbrickMatrix()[i][j])
				{
					
					int brickType = static_cast<int>(pGame->getGrid()-> getbrickMatrix()[i][j]->type());
					
					writefile << i << "\t" << j << "\t" << brickType;
					writefile << "\n";
				}
			}
		}

		writefile.close();




}

////////////////////////////////////////////////////  class iconplay   //////////////////////////////////////////
//
iconplay::iconplay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconplay::onClick()
{
	pGame->changegamemode();
	pGame->setStartClock();
	if (pGame->getGrid()->isGridEmpty())
		pGame->getGrid()->loadGame();
}


////////////////////////////////////////////////////  class iconpause   //////////////////////////////////////////
//
iconpause::iconpause(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconpause::onClick()
{
	pGame->setstate(false);
}


////////////////////////////////////////////////////  class iconcont   //////////////////////////////////////////
//
iconcont::iconcont(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconcont::onClick()
{

	pGame->setstate(true);
}



iconstop::iconstop(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}

void iconstop::onClick()
{

	pGame->setlives(3);
	pGame->getPaddle()->setuprlft(600, 500);
	pGame->getPaddle()->setheight(30);
	pGame->getPaddle()->setwidth(100);


	pGame->getBall()->setuprlft(650, 460);
	pGame->getBall()->setheight(20);
	pGame->getBall()->setwidth(20);
	pGame->getBall()->setspeed(10, 10);
	pGame->getGrid()->draw();
	pGame->modetodesign();
	for (int i = 0; i < pGame->getGrid()->getrows(); i++)
		for (int j = 0; j < pGame->getGrid()->getcols(); j++)
		{
			point click;
			click.x = i;
			click.y = j;
			pGame->getGrid()->deleteBrick(click);
		}


}



////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconExit::onClick()
{
	pGame->printMessage("the game ended ");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	pGame->printMessage("");
	//TO DO: add code for cleanup and game exit here

}


icontimer::icontimer(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}

void icontimer::onClick()
{

}

iconscore::iconscore(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}

void iconscore::onClick()
{

}

////////////////////////////////////////////////////  class iconheart   //////////////////////////////////////////
//
iconheart::iconheart(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconheart::onClick()
{

}


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{

	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_ADD_HARD] = "images\\ToolbarIcons\\hard.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\rock.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\bomb.jpg";
	iconsImages[ICON_ADD_BRISM] = "images\\ToolbarIcons\\brism.jpg";
	iconsImages[ICON_ADD_POWER] = "images\\ToolbarIcons\\power.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\save.jpg";
	iconsImages[ICON_Delete] = "images\\ToolbarIcons\\delete.jpg";
	iconsImages[ICON_play] = "images\\ToolbarIcons\\play.jpg";
	iconsImages[ICON_pause] = "images\\ToolbarIcons\\pause.jpg";
	iconsImages[ICON_Cont] = "images\\ToolbarIcons\\continue.jpg";
	iconsImages[ICON_Stop] = "images\\ToolbarIcons\\stop.jpg";
	iconsImages[ICON_timer] = "images\\ToolbarIcons\\timer.jpg";
	iconsImages[ICON_score] = "images\\ToolbarIcons\\timer.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\exit.jpg";
	iconsImages[ICON_heart] = "images\\ToolbarIcons\\heart.jpg";
	iconsImages[ICON_heart1] = "images\\ToolbarIcons\\heart1.jpg";
	iconsImages[ICON_heart2] = "images\\ToolbarIcons\\heart2.jpg";

	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_HARD] = new iconAddhardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_BRISM] = new iconAddBrismBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_ADD_POWER] = new iconAddPowerBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_Delete] = new iconDelete(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_play] = new iconplay(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_pause] = new iconpause(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_Cont] = new iconcont(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_Stop] = new iconstop(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_timer] = new icontimer(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_score] = new iconscore(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_heart] = new iconheart(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_heart1] = new iconheart(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;
	iconsList[ICON_heart2] = new iconheart(p, config.iconWidth, height, pGame);

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick_play(int x, int y)
{

	if (x < ICON_pause * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;


}


bool toolbar::handleClick_exit(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;


}



iconDelete::iconDelete(point r_uprleft, int r_width, int r_height, game* r_pGame): toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{
}
void iconDelete::onClick()
{
	pGame->printMessage("Click on the bricks you want to delete ==> Right-Click to stop <==");

	int x, y;
	clicktype t;
		t = pGame->getMouseClick(x, y);

		while (t == LEFT_CLICK) {
			// Get the clicked point
			point clicked;
			clicked.x = x;
			clicked.y = y;

			// Get the grid and try to delete the brick at the clicked point
			grid* pGrid = pGame->getGrid();
			pGrid->deleteBrick(clicked);

			// Redraw the grid
			pGame->getGrid()->draw();
			t = pGame->getMouseClick(x, y);
		}
		


	pGame->printMessage("");
}
