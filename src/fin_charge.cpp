#include <iostream>           // printf, fprintf  (remplace stdio.h)
#include "client_db.hpp"
#include "memoire_partagee.hpp"
#include "generateur_save.hpp"
extern "C" {
#include <lcarte.h>
}
#include "lecteurcarte.hpp"
#include "prise.hpp"
#include "voyants.hpp"
#include "fin_charge.hpp"

extern ClientDB db;                      /* Accès à la base de données clients */
extern    GestionnaireCharge gen_charge;   /* Instance du gestionnaire de charge */
extern    Voyants v;                    /* Instance de gestion des voyants */
extern    bouton b;                        /* Instance de gestion des boutons */
extern    Prise p;                      /* Instance de gestion de la prise */


//si le bouton stop est appuye ou si la fin de charge est atteinte cette fonction est appelee
int check_and_deconnect(void) {


    //check l identifiant de la carte
    initialisations_ports();          /**************/
    std::cout << "Veillez entrer votre carte pour se deconnecter...\n" << std::endl;
           
    attente_insertion_carte();            /**************/
    int numero = lecture_numero_carte();  /**************/
    //int numero = 14;   

    if (db.authentification_carte(numero, "users.txt", 2, NULL))
    {   std::cout << "Acces autorise pour la carte n " << numero << std::endl;
                        
        p.deverouiller_trappe();              /* Trappe déverrouillée */
        v.reset_dispo();                      /* Éteint voyant dispo */
		gen_charge.genererPwm(DC);
		std::cout << "Veuillez retirer la prise ...\n" << std::endl;
						
		while(gen_charge.tension() != 12){ //attente retrait prise
			sleep(1);
		}   
		v.set_dispo();
        v.reset_charge();
        p.reset_prise();				
        std::cout << "Veuillez retirer votre carte...\n" << std::endl;
        attente_retrait_carte();
        liberation_ports();
        gen_charge.deconnecter();
        
        return 1;           /* Sortie de la boucle */
    }            
    else                
    {
        std::cout << "Accès refusé pour la carte n° " << numero << std::endl;
        return 0;
        }
}
