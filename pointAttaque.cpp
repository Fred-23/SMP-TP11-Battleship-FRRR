#include "pointAttaque.h"

//Constructeur initial à l'origine
pointAttaque::pointAttaque()
{
    this->setPointX(0);
    this->setPointY(0);
}
//Constructeur via des positions entieres x et y
pointAttaque::pointAttaque(int x, int y)
{
    this->setPointX(x);
    this->setPointY(y);
}

//GETTERS
int pointAttaque::getPointX()
{
    return this->pointX;
}

int pointAttaque::getPointY()
{
    return this->pointY;
}

//SETTERS
void pointAttaque::setPointX(int x)
{
    this->pointX = x;
}

void pointAttaque::setPointY(int y)
{
    this->pointY = y;
}
