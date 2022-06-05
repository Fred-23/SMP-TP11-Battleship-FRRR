#include <iostream>
#include "joueur.h"
#include "partie.h"

using namespace std;



int choixTypePartie() {
    int typePartie = getConsole("Type de partie = ");
    if (not((0 <= typePartie) and (typePartie <= 2))) {
        std::cout << "Erreur tu n'as pas saisi de valeur entre 0 et 2 inclus" << endl;
        typePartie = choixTypePartie();
    }
    return typePartie;
}

int main()
{
    srand(time(NULL));
    //joueur humain1;
    //humain1.defInfoBateaux();
    //humain1.afficherBateau();
    cout << "------ Jeu de la bataille navale ------" << endl << endl;
    cout << "Choisis ton type de partie :" << endl;
    cout << "Entre 0 : Joueur contre Joueur " << endl;
    cout << "Entre 1 : Joueur contre IA " << endl;
    cout << "Entre 2 : IA contre IA " << endl;

    int typePartie = choixTypePartie();

    
    if (typePartie == 0) {
        cout << "------ Humain 1 ------" << endl;
        cout << "Placez vos bateaux !" << endl << endl;

        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl << endl;

        humain joueurIRL1;
        joueurIRL1.affichage();

        joueurIRL1.defInfoBateaux();
        //joueurIRL.afficherBateau();
        //joueurIRL.affichage();
        cout << endl;

        cout << "------ Humain 2 ------" << endl;
        cout << "Placez vos bateaux !" << endl << endl;

        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl << endl;


        humain joueurIRL2;
        joueurIRL2.affichage();

        joueurIRL2.defInfoBateaux();
        //joueurIRL.afficherBateau();
        //joueurIRL.affichage();
        cout << endl;

        std::cout << "--- Debut de partie ---" << endl;

        partie partie0(joueurIRL1, joueurIRL2);
        partie0.lancerTour(0, typePartie); //lancement de la partie

    }else if (typePartie == 1) {
        cout << "------ IA ------" << endl;
        joueurIA ordinateur;
        ordinateur.defInfoBateaux();
        ordinateur.afficherBateau();
        ordinateur.affichage();

        cout << endl;

        cout << "------ Humain ------" << endl;
        cout << "Placez vos bateaux !" << endl << endl;

        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl << endl;

        humain joueurIRL;
        joueurIRL.affichage();

        joueurIRL.defInfoBateaux();
        //joueurIRL.afficherBateau();
        //joueurIRL.affichage();
        cout << endl;

        partie partie1(joueurIRL, ordinateur);
        partie1.lancerTour(0, typePartie); //lancement de la partie

    }
    else if(typePartie == 2) {
        cout << "------ IA1 ------" << endl;
        joueurIA ordinateur1;
        ordinateur1.defInfoBateaux();
        ordinateur1.afficherBateau();
        cout << endl;

        //test IA VS IA
        cout << "------ IA2 ------" << endl;
        joueurIA ordinateur2;
        ordinateur2.defInfoBateaux();
        ordinateur2.afficherBateau();
        cout << endl;

        std::cout << "--- Debut de partie ---" << endl;

        partie partie2(ordinateur1, ordinateur2);
        partie2.lancerTour(0, typePartie); //lancement de la partie
    }
    else {
        cout << "Erreur, fin du programme" << endl;
    }
    
    



    /*
    cout << "------ Tests classe bateau ------" << endl;
    //x = 2 , y = 3 , taille = 5 , orietation = NORD
    bateau b1(2, 3, 5, SUD);

    std::cout << b1.getShot(2, 2) << endl;
    std::cout << b1.getShot(3, 3) << endl;
    std::cout << b1.getShot(1, 3) << endl;

    std::cout << b1.getShot(2, 3) << endl;
    std::cout << b1.getShot(2, 4) << endl;
    std::cout << b1.getShot(2, 5) << endl;
    std::cout << b1.getShot(2, 6) << endl;
    std::cout << b1.getShot(2, 7) << endl;
    std::cout << b1.getShot(2, 8) << endl;

    std::cout << b1.getShot(2, 4) << endl;
    */

    
    




    

}

