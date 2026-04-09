#ifndef GENERATEUR_SAVE_HPP
#define GENERATEUR_SAVE_HPP

#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "voyants.hpp"
#include "prise.hpp"

/**
 * @file generateur_save.hpp
 * @brief Machine d'etats pilotant la sequence de charge du vehicule.
 */

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

/**
 * @class GestionnaireCharge
 * @brief Pilote la sequence complete de charge et de deconnexion.
 */
class GestionnaireCharge {
public:
    /**
     * @brief Construit le gestionnaire et initialise la machine d'etats.
     */
    GestionnaireCharge();

    /**
     * @brief Lance la sequence de charge complete.
     */
    void charger();

    /**
     * @brief Modifie le signal PWM envoye au vehicule.
     * @param mode Mode PWM a appliquer.
     */
    void genererPwm(pwm mode);

    /**
     * @brief Retourne la tension actuellement lue sur la borne.
     * @return Valeur de tension issue de la memoire partagee.
     */
    int tension() const;

    /**
     * @brief Ouvre le contacteur AC pour couper l'alimentation.
     */
    void ouvrirAC();

    /**
     * @brief Ferme le contacteur AC pour alimenter la prise.
     */
    void fermerAC();

    /**
     * @brief Reinitialise la borne apres la deconnexion du vehicule.
     */
    void deconnecter();

private:
    /* Enum class scopé : EtatCharge::A, EtatCharge::B, etc.
     * En C on écrivait "etatA", ce qui polluait le namespace global. */
    enum class EtatCharge { A, B, C, D, E };

    EtatCharge etatPresent;
    EtatCharge etatSuivant;

    /**
     * @brief Initialise l'etat interne et les sorties partagees.
     */
    void init();
};

#endif /* GESTIONNAIRE_CHARGE_HPP */