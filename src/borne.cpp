#include <stdio.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "lecteurcarte.hpp"

int main()
{
    LecteurCarte lecteur;
    lecteur.lecteurcarte_initialiser();

  	while(1){
        lecteur.lecteurcarte_lire_carte();
    }

}