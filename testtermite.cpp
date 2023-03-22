#include "termite.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
									   << " line " << __LINE__ << ": " #test << std::endl

/** Tests des fonction du type tabTermite **/
void testTabTermites(){
	Grille g;
	initialiseGrilleVide(g);
	
	tabTermites t;
	tabVide(t);
	ASSERT(t.taille == 0);
	int nbTermites = (TAILLE*TAILLE)/10 + 5;
	int x, y;
	for(int i = 0; i < nbTermites; i++){
		do{
			x = rand()%TAILLE;
			y = rand()%TAILLE;
		}while(!estVide(g, {x, y}));
		creeTermite(t, {x, y});
	}
	ASSERT(t.taille < nbTermites);
	ASSERT(t.taille == (TAILLE*TAILLE)/10);
	ASSERT(estPlein(t));
}

/** Tests des fonctions du type Termite **/
void testTermite(){
	Grille g;
	initialiseGrilleVide(g);
	int x, y;
	
	tabTermites t;
	tabVide(t);
	for(int i = 0; i < (TAILLE*TAILLE)/10; i++){
		do{
			x = rand()%TAILLE;
			y = rand()%TAILLE;
		}while(!estVide(g, {x, y}));
		creeTermite(t, {x, y});
	}
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++)
			if(numeroTermite(g, {i, j}) >= 0){
				ASSERT(egalCoord(t.tab[numeroTermite(g, {i,j})].position, {i, j}));
				ASSERT(t.tab[numeroTermite(g, {i,j})].numero == numeroTermite(g, {i, j}));
			}
	
	for(int i = 0; i < (TAILLE*TAILLE)/10; i++){
		ASSERT(!porteBrindille(t.tab[i]));
		if(laVoieEstLibre(g, t.tab[i])){
			poseBrindille(g, devantTermite(t.tab[i]));
			chargeTermite(g, t.tab[i]);
			ASSERT(porteBrindille(t.tab[i]));
			dechargeTermite(g, t.tab[i]);
		}
	}
	
	for(int i = 0; i < (TAILLE*TAILLE)/10; i++){
		ASSERT(!porteBrindille(t.tab[i]));
		ASSERT(brindilleEnFace(g, t.tab[i]) or !laVoieEstLibre(g, t.tab[i]));
	}
}

int main(){
	srand(time(0));
	testTabTermites();
	testTermite();
	return 0;
}