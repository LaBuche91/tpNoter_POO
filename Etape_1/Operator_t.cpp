#include "headers/Operator_t.h"

// Constructeur
Operator_t::Operator_t(char s) {
    if (s != '+' && s != '-' && s != '*' && s != '/') {
        throw std::invalid_argument("Symbole d'opérateur invalide. Utilisez +, -, * ou /.");
    }
    symbole = s;
}

// Getter
char Operator_t::getSymbole() const {
    return symbole;
}

// Setter
void Operator_t::setSymbole(char s) {
    if (s != '+' && s != '-' && s != '*' && s != '/') {
        throw std::invalid_argument("Symbole d'opérateur invalide. Utilisez +, -, * ou /.");
    }
    symbole = s;
}

// Appliquer l'opérateur
int Operator_t::apply(int a, int b) const {
    switch (symbole) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::invalid_argument("Division par zéro.");
            }
            return a / b;
        default:
            throw std::logic_error("Opérateur non supporté.");
    }
}

// Afficher le symbole
void Operator_t::afficher() const {
    std::cout << "Symbole de l'opérateur: " << symbole << std::endl;
}

// Destructeur
Operator_t::~Operator_t() {}