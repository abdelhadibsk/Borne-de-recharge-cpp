#include <iostream>          
#include <stdlib.h>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "generateur_save.hpp"
#include "memoire_partagee.hpp"
#include "lecteurcarte.hpp"
#include <lcarte.h>
#include "voyants.hpp"
#include "prise.hpp"
#include "client_db.hpp"
#include "fin_charge.hpp"

/* ──────────────────────────────────────────────────────────────
   Constructeur  (remplace generateur_save_init())
   En C++ l'initialisation des membres se fait dans la liste
   d'initialisation ": etatPresent(...), etatSuivant(...)"
   avant même que le corps du constructeur s'exécute.
   ────────────────────────────────────────────────────────────── */

extern MemoirePartagee mem; // Instance globale pour gérer la mémoire partagée
extern Voyants v;      // Instance globale pour gérer les voyants
Prise p;              // Instance globale pour gérer la prise

GestionnaireCharge::GestionnaireCharge()
    : etatPresent(EtatCharge::A)
    , etatSuivant(EtatCharge::A)
{
    init();
}

void GestionnaireCharge::init()
{
    mem.init_memoire_partagee();
    if (io_shared == nullptr) {   // nullptr remplace NULL en C++
        std::cerr << "GestionnaireCharge: mémoire partagée non disponible\n";
        return;
    }
    io_shared->gene_pwm      = STOP;
    io_shared->led_trappe    = OFF;
    io_shared->contacteur_AC = 0;

    etatPresent  = EtatCharge::A;
    etatSuivant  = EtatCharge::A;

}

/* ──────────────────────────────────────────────────────────────
   genererPwm  (snake_case → camelCase, convention C++)
   ────────────────────────────────────────────────────────────── */
void GestionnaireCharge::genererPwm(pwm mode)
{
    if (io_shared == nullptr) {
        mem.init_memoire_partagee();
        if (io_shared == nullptr) return;
    }
    io_shared->gene_pwm = mode;
}

/* ──────────────────────────────────────────────────────────────
   tension()  — qualificateur "const" : cette méthode ne modifie
   aucun membre de la classe, le compilateur peut le vérifier.
   ────────────────────────────────────────────────────────────── */
int GestionnaireCharge::tension() const
{
    if (io_shared == nullptr) return 0;
    return io_shared->gene_u;
}

/* ──────────────────────────────────────────────────────────────
   charger()  — la machine d'états
   Différence principale : etatPresent/etatSuivant sont des
   membres de la classe, pas des variables statiques globales.
   On utilise EtatCharge::A au lieu de etatA.
   ────────────────────────────────────────────────────────────── */
void GestionnaireCharge::charger()
{
    if (io_shared == nullptr) init();
    if (io_shared == nullptr) return;

    init();  // réinitialisation
    int user = 0;

    while (true) {   // "while (true)" idiomatique en C++ (pas while(1))
        switch (etatPresent) {

            /* État A : Initialisation */
            case EtatCharge::A:
                std::cout << "Debut de la charge\n" << std::endl;
                p.deverouiller_trappe();
                v.reset_dispo();
                //genererPwm(DC); // need to call the method, not the C function
                genererPwm(DC);

                std::cout << "Veuillez connecter la prise...\n" << std::endl;
                while (tension() != 9) {
                    sleep(1);
                }
                p.verouiller_trappe();
                genererPwm(DC);
                p.set_prise();

                if (tension() == 9) {
                    etatSuivant = EtatCharge::B;
                }
                break;

            /* État B : 1ère négociation */
            case EtatCharge::B:
                v.Set_ChargeVert();
                genererPwm(AC_1K);
                ouvrirAC();

                if (tension() == 6) {
                    etatSuivant = EtatCharge::C;
                }
                break;

            /* État C : 2e négociation — charge active */
            case EtatCharge::C:
                std::cout << "Charge en cours...\n" << std::endl;
                genererPwm(AC_CL);
                fermerAC();

                if (io_shared->bouton_stop == 1) {
                    user = check_and_deconnect();
                }
                if (user == 1) return;

                if (tension() == 9) {
                    etatSuivant = EtatCharge::D;
                }
                break;

            /* État D : Attente */
            case EtatCharge::D:
                sleep(1);
                if (tension() == 9) {
                    etatSuivant = EtatCharge::E;
                }
                break;

            /* État E : Véhicule rechargé */
            case EtatCharge::E:
                std::cout << "Charge complete. Veuillez deconnecter.\n" << std::endl;
                v.Set_ChargeVert();
                ouvrirAC();
                genererPwm(DC);
                user = check_and_deconnect();
                if (user == 1) return;
                break;

            default:
                std::cerr << "Erreur: état inconnu\n" << std::endl;
                return;
        }

        etatPresent = etatSuivant;
        sleep(1);
    }
}

void GestionnaireCharge::ouvrirAC()
{
    if (io_shared == nullptr) init();
    if (io_shared == nullptr) return;
    io_shared->contacteur_AC = 0;
}

void GestionnaireCharge::fermerAC()
{
    if (io_shared == nullptr) init();
    if (io_shared == nullptr) return;
    io_shared->contacteur_AC = 1;
}

void GestionnaireCharge::deconnecter()
{
    if (io_shared == nullptr) init();
    if (io_shared == nullptr) return;

    genererPwm(STOP);
    ouvrirAC();
    p.verouiller_trappe();
    io_shared->bouton_charge = 0;
    io_shared->bouton_stop   = 0;
    std::cout << "[Chargeur] Deconnecte\n" << std::endl;
}