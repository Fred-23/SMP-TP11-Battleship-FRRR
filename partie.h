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
	partie();
	partie(humain joueur1, joueurIA joueur2);
	partie(joueurIA joueur3, joueurIA joueur2);
	partie(humain joueur1, humain joueur2);
	void lancerTour(int tour, int typePartie);
};

