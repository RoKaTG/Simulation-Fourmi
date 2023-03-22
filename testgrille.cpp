#include "grille.hpp"
#include <iostream>
using namespace std;

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
									   << " line " << __LINE__ << ": " #test << std::endl

/** Tests de la fonction initialiseGrilleVide **/
void testInitialiseGrilleVide(){
	Grille g;
	initialiseGrilleVide(g);
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++)
			ASSERT(estVide(g, {i, j}));
}

/** Tests des fonctions poseBrindille, enleveBrindille et contientBrindille **/
void testBrindille(){
	Grille g;
	initialiseGrilleVide(g);
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++){
			ASSERT(!(contientBrindille(g, {i, j})));
			poseBrindille(g, {i, j});
			ASSERT(contientBrindille(g, {i, j}));
		}
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++){
			enleveBrindille(g, {i, j});
			ASSERT(estVide(g, {i,j}));
		}
}

/** Tests des fonctions poseTermite, enleveTermite et numeroTermite **/
void testTermite(){
	Grille g;
	initialiseGrilleVide(g);
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++){
			ASSERT(numeroTermite(g, {i,j}) == -1);
			poseTermite(g, {i,j}, i*j);
			ASSERT(numeroTermite(g, {i,j}) != -1);
		}
	
	for(int i = 0; i < TAILLE; i++)
		for(int j = 0; j < TAILLE; j++){
			ASSERT(numeroTermite(g, {i,j}) == i*j);
			enleveTermite(g, {i,j});
			ASSERT(numeroTermite(g, {i,j}) == -1);
			ASSERT(estVide(g, {i,j}));
		}
}


int main(){
	testInitialiseGrilleVide();
	testBrindille();
	testTermite();
	
	return 0;
}