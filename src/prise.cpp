#include <iostream>
#include "prise.hpp"
#include "memoire_partagee.hpp"

// Constructeur
Prise::Prise() {
    if (io_shared == nullptr) {
        std::cerr << "Erreur: mémoire partagée non initialisée" << std::endl;
    }
}

// Méthodes
void Prise::verouiller_trappe() {
    if (io_shared == nullptr) return;
    io_shared->led_trappe = OFF;
}

void Prise::deverouiller_trappe() {
    if (io_shared == nullptr) return;
    io_shared->led_trappe = VERT;
}

void Prise::set_prise() {
    if (io_shared == nullptr) return;
    io_shared->led_prise = VERT;
}

void Prise::reset_prise() {
    if (io_shared == nullptr) return;
    io_shared->led_prise = OFF;
}