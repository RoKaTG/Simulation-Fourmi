#include "projet.hpp"
#include <iostream>
#include <cstdlib>

using  namespace std;

void afficheGrille(Grille g, tabTermites T){                         //Nouvelle mise en forme avec simplification encore une fois de                                                                              l'affichage et du prgm qui est beaucoup moins lourd (cf fin .cpp)
    system("clear");
    for(int i = 0; i < TAILLE; i++){
        for(int j = 0; j < TAILLE; j++){
            if(contientBrindille(g, {i,j})){
                cout << "*";
           }
            else if(numeroTermite(g, {i,j}) != -1)
                switch(directionTermite(T.tab[numeroTermite(g, {i,j})])){
                    case N: case S: cout << "|"; break;
                    case NE: case SO: cout << "/"; break;
                    case E: case O: cout << "-"; break;
                    case SE: case NO: cout << "\\"; break;
                }
            else 
                cout << " ";
            cout << " ";
        }
        cout << endl;
    }
}

void test(Grille &g, tabTermites &T){                                   //Creation des nouvelles procédures terminer pour points bonus et                                                                                     simulation d'un essai.
    int nbPasse = 1;
    string a;
    bool passe;

    const int maxBrindilles = initGrille(g, T);
    afficheGrille(g, T);
    Coord grosTas[maxBrindilles];
    initTabTasVide(maxBrindilles, grosTas);
    int tailleTas = 0;
    bool con = false;

    while(true){              
        passe = true;
        getline(cin, a);
        for(char i: a)
        switch(i){
        case 'q': return;
        case '*': nbPasse *= 2; passe = false; break;                          //NB:  J'ai fais n'importe quoi ici ! Inversion totale des                                                                                 valeurs approprié pour l'affichage en caractére des differents                                                                                   termites (PTS BONUS)
        case '/': if(nbPasse > 1) nbPasse /= 2; passe = false; break;
        case 'c': con = !con; passe = false; break;
        default: break;
        }

        if(passe){
            for(int i = 0; i < nbPasse; i++){
                tailleTas = tailleMaxTas(g, maxBrindilles, grosTas);
                if(con)
                    deplacement(g, T, maxBrindilles, grosTas);
                else
                    deplacement(g, T);
            }
        }
        afficheGrille(g, T);
        cout << "Vitesse x" << nbPasse << endl;
        cout << "Taille du plus gros tas :" << tailleTas << endl;
     }
}

int main(){
    srand(time(0));
    tabTermites tabT;
    tabVide(tabT);
    Grille g;
    test(g, tabT);
    return 0;
}
/*de base j'avais ca :
void placeTermite(Grille &G, Armoire &A){
	Coord cr;
	int direct;
	for(int i =0; i<NOMBRETERMITE; i++){
		cr.ligne=rand()%G.hauteur;
		cr.colonne=rand()%G.largeur;
		if(estVide(G, cr) && dansGrille(G, cr)){
			
			direct=rand()%8;
			switch(direct)
			{
				case 0:
					A.nom[i].dir=Direction::N;
					break;
				case 1:
					A.nom[i].dir=Direction::NO;
					break;
				case 2:
					A.nom[i].dir=Direction::O;
					break;
				case 3:
					A.nom[i].dir=Direction::SO;
					break;
				case 4:
					A.nom[i].dir=Direction::S;
					break;
				case 5:
					A.nom[i].dir=Direction::SE;
					break;
				case 6:
					A.nom[i].dir=Direction::E;
					break;
				default:
					A.nom[i].dir=Direction::NE;
					break;
			}
			
			A.nom[i].brindille=false;
			A.nom[i].sablier=0;
			A.nom[i].numeroT=i;
			A.nom[i].tourneSurPlace=false;
			A.nom[i].c=cr;
			
			G.grille[cr.ligne][cr.colonne].termite=i;
		}
		else{
			i--;
		}		
	}
}



void placeBrindille(Grille &G){
	Coord cr;
	for (int i=0; i<NOMBREBRINDILLE; i++){
		cr.ligne=rand()%G.hauteur;
		cr.colonne=rand()%G.largeur;
		if(estVide(G, cr) && dansGrille(G, cr)){
			G.grille[cr.ligne][cr.colonne].brindille=true;
		}
		else{
			i--;
		}		
	}	
}

//ATTENTION: des fois ya des brindilles/termites qui apparaissent 
//en dehors de la grille...
*/