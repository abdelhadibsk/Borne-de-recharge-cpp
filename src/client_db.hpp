#ifndef CLIENT_DB_HPP
#define CLIENT_DB_HPP

#include <string>

class ClientDB {
public:
    ClientDB();

    bool authentification_carte(int numero, const std::string& filename, int passage, int check);
    static void load_cards_from_file(const std::string& filename);
    static int count_cards_in_file(const std::string& filename);


private:
    static const int MAX_CARDS = 100;

    static int allowed_cards[MAX_CARDS];
    static int allowed_count;

};

#endif /* CLIENT_DB_HPP */