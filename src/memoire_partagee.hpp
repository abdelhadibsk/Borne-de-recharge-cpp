#ifndef MEMOIRE_PARTAGEE_HPP
#define MEMOIRE_PARTAGEE_HPP

// passage de c à cpp : remplacement de stdio.h par iostream et fprintf par cerr

#include <donnees_borne.h>
#include <memoire_borne.h>
#include "memoire_partagee.hpp"

/* Variable globale unique pour accès à la mémoire partagée */
extern entrees *io_shared;
extern int shmid_shared;

class MemoirePartagee {
public:

    /* Fonction pour initialiser l'accès à la mémoire partagée */
    void init_memoire_partagee(void);
};

#endif /* MEMOIRE_PARTAGEE_HPP */