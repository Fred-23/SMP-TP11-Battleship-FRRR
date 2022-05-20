#include "bateau.h"

bateau::bateau(int x, int y, int taille, string orientation) {
	this->posX = x;
	this->posY = y;
	this->taille = taille;
	this->orientation = orientation;
}

bateau::bateau()
{
	this->orientation = "None";
	for (int i = 0; i < this->taille; i++) {
		this->tabVie[i] = "intact";
	}
	for (int i = taille; i < 5; i++)
	{
		this->tabVie[i] = "None";
	}
}

void bateau::afficherCoordonnees()
{
	cout << "X = " << this->posX << ", Y = " << this->posY << endl;
}
void bateau::afficherInfoBateau()
{
	this->afficherCoordonnees();
	cout << "orientation = " << this->orientation << endl;
	cout << "tabVie = ";
	for(int i = 0; i < 5; i++) {
		cout << this->tabVie[i]<<", ";
	}
	cout << endl;

}
