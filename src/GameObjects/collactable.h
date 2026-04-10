#pragma
#include "../Base/collidable.h"
#include "ball.h"

enum CollectableType
{
    WINDGLIDE_COLLECTABLE,
    WIDEPADDLE_COLLECTABLE,
    FIREBALL_COLLECTABLE,
    ReversePaddle_COLLECTABLE,
    NUM_COLLECTABLE_TYPES  // Should be the last entry
};
class Collectable : public collidable
{
protected:
    bool isGrounded;

public:
    Collectable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void move();
 /*   void removeFromGame();*/
    bool checkCollisionWithGround() const;
};
class WindGlide : public Collectable {
public:
    WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void draw() const override;
    void collisionAction() override;
    void move();
};


class WidePaddle : public Collectable {
public:
    WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void draw()  const override;
    void collisionAction() override;
    void move();
};


class fireball :public Collectable
{
public:
    fireball(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void draw() const override;
    void collisionAction() override;
    void move();
};
class ReversePaddle : public Collectable {
public:
    ReversePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    void draw() const override;
    void collisionAction() override;
    void move();
};
