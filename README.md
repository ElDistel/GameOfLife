# Projet : Game Of Life

Ce dépôt contient l'intégralité de l'avancée du projet de Technique de développement cycle 2019-2020 intitulé **Game Of Life**.


# Fichiers

 - /src contient tous les fichiers sources (*.c)
 - /include contient tous les fichiers headers (*.h)
 - /doc contient la documentation
 - /grilles contient les grilles utilisées par le jeu

# Commandes

Tout d'abord afin de pouvoir lancer le jeu il faut le compiler, ceci fait par le Makefile avec la commande suivante : 

    make

Ensuite une fois les dossiers binaires et objets générés il suffit pour lancer le jeu d'entrer la commande suivante :

    ./bin/main grilles/grille<chiffre de la grilles>.txt

Une fois ces dossiers générés pour les supprimer il vous suffira d'entrer ceci :

    make clean

Et enfin pour créer une archive du code source, ainsi que la doc et le Makefile :

    make dist

# Journal des versions

 - v3.0 niveau 2 complété
 - v2.0 niveau 1 complété
 - v1.0 version initiale
