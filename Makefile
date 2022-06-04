machin.out : main.o bateau.o joueur.o partie.o pointAttaque.o 
	g++ -o machin.out main.o bateau.o joueur.o partie.o pointAttaque.o
main.o : main.cpp
	g++ -c main.cpp
bateau.o : bateau.cpp
	g++ -c bateau.cpp
joueur.o : joueur.cpp
	g++ -c joueur.cpp
partie.o : partie.cpp
	g++ -c partie.cpp
pointAttaque.o : pointAttaque.cpp
	g++ -c pointAttaque.cpp
