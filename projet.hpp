#ifndef DEF_AUTRES
#define DEF_AUTRES

#include "termite.hpp"
#include <vector>
 
const float DENSITE_TERMITE = 0.20;                             //Préferable à const int NOMBRETERMITE=40;   const int NOMBREBRINDILLE=80;                                                                       car beaucoup plus précis avec ces floats ci
const float DENSITE_BRINDILLE = 0.15;


/////////////////////////////////////////////////////////////////////////////////
//                    Documentation des fonctions du type abstrait             //
/////////////////////////////////////////////////////////////////////////////////


/** indique si un tableau de Coord contient un obstacle tel un termite ou une brindille
 * @param [in] c: la coordonnée recherchée
 * @param [in] taille: la taille du tableau dans lequel la recherche est faite
 * @param [in] tab: le tableau où l'on cherche les coordonnées c
 * @return true si c est dans tab sinon false
 **/
bool tabContient(Coord c, int const& taille, Coord tab[]);               //Ajout de plusieurs nouvelles fontions pour l'optimisation du projet en generale sur conseil de Bilel

/** Gère les déplacements de tous les termites lors du test
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] T: le tableau contenant les termites du test lancé
 **/
void deplacement(Grille &g, tabTermites &T);

/** Version de la fonction de déplacmenent permettant de garder la connexité
 *  du tas de brindilles composé des brindilles dont les coordonnées sont dans
 *  coordTas                                                                        
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] T: le tableau contenant les termites de la simulation
 * @param [in] nbBrindilles: le nombre total de brindilles dans la grille
 * @param [in] coordTas: le tableau qui contient les coordonnées des brindilles du plus gros tas
 **/
void deplacement(Grille &g, tabTermites &T, int const& nbBrindilles, Coord coordTas[]);                  //Donner par un L2 Info PYTHON, un deuxieme deplacement beaucoup plus pratique, utilisation des deux pour comparaisons faite(NB !!!)
 
/** indique si un vecteur contient un obstacle tel un termite ou une brindille
 * @param [in] c: la coordonnée recherchée
 * @param [in] tab: le vecteur contenant les coordonées c recherchées
 * @return true si c est dans tab sinon false
 **/
bool contient(Coord c, std::vector<Coord> const& tab);

/** Permet de récuperer les coordonnées des brindilles appartenant à une case contenant tas (donc plusieurs brindilles)
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] depart: la coordonée par laquelle on commence le parcours du tas                         
 * @param [out] explores: le vecteur contenant les coordonnées des brindilles
 *				trouvée lors du parcout 
 **/
void tas(Grille const& g, Coord depart, std::vector<Coord> &explores);                        // depart non inclue dans les coordonées                                                                                                     d'explore, NB:  A MODIFIER !

/** indique la taille du plus gros tas de brindilles
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] maxBrindilles: le nombre total de brindilles dans la grille
 * @param [out] coordTas: le tableau qui contient les coordonnées des brindilles du plus gros tas
 * @return le nombre de brindilles du plus gros tas
 **/
int tailleMaxTas(Grille const& g, int const& maxBrindilles, Coord coordTas[]);

/** initialise la grille pour le test
 * @param [out] g: la grille contenant les termites et les brindilles
 * @param [in/out] T: le tableau contenant les termites du test
 * @return le nombre total de brindilles de la grille
 **/
int initGrille(Grille &g, tabTermites &T);

/** initialise le tableau qui contiendra les coordonnées des brindilles
 ** du plus gros tas
 * @param [in] taille: la taille du tableau 
 * @param [out] tabTas: le tableau initialisé à vide
 **/
void initTabTasVide(int const taille, Coord tabTas[]);

#endif // DEF_AUTRES