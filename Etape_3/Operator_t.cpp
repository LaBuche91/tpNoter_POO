#include "headers/Operator_t.h"

// Getter
char Operator_t::getSymbole() const {
    return symbol;
}

// Setter
void Operator_t::setSymbole(char s) {
    if (s != '+' && s != '-' && s != '*' && s != '/') {
        throw std::invalid_argument("Symbole d'opérateur invalide. Utilisez +, -, * ou /.");
    }
    symbol = s;
}

// Afficher le symbole
void Operator_t::afficher() const {
    std::cout << "Symbole de l'opérateur: " << symbol << std::endl;
}