#pragma once

//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "../Base/drawable.h"

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick() = 0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
///////////////////////////////////////////////////  class iconAddhardBrick   //////////////////////////////////////////////
class iconAddhardBrick :public toolbarIcon
{
public:
	iconAddhardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
///////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
/////////////////////////////////////////////////// class iconAddbombBrick   //////////////////////////////////////////////
class iconAddBombBrick :public toolbarIcon
{
public:
	iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

///////////////////////////////////////////////////  class iconAddBrismBrick   //////////////////////////////////////////////
class iconAddBrismBrick :public toolbarIcon
{
public:
	iconAddBrismBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
///////////////////////////////////////////////////  class iconAddPowerBrick   ////////////////////////////////////////
class iconAddPowerBrick :public toolbarIcon
{
public:
	iconAddPowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class iconsave   //////////////////////////////////////////////
class iconSave :public toolbarIcon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
class iconDelete :public toolbarIcon
{
public:
	iconDelete(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
///////////////////////////////////////////////////  class iconplay   //////////////////////////////////////////////
class iconplay :public toolbarIcon
{
public:
	iconplay(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconpause   //////////////////////////////////////////////
class iconpause :public toolbarIcon
{
public:
	iconpause(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

class iconcont :public toolbarIcon
{
public:
	iconcont(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};


class iconstop :public toolbarIcon
{
public:
	iconstop(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class icontimer   //////////////////////////////////////////////
class icontimer :public toolbarIcon
{
public:
	icontimer(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconscore   //////////////////////////////////////////////
class iconscore :public toolbarIcon
{
public:
	iconscore(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};

///////////////////////////////////////////////////  class iconhearts   //////////////////////////////////////////////
class iconheart :public toolbarIcon
{
public:
	iconheart(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void onClick();
};
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar :public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,		//add normal brick
		ICON_ADD_HARD,
		ICON_ADD_ROCK,
		ICON_ADD_BOMB,
		ICON_ADD_BRISM,
		ICON_ADD_POWER,
		ICON_SAVE,
		ICON_Delete,
		ICON_play,
		ICON_pause,
		ICON_Cont,
		ICON_Stop,
		//TODO: Add more icons names here
		ICON_timer,
		ICON_score,
		ICON_EXIT,		//Exit icon
		ICON_heart,
		ICON_heart1,
		ICON_heart2,
		ICON_COUNT		                   //no. of menu icons ==> This should be the last line in this enum

	};

private:
	toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
	void draw() const;
	bool handleClick_play(int x, int y);

	bool handleClick_exit(int x, int y);

};
