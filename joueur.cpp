#include "joueur.h"

joueur::joueur()
{
	this->contreTorpilleur1.afficherCoordonnees();

}

void joueur::afficherBateau()
{
    cout << "### Torpilleur ###" << endl;
    this->torpilleur.afficherInfoBateau();
    cout << "### Porte avion ###" << endl;
    this->porteAvion.afficherInfoBateau();
    cout << "### Croiseur ###" << endl;
    this->croiseur.afficherInfoBateau();
    cout << "### Contre Torpilleur 1 ###" << endl;
    this->contreTorpilleur1.afficherInfoBateau();
    cout << "### Contre Torpilleur 2 ###" << endl;
    this->contreTorpilleur2.afficherInfoBateau();
}

void joueur::defInfoBateaux()
{

}
