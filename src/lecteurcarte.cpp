
#include <iostream>
#include <unistd.h>
extern "C" {
#include <lcarte.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
}
#include "lecteurcarte.hpp"
#include "timer.hpp"
#include "voyants.hpp"
#include "memoire_partagee.hpp"
#include "client_db.hpp"
#include "bouton.hpp"
#include "generateur_save.hpp"

/**
 * @file lecteurcarte.cpp
 * @brief Implementation du cycle de lecture carte et declenchement de charge.
 */

//ipcclean

MemoirePartagee mem; // Instance globale pour gérer la mémoire partagée
Timer t;      // Instance globale pour gérer le timer
Voyants v;      // Instance globale pour gérer les voyants
bouton b;      // Instance globale pour gérer les boutons
ClientDB db;   // Instance globale pour gérer la base de données des clients
GestionnaireCharge gen_charge;   // Instance globale pour gérer la charge

/** @copydoc LecteurCarte::LecteurCarte */
LecteurCarte::LecteurCarte() {
    mem.init_memoire_partagee();
    b.bouton_init();


    if (io_shared == NULL) {
        std::cerr << "Erreur: accès mémoire partagée impossible" << std::endl;
    }
}

/** @copydoc LecteurCarte::lecteurcarte_initialiser */
void LecteurCarte::lecteurcarte_initialiser()
{
    mem.init_memoire_partagee();
    b.bouton_init();
    if (io_shared == NULL) {
        std::cerr << "Erreur: accès mémoire partagée impossible" << std::endl;
    }
}

/** @copydoc LecteurCarte::lecteurcarte_lire_carte */
void LecteurCarte::lecteurcarte_lire_carte()
{  
    /* Vérification de l'initialisation de la mémoire partagée*/
    if (io_shared == NULL) {  
        std::cerr << "Erreur: mémoire partagée non initialisée" << std::endl;
        return;
    }
    // Initialisation des voyants
    v.init();

    initialisations_ports();
    std::cout << "Veuillez insérer votre carte..." << std::endl;    
   
    // à décommenter pour test réel
    attente_insertion_carte();
   
    t.timer_raz ();   // remise à zéro et lancement du timer

    numero = lecture_numero_carte();
    //numero = 14;    // Valeur de test

    std::cout << "Numéro de carte lue  : " << numero << std::endl;
    std::cout << "Vérification de l'accès pour la carte n° " << numero << "..." << std::endl;
   
    // ajouter une classe client_db pour gérer la base de données des clients et une méthode d'authentification qui prend en paramètre le numéro de carte et retourne un booléen
    if (db.authentification_carte(numero, "users.txt", 1))
    {
        std::cout << "Accès autorisé pour la carte n° " << numero << std::endl;
        std::cout << "Appuyez sur le boutton charge\n" << std::endl;

        //clignotement de charge pour 8 seconds
        v.clignoteCharge();

         //while (  timer_valeur() <= 60 )
        while ( t.timer_valeur() <= 60 )        // 60
        {
            if(b.bouton_charge_lit() == 1){
                statut_boutton = 1; 
                break;
            }
            else
            {
               statut_boutton = 0;
            }
        }
   
        if(statut_boutton == 1) /* cas où le bouton a été appuyé */
        {      
                std::cout << "Le bouton de charge a été appuyé" << std::endl;
                v.reset_dispo();     // etendre le voyant de dispo
                std::cout << "Veuillez retirer votre carte..." << std::endl;
               
                attente_retrait_carte();
                liberation_ports();
               
                // début de la charge
                gen_charge.charger();  // classe charge à créer pour gérer la charge et une méthode charger qui lance la charge et gère son déroulement

                return;
                v.reset_dispo();     // etendre le voyant de dispo
        }
        else    /* cas où le temps est écoulé sans appui sur le bouton */
            {
                std::cout << "Temps d'attente écoulé, retirez votre carte." << std::endl;
                attente_retrait_carte();
                liberation_ports();
                return;
            }
     
        b.bouton_charge_reset();

        return;
   
    }
    else {

        std::cout << "Accès refusé pour la carte n° " << numero << std::endl;
        v.clignoteDefaut();   // clignotement voyant defaut
       

        return;
    }


}
