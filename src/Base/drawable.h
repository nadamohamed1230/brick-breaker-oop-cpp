#pragma once
#include <string>
using namespace std;
#include "../../CMUgraphicsLib/CMUgraphics.h"

class game;     

struct point
{
    int x, y;
};


class drawable
{
protected:
    string imageName;
    point uprLft;       
    int width, height;

protected:
    game* pGame;        //pointer to game object
public:
    drawable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void draw() const;
    void setImageName(string path);
    point getuprlft();
    int getheight();
    int getwidth();
    void setuprlft(int ulft, int ulfty);
    void setwidth(int w);
    void setheight(int h);

};
