#pragma once
#include <string>
#include <iostream>
using namespace std;

class bateau
{
private :
	int posX = 0;
	int posY = 0;
	string orientation;
	int taille = 0;
	bool tabVie[10][10];

public:
	bateau(int x, int y, int taille);
	void afficherCoordonnees();


};

