#pragma once
#include "bateau.h"

class joueur
{
private:
    bateau torpilleur;
    bateau porteAvion;
    bateau croiseur;
    bateau contreTorpilleur1;
    bateau contreTorpilleur2;

public:
    joueur();
    void afficherBateau();
    void defInfoBateaux();


};

