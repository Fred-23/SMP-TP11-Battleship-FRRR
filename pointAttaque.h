#pragma once
#include <random>

class pointAttaque {
protected:
    int pointX = 0;
    int pointY = 0;
public:
    pointAttaque();
    pointAttaque(int, int);

    int getPointX();
    int getPointY();

    void setPointX(int);
    void setPointY(int);

};

