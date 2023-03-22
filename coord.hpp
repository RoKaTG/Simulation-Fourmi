#ifndef DEF_COORD
#define DEF_COORD
#include <iostream>
#include <cstdlib>
#include <ctime>
#define couleur(param) printf("\033[%sm",param)


using namespace std;

struct Coord{
    int ligne, colonne;
};

enum Direction {N, NO, O, SO, S, SE, E, NE};

/////////////////////////////////////////////////////////////////////////////////
//                    Documentation des fonctions du type abstrait             //
/////////////////////////////////////////////////////////////////////////////////


/** Constructeur du type Coord qui retourne une coordonnée 
 * @param [in] lig la coordonnée en abscisse
 * @param [in] col la coordonnée en ordonnée
 * @return une plage de valeurs de coordonées (lig, col)
 **/
Coord creeCoord(int lig, int col);

 /** Affiche une plage de valeurs de coordonées (lig, col)
 * @param [in] c la coordonnée à afficher
 **/
void afficheCoord(Coord c);

/** Permet d'obtenir x d'une Coord
 * @param [in] c la coordonnée en l'abscisse
 * @return l'abscisse de c
 **/
int getX(Coord c);

/** Permet d'obtenir y d'une Coord
 * @param [in] c la coordonnée en l'ordonnée
 * @return l'ordonnée de c
 **/
int getY(Coord c);

/** Vérifie si deux coordonées sont égales
 * @param [in] c1 la première plage de valeurs de coordonées
 * @param [in] c2 la seconde plage de valeurs de coordonées
 * @return true si les deux coordonnées sont égales sinon false
 **/
bool egalCoord(Coord c1, Coord c2);



/** Affiche une direction
 * @param [in] dir la direction qu'on affiche
 **/
void afficheDirection(Direction dir);

/** Indique la direction à droite d'une direction donnée
 * @param [in] dir la direction donnée
 * @return la direction située à droite de dir
 **/
Direction aDroite(Direction dir);

/** Indique la direction à gauche d'une direction donnée
 * @param [in] dir la direction donnée
 * @return la direction située à gauche de dir
 **/
Direction aGauche(Direction dir);

/** Indique la coordonnée se truvant devant la case de coordonées et direction données
 * @param [in] c une coordonnée
 * @param [in] dir une direction
 * @return la coordonnée obtenue lorsqu'on avance de 1 dans la direction dir donnée
 *         à partir des coordonées c donnée
 **/ 
Coord devantCoord(Coord c, Direction dir);

#endif // DEF_COORD