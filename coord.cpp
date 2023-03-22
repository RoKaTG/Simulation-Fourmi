#include "coord.hpp"
#include <iostream>

using namespace std;

Coord creeCoord(int lig, int col){
    return {lig, col};
}

void afficheCoord(Coord c){
    cout << "(" << c.ligne << "," << c.colonne << ")"<<endl;
}

int getX(Coord c){
    return c.ligne;
}

int getY(Coord c){
    return c.colonne;
}

bool egalCoord(Coord c1, Coord c2){
    return c1.ligne == c2.ligne and c1.colonne == c2.colonne;
}

void afficheDirection(Direction dir){
    switch(dir){
        case 0: cout << "nord"; break;
        case 1: cout << "nord-ouest"; break;
        case 2: cout << "ouest"; break;
        case 3: cout << "sud-ouest"; break;
        case 4: cout << "sud"; break;
        case 5: cout << "sud-est"; break;
        case 6: cout << "est"; break;
        case 7: cout << "nord-est"; break;
    }

}
//Aide venant d'un L2 pour me simplifier l'utilisation de afficheDirection sinon nous avions pour le aDroite et aGauche(qui différe un peu) :
//switch(dir)
	//{
	//case Direction::N:
	//		dir = Direction::NO;
	//		break;
	//case Direction::NO:
		//	dir = Direction::O;
			//break;
	//case Direction::O:
		//	dir = Direction::SO;
			//break;
//	case Direction::SO:
	//		dir = Direction::S;
		//	break;
	//case Direction::S:
		//	dir = Direction::SE;
			//break;
	//case Direction::SE:
		//	dir = Direction::E;
			//break;
	//case Direction::E:
		//	dir = Direction::NE;
			//break;
	//case Direction::NE:
		//	dir = Direction::N;
			//break;
		//default:
			//cout << "Direction invalide" << endl;
			//break;
//	}
	
Direction aDroite(Direction dir){   
    if(dir == 7)
        return Direction(0);
    return Direction(dir + 1);
}

Direction aGauche(Direction dir){
    if(dir == 0)
        return Direction(7);
    return Direction(dir - 1);
}

Coord devantCoord(Coord c, Direction dir){
    if(dir <= 2)
        c.ligne--;
    if(dir >= 4 and dir <= 6)
        c.ligne++;
    if(dir == 0 or dir >= 6)
        c.colonne--;
    if(dir >= 2 and dir <= 4)
        c.colonne++;
    return c;
}