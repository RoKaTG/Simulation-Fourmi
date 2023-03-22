#include "projet.hpp"

bool tabContient(Coord c, int const& taille, Coord tab[]){
	for(int i = 0; i < taille; i++){
		if(egalCoord(tab[i],{-1, -1})) break;
		if(egalCoord(tab[i], c)) return true;
	}
	return false;
}

void deplacement(Grille &g, tabTermites &T){
	for(int i = 0; i < tailleTableau(T); i++){
		modifierSablier(T.tab[i]);
		modifierAvub(T.tab[i]);
		
		if(not porteBrindille(T.tab[i])){
			if(not brindilleEnFace(g, T.tab[i]) or (T.tab[i].sablier != 0)){
				marcheAleatoire(g, T.tab[i]);
			} else {
				chargeTermite(g, T.tab[i]);
			}
		} else {
			if(not aVuBrindille(T.tab[i]) or T.tab[i].sablier != 0 or !pasEnferme(g, T.tab[i]) or !laVoieEstLibre(g,T.tab[i])){
				marcheAleatoire(g, T.tab[i]);
				if(brindilleEnFace(g, T.tab[i]))
					VoitBrindille(g, T.tab[i]);
			} else {
				dechargeTermite(g, T.tab[i]);
			}
		}
	}
}

void deplacement(Grille &g, tabTermites &T, int const& nbBrindilles, Coord coordTas[]){
	for(int i = 0; i < tailleTableau(T); i++){
		modifierSablier(T.tab[i]);
		modifierAvub(T.tab[i]);
		
		if(not porteBrindille(T.tab[i])){
			if(not brindilleEnFace(g, T.tab[i]) or (T.tab[i].sablier != 0) or tabContient(devantTermite(T.tab[i]), nbBrindilles, coordTas)){
				marcheAleatoire(g, T.tab[i]);
			} else {
				chargeTermite(g, T.tab[i]);
			}
		} else {
			if(not aVuBrindille(T.tab[i]) or T.tab[i].sablier != 0 or !pasEnferme(g, T.tab[i]) or !laVoieEstLibre(g,T.tab[i])){
				marcheAleatoire(g, T.tab[i]);
				if(brindilleEnFace(g, T.tab[i]))
					VoitBrindille(g, T.tab[i]);
			} else {
				dechargeTermite(g, T.tab[i]);
			}
		}
	}
}

bool contient(Coord c, std::vector<Coord> const& tab){
	for(uint i = 0; i < tab.size(); i++)
		if(egalCoord(tab[i], c)) return true;
	return false;
}

void tas(Grille const& g, Coord depart, std::vector<Coord> &explores){
	explores.push_back(depart);
	
	Coord voisins[4];
	voisins[0] = {getX(depart) + 1, getY(depart)};
	voisins[1] = {getX(depart) - 1, getY(depart)};
	voisins[2] = {getX(depart), getY(depart) + 1};
	voisins[3] = {getX(depart), getY(depart) - 1};
	
	for(int i = 0; i < 4; i++)
		if(!contient(voisins[i], explores) && contientBrindille(g, voisins[i]))
		if(!contient(voisins[i], explores) && contientBrindille(g, voisins[i]))
			tas(g, voisins[i], explores);
	return;
}

int tailleMaxTas(Grille const& g, int const& maxBrindilles, Coord coordTas[]){
	int tailleTas = 0, max = 0;
	std::vector<Coord> parcourus;
	std::vector<Coord> temp;
	
	for(int i = 0; i < TAILLE; i++){
		for(int j = 0; j < TAILLE; j++){
			if(!contient({i,j}, parcourus) && contientBrindille(g, {i,j})){
				tas(g, {i,j}, temp);
				tailleTas = temp.size();
				for(uint i = 0; i < temp.size(); i++)
					parcourus.push_back(temp[i]);
				if(tailleTas > max){
					max = tailleTas;
					for(uint i = 0; i < temp.size(); i++)
						coordTas[i] = temp[i];
					for(int i = temp.size(); i < maxBrindilles; i++)
						coordTas[i] = {-1,-1};
				}
				temp = std::vector<Coord>(0);
			}
		}
	}
	return max;
}

int initGrille(Grille &g, tabTermites &T){
	initialiseGrilleVide(g);
	int nbBrindilles = 0;
	for(int i = 0; i < TAILLE; i++){
		for(int j = 0; j < TAILLE; j++){
			float nb = rand()%100;
			nb /= 100;
			if(nb < DENSITE_BRINDILLE){
				poseBrindille(g, {i,j});
				nbBrindilles++;
			} else if(nb < DENSITE_TERMITE && nb > DENSITE_BRINDILLE){
				if(!estPlein(T)){
					creeTermite(T, {i,j});
					poseTermite(g, {i,j}, tailleTableau(T));
				}
			}
		}
	}
	return nbBrindilles;
}

void initTabTasVide(int const taille, Coord tabTas[]){
	for(int i = 0; i < taille; i++)
		tabTas[i] = {-1, -1};
}