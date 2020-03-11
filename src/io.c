#include <string.h>
#include "io.h"

void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne, int vieillissement) {
	int i;
	if (vieillissement) {
		for (i=0; i<c; ++i) {
			if (ligne[i] == 0 ) printf ("|   ");
			else if (ligne[i] == -1) printf("| X ");
			else printf ("| %d ", ligne[i]);
		}
	} else {
		for (i=0; i<c; ++i) {
			if (ligne[i] == 0 ) printf ("|   ");
			else if (ligne[i] == -1) printf("| X ");
			else printf ("| 0 ");
		}
	}
	printf("|\n");
	return;
}

void affiche_grille (grille g, int tempsEvolution, int comptageCyclique, int vieillissement){
	int i, l=g.nbl, c=g.nbc;
	printf("Temps d'évolution : %d | ", tempsEvolution);
	printf("Comptage : ");
	comptageCyclique ? printf("Cyclique     | ") : printf("Non-cyclique | ");
	printf("Vieillissement : ");
	vieillissement ? printf("Activé    ") : printf("Désactivé		");
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i], vieillissement);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}

void efface_grille (grille g){
	printf("\n\e[%dA",g.nbl*2 + 5); 
}

void debut_jeu(grille *g, grille *gc){
	
	char c = getchar();
	int tempsEvolution = 1;
	int comptageCyclique = 1;
	int vieillissement = 0;
	int (*compte_voisins_vivants) (int, int, grille) = compte_voisins_vivants_cyclique;

	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) {

			case '\n' : 
			{ // touche "entree" pour évoluer
				evolue(g,gc, &tempsEvolution, compte_voisins_vivants, vieillissement);
				efface_grille(*g);
				affiche_grille(*g, tempsEvolution, comptageCyclique, vieillissement);
				break;
			}

			case 'n' :
			{ // touche 'n' pour charger dynamiquement une nouvelle grille
				libere_grille(g);
				libere_grille(gc);

				char numeroGrille[19];
				printf("Entrez ->  grilles/grille<numero de la grille>.txt : ");
				scanf("%256s", numeroGrille);
				init_grille_from_file(numeroGrille, g);
				alloue_grille (g->nbl, g->nbc, gc);
				tempsEvolution = 0;
				printf("\n");
				affiche_grille(*g, tempsEvolution, comptageCyclique, vieillissement);
				printf("\n");
				
				break;
			}

			case 'c' :
			{
				// voisinnage cyclique / non-cyclique
				if (comptageCyclique) { // On repasse à un comptage non-cyclique
					comptageCyclique = 0;
					compte_voisins_vivants = &(compte_voisins_vivants_non_cyclique);
				} 
				else { // On repasse à un comptage cyclique
					comptageCyclique = 1;
					compte_voisins_vivants = &(compte_voisins_vivants_cyclique);
				}
				break;
			}

			case 'v' :
			{
				// activation / désactivation du vieillissement
				vieillissement = !vieillissement;
				break;
			}

			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}
