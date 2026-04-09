#include <iostream>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include "memoire_partagee.hpp"
#include "voyants.hpp"

/**
 * @file voyants.cpp
 * @brief Implementation du pilotage des voyants de la borne.
 */

extern MemoirePartagee mem;

/** @copydoc Voyants::init */
void Voyants::init()
{
    mem.init_memoire_partagee();
}

/** @copydoc Voyants::clignoteDefaut */
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

/** @copydoc Voyants::clignoteCharge */
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

/** @copydoc Voyants::reset_dispo */
void Voyants::reset_dispo()
{
    io_shared->led_dispo = OFF;
}

/** @copydoc Voyants::set_dispo */
void Voyants::set_dispo()
{
    io_shared->led_dispo = VERT;
}

/** @copydoc Voyants::set_Charge */
void Voyants::set_Charge()
{
    io_shared->led_charge = ROUGE;
}

/** @copydoc Voyants::reset_charge */
void Voyants::reset_charge()
{
    io_shared->led_charge = OFF;
}

/** @copydoc Voyants::Set_ChargeVert */
void Voyants::Set_ChargeVert()
{
    io_shared->led_charge = VERT;
}

