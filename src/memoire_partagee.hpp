#ifndef MEMOIRE_PARTAGEE_HPP
#define MEMOIRE_PARTAGEE_HPP

// passage de c à cpp : remplacement de stdio.h par iostream et fprintf par cerr

#include <donnees_borne.h>
#include <memoire_borne.h>
#include "memoire_partagee.hpp"

/**
 * @file memoire_partagee.hpp
 * @brief Acces centralise a la memoire partagee de la borne.
 */

/* Variable globale unique pour accès à la mémoire partagée */
extern entrees *io_shared;
extern int shmid_shared;

/**
 * @class MemoirePartagee
 * @brief Initialise et expose l'acces a la memoire partagee materielle.
 */
class MemoirePartagee {
public:

    /**
     * @brief Attache le processus a la memoire partagee si necessaire.
     */
    void init_memoire_partagee(void);
};

#endif /* MEMOIRE_PARTAGEE_HPP */