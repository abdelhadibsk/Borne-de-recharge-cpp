#include <iostream>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "memoire_partagee.hpp"
#include "voyants.hpp"

extern MemoirePartagee mem;

// passage en C++ du module voyants
// Fonction pour initialiser les voyants
void Voyants::init()
{
    mem.init_memoire_partagee();
}

void Voyants::clignoteDefaut()
{
    for ( int i = 0; i < 2; i++)   // temps du for (clignotement): 8 secondes ** 2
    {
        io_shared->led_defaut = OFF;
        sleep(1);   //sleep for 1 second
        io_shared->led_defaut = ROUGE;
        sleep(1);   //sleep for 1 second
    }
}

void Voyants::clignoteCharge()
{
    for ( int i = 0; i <= 4; i++)
    {
        io_shared->led_charge = VERT;
        sleep(1);   //sleep for 1 second
        io_shared->led_charge = OFF;
        sleep(1);   //sleep for 1 second
    }
}

void Voyants::reset_dispo()
{
    io_shared->led_dispo = OFF;
}

void Voyants::set_dispo()
{
    io_shared->led_dispo = VERT;
}

void Voyants::set_Charge()
{
    io_shared->led_charge = ROUGE;
}

void Voyants::reset_charge()
{
    io_shared->led_charge = OFF;
}

void Voyants::Set_ChargeVert()
{
    io_shared->led_charge = VERT;
}

