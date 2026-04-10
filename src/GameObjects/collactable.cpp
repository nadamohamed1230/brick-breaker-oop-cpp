#include "collactable.h"
#include "../Core/game.h"
#include "../../CMUgraphicsLib/auxil.h"

Collectable::Collectable(point r_uprleft, int r_width, int r_height, game* r_pGame)
    : collidable(r_uprleft, r_width, r_height, r_pGame), isGrounded(false)
{

}
void Collectable::move()
{
   
}

//void Collectable::removeFromGame()
//{
//     //Remove the collectable from the game
//    pGame->removeCollectable(this);
//}




bool Collectable::checkCollisionWithGround() const
{

    // Adjust the ground level as needed
    return uprLft.y + height / 2 >= pGame->getWind()->GetHeight() - 50;
}
WindGlide::WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame)
    : Collectable(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\collectables\\windglide.jpg";
}

void WindGlide::draw()const
{
    window* pWind = pGame->getWind();
    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, brick->getuprlft().y+40, width, height);
}

void WindGlide::collisionAction() 
{
    pGame->getPaddle()->activateWindGlideEffect();
}

void WindGlide::move()
{
  
        window* pWind = pGame->getWind();

        draw();
        pWind->SetPen(LAVENDER);
        pWind->SetBrush(LAVENDER);
        collidable* brick = pGame->getGrid()->getbrick();
        pWind->DrawRectangle(brick->getuprlft().x  , uprLft.y ,
            brick->getuprlft().x + width , uprLft.y + height );
        uprLft.y += 10;
       
        pWind->DrawImage(imageName, brick->getuprlft().x, uprLft.y + 40, width, height);
        pWind->DrawRectangle(brick->getuprlft().x, uprLft.y,
            brick->getuprlft().x + width, uprLft.y + height);
        pGame->getGrid()->draw();
        pWind->UpdateBuffer();
        Pause(20);
    
}



WidePaddle::WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame)
    : Collectable(r_uprleft, r_width, r_height, r_pGame) {
    imageName = "images\\collectables\\widepaddle.jpg";
}

void WidePaddle::draw() const {
    window* pWind = pGame->getWind();
    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, brick->getuprlft().y+40, width, height);
}

void WidePaddle::collisionAction() {
    pGame->getPaddle()->activateWidePaddleEffect();
}

void WidePaddle::move()
{
    
        window* pWind = pGame->getWind();
        
        draw();
      
        uprLft.y += 5;
        Collectable* p = pGame->pCollactable();
           
            collidable* brick = pGame->getGrid()->getbrick();
            pWind->DrawImage(imageName, brick->getuprlft().x, uprLft.y + 40, width, height);
        
        pGame->getGrid()->draw();
        pWind->UpdateBuffer();
        Pause(40);
   
}

fireball::fireball(point r_uprleft, int r_width, int r_height, game* r_pGame)
    : Collectable(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\collectables\\fireball.jpg";
}

void fireball::draw() const
{
    window* pWind = pGame->getWind();
    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, brick->getuprlft().y + 40, width, height);
   
  
}

void fireball::collisionAction()
{
    pGame->getBall()->activatefireball();
}

void fireball::move()
{
    window* pWind = pGame->getWind();

    draw();

    uprLft.y += 5;
    Collectable* p = pGame->pCollactable();

    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, uprLft.y + 40, width, height);

    pGame->getGrid()->draw();
    pWind->UpdateBuffer();
    Pause(40);

}
ReversePaddle::ReversePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame)
    : Collectable(r_uprleft, r_width, r_height, r_pGame) {
    imageName = "images\\collectables\\widepaddle.jpg";
}

void ReversePaddle::draw() const {
    window* pWind = pGame->getWind();
    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, brick->getuprlft().y + 40, width, height);
}

void ReversePaddle::collisionAction() {
    pGame->getPaddle()->activateReversePaddleEffect();
}

void ReversePaddle::move() {
    window* pWind = pGame->getWind();

    draw();

    uprLft.y += 5;
    Collectable* p = pGame->pCollactable();

    collidable* brick = pGame->getGrid()->getbrick();
    pWind->DrawImage(imageName, brick->getuprlft().x, uprLft.y + 40, width, height);

    pGame->getGrid()->draw();
    pWind->UpdateBuffer();
    Pause(40);
}
