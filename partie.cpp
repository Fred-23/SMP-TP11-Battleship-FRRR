#include "partie.h"


partie::partie()
{
	this->partieEnCours = false;
}

partie::partie(humain joueur1, humain joueur2)
{
	this->joueur1 = joueur1;
	this->joueur2 = joueur2;
	this->partieEnCours = true; //lancement de la partie
}

partie::partie(humain joueur, joueurIA ordinateur)
{
	this->joueur1 = joueur;
	this->joueur3 = ordinateur;
	this->partieEnCours = true; //lancement de la partie
}

partie::partie(joueurIA ordinateur1, joueurIA ordinateur2)
{
	this->joueur3 = ordinateur1;
	this->joueur4 = ordinateur2;
	this->partieEnCours = true; //lancement de la partie
}

void partie::lancerTour(int tour, int typePartie)
{
	std::cout << endl << "Tour " << tour << endl;

	int test = -1;
	// -1 -> erreur
	// 0 -> aucun bateau coule
	// 1 -> un bateau coule
	// 2-> tous les bateaux coules

	if (typePartie == 0) { //si joueur contre joueur
		if (tour % 2 == 0) { //si nombre de tours pair
			int x = this->joueur1.attaqueX(); //saisie abscisse d'attaque
			int y = this->joueur1.attaqueY(); //saisie ordonnée d'attaque
			pointAttaque attActuelle(x, y);
			test = this->joueur2.getAttaque(attActuelle); // l'humain attaque l'autre humain
		}
		else { //si nombre de tours impair
			int x = this->joueur2.attaqueX(); //saisie abscisse d'attaque
			int y = this->joueur2.attaqueY(); //saisie ordonnée d'attaque
			pointAttaque attActuelle(x, y);
			test = this->joueur1.getAttaque(attActuelle); // l'humain attaque l'autre humain
		}
	}
	else if (typePartie == 1) { //si joueur contre ordinateur
		if (tour % 2 == 0) { //si nombre de tours pair
			int x = this->joueur1.attaqueX(); //saisie abscisse d'attaque
			int y = this->joueur1.attaqueY(); //saisie ordonnée d'attaque
			pointAttaque attActuelle(x, y);
			test = this->joueur3.getAttaque(attActuelle); // l'humain attaque l'IA
		}
		else { //si nombre de tours impair
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur3.attaqueXY(); //génération de coordonnées d'attaque 
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur1.getAttaque(attActuelle); // l'IA attaque l'humain
		}
	}
	else if (typePartie == 2) { //si ordinateur contre ordinateur
		if (tour % 2 == 0) { //si nombre de tours pair
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur3.attaqueXY(); //génération de coordonnées d'attaque 
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur4.getAttaque(attActuelle); // l'IA attaque l'autre IA
		}
		else { //si nombre de tours impair
			pointAttaque attActuelle(0, 0);
			attActuelle = this->joueur4.attaqueXY(); //génération de coordonnées d'attaque 
			std::cout << "Tir de l'IA : x = " << attActuelle.getPointX() << ", y = " << attActuelle.getPointY() << endl;
			test = this->joueur3.getAttaque(attActuelle); // l'IA attaque l'autre IA
		}
	}

	tour++; //incrémentation tour suivant

	if (test == 0) {
		// aucun bateau n'a ete coule
		this->lancerTour(tour, typePartie); //tour suivant
	}
	else if (test == 1) {
		//un bateau a ete touche
		this->lancerTour(tour, typePartie); //tour suivant
	}
	else if (test == 2) {
		//un bateau a ete coule
		this->lancerTour(tour, typePartie); //tour suivant
	}
	else if (test == 3) {
		//tous les bateaux ont ete coules
		std::cout << "--- Fin de partie ---" << endl;
		if (tour % 2 == 0) { //si nombre de tours pair
			std::cout << "Le joueur 1 a gagne" << endl;
		}
		else { //si nombre de tours impair
			std::cout << "Le joueur 2 a gagne" << endl;
		}
	}
	else {
		std::cout << "Erreur de programmation -> Fin de partie" << endl;
	}
	
}

