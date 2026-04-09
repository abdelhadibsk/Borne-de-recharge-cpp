#include <iostream>
#include "bouton.hpp"
#include "memoire_partagee.hpp"


bouton::bouton(/* args */)
{
    
}

void bouton::bouton_init(void)
{
    /* Initialisation des boutons (optionnelle) */
    /* Assure que la mémoire partagée est disponible */
    if (io_shared == NULL) {
        std::cerr << "Erreur bouton: mémoire partagée non initialisée" << std::endl;
    }
}

int bouton::bouton_charge_lit(void)
{
    if (io_shared == NULL) {
        std::cerr << "Erreur bouton_charge_lit: mémoire partagée non initialisée" << std::endl;
        return 0;
    }
    return io_shared->bouton_charge;
}

int bouton::bouton_stop_lit(void)
{
    if (io_shared == NULL) {
        std::cerr << "Erreur bouton_stop_lit: mémoire partagée non initialisée" << std::endl;
        return 0;
    }
    return io_shared->bouton_stop;
}

void bouton::bouton_charge_reset(void)
{
    if (io_shared == NULL) {
        std::cerr << "Erreur bouton_charge_reset: mémoire partagée non initialisée" << std::endl;
        return;
    }
    io_shared->bouton_charge = 0;
}

void bouton::bouton_stop_reset(void)
{
    if (io_shared == NULL) {
        std::cerr << "Erreur bouton_stop_reset: mémoire partagée non initialisée" << std::endl;
        return;
    }
    io_shared->bouton_stop = 0;
}

