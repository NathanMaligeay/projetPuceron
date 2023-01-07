all: simulationPucerons reponseNiveau1Question1 reponseNiveau1Question2 clean

simulationPucerons : main_simulation.o affichage.o infos.o initialisation.o  puceron.o tomate.o
	gcc -Wall main_simulation.o affichage.o infos.o initialisation.o  puceron.o tomate.o -o simulationPucerons

reponseNiveau1Question1: main_Niveau1Question1.o affichage.o infos.o initialisation.o  puceron.o tomate.o
	gcc -Wall main_Niveau1Question1.o affichage.o infos.o initialisation.o  puceron.o tomate.o -o reponseNiveau1Question1

main_Niveau1Question1.o: main_Niveau1Question1.c structure.h tomate.h affichage.h infos.h initialisation.h puceron.h
	gcc -Wall -c main_Niveau1Question1.c

reponseNiveau1Question2: main_Niveau1Question2.o affichage.o infos.o initialisation.o  puceron.o tomate.o
	gcc -Wall main_Niveau1Question2.o affichage.o infos.o initialisation.o  puceron.o tomate.o -o reponseNiveau1Question2

main_Niveau1Question2.o: main_Niveau1Question2.c structure.h tomate.h affichage.h infos.h initialisation.h puceron.h
	gcc -Wall -c main_Niveau1Question2.c

main_simulation.o: main_simulation.c structure.h tomate.h affichage.h infos.h initialisation.h puceron.h
	gcc -Wall -c main_simulation.c

affichage.o: affichage.c affichage.h
	gcc -Wall -c affichage.c

infos.o: infos.c infos.h
	gcc -Wall -c infos.c

initialisation.o: initialisation.c initialisation.h
	gcc -Wall -c initialisation.c

tomate.o: tomate.c tomate.h
	gcc -Wall -c tomate.c

puceron.o: puceron.c puceron.h
	gcc -Wall -c puceron.c

clean:
	rm -f *.o

mrproper:
	rm -f simulationPucerons reponseNiveau1Question1 reponseNiveau1Question2

#simulationPuceronsCoccinelles :