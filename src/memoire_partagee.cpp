#include <iostream>
extern "C" {
#include <donnees_borne.h>
#include <memoire_borne.h>
}
#include "memoire_partagee.hpp" 

/* Définition de la variable globale unique */
entrees *io_shared = NULL;
int shmid_shared;;  

/* Fonction pour initialiser l'accès à la mémoire partagée */
void MemoirePartagee::init_memoire_partagee(void)
{
    if (io_shared == NULL) {
        io_shared = acces_memoire(&shmid_shared);
        if (io_shared == NULL) {
            std::cerr << "Erreur : pas de mémoire partagée" << std::endl;
        }
    }
}
