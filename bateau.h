#pragma once
#include <string>
#include <iostream>

//Constante pour la variable orientation
#define NORD 0
#define SUD 1
#define EST 2
#define OUEST 3

//Constante pour la variable resultat
#define PLOUF 0
#define TOUCHE 1
#define COULE 2

using namespace std;

class bateau
{
private:
	int posX = 0;
	int posY = 0;
	int orientation;
	int taille = 0;
	int tabVie[5] = { 0 };

public:
//constructeur
	bateau();
	bateau(int x, int y, int taille, int orientation);

//methodes d'utilisations
	void afficherCoordonnees();
	void afficherInfoBateau();
	int getShot(int x, int y);
	int bateauEnVie();

	// GETTERS
	int getPosX();
	int getPosY();
	int getOrientation();
	int getTaille();
	int getTabVie(int num);

	// SETTERS
	void setPosX(int posX);
	void setPosY(int posY);
	void setOrientation(int orientation);
	void setTaille(int taille);
	void setTabVie(int num, int valeur);

};