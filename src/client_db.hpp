#ifndef CLIENT_DB_HPP
#define CLIENT_DB_HPP

#include <string>

/**
 * @file client_db.hpp
 * @brief Gestion de la liste des cartes autorisees et de la carte active.
 */

/**
 * @class ClientDB
 * @brief Gere les cartes connues et la carte autorisee pour la deconnexion.
 */
class ClientDB {
public:
    /**
     * @brief Construit la base client et charge les cartes depuis le fichier.
     */
    ClientDB();

    /**
     * @brief Verifie une carte lors du debut ou de la fin de charge.
     * @param numero Numero de la carte lue.
     * @param filename Fichier de persistance des cartes autorisees.
     * @param passage Type de verification: debut de charge ou deconnexion.
     * @return true si la carte est autorisee pour l'operation demandee.
     */
    bool authentification_carte(int numero, const std::string& filename, int passage);

    /**
     * @brief Recharge toutes les cartes autorisees depuis un fichier texte.
     * @param filename Nom du fichier contenant une carte par ligne.
     */
    static void load_cards_from_file(const std::string& filename);

    /**
     * @brief Compte le nombre de cartes presentes dans un fichier texte.
     * @param filename Nom du fichier a analyser.
     * @return Nombre de lignes non vides detectees.
     */
    static int count_cards_in_file(const std::string& filename);

    /**
     * @brief Efface la carte active memorisee apres une deconnexion.
     */
    static void reset_carte_active();


private:
    static const int MAX_CARDS = 100;

    static int allowed_cards[MAX_CARDS];
    static int allowed_count;
    static int carte_active;

    /**
     * @brief Indique si une carte existe deja dans la base locale.
     * @param numero Numero de carte a rechercher.
     * @return true si la carte est deja autorisee.
     */
    static bool carte_autorisee(int numero);

};

#endif /* CLIENT_DB_HPP */