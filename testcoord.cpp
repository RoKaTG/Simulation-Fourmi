#include "coord.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
									   << " line " << __LINE__ << ": " #test << std::endl

/** Tests de la fonction egalCoord **/
void testEgalCoord(){
	int a, b;
	Coord c1, c2;
	for(int i = 0; i < 1000; i++){
		a = rand();
			if(a < 0) a *= -1;
		b = rand();
			if(b < 0) b *= -1;
		c1 = creeCoord(a,b);
		c2 = creeCoord(a,b);
		
		ASSERT(egalCoord(c1,c2));
		ASSERT(egalCoord(c1,{a,b}));
		ASSERT(egalCoord({a,b}, c2));
	}
}

/** Tests de la fonction ADroite **/
void testADroite(){
	Direction dir;
	Direction init;
	for(int i = 0; i < 8; i++){
		dir = Direction(i);
		init = dir;
		dir = aDroite(dir);
		dir = aGauche(dir);
		ASSERT(dir == init);
		
		dir = Direction(i);
		init = dir;
		for(int j = 0; j < 8; j++)
			dir = aDroite(dir);
		ASSERT(dir == init);
	}
}

/** Tests de la fonction AGauche **/
void testAGauche(){
	Direction dir;
	Direction init;
	for(int i = 0; i < 8; i++){
		dir = Direction(i);
		init = dir;
		dir = aGauche(dir);
		dir = aDroite(dir);
		ASSERT(dir == init);
		
		dir = Direction(i);
		init = dir;
		for(int j = 0; j < 8; j++)
			dir = aGauche(dir);
		ASSERT(dir == init);
	}
}

/** Tests de la fonction devantCoord **/
void testDevantCoord(){
	Coord c = creeCoord(1,2);
	ASSERT(egalCoord(devantCoord(c, N), {0,2}));
	ASSERT(egalCoord(devantCoord(c, SE), {2,3}));
	
	Direction dir;
	Coord init;
	for(int i = 0; i < 8; i++){
		dir = Direction(i);
		init = c;
		c = devantCoord(c, dir);
		for(int j = 0; j < 4; j++)
			dir = aDroite(dir);
		c = devantCoord(c, dir);
		ASSERT(egalCoord(c, init));
	}
}

int main(){
	testEgalCoord();
	testADroite();
	testADroite();
	testDevantCoord();
	return 0;
}