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




#if CAIRO   

    #define SIZEX 1000
    #define SIZEY 600

    /** 
     * Création d'une surface Xlib Cairo
     * \param  x Largeur de la surface (en pixels)
     * \param  y Hauteur de la surface (en pixels)
     */
    cairo_surface_t *cairo_create_x11_surface0(int x, int y);

    /**
     * Destruction d'une surface Xlib Cairo et fermeture de la connexion à X
     */
    void cairo_close_x11_surface();

    /**
     * Affichage d'un trait horizontal (en mode GUI Cairo)
     * \param  c           Nombre de cellules du trait
     * \param  hauteur     Numéro de la hauteur du trait à tracer (en partant du haut de la grille)
     * \param  tailleLigne Hauteur de la ligne (en pixels)
     */
    void affiche_trait (int c, int hauteur, float tailleLigne);

    /**
     * Affichage d'une ligne de la grille (en mode GUI Cairo)
     * \param  c              Nombre de cellules de la ligne
     * \param  ligne          Tableau indiquant pour chaque cellule si elle est vivante ou morte
     * \param  vieillissement Indique si le vieillissement est activé (1) ou désactivé (0)
     * \param  hauteur        Numéro de la hauteur du trait à tracer (en partant du haut de la grille)
     * \param  tailleLigne    Hauteur de la ligne (en pixels)
     */
    void affiche_ligne (int c, int* ligne, int vieillissement, int hauteur, float tailleLigne);

    /**
     * Effacement de la grille sur l'interface graphique (en mode GUI Cairo)
     */
    void efface_grille ();

    /**
     * Affiche une entrée de texte au bas de l'écran
     * \param input  Entrée à afficher (saisie au clavier)
     * \param erreur Erreur à afficher entre parenthèses si nécessaire
     */
    void drawTextInput(char *input, char *erreur);

#else

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
 * \param vieillissement vieillissement de la cellule
 * 
 */
void affiche_ligne (int c, int* ligne, int vieillissement);


/**
 * \fn void efface_grille (grille g)
 * \brief Effacement d'une grille
 *
 * \param g Grille actuellement utilisée.
 */
void efface_grille (grille g);

#endif


/**
 * \fn void debut_jeu(grille *g, grille *gc)
 * \brief Debute le jeu
 *
 * \param g Grille actuellement utilisée.
 */
void debut_jeu(grille *g, grille *gc);


/**
 * \fn void affiche_grille (grille g)
 * \brief Affichage d'une grille et les informations associées
 *
 * \param tempsEvolution Temps actuel de l'évolution
 * \param g Grille actuellement utilisée.
 * \param comptageCyclique comptage actuellment utilisé
 * \param vieillissement vieillissement de la cellule
 * \param tempsOsc   Indique le temps d'oscillation d'une grille
 * 
 */
void affiche_grille (grille g, int tempsEvolution, int comptageCyclique, int vieillissement, int tempsOsc);

#endif
