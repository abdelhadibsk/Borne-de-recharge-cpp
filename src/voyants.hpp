#ifndef VOYANTS_HPP
#define VOYANTS_HPP

// passage en C++ du module voyants

/**
 * @file voyants.hpp
 * @brief Interface de pilotage des voyants de la borne.
 */

/**
 * @class Voyants
 * @brief Gere l'etat lumineux de la borne et les clignotements associes.
 */
class Voyants
{
public:
    /**
     * @brief Initialise l'acces a la memoire partagee pour les voyants.
     */
    void init();

    /**
     * @brief Fait clignoter le voyant defaut.
     */
    void clignoteDefaut();

    /**
     * @brief Fait clignoter le voyant de charge.
     */
    void clignoteCharge();

    /**
     * @brief Eteint le voyant de disponibilite.
     */
    void reset_dispo();

    /**
     * @brief Allume le voyant de disponibilite.
     */
    void set_dispo();

    /**
     * @brief Place le voyant de charge en rouge.
     */
    void set_Charge();

    /**
     * @brief Eteint le voyant de charge.
     */
    void reset_charge();

    /**
     * @brief Place le voyant de charge en vert.
     */
    void Set_ChargeVert();
};


#endif /* VOYANTS_HPP */