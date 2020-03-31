/**
 * \file grille.h
 * \brief Fonctions de gestion des grilles
 * \author Louis Distel
 */



#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
 * \struct grille
 * \brief structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules.
 * 
 * \param cellules Pointeur sur un tableau d'entiers
 * \param nbl Nombre de lignes dans la grille.
 * \param nbc Nombre de colonnes dans la grille.
 * 
 */

typedef struct {int nbl; int nbc; int** cellules;} grille;
 

/**
 * \fn void alloue_grille (int l, int c, grille* g)
 * \brief Alloue une grille de taille l*c, et initialise toutes les cellules à mortes.
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 */

void alloue_grille (int l, int c, grille* g);


/**
 * \fn void libere_grille (grille* g)
 * \brief Libère une grille.
 *
 * \param g Grille actuellement utilisée.
 * 
 */

void libere_grille (grille* g);


/**
 * \fn void init_grille_from_file (char * filename, grille* g)
 * \brief alloue et initalise la grille g à partir d'un fichier.
 *
 * \param filename Fichier utilisé pour initialiser la grille.
 * \param g Espace alloué pour une grille.
 * 
 */

int init_grille_from_file (char * filename, grille* g);

 
/**
 * \fn static inline void set_vivante(int i, int j, grille g)
 * \brief Rend vivante la cellule (i,j) de la grille g.
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 */

static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}


/**
 * \fn static inline void set_morte(int i, int j, grille g)
 * \brief   rend morte la cellule (i,j) de la grille g
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 */

static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}


/**
 * \fn static inline void set_non_viable(int i, int j, grille g)
 * \brief   rend non viable la cellule (i,j) de la grille g
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 */

static inline void set_non_viable(int i, int j, grille g){g.cellules[i][j] = -1;}



/**
 * \fn static inline void est_vivante(int i, int j, grille g)
 * \brief Teste si la cellule (i,j) de la grille g est vivante
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 * \return un int indiquant si la cellule est morte ou vivante
 */

static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] >= 1;}


/**
 * \fn static inline void est_non_viable(int i, int j, grille g)
 * \brief Teste si la cellule (i,j) de la grille g est non viable
 *
 * \param g Grille actuellement utilisée.
 * \param c Dimension de la grille.
 * \param l Dimension de la grille.
 * 
 * \return un int indiquant si la cellule est morte ou vivante
 */

static inline int est_non_viable(int i, int j, grille g){return g.cellules[i][j] == -1;}



/**
 * \fn void copie_grille (grille gs, grille gd)
 * \brief Recopie gs dans gd (sans allocation).
 *
 * \param gs Grille actuellement utilisée.
 * \param gd Grille cible.
 * 
 */

void copie_grille (grille gs, grille gd);

#endif
