#include "bateau.h"


//Ce constructeur est utilisé pour sortir le bateau du plateau et indiqué une erreur
bateau::bateau()
{
    this->posX = -99;
    this->posY = -99;
    this->taille = -99;

    this->orientation = -99;
    for (int i = 0; i < 5; i++) {
        this->tabVie[i] = 0;
    }
}

//Constructeur par défaut initialisiant les valeurs selon les entrées
bateau::bateau(int x, int y, int taille, int orientation) {
    this->posX = x;
    this->posY = y;
    this->taille = taille;
    this->orientation = orientation;
}

//Méthode d'affichages des coordonnées et des informations du bateau

void bateau::afficherCoordonnees()
{
    cout << "X = " << this->posX << ", Y = " << this->posY << endl;
}

void bateau::afficherInfoBateau()
{
    this->afficherCoordonnees();
    cout << "orientation = " << this->orientation << endl;
    cout << "tabVie = ";
    for (int i = 0; i < 5; i++) {
        cout << this->tabVie[i] << ", ";
    }
    cout << endl;

}

// GETTERS
int bateau::getPosX() {
    return this->posX;
}
int bateau::getPosY() {
    return this->posY;
}
int bateau::getOrientation() {
    return this->orientation;
}
int bateau::getTaille() {
    return this->taille;
}
int bateau::getTabVie(int num) {
    return this->tabVie[num];
}

// SETTERS
void bateau::setPosX(int posX) {
    this->posX = posX;
}
void bateau::setPosY(int posY) {
    this->posY = posY;
}
void bateau::setOrientation(int orientation) {
    this->orientation = orientation;
}
void bateau::setTaille(int taille) {
    this->taille = taille;
}
void bateau::setTabVie(int num, int valeur) {
    this->tabVie[num] = valeur;
}

//RECEPTION SHOT
//Méthode traitant la réception d'un tir en fonction de ses positions
int bateau::getShot(int y, int x) {
    
    int resultat = PLOUF;//initialisation d'un shot à loupé = PLOUF

    for (int j = 0; j < this->taille; j++) {//on regarde sur la dimension total du bateau
        if (this->orientation == NORD) {
            if ((this->posX == x) && (this->posY - j == y)) {// on trouve x position NORD on cherche y
                //touché !
                this->tabVie[j] = 1;
                resultat = TOUCHE;
            }
        }
        else if (this->orientation == SUD) {
            if ((this->posX == x +j ) && (this->posY == y)) {// on trouve y position SUD on cherche x
                //touché !
                this->tabVie[j] = 1;
                resultat = TOUCHE;
            }
        }
        else if (this->orientation == EST) {

            if ((this->posX == x) && (this->posY + j == y)) {// on trouve x position EST on cherche y
                //touché !
                this->tabVie[j] = 1;
                resultat = TOUCHE;
            }
        }
        else if (this->orientation == OUEST) {// on trouve y position OUEST on cherche x

            if ((this->posX - j == x) && (this->posY == y)) {
                //touché !
                this->tabVie[j] = 1;
                resultat = TOUCHE;
            }
        }
    }

    if (resultat == TOUCHE && this->bateauEnVie()) resultat = COULE; // on regarde la vie du bateau et les touchés

    /*
    if (resultat == PLOUF) {
        std::cout << "Plouf" << endl;
    }
    else if (resultat == TOUCHE) {
        std::cout << "Touch�" << endl;
    }
    else if (resultat == COULE) {
        std::cout << "Coul�" << endl;
    }
    */

    return resultat;   //On retourne le résultat qui est soit PLOUF (Aucun contact) ou TOUCHE ou COULE

}

//Cette méthode nous permet d'évaluer l'état de santé d'un bateau
int bateau::bateauEnVie()
{
    int recep_vie = 0;
  //Balayage du bateau
    for (int j = 0; j < this->taille; j++) {
        recep_vie += this->tabVie[j];
    }
    if (recep_vie == this->taille) {//test ve du bateau
        return 1; //bateau coul�
    }
    else
    {
        return 0; //bateau vivant
    }

}
