#ifndef DEF_GRILLE
#define DEF_GRILLE

#include "coord.hpp"

const int TAILLE = 20;

struct Case{
    int valeur; // -2 pour une brindille, -1 pour une case vide, un nombre >0 pour un termite, valeur c++ default restriction.
};

struct Grille{
    Case t[TAILLE][TAILLE]; // Deuxieme solution possible(mais beaucoup moins propre !):int hauteur; int largeur; case grille[500][500];
};


/////////////////////////////////////////////////////////////////////////////////
//                    Documentation des fonctions du type abstrait             //
/////////////////////////////////////////////////////////////////////////////////


/** Initialise une grille vide           
 * @param [in/out] g la grille initialisée vide
 **/
void initialiseGrilleVide(Grille &g);                 //Probléme mineur lors de l'implémentation, j'utilise ensuite des cases, NB:                                                                  initialise une nouvelle procédure CaseVide pour la cohérence de l'execution

/** Vérifie si une case d'une grille est vide
 * @param [in] c coordonée de la case à vérifier dans la grille 
 * @param [in] g la grille contenant la case
 * @return true si la case spécifiées est vide sinon false
 **/
bool estVide(Grille g, Coord c);

/** Vérifie la position indiquée est dans une grille
 * @param [in] c les coordonnées à vérifier
 * @return true si les coordonées données sont dans la grille sinon false
 **/
bool dansGrille(Grille g, Coord c);

/** Vérifie si la case indiquée contient une brindille
 * @param [in] g la grille contenant la case
 * @param [in] c les coordonées de la case dans la grille
 * @return true si la case aux coordonnées données contient une brindille sinon false
 **/
bool contientBrindille(Grille g, Coord c);

/** Indique le numéro du termite présent
 * @param [in] g la grille contenant la case
 * @param [in] c les coordonées de la case dans la grille
 * @return le numéro du termite qui est sur la case ou -1 si il n'y a pas de termite
 **/
int numeroTermite(Grille g, Coord c);

/** Modifie une case pour mettre une brindille 
 * @param [in/out] g la grille à modifier
 * @param [in] c les coordonées de la case à modifier
 **/
void poseBrindille(Grille &g, Coord c);

/** Modifie une case pour enlever une brindille
 * @param [in/out] g la grille à modifier
 * @param [in] c les coordonées de la case à modifier 
 **/
void enleveBrindille(Grille &g, Coord c);

/** Modifie une case pour mettre un termite
 * @param [in/out] g la grille à modifier
 * @param [in] c les coordonées de la case à modifier
 * @param [in] numTermite le numero associé au termite qui va être poser
 **/
void poseTermite(Grille &g, Coord c, int numTermite);

/** Modifie une case pour enlever un termite
 * @param [in/out] g la grille à modifier
 * @param [in] c les coordonées de la case à modifier
 **/
void enleveTermite(Grille &g, Coord c);

#endif // DEF_GRILLE