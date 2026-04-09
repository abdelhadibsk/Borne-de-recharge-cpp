#include <iostream>
extern "C" {
#include <donnees_borne.h>
#include <memoire_borne.h>
}
#include "memoire_partagee.hpp" 

/**
 * @file memoire_partagee.cpp
 * @brief Implementation de l'acces a la memoire partagee.
 */

/* Définition de la variable globale unique */
entrees *io_shared = NULL;
int shmid_shared;;  

/** @copydoc MemoirePartagee::init_memoire_partagee */
void MemoirePartagee::init_memoire_partagee(void)
{
    if (io_shared == NULL) {
        io_shared = acces_memoire(&shmid_shared);
        if (io_shared == NULL) {
            std::cerr << "Erreur : pas de mémoire partagée" << std::endl;
        }
    }
}
