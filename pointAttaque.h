#pragma once
#include <random>

//Défintion de la classe PointAttaque  avec les parties proteges et publiques
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

