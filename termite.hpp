#ifndef DEF_TERMITE
#define DEF_TERMITE

#include "grille.hpp"
#include <cstdlib>

struct Termite{
    int numero;                                                        //Puisque bientot ajout d'un sablier temps et d'une nouvelle fonction                                                                        pour automatisation des termites, je rajouterais des entêtes de                                                                               fonction plus tard SERA FONCTIONNEL POUR ORAL
    Coord position;
    Direction direction;
    bool charge;
    int tournerSurPlace;
    int a;
    int sablier;
};

struct tabTermites{
    Termite tab[(TAILLE*TAILLE)/10];
    int taille;
};


/////////////////////////////////////////////////////////////////////////////////
//                    Documentation des fonctions du type abstrait             //
/////////////////////////////////////////////////////////////////////////////////


/** Déclare un tableau de termites vide
 * @param [out] T le tableau de termites qui sera entierement vide
 **/
void tabVide(tabTermites &T);

/** Indique ce que contient le tableau de termite
 * @param [in] T le tableau de termites
 * @return le nombre de termites contenu en T
 **/
int tailleTableau(tabTermites T);

/** Déclare un tableau de termite remplit 
 * @param [in] T le tableau des termites du test
 * @return true si le tableau est plein sinon false
 **/
bool estPlein(tabTermites T);

/** Crée un nouveau termite dans le tableau de termites /!\non remplit /!\
 * @param [in/out] T le tableau des termites du test
 **/
void creeTermite(tabTermites &T, Coord c);


/** Donne la direction vers laquelle le termite pointe
 * @param [in] t le termite dont on souhaite connaitre l'orientation
 * @return la direction du termite t
 **/
Direction directionTermite(Termite t);

/** Indique les coordonnées de la case en face du termite
 * @param [in] t un termite
 * @return les coordonnées de la case en face du termite t
 **/
Coord devantTermite(Termite t);

/** Vérifie si un termite porte une brindille
 * @param [in] t un termite
 * @return true si t porte une brindille sinon false
 **/
bool porteBrindille(Termite t);

/** Termine tourne à droite
 * @param [in/out] t un termite
 **/
void tourneADroite(Termite &t);

/** Termite tourne à gauche
 * @param [in/out] t un termite
 **/
void tourneAGauche(Termite &t);

/** Termine tourne dans une direction aléatoire
 * @param [in/out] t un termite
 **/
void tourneAleat(Termite &t);



/** Vérifie si la case en face d'un termite est vide
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] t un termite
 * @return true si la case est vide sinon false
 **/
bool laVoieEstLibre(Grille g, Termite t);

/** Vérifie si la case en face d'un termite contient une brindille
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] t un termite
 * @return true si la case contient une brindille sinon false
 **/
bool brindilleEnFace(Grille g, Termite t);

/** Vérifie si un termite n'atteint pas la limite de la grille
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] t un termite
 * @return true si le termite ne peut plus avancer sinon false
 **/
bool murEnFace(Grille g, Termite t);

/** Vérifie si un termite ne s'enferme pas s'il pose une brindille en face de lui
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in] t un termite
 * @return true si le termite ne peut pas s'enfermer sinon false
 **/
bool pasEnferme(Grille g, Termite t);



/** Permet de faire avancer un termite sur la case de devant
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: le termite qu'on veut faire avancer
 **/
void avanceTermite(Grille &g, Termite &t);

/** Permet au termite de deposer une brindille devant lui
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: le termite qui va déposer la brindille 
 **/
void dechargeTermite(Grille &g, Termite &t);

/** Permet au termite de ramasser une brindille devant lui
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: le termite qui va ramasser la brindille
 **/
void chargeTermite(Grille &g, Termite &t);

/** Permet de déplacer aléatoirement le termite
 * @param [in/out] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: le termite qui va être deplacer
 **/
void marcheAleatoire(Grille &g, Termite &t); 

/** fait tourner un termite sur lui mème plusieurs fois
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: le termite qui va tourner sur lui même
 * @return true si le termite doit tourner sur place sinon false
 **/
bool tourneSurPlace(Grille g, Termite &t);

/** Décremente le sablier d'un termite
 * @param [in/out] t: un termite
 **/
void modifierSablier(Termite &t);

/** indique la valeur du sablier d'un termite
 * @param [in] t: un termite
 * @return le sablier de t
 **/
int sablier(Termite t);

/** initialise le sablier de dépôt de brindille d'un termite si il est face
 *  à une brindille et qu'il est chargé
 * @param [in] g: la grille contenant les termites et les brindilles
 * @param [in/out] t: un termite chargé
 **/
void VoitBrindille(Grille g, Termite &t);

/** Décremente le sablier de dépôt de brindille d'un termite
 * @param [in/out] t: un termite
 **/
void modifierAvub(Termite &t);

/** Indique si le termite a vu une brindille, (ce qui implique qu'il doit lâcher
 *  la brindille qu'il porte sur une case adjacente dans le cas ou il est chargé)
 * @param [in] t: un termite
 * @return true si le termite a vu une brindille
 **/
bool aVuBrindille(Termite t);

#endif // DEF_TERMITE