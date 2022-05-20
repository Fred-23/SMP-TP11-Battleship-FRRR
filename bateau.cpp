#include "bateau.h"

bateau::bateau(int x, int y, int taille) {
	this->posX = x;
	this->posY = y;
	this->taille = taille;
}

void bateau::afficherCoordonnees()
{
	cout <<"X = " << this->posX <<", Y = " << this->posY << endl;
}
