#include "ball.h"
#include "../Core/game.h"
#include "../Base/collidable.h"
#include "../Core/gameConfig.h"
#include "../UI/toolbar.h"
#include <algorithm>
#include <iostream>
using namespace std;

Ball::Ball(point r_uprleft, point speed, int r_width, int r_height, game* r_pGame):
    collidable(r_uprleft, r_width, r_height, r_pGame),
    isfireball (false),
    fireballduration(60)

{
    speedx = speed.x;
    speedy = speed.y;
}
void Ball::collisionwithscreenedges()
{
    window* pWind = pGame->getWind();
    
    if ((uprLft.x -width / 2 <= 0) || (uprLft.x +width / 2 >= pWind->GetWidth()))
        speedx = -speedx;

    if ((uprLft.y - height / 2 <= 60) || (uprLft.y + height / 2 >= pWind->GetHeight() - 50))
        speedy = -speedy;
}

void Ball::moving_ball()
{
    uprLft.x += speedx;
    uprLft.y += speedy;
}

void Ball::reflectVertical()
{
        speedy= -speedy;
   
}

void Ball::setUpperLeft(const point& newUpperLeft)
{
    uprLft.x = newUpperLeft.x;
    uprLft.y = newUpperLeft.y;
}

void Ball::setspeed(int spx, int spy)
{
    speedx = spx;
    speedy = spy;
}

void Ball::BallMovement()
{

            window* pWind = pGame->getWind();
            pWind->SetPen(LAVENDER);
            pWind->SetBrush(LAVENDER);
            pWind->DrawRectangle(uprLft.x -width / 2, uprLft.y - height / 2,
                uprLft.x +width / 2, uprLft.y + height / 2);
            pGame->getGrid()->draw();
            // Move the ball
            moving_ball();
            this->draw();
            pWind->UpdateBuffer();
            Pause(10);
            
  
}



void Ball::draw() const
{
    window* pWind = pGame->getWind();
    pWind->SetPen(BLACK);
    pWind->SetBrush(BLACK);

    // Draw the rectangle
    pWind->DrawRectangle(uprLft.x -width / 2, uprLft.y - height / 2,
        uprLft.x +width / 2, uprLft.y + height / 2);
}

void Ball::collisionAction()
{
    if (iscollision(this, pGame->getPaddle()))

    {

        reflectwithpaddle();
        pGame->getPaddle()->draw();

    }
    if ( pGame->getGrid()->getbrick()!=nullptr)
    {
        if (!(isfireball))
        {
            reflectwithbricks();
        }
        pGame->getGrid()->getbrick()->collisionAction();
    }
}


void Ball::reflectwithpaddle()
{
    double paddleCenterX = pGame->getPaddle()->getuprlft().x + pGame->getPaddle()->getwidth() / 2.0;
    double relativeCollisionPoint = (uprLft.x - paddleCenterX) / (pGame->getPaddle()->getwidth() / 2.0);


    double reflectionAngle = 90.0 - relativeCollisionPoint * 45.0;
    double reflectionAngleRad = reflectionAngle * 3.14 / 180.0;

    // Calculate new speeds
    double magnitude = sqrt(speedx * speedx + speedy * speedy);
    speedx = magnitude * cos(reflectionAngleRad);
    speedy = -magnitude * sin(reflectionAngleRad);
}


void Ball::reflectwithbricks()
{
    collidable* brick = pGame->getGrid()->getbrick();
    point collisionPoint = collidable::collision(this, brick);

   
    double relativeCollisionX = collisionPoint.x - (brick->getuprlft().x + brick->getwidth() / 2);
    double relativeCollisionY = collisionPoint.y - (brick->getuprlft().y + brick->getheight() / 2);

 
    double reflectionAngleRad = atan2(relativeCollisionY, relativeCollisionX);
    double  reflectionAngleDeg = reflectionAngleRad * 180.0 / 3.14;

  
    reflect(reflectionAngleDeg);

}

void Ball::reflect(double reflectionAngleDeg)
{
    // Reflect the ball based on the specified angle in degrees
    double reflectionAngleRad = reflectionAngleDeg * 3.14 / 180.0;
    double magnitudeSpeed = sqrt(speedx * speedx + speedy * speedy);

    speedx = magnitudeSpeed * cos(reflectionAngleRad);
    speedy = magnitudeSpeed * sin(reflectionAngleRad);
}



void Ball::activatefireball()
{
    isfireball = true;
    fireballstarttime = clock();
}
