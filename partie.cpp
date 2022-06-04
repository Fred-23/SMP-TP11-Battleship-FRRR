#pragma once	
#include "partie.h"


partie::partie()
{
	this->partieEnCours = false;
}

partie::partie(humain joueur1, humain joueur2)
{
	this->joueur1 = joueur1;
	this->joueur2 = joueur2;
	this->partieEnCours = true;
}

partie::partie(humain joueur, joueurIA ordinateur)
{
	this->joueur1 = joueur;
	this->joueur3 = ordinateur;
	this->partieEnCours = true;
}

partie::partie(joueurIA ordinateur1, joueurIA ordinateur2)
{
	this->joueur3 = ordinateur1;
	this->joueur4 = ordinateur2;
	this->partieEnCours = true;
}

void partie::lancerTour(int tour, int typePartie)
{
	std::cout << endl << "Tour " << tour << endl;

	int test = -1;
	// -1 -> erreur
	// 0 -> aucun bateau coulé
	// 1 -> un bateau coulé
	// 2-> tous les bateaux coulés

	if (typePartie == 0) {
		if (tour % 2 == 0) {
			int x = this->joueur1.attaqueX();
			int y = this->joueur1.attaqueY();
			pointAttaque attActuelle(x, y);
			test = this->joueur2.getAttaque(attActuelle); // l'humain attaque l'autre humain
		}
		else {
			int x = this->joueur2.attaqueX();
			int y = this->joueur2.attaqueY();
			pointAttaque attActuelle(x, y);
			test = this->joueur1.getAttaque(attActuelle); // l'humain attaque l'autre humain
		}
	}
	else if (typePartie == 1) {
		if (tour % 2 == 0) {
			int x = this->joueur1.attaqueX();
			int y = this->joueur1.attaqueY();
			pointAttaque attActuelle(x, y);
			test = this->joueur3.getAttaque(attActuelle); // l'humain attaque l'IA
		}
		else {
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur3.attaqueXY();
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur1.getAttaque(attActuelle); // l'IA attaque l'humain
		}
	}
	else if (typePartie == 2) {
		if (tour % 2 == 0) {
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur3.attaqueXY();
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur4.getAttaque(attActuelle); // l'IA attaque l'humain
		}
		else {
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur4.attaqueXY();
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur3.getAttaque(attActuelle); // l'IA attaque l'humain
		}
	}



	tour++;

	if (test == 0) {
		// aucun bateau n'a ete coule
		this->lancerTour(tour, typePartie);
	}
	else if (test == 1) {
		//un bateau a ete touche
		this->lancerTour(tour, typePartie);
	}
	else if (test == 2) {
		//un bateau a ete coule
		this->lancerTour(tour, typePartie);
	}
	else if (test == 3) {
		//tous les bateaux ont ete coules
		std::cout << "--- Fin de partie ---" << endl;
		//MESSAGE DE FIN DE PARTIE x joueur a gagne...
	}
	else {
		std::cout << "Erreur de programmation -> Fin de partie" << endl;
	}

}

