#ifndef OPERATOR_T_H
#define OPERATOR_T_H

#include <iostream>
#include <stdexcept>

class Operator_t {
private:
    char symbole;  // Symbole de l'opérateur (+, -, *, /)

public:
    char symbol;
    explicit Operator_t(char s) : symbol(s) {
        if (s != '+' && s != '-' && s != '*' && s != '/') {
            throw std::runtime_error("Opérateur inconnu");
        }
    }
    int apply(int a, int b) const {
        switch (symbol) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return b != 0 ? a / b : 0;
            default: throw std::runtime_error("Opérateur inconnu");
        }
    }

    char getSymbole() const;
    void setSymbole(char s);
    void afficher() const;
};

#endif // OPERATOR_T_H