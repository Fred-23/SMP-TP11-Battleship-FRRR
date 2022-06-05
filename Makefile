prog : main.o bateau.o joueur.o partie.o pointAttaque.o 
	g++ -o prog main.o bateau.o joueur.o partie.o pointAttaque.o

test : test_bateau.o bateau.o
	g++ -o $@ test_bateau.o bateau.o -pthread ./googletest/lib/libgtest.a ./googletest/lib/libgtest_main.a

main.o : main.cpp
	g++ -o $@ -c $<

bateau.o : bateau.cpp
	g++ -o $@ -c $<

joueur.o : joueur.cpp
	g++ -o $@ -c $<

partie.o : partie.cpp
	g++ -o $@ -c $<

pointAttaque.o : pointAttaque.cpp
	g++ -o $@ -c $<

test_bateau.o: test_bateau.cpp
	g++ -o $@ -c $<
