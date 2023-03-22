#include "grille.hpp"
#include <iostream>

using namespace std;

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
                                       << " line " << __LINE__ << ": " #test << std::endl

void initialiseCaseVide(Case &c){
	c.valeur = -1;
}

void initialiseGrilleVide(Grille &g){
     for(int j = 0; j <TAILLE; j++)
    for(int i = 0; i < TAILLE; i++)
         initialiseCaseVide(g.t[j][i]);
}

bool estVide(Grille g, Coord c){
    return g.t[getX(c)][getY(c)].valeur == -1;
}

bool dansGrille(Grille g, Coord c){
    int x = getX(c);
    int y = getY(c);
    return x >= 0 and x < TAILLE and y >= 0 and y < TAILLE;
}

bool contientBrindille(Grille g, Coord c){
    return dansGrille(g, c) and g.t[getX(c)][getY(c)].valeur == -2;
}

int numeroTermite(Grille g, Coord c){
    if(g.t[getX(c)][getY(c)].valeur < 0)
        return -1;
    else {
    return g.t[getX(c)][getY(c)].valeur;
    }
}

void poseBrindille(Grille &g, Coord c){        //Possible utilisation de l'assert pour vérifier au fil de l'execution des erreurs
    if(dansGrille(g, c) and estVide(g, c))
        g.t[getX(c)][getY(c)].valeur = -2;              //Correcton de la plage e valeur -2 à la place de -5
}

void enleveBrindille(Grille &g, Coord c){                //Possible utilisation de l'assert pour vérifier au fil de l'execution des erreurs
    if(dansGrille(g, c) and contientBrindille(g, c))    
        g.t[getX(c)][getY(c)].valeur = -1;                   //Idem ici y'avais un problème de valeur que j'ai corriger, j'ai compris le                                                                      systeme de la selection des plages de valeurs et des coco
}

void poseTermite(Grille &g, Coord c, int numTermite){         //Possible utilisation de l'assert pour vérifier au fil de l'execution des                                                                            erreurs
    if(dansGrille(g, c) and estVide(g, c) and numTermite >= 0)
        g.t[getX(c)][getY(c)].valeur = numTermite;
}

void enleveTermite(Grille &g, Coord c){                      //Possible utilisation de l'assert pour vérifier au fil de l'execution des                                                                         erreurs
    if(dansGrille(g, c) and numeroTermite(g, c) != -1)
        g.t[getX(c)][getY(c)].valeur = -1;
}