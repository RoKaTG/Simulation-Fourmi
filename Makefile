# Fichier makefile pour projet termite
######################################

# Quelques variables de configuration du compilateur
####################################################
# Le compilateur Ã  utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

# Les programmes principaux
###########################
# On donne le fichier .cpp et la liste des fichiers .o qu'ils utilisent

all: projet_gui projet testcoord testgrille testtermite

projet: projet.cpp test.o termite.o grille.o coord.o # Ã  complÃ©ter...
testcoord: testcoord.cpp coord.o
testgrille: testgrille.cpp grille.o coord.o
testtermite: testtermite.cpp termite.o grille.o coord.o
projet_gui: projet_gui.cpp gui.o test.o termite.o grille.o coord.o
	$(CXX) $(CXXFLAGS) projet_gui.cpp gui.o test.o termite.o grille.o coord.o -o projet_gui $(SFOPT)
# Ã  complÃ©ter...

# Les diffÃ©rents composants
###########################
# on donne le fichier .cpp ainsi que la liste
# des fichiers .hpp dont ils dÃ©pendent

coord.o: coord.cpp coord.hpp
grille.o: grille.cpp grille.hpp coord.hpp
termite.o: termite.cpp termite.hpp grille.hpp coord.hpp
test.o: test.cpp projet.hpp termite.hpp grille.hpp coord.hpp
gui.o: gui.cpp gui.hpp termite.hpp grille.hpp coord.hpp

clean:
	rm -f projet_gui projet testgrille testcoord testtermite gui *.o

# Attention dans la ligne ci-dessus il faut Ã©crire
# un seul caractÃ¨re de tabulation et pas 8 espaces.
