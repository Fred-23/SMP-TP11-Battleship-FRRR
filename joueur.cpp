#include "joueur.h"
#include <random>

joueur::joueur()
{
    this->torpilleur.setTaille(2); // taille 2
    this->porteAvion.setTaille(5); // taille 5
    this->croiseur.setTaille(4); // taille 4
    this->contreTorpilleur1.setTaille(3); // taille 3
    this->contreTorpilleur2.setTaille(3); // taille 3
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

void joueur::defInfoBateau(bateau & objet)
{
    objet.setPosX(5);
    objet.setPosY(5);
    objet.setOrientation(OUEST);
    for (int i = 0; i < 5; i++) {
        objet.setTabVie(i, 0);
    }
}

void joueur::defInfoBateaux() {
    this->defInfoBateau(this->torpilleur);
    this->defInfoBateau(this->porteAvion);
    this->defInfoBateau(this->croiseur);
    this->defInfoBateau(this->contreTorpilleur1);
    this->defInfoBateau(this->contreTorpilleur2);
}

int joueur::getAttaque(pointAttaque attAtuelle)
{
    int xTir = attAtuelle.getPointX();
    int yTir = attAtuelle.getPointY();
    int etat = -1;
    // -1 -> erreur
    // 0 -> plou
    // 1 -> bateau touch�
    // 2 -> bateau coul�
    // 3 -> tous les bateaux coul�s

    //getShot retourne 
    // #define PLOUF 0
    // #define TOUCHE 1
    // #define COULE 2

    if (this->torpilleur.getShot(xTir, yTir) == 0
        && this->porteAvion.getShot(xTir, yTir) == 0
        && this->croiseur.getShot(xTir, yTir) == 0
        && this->contreTorpilleur1.getShot(xTir, yTir) == 0
        && this->contreTorpilleur2.getShot(xTir, yTir) == 0
        ) {
        std::cout << "Plouf" << endl;
        etat = 0;
    }
    else if (this->torpilleur.getShot(xTir, yTir) == 1
        || this->porteAvion.getShot(xTir, yTir) == 1
        || this->croiseur.getShot(xTir, yTir) == 1
        || this->contreTorpilleur1.getShot(xTir, yTir) == 1
        || this->contreTorpilleur2.getShot(xTir, yTir) == 1) {
            
         std::cout << "Touche" << endl;
         etat = 1;
    }
    else if (this->torpilleur.getShot(xTir, yTir) == 2
        || this->porteAvion.getShot(xTir, yTir) == 2
        || this->croiseur.getShot(xTir, yTir) == 2
        || this->contreTorpilleur1.getShot(xTir, yTir) == 2
        || this->contreTorpilleur2.getShot(xTir, yTir) == 2) {

        std::cout << "Coule" << endl;
        etat = 2;
    }

    if (this->torpilleur.bateauEnVie()
        && this->porteAvion.bateauEnVie()
        && this->croiseur.bateauEnVie()
        && this->contreTorpilleur1.bateauEnVie()
        && this->contreTorpilleur2.bateauEnVie()
        ) {
        std::cout << "Dernier bateau coule" << endl;
        etat = 3;
    }
    return etat; // erreur
}

int joueur::attaqueX()
{
    return -1; // erreur
}
/*
void remplissageTableau(string & tab, bateau & bat, string acronyme) {
    for (int sens = 0; sens < bat.getTaille(); sens++) {
        if (bat.getOrientation() == 0) {
            tab[bat.getPosX()][bat.getPosY() - sens] = acronyme;
        }
        else if (bat.getOrientation() == 1) {
            tab[bat.getPosX() + sens][bat.getPosY()] = acronyme;
        }
        else if (bat.getOrientation() == 2) {
            tab[bat.getPosX()][bat.getPosY() + sens] = acronyme;
        }
        else if (bat.getOrientation() == 3) {
            tab[bat.getPosX() - sens][bat.getPosY() - sens] = acronyme;
        }
    }
}
*/
void joueur::affichage()
{
    string tab[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tab[i][j] = " . ";
        }
    }
    
    //remplissageTableau(tab[0][0], this->torpilleur, "Tor");
    string acronyme = "Tor";
    if ((this->torpilleur.getPosX() < 10) && (this->torpilleur.getPosX() >= 0)
        && (this->torpilleur.getPosY() < 10) && (this->torpilleur.getPosY() >= 0)
        ) {
        for (int sens = 0; sens < this->torpilleur.getTaille(); sens++) {
            if (this->torpilleur.getOrientation() == 0) {
                tab[this->torpilleur.getPosX()][this->torpilleur.getPosY() - sens] = acronyme;
            }
            else if (this->torpilleur.getOrientation() == 1) {
                tab[this->torpilleur.getPosX() + sens][this->torpilleur.getPosY()] = acronyme;
            }
            else if (this->torpilleur.getOrientation() == 2) {
                tab[this->torpilleur.getPosX()][this->torpilleur.getPosY() + sens] = acronyme;
            }
            else if (this->torpilleur.getOrientation() == 3) {
                tab[this->torpilleur.getPosX() - sens][this->torpilleur.getPosY()] = acronyme;
            }
        }
    }
    

    //remplissageTableau(tab[0][0], this->porteAvion, "PAv");
    acronyme = "PAv";
    if ((this->porteAvion.getPosX() < 10) && (this->porteAvion.getPosX() >= 0)
        && (this->porteAvion.getPosY() < 10) && (this->porteAvion.getPosY() >= 0)
        ) {
        for (int sens = 0; sens < this->porteAvion.getTaille(); sens++) {
            if (this->porteAvion.getOrientation() == 0) {
                tab[this->porteAvion.getPosX()][this->porteAvion.getPosY() - sens] = acronyme;
            }
            else if (this->porteAvion.getOrientation() == 1) {
                tab[this->porteAvion.getPosX() + sens][this->porteAvion.getPosY()] = acronyme;
            }
            else if (this->porteAvion.getOrientation() == 2) {
                tab[this->porteAvion.getPosX()][this->porteAvion.getPosY() + sens] = acronyme;
            }
            else if (this->porteAvion.getOrientation() == 3) {
                tab[this->porteAvion.getPosX() - sens][this->porteAvion.getPosY()] = acronyme;
            }
        }
    }

    
    //remplissageTableau(tab[0][0], this->croiseur, "Cro");
    acronyme = "Cro";
    if ((this->croiseur.getPosX() < 10) && (this->croiseur.getPosX() >= 0)
        && (this->croiseur.getPosY() < 10) && (this->croiseur.getPosY() >= 0)
        ) {
        for (int sens = 0; sens < this->croiseur.getTaille(); sens++) {
            if (this->croiseur.getOrientation() == 0) {
                tab[this->croiseur.getPosX()][this->croiseur.getPosY() - sens] = acronyme;
            }
            else if (this->croiseur.getOrientation() == 1) {
                tab[this->croiseur.getPosX() + sens][this->croiseur.getPosY()] = acronyme;
            }
            else if (this->croiseur.getOrientation() == 2) {
                tab[this->croiseur.getPosX()][this->croiseur.getPosY() + sens] = acronyme;
            }
            else if (this->croiseur.getOrientation() == 3) {
                tab[this->croiseur.getPosX() - sens][this->croiseur.getPosY()] = acronyme;
            }
        }
    }

    
    //remplissageTableau(tab[0][0], this->contreTorpilleur1, "CT1");
    acronyme = "CT1";
    if ((this->contreTorpilleur1.getPosX() < 10) && (this->contreTorpilleur1.getPosX() >= 0)
        && (this->contreTorpilleur1.getPosY() < 10) && (this->contreTorpilleur1.getPosY() >= 0)
        ) {
        for (int sens = 0; sens < this->contreTorpilleur1.getTaille(); sens++) {
            if (this->contreTorpilleur1.getOrientation() == 0) {
                tab[this->contreTorpilleur1.getPosX()][this->contreTorpilleur1.getPosY() - sens] = acronyme;
            }
            else if (this->contreTorpilleur1.getOrientation() == 1) {
                tab[this->contreTorpilleur1.getPosX() + sens][this->contreTorpilleur1.getPosY()] = acronyme;
            }
            else if (this->contreTorpilleur1.getOrientation() == 2) {
                tab[this->contreTorpilleur1.getPosX()][this->contreTorpilleur1.getPosY() + sens] = acronyme;
            }
            else if (this->contreTorpilleur1.getOrientation() == 3) {
                tab[this->contreTorpilleur1.getPosX() - sens][this->contreTorpilleur1.getPosY()] = acronyme;
            }
        }
    }

    
    //remplissageTableau(tab[0][0], this->contreTorpilleur2, "CT2");
    acronyme = "CT2";
    if ((this->contreTorpilleur2.getPosX() < 10) && (this->contreTorpilleur2.getPosX() >= 0)
        && (this->contreTorpilleur2.getPosY() < 10) && (this->contreTorpilleur2.getPosY() >= 0)
        ) {
        for (int sens = 0; sens < this->contreTorpilleur2.getTaille(); sens++) {
            if (this->contreTorpilleur2.getOrientation() == 0) {
                tab[this->contreTorpilleur2.getPosX()][this->contreTorpilleur2.getPosY() - sens] = acronyme;
            }
            else if (this->contreTorpilleur2.getOrientation() == 1) {
                tab[this->contreTorpilleur2.getPosX() + sens][this->contreTorpilleur2.getPosY()] = acronyme;
            }
            else if (this->contreTorpilleur2.getOrientation() == 2) {
                tab[this->contreTorpilleur2.getPosX()][this->contreTorpilleur2.getPosY() + sens] = acronyme;
            }
            else if (this->contreTorpilleur2.getOrientation() == 3) {
                tab[this->contreTorpilleur2.getPosX() - sens][this->contreTorpilleur2.getPosY()] = acronyme;
            }
        }
    }

    


    std::cout << "     -------------------------------------------------------------" << endl;
    std::cout << "   ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "  |  " << i;
    }
    std::cout << "  |" << endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "------------------------------------------------------------------" << endl;
        std::cout << "|  " << char('A' + i);
        for (int j = 0; j < 10; j++)
        {
            std::cout << " | " << tab[j][i];
        }
        std::cout << " |" << endl;
    }
    std::cout << "------------------------------------------------------------------" << endl;
}

bool joueur::superpositionDesBateaux()
{
    if (superpositionDeuxBateaux(this->torpilleur, this->porteAvion) 
        || superpositionDeuxBateaux(this->torpilleur, this->croiseur)
        || superpositionDeuxBateaux(this->torpilleur, this->contreTorpilleur1)
        || superpositionDeuxBateaux(this->torpilleur, this->contreTorpilleur2)

        || superpositionDeuxBateaux(this->porteAvion, this->croiseur)
        || superpositionDeuxBateaux(this->porteAvion, this->contreTorpilleur1)
        || superpositionDeuxBateaux(this->porteAvion, this->contreTorpilleur2)

        || superpositionDeuxBateaux(this->croiseur, this->contreTorpilleur1)
        || superpositionDeuxBateaux(this->croiseur, this->contreTorpilleur2)

        || superpositionDeuxBateaux(this->contreTorpilleur1, this->contreTorpilleur2)){
        
        return true;
    }else {
        return false;
    }
}

bool joueur::superpositionDeuxBateaux(bateau & bat1, bateau & bat2) {
    bool supBat = false;
    for (int i = 0; i < bat1.getTaille(); i++) {
        if (bat1.getOrientation() == 0) {
            for (int j = 0; j < bat2.getTaille(); j++) {
                if (bat2.getOrientation() == 0) {
                    if ((bat1.getPosX() == bat2.getPosX()) && (bat1.getPosY()+i == bat2.getPosY()+j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 1) {
                    if ((bat1.getPosX() == bat2.getPosX()+j) && (bat1.getPosY() + i == bat2.getPosY())) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 2) {
                    if ((bat1.getPosX() == bat2.getPosX()) && (bat1.getPosY() + i == bat2.getPosY()-j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 3) {
                    if ((bat1.getPosX() == bat2.getPosX()-j) && (bat1.getPosY() + i == bat2.getPosY())) {
                        supBat = true;
                    }
                }
            }
        }else if (bat1.getOrientation() == 1) {
            for (int j = 0; j < bat2.getTaille(); j++) {
                if (bat2.getOrientation() == 0) {
                    if ((bat1.getPosX()+i == bat2.getPosX()) && (bat1.getPosY() == bat2.getPosY() + j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 1) {
                    if ((bat1.getPosX()+i == bat2.getPosX() + j) && (bat1.getPosY() == bat2.getPosY())) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 2) {
                    if ((bat1.getPosX()+i == bat2.getPosX()) && (bat1.getPosY() + i == bat2.getPosY() - j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 3) {
                    if ((bat1.getPosX()+i == bat2.getPosX() - j) && (bat1.getPosY() + i == bat2.getPosY())) {
                        supBat = true;
                    }
                }
            }
        }else if(bat1.getOrientation() == 2) {
            for (int j = 0; j < bat2.getTaille(); j++) {
                if (bat2.getOrientation() == 0) {
                    if ((bat1.getPosX() == bat2.getPosX()) && (bat1.getPosY() - i == bat2.getPosY() + j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 1) {
                    if ((bat1.getPosX() == bat2.getPosX() + j) && (bat1.getPosY() - i == bat2.getPosY())) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 2) {
                    if ((bat1.getPosX() == bat2.getPosX()) && (bat1.getPosY() - i == bat2.getPosY() - j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 3) {
                    if ((bat1.getPosX() == bat2.getPosX() - j) && (bat1.getPosY() - i == bat2.getPosY())) {
                        supBat = true;
                    }
                }
            }
        }else if (bat1.getOrientation() == 3) {
            for (int j = 0; j < bat2.getTaille(); j++) {
                if (bat2.getOrientation() == 0) {
                    if ((bat1.getPosX() -i == bat2.getPosX()) && (bat1.getPosY() == bat2.getPosY() + j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 1) {
                    if ((bat1.getPosX() -i == bat2.getPosX() + j) && (bat1.getPosY() == bat2.getPosY())) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 2) {
                    if ((bat1.getPosX() - i == bat2.getPosX()) && (bat1.getPosY() == bat2.getPosY() - j)) {
                        supBat = true;
                    }
                }
                else if (bat2.getOrientation() == 3) {
                    if ((bat1.getPosX() - i == bat2.getPosX() - j) && (bat1.getPosY() == bat2.getPosY())) {
                        supBat = true;
                    }
                }
            }
        }
    }

    return supBat;
}

int joueur::attaqueY()
{
    return -1; // erreur
}

// ### classe JOUEURIA ###

int orientationAleatoire(int pos_x, int pos_y, int taille) {
    int nbAleatoire = rand() % 4;
    int resultat;
    if ((nbAleatoire == 0) && (pos_y - taille > 0)){
        resultat = nbAleatoire;
    }
    else if ((nbAleatoire == 1) && (pos_x + taille < 10)) {
        resultat = nbAleatoire;
    }
    else if ((nbAleatoire == 2) && (pos_y + taille < 10)) {
        resultat = nbAleatoire;
    }
    else if ((nbAleatoire == 3) && (pos_x - taille > 0)) {
        resultat = nbAleatoire;
    }
    else {
        resultat = orientationAleatoire(pos_x, pos_y, taille);
    }
    return resultat;
}

void joueurIA::defInfoBateau(bateau & objet)
{
    objet.setPosX(rand() % 10);
    objet.setPosY(rand() % 10);
    objet.setOrientation(orientationAleatoire(objet.getPosX(), objet.getPosY(), objet.getTaille()));

    for (int i = 0; i < 5; i++) {
        objet.setTabVie(i, 0);
    }
}

void joueurIA::defInfoBateaux() {
    this->defInfoBateau(this->torpilleur);
    this->defInfoBateau(this->porteAvion);
    this->defInfoBateau(this->croiseur);
    this->defInfoBateau(this->contreTorpilleur1);
    this->defInfoBateau(this->contreTorpilleur2);

    if (this->superpositionDesBateaux() == true) { //si les bateaux se superposent on rappelle la fonction jusqu a ce qu ils ne se superposent plus
        this->defInfoBateaux();
    }
}

pointAttaque joueurIA::attaqueXY() {
    int xTir = rand() % 10;
    int yTir = rand() % 10;
    pointAttaque attaqueActuelle(xTir, yTir);
    bool tirDifferent = true;

    for (int i = 0; i < this->shoots.size() ; i++)
    {
        if (this->shoots[i].getPointX() == xTir && this->shoots[i].getPointY() == yTir) {
            if (this->shoots.size() <= 100) {
                tirDifferent = false;
            }
            else {
                std::cout << "Le plateau a ete crible dans son entierete" << endl;
            }
        } 
    }
    if (tirDifferent == false)
    {
        attaqueActuelle = attaqueXY();
    }
    
    this->shoots.push_back(attaqueActuelle);
    
    return attaqueActuelle;
}

// ### classe HUMAIN ###

int getConsole(string message) {
    int data;
    std::cout << message;
    std::cin >> data;
    //std::cout << data << endl;
    return data;
}

int getConsoleChar(string message) {
    char data;
    std::cout << message;
    std::cin >> data;
    //std::cout << data << endl;
    return data;
}

int getVarPosX() {
    int posX = int(getConsoleChar("Colonne = ")-'0');
    if (not((0 <= posX) and (posX <= 9))) {
        std::cout << "Erreur la colonne saisie n'est pas comprise entre 0 et 9 inclus" << endl;
        posX = getVarPosX();
    }
    return posX;
}

int getVarPosY() {
    char posY = getConsoleChar("Ligne = ");
    if (not(('a' <= posY) and (posY <= 'j'))) {
        std::cout << "Erreur la ligne saisie n'est pas comprise entre a et j inclus" << endl;

        posY = getVarPosY();
    }
    return int(posY - 'a');
}

int getOrientation() {
    int orientation = getConsole("orientation = ");
    if (not((0 <= orientation) and (orientation <= 3))) {
        std::cout << "Erreur l'orientation saisie n'est pas comprise entre 0 et 3 inclus" << endl;
        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl;
        orientation = getOrientation();
    }
    return orientation;
}

void humain::defInfoBateau(bateau & objet)
{
    objet.setPosY(getVarPosY());
    objet.setPosX(getVarPosX());
    
    int resultat = getOrientation();
    if ((resultat == 0) && (objet.getPosY() - objet.getTaille() > 0)) {
        objet.setOrientation(resultat);
    }
    else if ((resultat == 1) && (objet.getPosX() + objet.getTaille() < 10)) {
        objet.setOrientation(resultat);
    }
    else if ((resultat == 2) && (objet.getPosY() + objet.getTaille() < 10)) {
        objet.setOrientation(resultat);
    }
    else if ((resultat == 3) && (objet.getPosX() - objet.getTaille() > 0)) {
        objet.setOrientation(resultat);
    }else {
        std::cout << "Erreur, ton bateau sort du plateau" << endl;
        std::cout << "Replace le" << endl;
        defInfoBateau(objet);
    }

    for (int i = 0; i < 5; i++) {
        objet.setTabVie(i, 0);
    }

    if(superpositionDesBateaux())
    {
        std::cout << endl << "Erreur, ton bateau se superpose a un autre bateau" << endl;
        this->defInfoBateau(objet);
    }
    
}

void humain::defInfoBateaux() {
    std::cout << " --- Torpilleur --- " << endl;
    this->defInfoBateau(this->torpilleur);
    affichage();

    std::cout << endl << " --- Porte Avion --- " << endl;
    this->defInfoBateau(this->porteAvion);
    affichage();
    
    std::cout << endl << " --- Croiseur --- " << endl;
    this->defInfoBateau(this->croiseur);
    affichage();

    std::cout << endl << " --- Contre Torpilleur 1 --- " << endl;
    this->defInfoBateau(this->contreTorpilleur1);
    affichage();

    std::cout << endl << " --- Contre Torpilleur 2 --- " << endl;
    this->defInfoBateau(this->contreTorpilleur2);
    affichage();

    if (this->superpositionDesBateaux() == true) { //si les bateaux se superposent on rappelle la fonction jusqu a ce qu ils ne se superposent plus
        std::cout << endl << " Erreur, au moins deux de vos bateaux se superposent " << endl;
        this->defInfoBateaux();
    }
}


int humain::attaqueX()
{
    std::cout << "A toi de tirer" << endl;
    return getVarPosY();
}

int humain::attaqueY()
{
    return getVarPosX();
}