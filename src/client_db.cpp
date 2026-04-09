#include <iostream>
#include <fstream>
#include <string>
#include "client_db.hpp"

std::string filename = "users.txt";


// Initialisation des variables statiques
int ClientDB::allowed_cards[ClientDB::MAX_CARDS];
int ClientDB::allowed_count = count_cards_in_file("users.txt");

ClientDB::ClientDB() {}

// Compter lignes fichier
int ClientDB::count_cards_in_file(const std::string& name_file) {
    std::ifstream file(name_file);
    int count = 0;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }

    return count;
}

// Charger cartes depuis fichier
void ClientDB::load_cards_from_file(const std::string& name_file) {
    std::ifstream file(name_file);  // lire
    std::string line;
    int index = 0;

    while (std::getline(file, line) && index < MAX_CARDS) {
        if (!line.empty()) {
            allowed_cards[index++] = std::stoi(line);
        }
    }

    allowed_count = index;  
}

// Authentification
bool ClientDB::authentification_carte(int numero, const std::string& filename, int passage, int* check)
{
    
        // Vérifier si existe déjà
    
        for (int i = 0; i < allowed_count; ++i) {
            if (allowed_cards[i] == numero) {
                if (numero == check && passage ==2){
                    return true;
                }
            }
        }
        if (passage == 2){
            return false;
        }

        // Nouvelle carte
        std::cout << "Nouvelle carte detectee: " << numero << std::endl;
        std::cout << "Ajouter ? (1=oui, 0=non): ";

        int reponse2 = 0;

        if (!(std::cin >> reponse2)) {
            std::cerr << "Erreur de saisie" << std::endl;
            return false;
        }

        if (reponse2 == 1 && allowed_count < MAX_CARDS) {
            // Ajouter la carte
            allowed_cards[allowed_count++] = numero;

            std::ofstream file(filename, std::ios::app);    // ecrire

            if (!file) {
                std::cerr << "Erreur ouverture fichier" << std::endl;
                return false;
            }

            file << numero << std::endl;

            std::cout << "Carte ajoutee et sauvegardee: " << numero << std::endl;
            return true;
    }


    return false;
    
}

 