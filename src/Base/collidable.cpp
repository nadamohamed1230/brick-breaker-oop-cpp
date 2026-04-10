#include "collidable.h"
#include "../Core/game.h"
#include <algorithm>
#include <Windows.h>
#include "../GameObjects/collactable.h"

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame):
			drawable(r_uprleft, r_width, r_height,  r_pGame)
{
}
bool collidable::iscollision(collidable* obj1, collidable* obj2)
{
    if (obj1 && obj2) {
        bool horizontalOverlap = (obj1->uprLft.x <= obj2->uprLft.x + obj2->width) && (obj1->uprLft.x + obj1->width >= obj2->uprLft.x);
        bool verticalOverlap = (obj1->uprLft.y <= obj2->uprLft.y + obj2->height) && (obj1->uprLft.y + obj1->height >= obj2->uprLft.y);
        return horizontalOverlap && verticalOverlap;
    }
}
point collidable::collision(collidable* obj1, collidable* obj2)
{
    point collisionpoint;
    double x1 = max(obj1->uprLft.x, obj2->uprLft.x);
    double y1 = max(obj1->uprLft.y, obj2->uprLft.y);
    double x2 = min(obj1->uprLft.x + obj1->width, obj2->uprLft.x + obj2->width);
    double y2 = min(obj1->uprLft.y + obj1->height, obj2->uprLft.y + obj2->height);
    collisionpoint.x = (x1 + x2) / 2;
    collisionpoint.y = (y1 + y2) / 2;
    return collisionpoint;
}


paddle::paddle(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    collidable(r_uprleft, r_width, r_height, r_pGame),
    isWindGlideActive(false),
    isWidePaddleActive(false),
    isReversePaddleActive(false),
    normalPaddleWidth(r_width),
    windGlideDuration(60), 
    widePaddleDuration(60),
    reversePaddleDuration(120)
{
}

void paddle::collisionAction() {

    if (isWidePaddleActive) {
        activateWidePaddleEffect();
    }
}

void paddle::moveLeft() {
    uprLft.x -= width;
}

void paddle::moveRight() {
    uprLft.x += width;
}

void paddle::paddleMovment() {
  
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
   
        pGame->getWind()->SetPen(LAVENDER);
        pGame->getWind()->SetBrush(LAVENDER);
        pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);

       
        if (uprLft.x > 0) {
            if (isReversePaddleActive) {
                if (isWindGlideActive) {
                    uprLft.x += width; 
                }
                if (isWidePaddleActive) {
                    uprLft.x += normalPaddleWidth / 4; 
                }
                uprLft.x += normalPaddleWidth / 2;
            }
            else {
                if (isWindGlideActive) {
                    uprLft.x -= width;
                }
                if (isWidePaddleActive) {
                    uprLft.x -= normalPaddleWidth / 4;
                }
                uprLft.x -= normalPaddleWidth / 2;
            }

        }
    }
   
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
      
        pGame->getWind()->SetPen(LAVENDER);
        pGame->getWind()->SetBrush(LAVENDER);
        pGame->getWind()->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);

      
        if (uprLft.x > 0) {
            if (isReversePaddleActive) {
                if (isWindGlideActive) {
                    uprLft.x -= width; 
                }
                if (isWidePaddleActive) {
                    uprLft.x -= normalPaddleWidth / 4; 
                }
                uprLft.x -= normalPaddleWidth / 2;
            }
            else {
                if (isWindGlideActive) {
                    uprLft.x += width;
                }
                if (isWidePaddleActive) {
                    uprLft.x += normalPaddleWidth / 4;
                }
                uprLft.x += normalPaddleWidth / 2;
            }

        }
    }

  
    if (isWindGlideActive && ((clock() - windGlideStartTime) / CLOCKS_PER_SEC >= windGlideDuration)) {
        isWindGlideActive = false;
    }


    if (isWidePaddleActive && ((clock() - widePaddleStartTime) / CLOCKS_PER_SEC >= widePaddleDuration)) {
        isWidePaddleActive = false;
        width = normalPaddleWidth; 
    }
    if (isReversePaddleActive && ((clock() - reversePaddleStartTime) / CLOCKS_PER_SEC >= reversePaddleDuration)) {
        isReversePaddleActive = false;
    }

    this->draw();
}

void paddle::draw() const {
    window* pWind = pGame->getWind();
    pWind->SetPen(RED);
    pWind->SetBrush(RED);
    pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + width, uprLft.y + height);
}

void paddle::redraw() {
    window* pWind = pGame->getWind();
    pWind->SetPen(RED);
    pWind->SetBrush(RED);
    pWind->DrawRectangle(600, 500, 700, 530);
}

void paddle::setUpperLeft(const point& newUpperLeft) {
    uprLft.x = newUpperLeft.x;
    uprLft.y = newUpperLeft.y;
}

void paddle::activateWindGlideEffect() {
    isWindGlideActive = true;
    windGlideStartTime = clock();
}

void paddle::activateWidePaddleEffect() {
    isWidePaddleActive = true;
    widePaddleStartTime = clock();
    width *= 2; 
}

void paddle::activateReversePaddleEffect() {
    isReversePaddleActive = true;
    reversePaddleStartTime = clock();
}
