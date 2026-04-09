#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "lecteurcarte.hpp"

/**
 * @file borne.cpp
 * @brief Point d'entree principal de l'application de borne.
 */

/**
 * @brief Lance la boucle principale de lecture carte de la borne.
 * @return Code de retour du programme.
 */
int main()
{
    LecteurCarte lecteur;
    lecteur.lecteurcarte_initialiser();

  	while(1){
        lecteur.lecteurcarte_lire_carte();
    }

}