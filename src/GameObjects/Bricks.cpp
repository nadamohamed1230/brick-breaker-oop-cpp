#include "Bricks.h"
#include "../Core/game.h"
////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

//BrickType brick::getBrickType() const
//{
//	return brk;
//}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";

}
void normalBrick::collisionAction()
{
	strenght--;
	pGame->setscore(1);
	if (getStrenght() == 0)
	{
		collidable* brick = pGame->getGrid()->getbrick();
		pGame->getGrid()->deleteBrick(brick->getuprlft());
	}
}

void normalBrick::setStrenght(int str)
{
	strenght = str;
}
int normalBrick::getStrenght() const
{
	return strenght;
}
BrickType normalBrick::type()
{
	return BRK_NRM ;
}
////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\hard.jpg";
}

void hardBrick::collisionAction()
{

	if (strenght >0)
	{
		pGame->setscore(1);
		strenght--;

	}
	else if (getStrenght() == 0)
	{
		collidable* brick = pGame->getGrid()->getbrick();
		pGame->getGrid()->deleteBrick(brick->getuprlft());

	}
}
void hardBrick::setStrenght(int str)
{
	strenght = str;
}
int hardBrick::getStrenght() const
{
	return strenght;
}
BrickType hardBrick::type()
{
	return BRK_HARD;
}
////////////////////////////////////////////////////  class RockBrick  /////////////////////////////////
RockBrick::RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\rock.jpg";
}

void RockBrick::collisionAction()
{

}

BrickType RockBrick::type()
{
	return BRK_ROCK;
}


///////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
bombBrick::bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\bomb.jpg";
}

void bombBrick::collisionAction()
{
	collidable* brick = pGame->getGrid()->getbrick();
	pGame->getGrid()->deleteBrick(brick->getuprlft());
}

BrickType bombBrick::type()
{
	return BRK_BOMB;
}



////////////////////////////////////////////////////  class BrismBrick  /////////////////////////////////
BrismBrick::BrismBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\brism.jpg";
}

void BrismBrick::collisionAction()
{
	pGame->setscore(5);
	collidable* brick = pGame->getGrid()->getbrick();
	pGame->getGrid()->deleteBrick(brick->getuprlft());
}
BrickType BrismBrick::type()
{
	return BRK_BRISM;
}
////////////////////////////////////////////////////  class poerBrick  /////////////////////////////////
PowerBrick::PowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame)
	:brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\power.jpg";
}

void PowerBrick::collisionAction()
{
	collidable* brick = pGame->getGrid()->getbrick();

	pGame->addCollectable(pGame->pCollactable());
	// Delete the PowerBrick from the grid
	pGame->getGrid()->deleteBrick(brick->getuprlft());

	
}

BrickType PowerBrick::type()
{
	return BRK_POWER;
}
