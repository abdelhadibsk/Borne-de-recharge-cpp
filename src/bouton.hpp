#ifndef BOUTON_HPP
#define BOUTON_HPP

/**
 * @file bouton.hpp
 * @brief Interface de lecture et de remise a zero des boutons physiques.
 */

/**
 * @class bouton
 * @brief Encapsule l'acces aux boutons de charge et d'arret.
 */
class bouton
{
private:
    
public:
    /**
     * @brief Construit l'objet de gestion des boutons.
     */
    bouton(/* args */);

    /**
     * @brief Verifie la disponibilite de la memoire partagee pour les boutons.
     */
    void bouton_init(void);

    /**
     * @brief Lit l'etat du bouton de lancement de charge.
     * @return Valeur du bouton de charge.
     */
    int bouton_charge_lit(void);

    /**
     * @brief Lit l'etat du bouton d'arret.
     * @return Valeur du bouton stop.
     */
    int bouton_stop_lit(void);

    /**
     * @brief Remet a zero le bouton de charge dans la memoire partagee.
     */
    void bouton_charge_reset(void);

    /**
     * @brief Remet a zero le bouton stop dans la memoire partagee.
     */
    void bouton_stop_reset(void);

};

#endif /* BOUTON_HPP */