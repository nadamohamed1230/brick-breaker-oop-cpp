#pragma
#include "../../CMUgraphicsLib/CMUgraphics.h"
#include "../../CMUgraphicsLib/auxil.h"
#include "../Base/collidable.h"
#include "../Base/drawable.h"
#include "../Core/game.h"
#include "../UI/toolbar.h"
#ifndef BALL_H
#define BALL_H

class Ball : public collidable {
public:
	Ball(point r_uprleft, point speed, int r_width, int r_height, game* r_pGame);
	
	void BallMovement();
	void draw() const;
	void collisionAction() override;
	void reflectwithpaddle();
	void reflectwithbricks();
	void reflect(double reflectionAngleDeg);
	void activatefireball();
	void  collisionwithscreenedges();
	void moving_ball();
	 void reflectVertical();
	void setUpperLeft(const point& newUpperLeft);
	void setspeed(int spx, int spy);

private:
	int speedx ;
	int speedy ;
	bool isfireball;
	clock_t fireballstarttime;
	const double fireballduration;

};

#endif  BALL_H
