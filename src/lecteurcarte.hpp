#ifndef LECTEURCARTE_HPP
#define LECTEURCARTE_HPP

#include <iostream>
#include <unistd.h>
#include <lcarte.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "lecteurcarte.hpp"
#include "timer.hpp"
#include "voyants.hpp"
#include "memoire_partagee.hpp"
#include "client_db.hpp"
#include "bouton.hpp"
#include "generateur_save.hpp"

/**
 * @file lecteurcarte.hpp
 * @brief Interface du lecteur de carte de la borne.
 */

/**
 * @class LecteurCarte
 * @brief Orchestre l'authentification et le lancement d'une charge.
 */
class LecteurCarte {
    public:
    /**
     * @brief Construit le lecteur et prepare les dependances partagees.
     */
        LecteurCarte();

    /**
     * @brief Initialise l'acces a la memoire partagee et aux boutons.
     */
    void lecteurcarte_initialiser();

    /**
     * @brief Lit une carte, verifie l'acces et declenche la charge si possible.
     */
    void lecteurcarte_lire_carte();

    private:
    int numero;
    int statut_boutton = 0;

};


#endif // LECTEURCARTE_HPP