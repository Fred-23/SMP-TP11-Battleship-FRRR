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
	string tabVie[5];

public:
	bateau();
	bateau(int x, int y, int taille, string orientation);
	void afficherCoordonnees();
	void afficherInfoBateau();


};

