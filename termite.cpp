#include "termite.hpp"

void tabVide(tabTermites &T){
    T.taille = 0;
}

int tailleTableau(tabTermites T){
    return T.taille;
}

bool estPlein(tabTermites T){
    return T.taille == (TAILLE*TAILLE)/10;
}

void creeTermite(tabTermites &T, Coord c){                   //Bientot un rajout de plusieurs fonctions/procédures sous la forme d'un                                                                         <sablier> pour timer fonctionnel
    Termite t;
    t.numero = T.taille;
    t.position = c;
    t.direction = Direction(rand()%8);
    t.charge = false;
    t.tournerSurPlace = 0;
    t.a = 0;
    t.sablier = 0;
    
    T.tab[T.taille] = t;
    T.taille++;
}


Direction directionTermite(Termite t){
    return t.direction;
}

Coord devantTermite(Termite t){
    return devantCoord(t.position, t.direction);
}

bool porteBrindille(Termite t){
    return t.charge;
}

void tourneADroite(Termite &t){
    t.direction = aDroite(t.direction);
}

void tourneAGauche(Termite &t){
    t.direction = aGauche(t.direction);
}

void tourneAleat(Termite &t){
    t.direction = Direction(rand()%8);  //Expliquer par prog lors d'une séance de suivis du projet
}

bool laVoieEstLibre(Grille g, Termite t){
    return dansGrille(g, devantTermite(t)) && estVide(g, devantTermite(t));
}

bool brindilleEnFace(Grille g, Termite t){
    return contientBrindille(g, devantTermite(t));
}

bool murEnFace(Grille g, Termite t){
    return !dansGrille(g, devantTermite(t));
}

bool pasEnferme(Grille g, Termite t){
    int casesV = 0;
    for(int i = 0; i < 8; i++){
        tourneADroite(t);
        if(laVoieEstLibre(g, t))
            casesV++;
    }
    return casesV >= 2;
}

void avanceTermite(Grille &g, Termite &t){
    poseTermite(g, devantTermite(t), t.numero);
    enleveTermite(g, t.position);
    t.position = devantTermite(t);
}

void dechargeTermite(Grille &g, Termite &t){
    poseBrindille(g, devantTermite(t));
    t.charge = false;
    t.sablier = 6;
}

void chargeTermite(Grille &g, Termite &t){
    enleveBrindille(g, devantTermite(t));
    t.charge = true;
    t.sablier = 6;
}

void marcheAleatoire(Grille &g, Termite &t){
    if(tourneSurPlace(g, t))
        return;
    int d = rand()%10;
    if(d > 0 and laVoieEstLibre(g, t))
        avanceTermite(g, t);
    else
        tourneAleat(t); 
}

bool tourneSurPlace(Grille g, Termite &t){
    bool res = false;
    if(t.tournerSurPlace == 0 and murEnFace(g, t)){
        int d = rand()%2;
        t.tournerSurPlace = rand()%2 + 3;
        if(d == 0)
            t.tournerSurPlace *= -1;
    }
    if(t.tournerSurPlace != 0){
        if(t.tournerSurPlace > 0){
            tourneADroite(t);
            t.tournerSurPlace--;
        } 
        else {
            tourneAGauche(t);
            t.tournerSurPlace++;
        }
        res = true;
    }
    return res;
}