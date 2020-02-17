/**
 * \file jeu.h
 * \brief Fonctions donnant vie au jeu
 * \author Louis Distel
 */



#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/**
 * \fn static inline int modulo(int i, int m)
 * \brief Gestion des dimensions de la grille au dépassement.
 *
 * \param i Dimension de la grille.
 * \param j Dimension de la grille.
 * \return modulo modifié pour traiter correctement les bords i=0 et j=0.
 */

static inline int modulo(int i, int m) {return (i+m)%m;}


/**
 * \fn int compte_voisins_vivants (int i, int j, grille g)
 * \brief Compte le nombre de voisins vivants de la cellule (i,j). Les bords sont non cycliques.
 * 
 * \param g Grille actuellement utilisée
 * \param i Dimension de la grille.
 * \param j Dimension de la grille.
 * \return Le nombre de voisins vivants de la cellule ciblée.
 */

int compte_voisins_vivants_non_cyclique (int i, int j, grille g);

/**
 * \fn int compte_voisins_vivants_cyclique (int i, int j, grille g)
 * \brief Compte le nombre de voisins vivants de la cellule (i,j). Les bords sont cycliques.
 * 
 * \param i Ligne de la cellule
 * \param j Colonne de la cellule
 * \param g Grille dans laquelle se trouve cette cellule et ses voisins à compter
 * 
 * \return Nombre de voisins vivants
 */

int compte_voisins_vivants_cyclique (int i, int j, grille g);

/**
 * \fn void evolue (grille *g, grille *gc)
 * \brief Fait évoluer la grille g d'un pas de temps.
 * 
 * \param g pointeur sur grille.
 * \param gc pointeur sur grille.
 * \param tempsEvolution pointeur sur le temps d'evolution actuel
 * \param compte_voisins_vivants pointeur sur le calcul de voisinage en cours
 * \param vieillissement vieillissement de la cellule
 * 
 */
void evolue (grille *g, grille *gc, int *tempsEvolution, int (*compte_voisins_vivants) (int, int, grille), int vieillissement);

#endif
