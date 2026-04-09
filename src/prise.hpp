#ifndef PRISE_HPP
#define PRISE_HPP

// le nom de classe doit être différent du nom de fichier pour éviter les conflits avec les fichiers
class Prise {
public:
    Prise();  // constructeur

    void verouiller_trappe();
    void deverouiller_trappe();
    void set_prise();
    void reset_prise();
};

#endif /* PRISE_HPP */