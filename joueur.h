#pragma once
#include "bateau.h"
#include <vector>
#include <tuple>
#include "pointAttaque.h"

int getConsole(string message);

class joueur
{
protected:
    bateau torpilleur; // taille 2
    bateau porteAvion; // taille 5
    bateau croiseur; // taille 4
    bateau contreTorpilleur1; // taille 3
    bateau contreTorpilleur2; // taille 3

public:
    joueur();
    void afficherBateau();
    void defInfoBateau(bateau& objet);
    void defInfoBateaux();
    int getAttaque(pointAttaque attActuelle);
    int attaqueX();
    int attaqueY();
    bool superpositionDesBateaux();
    bool superpositionDeuxBateaux(bateau& bat1, bateau& bat2);
    void affichage();
};

class humain : public joueur {
protected:

public:
    void defInfoBateau(bateau& objet);
    void defInfoBateaux();
    int attaqueX();
    int attaqueY();

};

class joueurIA : public joueur {
protected:
    vector<pointAttaque> shoots;
    vector<int> shootsResultat;

public:
    void defInfoBateau(bateau& objet);
    void defInfoBateaux();
    //int attaqueX();
    //int attaqueY();
    pointAttaque attaqueXY();

};

