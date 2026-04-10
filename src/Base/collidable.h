#pragma once
#include "drawable.h"
#include<ctime>
///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
class collidable :public drawable
{
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction() = 0; 
    //action that should be performed upon collision
    point collisionpoint;
    bool iscollision(collidable* obj1, collidable* obj2);
    point collision(collidable* obj1, collidable* obj2);
};

class paddle : public collidable {
private:
    bool isWindGlideActive;
    bool isWidePaddleActive;
    bool isReversePaddleActive;
    clock_t windGlideStartTime;
    clock_t widePaddleStartTime;
    clock_t reversePaddleStartTime;
    const double normalPaddleWidth; // Store the normal paddle width for resetting after wide paddle effect
    const double windGlideDuration; // Adjust the wind glide duration as needed
    const double widePaddleDuration; // Adjust the wide paddle effect duration as needed
    const double reversePaddleDuration;

public:
    paddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
     void collisionAction();
     void moveLeft();
     void moveRight();
     void paddleMovment();
     void activateWindGlideEffect();
     void activateWidePaddleEffect(); // Declaration of the new method
     void draw() const;
    void redraw();
    void setUpperLeft(const point& newUpperLeft);
    void activateReversePaddleEffect();

};
