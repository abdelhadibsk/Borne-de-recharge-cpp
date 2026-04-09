extern "C" {
#include <donnees_borne.h>
#include <memoire_borne.h>
}

/**
 * @file accesMemoire.cpp
 * @brief Initialisation d'un acces bas niveau a la memoire partagee.
 */

entrees *io;
int shmid;
int depart_timer;

/**
 * @brief Initialise le timer a partir de la memoire partagee.
 */
void timer_initialiser()
{
    io=acces_memoire(&shmid);
    /* associe la zone de memoire partagee au pointeur */
    if (io==NULL) printf("Erreur pas de mem sh\n");
    depart_timer=io->timer_sec;
}