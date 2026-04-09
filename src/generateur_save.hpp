#ifndef GENERATEUR_SAVE_HPP
#define GENERATEUR_SAVE_HPP

#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "voyants.hpp"
#include "prise.hpp"

/*
 * Module de gestion du chargeur de véhicule électrique
 * Implémente une machine d'états pour la séquence de charge complète.
 *
 * Changements C → C++ :
 *  - La variable globale etat_present et les fonctions libres deviennent
 *    membres privés/publics d'une classe.
 *  - L'enum non scopé devient un enum class (évite les collisions de noms).
 *  - Le constructeur remplace generateur_save_init().
 *  - Les méthodes const garantissent qu'elles ne modifient pas l'état.
 */

class GestionnaireCharge {
public:
    /* Constructeur : initialise la mémoire partagée et remet l'état à A */
    GestionnaireCharge();

    /* Démarre la séquence de charge automatique (boucle bloquante) */
    void charger();

    /* Règle le mode PWM (STOP, DC, AC_1K, AC_CL) */
    void genererPwm(pwm mode);

    /* Retourne la tension mesurée (gene_u) */
    int tension() const;

    /* Ouvre le contact AC (coupe l'alimentation) */
    void ouvrirAC();

    /* Ferme le contact AC (active l'alimentation) */
    void fermerAC();

    /* Déconnecte le chargeur et réinitialise l'état */
    void deconnecter();

private:
    /* Enum class scopé : EtatCharge::A, EtatCharge::B, etc.
     * En C on écrivait "etatA", ce qui polluait le namespace global. */
    enum class EtatCharge { A, B, C, D, E };

    EtatCharge etatPresent;
    EtatCharge etatSuivant;

    /* Initialisation interne (appelée par le constructeur) */
    void init();
};

#endif /* GESTIONNAIRE_CHARGE_HPP */