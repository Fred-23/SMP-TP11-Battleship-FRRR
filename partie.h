#pragma once
#include "joueur.h"
#include "pointAttaque.h"

class partie
{
protected:
	humain joueur1;
	humain joueur2;
	joueurIA joueur3;
	joueurIA joueur4;

	//plateau ?
	bool partieEnCours = false;

public:
  // constructeurs :
	partie();
	partie(humain joueur1, joueurIA joueur2); //joueur contre joueur
	partie(joueurIA joueur3, joueurIA joueur2); //joueur contre ordinateur
	partie(humain joueur1, humain joueur2); //ordinateur contre ordinateur

	void lancerTour(int tour, int typePartie); //méthode déroulement d'un tour
};

