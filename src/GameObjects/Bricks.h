#pragma once
#include "../Base/collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_HARD,		//Hard Brick
	BRK_ROCK,
	BRK_BOMB,
	BRK_BRISM,
	BRK_POWER
	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual BrickType type()=0;

};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
	int strenght = 1;
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void setStrenght(int str);
	int getStrenght() const;
	BrickType type() override;
};

//////////////////////////////////////////////////////  class hardBrick  /////////////////////////////////
class hardBrick :public brick
{
	int strenght = 3;
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void setStrenght(int str);
	int getStrenght() const;
	BrickType type() override;

};

////////////////////////////////////////////////////  class RockBrick  /////////////////////////////////
class RockBrick :public brick
{
public:
	RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType type() override;
};


////////////////////////////////////////////////////  class bombBrick  /////////////////////////////////
class bombBrick :public brick
{
public:
	bombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType type() override;
};
////////////////////////////////////////////////////  class BrismBrick  /////////////////////////////////
class BrismBrick :public brick
{
public:
	BrismBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType type() override;
};
////////////////////////////////////////////////////  class PowerBrick  /////////////////////////////////
class PowerBrick :public brick
{
public:
	PowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	BrickType type() override;
};
