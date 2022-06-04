#include <iostream>
#include "joueur.h"
#include "partie.h"

using namespace std;

int main()
{
    srand(time(NULL));
    //joueur humain1;
    //humain1.defInfoBateaux();
    //humain1.afficherBateau();
    cout << "------ Jeu de la btaille navale ------" << endl << endl;

    
    cout << "------ Humain ------" << endl;
    cout << "Placez vos bateaux !" << endl;
    humain joueurIRL;
    joueurIRL.defInfoBateaux();
    joueurIRL.afficherBateau();
    cout << endl;
    

    cout << "------ IA ------" << endl;
    joueurIA ordinateur;
    ordinateur.defInfoBateaux();
    ordinateur.afficherBateau();
    cout << endl;

    /*
    * //test IA VS IA
    cout << "------ IA2 ------" << endl;
    joueurIA ordinateur2;
    ordinateur2.defInfoBateaux();
    ordinateur2.afficherBateau();
    cout << endl;

    std::cout << "--- Debut de partie ---" << endl;

    partie partie1(ordinateur2, ordinateur);
    */

    std::cout << "--- Debut de partie ---" << endl;

    partie partie1(joueurIRL, ordinateur);
    

    partie1.lancerTour(0,1); //lancement de la partie



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
