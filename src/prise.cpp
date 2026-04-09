#include <iostream>
#include "prise.hpp"
#include "memoire_partagee.hpp"

/**
 * @file prise.cpp
 * @brief Implementation du pilotage de la prise et de la trappe.
 */

/** @copydoc Prise::Prise */
Prise::Prise() {
    if (io_shared == nullptr) {
        std::cerr << "Erreur: mémoire partagée non initialisée" << std::endl;
    }
}

/** @copydoc Prise::verouiller_trappe */
void Prise::verouiller_trappe() {
    if (io_shared == nullptr) return;
    io_shared->led_trappe = OFF;
}

/** @copydoc Prise::deverouiller_trappe */
void Prise::deverouiller_trappe() {
    if (io_shared == nullptr) return;
    io_shared->led_trappe = VERT;
}

/** @copydoc Prise::set_prise */
void Prise::set_prise() {
    if (io_shared == nullptr) return;
    io_shared->led_prise = VERT;
}

/** @copydoc Prise::reset_prise */
void Prise::reset_prise() {
    if (io_shared == nullptr) return;
    io_shared->led_prise = OFF;
}