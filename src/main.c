#include <stdio.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"


int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);

	printf("Commandes du programme :\n");
	printf("- n : Charger une nouvelle grille\n");
	printf("- c : Passer en mode cyclique/non-cyclique\n");
	printf("- q : Quitter le programme\n\n");

	//temps d'évolution initial à 1
	affiche_grille(g, 1, 1);	
	debut_jeu(&g, &gc);

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}
