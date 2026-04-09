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

class LecteurCarte {
    public:
        LecteurCarte(); // Constructeur
    void lecteurcarte_initialiser();
    void lecteurcarte_lire_carte();

    private:
    int numero;
    int statut_boutton = 0;

};


#endif // LECTEURCARTE_HPP