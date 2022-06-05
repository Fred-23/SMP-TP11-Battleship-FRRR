#include <iostream>
#include "joueur.h"
#include "partie.h"

using namespace std;

//Fonction où on demande au joueur de sélectionner le mode de jeu via une valeur entière entre 0 et 2 
//Le traitement serait fait en fonction de la variable TypePartie

/*Voici les 3 différents modes de jeu
0  = J1 vs J2
1  = J1 vs IA
2  = IA vs IA
*/

int choixTypePartie() {
    int typePartie = getConsole("Type de partie = ");
    if (not((0 <= typePartie) and (typePartie <= 2))) { //valeur non comprise entre 0 et 2
        std::cout << "Erreur tu n'as pas saisi de valeur entre 0 et 2 inclus" << endl;
        typePartie = choixTypePartie();
    }
    return typePartie;
}

int main()
{
    //On initialise la seed srand pour générer aléatoirement le plateau de l'IA
    srand(time(NULL));

  
    /*joueur humain1;
    humain1.defInfoBateaux();
    humain1.afficherBateau();*/

    //IHM à destination du/des joueur(s)
    cout << "------ Jeu de la bataille navale ------" << endl << endl;

    cout << "Vous ne devez rentrer que des chars en entre clavier " << endl;
    cout << "C est a dire un seul caractere" << endl;
    cout << "Les strings ne sont pas prises en compte par le programme" << endl << endl;
  
    cout << "Choisis ton type de partie :" << endl;
    cout << "Entre 0 : Joueur contre Joueur " << endl;
    cout << "Entre 1 : Joueur contre IA " << endl;
    cout << "Entre 2 : IA contre IA " << endl << endl;
  
    

    int typePartie = choixTypePartie();

    //debut de la partie
    if (typePartie == 0) {
        cout << "------ Humain 1 ------" << endl;
        cout << "Placez vos bateaux !" << endl << endl;

        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl << endl;

        humain joueurIRL1;
        joueurIRL1.affichage();//affichage des valeurs de joueur 1

        joueurIRL1.defInfoBateaux(); //Affichage du plateau du joueur 1
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
        joueurIRL2.affichage();//affichage des valeurs de joueur2

        joueurIRL2.defInfoBateaux(); //Affichage du plateau du joueur 2
        //joueurIRL.afficherBateau();
        //joueurIRL.affichage();
        cout << endl;

        std::cout << "--- Debut de partie ---" << endl;

        partie partie0(joueurIRL1, joueurIRL2);//creation d'une partie
        partie0.lancerTour(0, typePartie); //lancement de la partie

    }else if (typePartie == 1) {
        cout << "------ IA ------" << endl;
        joueurIA ordinateur;
        ordinateur.defInfoBateaux();//intialisation des bateaux
        //affichage des bateaux
        //ordinateur.afficherBateau();
        cout << "Pour terminer la partie plus rapidement et pour que vous puissiez verifier le code, les position des bateaux adverses vous est revelee" << endl;
        ordinateur.affichage();
        cout << "Les IA ne sont pas intelligentes, lorsqu elles touchent elles ne tirent pas a cote pour couler le bateau" << endl;
        cout << "C est une fonctionnalite qu il reste a developper" << endl;

        cout << endl;

        cout << "------ Humain ------" << endl;
        cout << "Placez vos bateaux !" << endl << endl;

        std::cout << "Orientation NORD = 0" << endl;
        std::cout << "Orientation EST = 1" << endl;
        std::cout << "Orientation SUD = 2" << endl;
        std::cout << "Orientation OUEST = 3" << endl << endl;

        humain joueurIRL;
        joueurIRL.affichage();

        joueurIRL.defInfoBateaux();//definition des bateaux d'un joueur
        //joueurIRL.afficherBateau();
        //joueurIRL.affichage();
        cout << endl;

        partie partie1(joueurIRL, ordinateur);
        partie1.lancerTour(0, typePartie); //lancement de la partie

    }
    else if(typePartie == 2) {
        cout << "------ IA1 ------" << endl;
        joueurIA ordinateur1; //creation d'un joueur type IA
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

        cout << "Ce mode est experimental, normalement une partie se termine au maximum en 199 tours." << endl;
        cout << "Les IA ne sont pas intelligentes, lorsqu elles touchent elles ne tirent pas a cote pour couler le bateau" << endl;
        cout << "C est une fonctionnalite qu il reste a developper" << endl;
      
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

