#ifndef OPERATOR_T_H
#define OPERATOR_T_H

#include <iostream>
#include <stdexcept>

class Operator_t {
private:
    char symbole;  // Symbole de l'opérateur (+, -, *, /)

public:
    // Constructeur
    Operator_t(char s);

    // Getter pour obtenir le symbole
    char getSymbole() const;

    // Setter pour modifier le symbole
    void setSymbole(char s);

    // Appliquer l'opérateur à deux entiers
    int apply(int a, int b) const;

    // Affichage du symbole
    void afficher() const;

    // Destructeur
    ~Operator_t();
};

#endif // OPERATOR_T_H