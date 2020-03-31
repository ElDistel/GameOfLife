#include <stdio.h>
#include <string.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"

cairo_surface_t *sfc;

int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);

	#if CAIRO
		
		printf("\n##### programme en cours #####\n\n");
		sfc = cairo_create_x11_surface0(SIZEX, SIZEY);		
		debut_jeu(&g, &gc);
		cairo_close_x11_surface(sfc);

	#else
		printf("\n\nSTART WITH MODE TEXTE\n\n");
		printf("Commandes du programme :\n");
		printf("- n : Charger une nouvelle grille\n");
		printf("- c : Passer en mode cyclique/non-cyclique\n");
		printf("- v : Passer en mode vieillissement\n");
		printf("- q : Quitter le programme\n\n");
		//temps d'évolution initial à 1, le comptage cyclique à 1, le vieillissement désactivé à 0
		affiche_grille(g, 1, 1, 0);	
		debut_jeu(&g, &gc);
	
	#endif
	

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}
