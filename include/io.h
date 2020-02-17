/**
 * \file io.h
 * \brief Fonctions d'affichage du jeu
 * \author Louis Distel
 */


#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"


/**
 * \fn void affiche_trait (int c)
 * \brief Affichage d'un trait horizontal
 *
 * \param c Dimension de la grille.
 */

void affiche_trait (int c);

/**
 * \fn void affiche_ligne (int c, int* ligne)
 * \brief Affichage d'une ligne de la grille
 *
 * \param ligne Tableau contenant la valeur de chaque cellules de la grille.
 * \param c Dimension de la grille.
 */

void affiche_ligne (int c, int* ligne);


/**
 * \fn void affiche_grille (grille g)
 * \brief Affichage d'une grille et les informations associées
 *
 * \param tempsEvolution Temps actuel de l'évolution
 * \param g Grille actuellement utilisée.
 */

void affiche_grille (grille g, int tempsEvolution);

/**
 * \fn void efface_grille (grille g)
 * \brief Effacement d'une grille
 *
 * \param g Grille actuellement utilisée.
 */

void efface_grille (grille g);


/**
 * \fn void debut_jeu(grille *g, grille *gc)
 * \brief Debute le jeu
 *
 * \param g Grille actuellement utilisée.
 */
void debut_jeu(grille *g, grille *gc);

#endif
