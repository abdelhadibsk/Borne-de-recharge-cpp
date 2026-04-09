#ifndef PRISE_HPP
#define PRISE_HPP

// le nom de classe doit être différent du nom de fichier pour éviter les conflits avec les fichiers
/**
 * @file prise.hpp
 * @brief Gestion des voyants et du verrou de la prise.
 */

/**
 * @class Prise
 * @brief Pilote l'etat physique de la prise et de la trappe.
 */
class Prise {
public:
    /**
     * @brief Construit le controleur de prise.
     */
    Prise();

    /**
     * @brief Verrouille la trappe de la prise.
     */
    void verouiller_trappe();

    /**
     * @brief Deverrouille la trappe de la prise.
     */
    void deverouiller_trappe();

    /**
     * @brief Allume l'indicateur de prise connectee.
     */
    void set_prise();

    /**
     * @brief Eteint l'indicateur de prise connectee.
     */
    void reset_prise();
};

#endif /* PRISE_HPP */