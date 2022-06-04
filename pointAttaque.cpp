#include "pointAttaque.h"

pointAttaque::pointAttaque()
{
    this->setPointX(0);
    this->setPointY(0);
}

pointAttaque::pointAttaque(int x, int y)
{
    this->setPointX(x);
    this->setPointY(y);
}

int pointAttaque::getPointX()
{
    return this->pointX;
}

int pointAttaque::getPointY()
{
    return this->pointY;
}

void pointAttaque::setPointX(int x)
{
    this->pointX = x;
}

void pointAttaque::setPointY(int y)
{
    this->pointY = y;
}
